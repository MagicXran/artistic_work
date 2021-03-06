#include "mainwindow.h"
#include "Ui_mainwindow.h"
#include "HellQt_Clion.h"
#include <iostream>
#include <QUrl>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow) {

    ui->setupUi(this);

    this->setWindowIcon(QIcon(QPixmap(":/res/icons8-robot-50.ico")));
    this->resize(1000 , 800);
    this->setWindowTitle("注射机选择与校验");

    /**
     * 初始化数据
     */

    calc_ = std::make_shared<calibration_parameters>();
    parser_ = std::make_shared<common_tools::ParseJson>();

    /**
    * 初始化表
    */

    // 超链接, 查询表
    ui->injectionM_table->setOpenExternalLinks(true);
    ui->tbl2->setOpenExternalLinks(true);
    ui->tbl3->setOpenExternalLinks(true);
    ui->tbl4->setOpenExternalLinks(true);
    ui->tbl5->setOpenExternalLinks(true);
    ui->tbl6->setOpenExternalLinks(true);
    ui->tbl7->setOpenExternalLinks(true);
    ui->tbl8->setOpenExternalLinks(true);
    ui->text_dia->setToolTip("请查表输入冷却水道直径");
    ui->text_dia->setToolTipDuration(1000);

    //way 1.
//    ui->injectionM_table->setText(tr(R"(<a href='file:C:\Projects\Qt\HelloQt_Clion\res\inject_table.png'>注射机型号于技术参数表)"));
//    way 2.获取当前路径下资源.
//    QString paht = QString("<a href='file:").append(PROJECT_PATH).append("/res/inject_table.png'>注射机型号于技术参数表");
    ui->injectionM_table->setText(
            QString("<a href='file:").append(PROJECT_PATH).append("/res/inject_table.png'>注射机型号于技术参数表"));
    ui->tbl2->setText(QString("<a href='file:").append(PROJECT_PATH).append("/res/p0.jpg'>部分塑料所需要的注射压力P0表"));
    ui->tbl3->setText(QString("<a href='file:").append(PROJECT_PATH).append("/res/p_mo.jpg'>常用塑料注射时,型腔内平均压力表表"));
    ui->tbl4->setText(QString("<a href='file:").append(PROJECT_PATH).append("/res/area.jpg'>分流道的横截面尺寸表"));
    ui->tbl5->setText(QString("<a href='file:").append(PROJECT_PATH).append("/res/qs.jpg'>常用塑料熔体单位热容量Qs表"));
    ui->tbl6->setText(QString("<a href='file:").append(PROJECT_PATH).append("/res/time.jpg'>常用塑料壁厚与冷却时间表"));
    ui->tbl7->setText(QString("<a href='file:").append(PROJECT_PATH).append("/res/f.jpg'>水温与f表"));
    ui->tbl8->setText(QString("<a href='file:").append(PROJECT_PATH).append("/res/d.jpg'>冷却水稳定湍流速度与流量"));

    // 初始化 流日志显示
    ui->text_log->setReadOnly(true);
    ui->text_log->setLineWrapMode(QTextEdit::WidgetWidth);
    ui->text_log->append(QString(HelloQt_Clion_VERSION_MINOR));

    //初始化 注射机型号列表, 浇口公式
    if (parser_->Open(JSON_PATH)) {
        ui->comboBox_machine->addItems(
                common_tools::ParseJson::vectorToQStringList(parser_->getJsonModelValuesFromArray("name")));


        for (const auto &var : parser_->getFormula()) {
//            std::cout << var.asString()  << std::endl;
            ui->comboBox_kou->addItem(var.asCString());
        }
    }

    connect(ui->comboBox_kou , &QComboBox::textActivated , [=](const QString &item) {
        std::cout << item.toStdString() << std::endl;
        ui->text_log->append("<span style=color:'green'> 选择浇口计算公式:" + item + "</span>");
    });

    // 确认机器型号
    connect(ui->btn_confirm , &QPushButton::clicked , this , &MainWindow::handle_machine_type);


    // 校核压力按钮
    connect(ui->btn_pressure , &QPushButton::clicked , [=]() {
        ui->text_log->append("<span style=color:'green'> 进行压力校核 </span>");
        calc_->getMSu();
        calc_->setP0(ui->text_p0->text().toDouble());
        parser_->getJsonModelValuesFromArray("pressure");

        int p_gong = parser_->getModel(ui->comboBox_machine->currentIndex() + 1)["pressure"][0].asInt();
        int p_0 = ui->text_p0->text().toInt();
        ui->text_p_gong->setText(QString::number(p_gong));
        ui->text_log->append("查表得公称压力: " + QString::number(p_gong) + "  实际压力: " + ui->text_p0->text());

        if (p_gong < p_0) {
            ui->text_log->append("<span style=color:'red'> 实际注射压力 ＞ 标准公称压力! </span>");
        } else
            ui->text_log->append("<span style=color:'green'> 实际注射压力 ＜  标准公称压力! </span>");
    });

    //浇注分流道系统计算
    connect(ui->btn_calc_gating_system , &QPushButton::clicked , [=]() {
        ui->text_log->append("<span style=color:'green'> 分流道系统计算 </span>");

        calc_->setSubL(ui->text_sub_L->text().toDouble());
        calc_->setSubA(ui->text_sub_area->text().toDouble());

        auto sebD = calc_->calc_subD();
        auto sebV = calc_->calc_subV();
        ui->text_sub_size->setText(QString::number(sebD));
        ui->text_sub_volume->setText(QString::number(sebV));

        ui->text_log->append("<span style=color:'green'> 分流道尺寸: </span>" + QString::number(sebD));
        ui->text_log->append("<span style=color:'green'> 分流道凝料体积: </span>" + QString::number(sebV));
    });

    //主流道设计
    connect(ui->btn_calc_main , &QPushButton::clicked , [=]() {
        ui->text_log->append("<span style=color:'green'> 主流道浇注系统计算 </span>");

        calc_->setMainL(ui->text_main_L->text().toDouble());

        auto hole = parser_->getModel(ui->comboBox_machine->currentIndex() + 1)["hole_radius"].asDouble();
        ui->text_log->append("<span style=color:'green'> 主流道小端半径: </span>" + QString::number(calc_->calc_main_r(hole)));


        ui->text_log->append("<span style=color:'green'> 主流道大端半径: </span>" + QString::number(calc_->calc_main_R()));


        auto sphere = parser_->getModel(ui->comboBox_machine->currentIndex() + 1)["sphere_radius"].asDouble();
        ui->text_log->append(
                "<span style=color:'green'> 主流道球面半径: </span>" + QString::number(calc_->calc_main_SR(sphere)));

        ui->text_log->append("<span style=color:'green'> 球面的配合高度: </span>" + QString::number(calc_->calc_main_h()));

        double main_Rn = calc_->calc_main_Rn();
        ui->text_main_radius->setText(QString::number(main_Rn));

        ui->text_main_volume->setText(QString::number(calc_->calc_main_v()));
    });
    // 锁模力计算
    connect(ui->btn_suo_force , &QPushButton::clicked , [=]() {

        ui->text_log->append("<span style=color:'green'> 进行锁模力校核 </span>");
        double p_mo = ui->text_p_mo->text().toDouble();

        int f_suo = parser_->getModel(ui->comboBox_machine->currentIndex() + 1)["suo_force"].asInt();

        double act_suo = calc_->calc_F_zhang(p_mo);
        ui->text_log->append("查表得锁模力: " + QString::number(f_suo) + "  实际锁模力: " + QString::number(act_suo));

        if (act_suo <= f_suo)
            ui->text_log->append("<span style=color:'green'> 实际锁模力符合标准锁模力! </span>");
        else
            ui->text_log->append("<span style=color:'red'> 实际锁模力 ＞ 标准锁模力! </span>");

        ui->text_f_grow->setText(QString::number(act_suo));

    });

    // 冷却系统计算
    connect(ui->btn_calc_cool_system , &QPushButton::clicked , [=]() {
        auto l = ui->text_l->text().toDouble();
        auto thetam = ui->text_theta_m->text().toDouble();
        auto theta1 = ui->text_theta_1->text().toDouble();
        auto theta2 = ui->text_theta_2->text().toDouble();
        auto f = ui->text_f->text().toDouble();
        auto v = ui->text_v->text().toDouble();
        auto rhoo = ui->text_rho->text().toDouble();
        auto time = ui->text_time->text().toDouble();

        auto time_cool = parser_->getModel(ui->comboBox_machine->currentIndex() + 1)["time"].asDouble();

        ui->text_log->append("<span style=color:'green'> 冷却时间: </span>" + QString::number(time));
        ui->text_log->append("<span style=color:'green'> 总体积V: </span>" + QString::number(calc_->calc_V()));
        ui->text_log->append(
                "<span style=color:'green'> 总时间: </span>" + QString::number(calc_->calc_t(time , time_cool)));

        auto W = calc_->calc_W(calc_->calc_N());
        ui->text_quantity->setText(QString::number(W));
        ui->text_log->append("<span style=color:'green'> 注射量: </span>" + QString::number(W));

        auto traffic = calc_->calc_Qv(ui->text_Qs->text().toDouble() , theta1 , theta2 , rhoo);
        ui->text_traffic->setText(QString::number(traffic));
        ui->text_log->append("<span style=color:'green'> 冷却水体积流量: </span>" + QString::number(traffic));

        auto flow_rate = calc_->calc_Speed(ui->text_dia->text().toDouble());
        ui->text_flow_rate->setText(QString::number(flow_rate));
        ui->text_log->append("<span style=color:'green'> 冷却水在管内流速: </span>" + QString::number(flow_rate));

        auto h = calc_->calc_H(f , v);
        ui->text_factor->setText(QString::number(h));
        ui->text_log->append("<span style=color:'green'> 冷却管壁与水交界的膜传热系数: </span>" + QString::number(h));

        auto A = calc_->calc_A(thetam);
        ui->text_area->setText(QString::number(A));
        ui->text_log->append("<span style=color:'green'> 冷却水道的传热总面积: </span>" + QString::number(A));

        auto x = calc_->calc_X(l);
        ui->text_X->setText(QString::number(x));
        ui->text_log->append("<span style=color:'green'> 管道数目: </span>" + QString::number(x));


    });
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::handle_machine_type() {

    calc_->setMachineType(ui->comboBox_machine->currentText().toStdString());
    calc_->setVSu(ui->text_v_su->text().toDouble());
    calc_->setASu(ui->text_a_su->text().toDouble());
    calc_->setN(ui->text_n->text().toDouble());
    calc_->calc_m_suo(calc_->getVSu());
    calc_->calc_v_main();

    //    std::cout << (calc_.get()) << std::endl;
    ui->text_log->append("确认型号: " + QString::fromStdString(calc_->getMachineType()));
    ui->text_log->append("V塑: " + QString::number(calc_->getVSu()));
    ui->text_log->append("A塑: " + QString::number(calc_->getASu()));
    ui->text_log->append("n: " + QString::number(calc_->getN()));
    ui->text_log->append("<span style=color:'green'> M塑: " + QString::number(calc_->getMSu()));
    ui->text_log->append("<span style=color:'green'>V总: " + QString::number(calc_->getVMain()));
//    ui->text_log->append("<span style=color:'red'>A塑: " + QString::number(calc_->getASu()) + "</span>");

}

bool MainWindow::eventFilter(QObject *target , QEvent *e) {
    std::cout << target->objectName().toStdString() << std::endl;
    std::cout << e->type() << std::endl;
    return QObject::eventFilter(target , e);
}

