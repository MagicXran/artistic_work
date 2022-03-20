/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_11;
    QTextEdit *text_log;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_13;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout;
    QLineEdit *text_v_su;
    QLabel *injectionM_table;
    QLineEdit *text_a_su;
    QComboBox *comboBox_machine;
    QPushButton *btn_confirm;
    QLineEdit *text_n;
    QGridLayout *gridLayout_12;
    QLineEdit *text_p0;
    QLabel *tbl2;
    QPushButton *btn_pressure;
    QLineEdit *text_p_gong;
    QGridLayout *gridLayout_5;
    QLineEdit *text_p_mo;
    QLabel *tbl3;
    QPushButton *btn_suo_force;
    QLineEdit *text_f_grow;
    QWidget *tab_3;
    QGridLayout *gridLayout_9;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_16;
    QGridLayout *gridLayout_15;
    QLineEdit *text_main_L;
    QLineEdit *text_main_volume;
    QLineEdit *text_main_radius;
    QComboBox *comboBox_kou;
    QPushButton *btn_calc_main;
    QWidget *tab_2;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_7;
    QLineEdit *text_sub_area;
    QLabel *tbl4;
    QLineEdit *text_sub_L;
    QLineEdit *text_sub_volume;
    QLineEdit *text_sub_size;
    QPushButton *btn_calc_gating_system;
    QWidget *tab_4;
    QGridLayout *gridLayout_14;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_5;
    QSplitter *splitter_3;
    QLineEdit *text_Qs;
    QLabel *tbl5;
    QGridLayout *gridLayout_10;
    QLineEdit *text_l;
    QLineEdit *text_theta_m;
    QLineEdit *text_X;
    QLineEdit *text_area;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout;
    QLineEdit *text_theta_1;
    QLineEdit *text_theta_2;
    QLineEdit *text_rho;
    QLineEdit *text_v;
    QLineEdit *text_traffic;
    QGridLayout *gridLayout_3;
    QLineEdit *text_time;
    QLineEdit *text_quantity;
    QLabel *tbl6;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_4;
    QSplitter *splitter_2;
    QLineEdit *text_f;
    QLabel *tbl7;
    QLineEdit *text_factor;
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter;
    QLineEdit *text_dia;
    QLabel *tbl8;
    QLineEdit *text_flow_rate;
    QPushButton *btn_calc_cool_system;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(686, 484);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_11 = new QGridLayout(centralWidget);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        text_log = new QTextEdit(centralWidget);
        text_log->setObjectName(QString::fromUtf8("text_log"));

        gridLayout_11->addWidget(text_log, 1, 0, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_13 = new QGridLayout(tab);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        text_v_su = new QLineEdit(tab);
        text_v_su->setObjectName(QString::fromUtf8("text_v_su"));
        sizePolicy.setHeightForWidth(text_v_su->sizePolicy().hasHeightForWidth());
        text_v_su->setSizePolicy(sizePolicy);

        gridLayout->addWidget(text_v_su, 0, 0, 1, 1);

        injectionM_table = new QLabel(tab);
        injectionM_table->setObjectName(QString::fromUtf8("injectionM_table"));
        sizePolicy.setHeightForWidth(injectionM_table->sizePolicy().hasHeightForWidth());
        injectionM_table->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(8);
        font.setUnderline(true);
        injectionM_table->setFont(font);

        gridLayout->addWidget(injectionM_table, 0, 1, 1, 1);

        text_a_su = new QLineEdit(tab);
        text_a_su->setObjectName(QString::fromUtf8("text_a_su"));
        sizePolicy.setHeightForWidth(text_a_su->sizePolicy().hasHeightForWidth());
        text_a_su->setSizePolicy(sizePolicy);

        gridLayout->addWidget(text_a_su, 1, 0, 2, 1);

        comboBox_machine = new QComboBox(tab);
        comboBox_machine->setObjectName(QString::fromUtf8("comboBox_machine"));
        sizePolicy.setHeightForWidth(comboBox_machine->sizePolicy().hasHeightForWidth());
        comboBox_machine->setSizePolicy(sizePolicy);

        gridLayout->addWidget(comboBox_machine, 1, 1, 1, 1);

        btn_confirm = new QPushButton(tab);
        btn_confirm->setObjectName(QString::fromUtf8("btn_confirm"));

        gridLayout->addWidget(btn_confirm, 2, 1, 2, 1);

        text_n = new QLineEdit(tab);
        text_n->setObjectName(QString::fromUtf8("text_n"));
        sizePolicy.setHeightForWidth(text_n->sizePolicy().hasHeightForWidth());
        text_n->setSizePolicy(sizePolicy);

        gridLayout->addWidget(text_n, 3, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setSpacing(6);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        text_p0 = new QLineEdit(tab);
        text_p0->setObjectName(QString::fromUtf8("text_p0"));
        sizePolicy.setHeightForWidth(text_p0->sizePolicy().hasHeightForWidth());
        text_p0->setSizePolicy(sizePolicy);

        gridLayout_12->addWidget(text_p0, 0, 0, 2, 1);

        tbl2 = new QLabel(tab);
        tbl2->setObjectName(QString::fromUtf8("tbl2"));
        sizePolicy.setHeightForWidth(tbl2->sizePolicy().hasHeightForWidth());
        tbl2->setSizePolicy(sizePolicy);
        tbl2->setFont(font);
        tbl2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_12->addWidget(tbl2, 0, 1, 1, 1);

        btn_pressure = new QPushButton(tab);
        btn_pressure->setObjectName(QString::fromUtf8("btn_pressure"));
        sizePolicy.setHeightForWidth(btn_pressure->sizePolicy().hasHeightForWidth());
        btn_pressure->setSizePolicy(sizePolicy);
        btn_pressure->setFlat(false);

        gridLayout_12->addWidget(btn_pressure, 1, 1, 2, 1);

        text_p_gong = new QLineEdit(tab);
        text_p_gong->setObjectName(QString::fromUtf8("text_p_gong"));
        text_p_gong->setEnabled(true);
        sizePolicy.setHeightForWidth(text_p_gong->sizePolicy().hasHeightForWidth());
        text_p_gong->setSizePolicy(sizePolicy);
        text_p_gong->setReadOnly(true);

        gridLayout_12->addWidget(text_p_gong, 2, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_12, 1, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        text_p_mo = new QLineEdit(tab);
        text_p_mo->setObjectName(QString::fromUtf8("text_p_mo"));
        sizePolicy.setHeightForWidth(text_p_mo->sizePolicy().hasHeightForWidth());
        text_p_mo->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(text_p_mo, 0, 0, 2, 1);

        tbl3 = new QLabel(tab);
        tbl3->setObjectName(QString::fromUtf8("tbl3"));
        sizePolicy.setHeightForWidth(tbl3->sizePolicy().hasHeightForWidth());
        tbl3->setSizePolicy(sizePolicy);
        tbl3->setFont(font);

        gridLayout_5->addWidget(tbl3, 0, 1, 1, 1);

        btn_suo_force = new QPushButton(tab);
        btn_suo_force->setObjectName(QString::fromUtf8("btn_suo_force"));
        sizePolicy.setHeightForWidth(btn_suo_force->sizePolicy().hasHeightForWidth());
        btn_suo_force->setSizePolicy(sizePolicy);
        btn_suo_force->setFlat(false);

        gridLayout_5->addWidget(btn_suo_force, 1, 1, 2, 1);

        text_f_grow = new QLineEdit(tab);
        text_f_grow->setObjectName(QString::fromUtf8("text_f_grow"));
        text_f_grow->setEnabled(true);
        sizePolicy.setHeightForWidth(text_f_grow->sizePolicy().hasHeightForWidth());
        text_f_grow->setSizePolicy(sizePolicy);
        text_f_grow->setReadOnly(true);

        gridLayout_5->addWidget(text_f_grow, 2, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 2, 0, 1, 1);


        gridLayout_13->addLayout(gridLayout_6, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_9 = new QGridLayout(tab_3);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        groupBox_3 = new QGroupBox(tab_3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        gridLayout_16 = new QGridLayout(groupBox_3);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_15 = new QGridLayout();
        gridLayout_15->setSpacing(6);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        text_main_L = new QLineEdit(groupBox_3);
        text_main_L->setObjectName(QString::fromUtf8("text_main_L"));
        sizePolicy.setHeightForWidth(text_main_L->sizePolicy().hasHeightForWidth());
        text_main_L->setSizePolicy(sizePolicy);

        gridLayout_15->addWidget(text_main_L, 0, 0, 1, 1);

        text_main_volume = new QLineEdit(groupBox_3);
        text_main_volume->setObjectName(QString::fromUtf8("text_main_volume"));
        text_main_volume->setEnabled(true);
        sizePolicy.setHeightForWidth(text_main_volume->sizePolicy().hasHeightForWidth());
        text_main_volume->setSizePolicy(sizePolicy);
        text_main_volume->setReadOnly(true);

        gridLayout_15->addWidget(text_main_volume, 0, 1, 1, 1);

        text_main_radius = new QLineEdit(groupBox_3);
        text_main_radius->setObjectName(QString::fromUtf8("text_main_radius"));
        sizePolicy.setHeightForWidth(text_main_radius->sizePolicy().hasHeightForWidth());
        text_main_radius->setSizePolicy(sizePolicy);
        text_main_radius->setReadOnly(true);

        gridLayout_15->addWidget(text_main_radius, 1, 0, 1, 1);

        comboBox_kou = new QComboBox(groupBox_3);
        comboBox_kou->setObjectName(QString::fromUtf8("comboBox_kou"));
        sizePolicy.setHeightForWidth(comboBox_kou->sizePolicy().hasHeightForWidth());
        comboBox_kou->setSizePolicy(sizePolicy);

        gridLayout_15->addWidget(comboBox_kou, 1, 1, 1, 1);

        btn_calc_main = new QPushButton(groupBox_3);
        btn_calc_main->setObjectName(QString::fromUtf8("btn_calc_main"));
        sizePolicy.setHeightForWidth(btn_calc_main->sizePolicy().hasHeightForWidth());
        btn_calc_main->setSizePolicy(sizePolicy);

        gridLayout_15->addWidget(btn_calc_main, 2, 0, 1, 2);


        gridLayout_16->addLayout(gridLayout_15, 0, 0, 1, 1);


        gridLayout_9->addWidget(groupBox_3, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_8 = new QGridLayout(tab_2);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        text_sub_area = new QLineEdit(tab_2);
        text_sub_area->setObjectName(QString::fromUtf8("text_sub_area"));
        sizePolicy.setHeightForWidth(text_sub_area->sizePolicy().hasHeightForWidth());
        text_sub_area->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(text_sub_area, 1, 0, 1, 1);

        tbl4 = new QLabel(tab_2);
        tbl4->setObjectName(QString::fromUtf8("tbl4"));
        sizePolicy.setHeightForWidth(tbl4->sizePolicy().hasHeightForWidth());
        tbl4->setSizePolicy(sizePolicy);
        tbl4->setFont(font);

        gridLayout_7->addWidget(tbl4, 1, 1, 1, 1);

        text_sub_L = new QLineEdit(tab_2);
        text_sub_L->setObjectName(QString::fromUtf8("text_sub_L"));
        sizePolicy.setHeightForWidth(text_sub_L->sizePolicy().hasHeightForWidth());
        text_sub_L->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(text_sub_L, 0, 0, 1, 1);

        text_sub_volume = new QLineEdit(tab_2);
        text_sub_volume->setObjectName(QString::fromUtf8("text_sub_volume"));
        text_sub_volume->setEnabled(true);
        sizePolicy.setHeightForWidth(text_sub_volume->sizePolicy().hasHeightForWidth());
        text_sub_volume->setSizePolicy(sizePolicy);
        text_sub_volume->setReadOnly(true);

        gridLayout_7->addWidget(text_sub_volume, 2, 0, 1, 1);

        text_sub_size = new QLineEdit(tab_2);
        text_sub_size->setObjectName(QString::fromUtf8("text_sub_size"));
        sizePolicy.setHeightForWidth(text_sub_size->sizePolicy().hasHeightForWidth());
        text_sub_size->setSizePolicy(sizePolicy);
        text_sub_size->setReadOnly(true);

        gridLayout_7->addWidget(text_sub_size, 3, 0, 1, 1);

        btn_calc_gating_system = new QPushButton(tab_2);
        btn_calc_gating_system->setObjectName(QString::fromUtf8("btn_calc_gating_system"));
        sizePolicy.setHeightForWidth(btn_calc_gating_system->sizePolicy().hasHeightForWidth());
        btn_calc_gating_system->setSizePolicy(sizePolicy);
        btn_calc_gating_system->setFlat(false);

        gridLayout_7->addWidget(btn_calc_gating_system, 2, 1, 2, 1);


        gridLayout_8->addLayout(gridLayout_7, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_14 = new QGridLayout(tab_4);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        groupBox_4 = new QGroupBox(tab_4);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        sizePolicy.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(groupBox_4);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        splitter_3 = new QSplitter(groupBox_4);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        text_Qs = new QLineEdit(splitter_3);
        text_Qs->setObjectName(QString::fromUtf8("text_Qs"));
        sizePolicy.setHeightForWidth(text_Qs->sizePolicy().hasHeightForWidth());
        text_Qs->setSizePolicy(sizePolicy);
        splitter_3->addWidget(text_Qs);
        tbl5 = new QLabel(splitter_3);
        tbl5->setObjectName(QString::fromUtf8("tbl5"));
        sizePolicy.setHeightForWidth(tbl5->sizePolicy().hasHeightForWidth());
        tbl5->setSizePolicy(sizePolicy);
        tbl5->setFont(font);
        splitter_3->addWidget(tbl5);

        verticalLayout_5->addWidget(splitter_3);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        text_l = new QLineEdit(groupBox_4);
        text_l->setObjectName(QString::fromUtf8("text_l"));
        sizePolicy.setHeightForWidth(text_l->sizePolicy().hasHeightForWidth());
        text_l->setSizePolicy(sizePolicy);

        gridLayout_10->addWidget(text_l, 0, 0, 1, 1);

        text_theta_m = new QLineEdit(groupBox_4);
        text_theta_m->setObjectName(QString::fromUtf8("text_theta_m"));
        sizePolicy.setHeightForWidth(text_theta_m->sizePolicy().hasHeightForWidth());
        text_theta_m->setSizePolicy(sizePolicy);

        gridLayout_10->addWidget(text_theta_m, 0, 1, 1, 1);

        text_X = new QLineEdit(groupBox_4);
        text_X->setObjectName(QString::fromUtf8("text_X"));
        sizePolicy.setHeightForWidth(text_X->sizePolicy().hasHeightForWidth());
        text_X->setSizePolicy(sizePolicy);
        text_X->setReadOnly(true);

        gridLayout_10->addWidget(text_X, 1, 0, 1, 1);

        text_area = new QLineEdit(groupBox_4);
        text_area->setObjectName(QString::fromUtf8("text_area"));
        sizePolicy.setHeightForWidth(text_area->sizePolicy().hasHeightForWidth());
        text_area->setSizePolicy(sizePolicy);
        text_area->setReadOnly(true);

        gridLayout_10->addWidget(text_area, 1, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_10);


        gridLayout_2->addLayout(verticalLayout_5, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        text_theta_1 = new QLineEdit(groupBox_4);
        text_theta_1->setObjectName(QString::fromUtf8("text_theta_1"));
        sizePolicy.setHeightForWidth(text_theta_1->sizePolicy().hasHeightForWidth());
        text_theta_1->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(text_theta_1);

        text_theta_2 = new QLineEdit(groupBox_4);
        text_theta_2->setObjectName(QString::fromUtf8("text_theta_2"));
        sizePolicy.setHeightForWidth(text_theta_2->sizePolicy().hasHeightForWidth());
        text_theta_2->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(text_theta_2);

        text_rho = new QLineEdit(groupBox_4);
        text_rho->setObjectName(QString::fromUtf8("text_rho"));
        sizePolicy.setHeightForWidth(text_rho->sizePolicy().hasHeightForWidth());
        text_rho->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(text_rho);

        text_v = new QLineEdit(groupBox_4);
        text_v->setObjectName(QString::fromUtf8("text_v"));
        sizePolicy.setHeightForWidth(text_v->sizePolicy().hasHeightForWidth());
        text_v->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(text_v);

        text_traffic = new QLineEdit(groupBox_4);
        text_traffic->setObjectName(QString::fromUtf8("text_traffic"));
        sizePolicy.setHeightForWidth(text_traffic->sizePolicy().hasHeightForWidth());
        text_traffic->setSizePolicy(sizePolicy);
        text_traffic->setReadOnly(true);

        verticalLayout->addWidget(text_traffic);


        gridLayout_4->addLayout(verticalLayout, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        text_time = new QLineEdit(groupBox_4);
        text_time->setObjectName(QString::fromUtf8("text_time"));
        sizePolicy.setHeightForWidth(text_time->sizePolicy().hasHeightForWidth());
        text_time->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(text_time, 0, 0, 1, 1);

        text_quantity = new QLineEdit(groupBox_4);
        text_quantity->setObjectName(QString::fromUtf8("text_quantity"));
        sizePolicy.setHeightForWidth(text_quantity->sizePolicy().hasHeightForWidth());
        text_quantity->setSizePolicy(sizePolicy);
        text_quantity->setReadOnly(true);

        gridLayout_3->addWidget(text_quantity, 1, 0, 1, 2);

        tbl6 = new QLabel(groupBox_4);
        tbl6->setObjectName(QString::fromUtf8("tbl6"));
        sizePolicy.setHeightForWidth(tbl6->sizePolicy().hasHeightForWidth());
        tbl6->setSizePolicy(sizePolicy);
        tbl6->setFont(font);

        gridLayout_3->addWidget(tbl6, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_4, 0, 1, 1, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        splitter_2 = new QSplitter(groupBox_4);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        text_f = new QLineEdit(splitter_2);
        text_f->setObjectName(QString::fromUtf8("text_f"));
        sizePolicy.setHeightForWidth(text_f->sizePolicy().hasHeightForWidth());
        text_f->setSizePolicy(sizePolicy);
        splitter_2->addWidget(text_f);
        tbl7 = new QLabel(splitter_2);
        tbl7->setObjectName(QString::fromUtf8("tbl7"));
        sizePolicy.setHeightForWidth(tbl7->sizePolicy().hasHeightForWidth());
        tbl7->setSizePolicy(sizePolicy);
        tbl7->setFont(font);
        splitter_2->addWidget(tbl7);

        verticalLayout_4->addWidget(splitter_2);

        text_factor = new QLineEdit(groupBox_4);
        text_factor->setObjectName(QString::fromUtf8("text_factor"));
        sizePolicy.setHeightForWidth(text_factor->sizePolicy().hasHeightForWidth());
        text_factor->setSizePolicy(sizePolicy);
        text_factor->setReadOnly(true);

        verticalLayout_4->addWidget(text_factor);


        verticalLayout_7->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        splitter = new QSplitter(groupBox_4);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        text_dia = new QLineEdit(splitter);
        text_dia->setObjectName(QString::fromUtf8("text_dia"));
        sizePolicy.setHeightForWidth(text_dia->sizePolicy().hasHeightForWidth());
        text_dia->setSizePolicy(sizePolicy);
        text_dia->setToolTipDuration(2);
        splitter->addWidget(text_dia);
        tbl8 = new QLabel(splitter);
        tbl8->setObjectName(QString::fromUtf8("tbl8"));
        sizePolicy.setHeightForWidth(tbl8->sizePolicy().hasHeightForWidth());
        tbl8->setSizePolicy(sizePolicy);
        tbl8->setFont(font);
        splitter->addWidget(tbl8);

        verticalLayout_3->addWidget(splitter);

        text_flow_rate = new QLineEdit(groupBox_4);
        text_flow_rate->setObjectName(QString::fromUtf8("text_flow_rate"));
        sizePolicy.setHeightForWidth(text_flow_rate->sizePolicy().hasHeightForWidth());
        text_flow_rate->setSizePolicy(sizePolicy);
        text_flow_rate->setReadOnly(true);

        verticalLayout_3->addWidget(text_flow_rate);


        verticalLayout_7->addLayout(verticalLayout_3);


        gridLayout_2->addLayout(verticalLayout_7, 1, 0, 1, 1);

        btn_calc_cool_system = new QPushButton(groupBox_4);
        btn_calc_cool_system->setObjectName(QString::fromUtf8("btn_calc_cool_system"));
        sizePolicy.setHeightForWidth(btn_calc_cool_system->sizePolicy().hasHeightForWidth());
        btn_calc_cool_system->setSizePolicy(sizePolicy);
        btn_calc_cool_system->setFlat(false);

        gridLayout_2->addWidget(btn_calc_cool_system, 1, 1, 1, 1);


        gridLayout_14->addWidget(groupBox_4, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());

        gridLayout_11->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 686, 22));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\263\250\346\250\241\350\256\241\347\256\227\345\231\250", nullptr));
        text_v_su->setText(QString());
        text_v_su->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245V\345\241\221", nullptr));
        injectionM_table->setText(QCoreApplication::translate("MainWindow", "\346\263\250\345\260\204\346\234\272\345\236\213\345\217\267\344\272\216\346\212\200\346\234\257\345\217\202\346\225\260\350\241\250", nullptr));
        text_a_su->setText(QString());
        text_a_su->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245A\345\241\221", nullptr));
        btn_confirm->setText(QCoreApplication::translate("MainWindow", "\347\241\256\350\256\244", nullptr));
        text_n->setText(QString());
        text_n->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245n", nullptr));
        text_p0->setText(QString());
        text_p0->setPlaceholderText(QCoreApplication::translate("MainWindow", "\346\263\250\345\260\204\345\216\213\345\212\233P0", nullptr));
        tbl2->setText(QCoreApplication::translate("MainWindow", "\351\203\250\345\210\206\345\241\221\346\226\231\346\211\200\351\234\200\350\246\201\347\232\204\346\263\250\345\260\204\345\216\213\345\212\233P0\350\241\250", nullptr));
        btn_pressure->setText(QCoreApplication::translate("MainWindow", "\345\216\213\345\212\233\346\240\241\351\252\214", nullptr));
        text_p_gong->setText(QString());
        text_p_gong->setPlaceholderText(QCoreApplication::translate("MainWindow", "\345\205\254\347\247\260\345\216\213\345\212\233P", nullptr));
        text_p_mo->setText(QString());
        text_p_mo->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245p\346\250\241", nullptr));
        tbl3->setText(QCoreApplication::translate("MainWindow", "\345\270\270\347\224\250\345\241\221\346\226\231\346\263\250\345\260\204\346\227\266,\345\236\213\350\205\224\345\206\205\345\271\263\345\235\207\345\216\213\345\212\233\350\241\250", nullptr));
        btn_suo_force->setText(QCoreApplication::translate("MainWindow", "\351\224\201\346\250\241\345\212\233\346\240\241\351\252\214", nullptr));
        text_f_grow->setText(QString());
        text_f_grow->setPlaceholderText(QCoreApplication::translate("MainWindow", "F\346\266\250", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\351\200\211\345\236\213\344\270\216\346\240\241\346\240\270", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\346\265\207\346\263\250\347\263\273\347\273\237\350\256\276\350\256\241\350\256\241\347\256\227", nullptr));
        text_main_L->setText(QString());
        text_main_L->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\344\270\273\346\265\201\351\201\223\351\225\277\345\272\246", nullptr));
        text_main_volume->setText(QString());
        text_main_volume->setPlaceholderText(QCoreApplication::translate("MainWindow", "\344\270\273\346\265\201\351\201\223\347\232\204\345\207\235\346\226\231\344\275\223\347\247\257", nullptr));
        text_main_radius->setText(QString());
        text_main_radius->setPlaceholderText(QCoreApplication::translate("MainWindow", "\344\270\273\346\265\201\351\201\223\345\275\223\351\207\217\345\215\212\345\276\204", nullptr));
        btn_calc_main->setText(QCoreApplication::translate("MainWindow", "\350\256\241\347\256\227", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\344\270\273\346\265\201\351\201\223", nullptr));
        text_sub_area->setText(QString());
        text_sub_area->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\345\210\206\346\265\201\351\201\223\346\250\252\346\210\252\351\235\242\351\235\242\347\247\257", nullptr));
        tbl4->setText(QCoreApplication::translate("MainWindow", "\345\210\206\346\265\201\351\201\223\347\232\204\346\250\252\346\210\252\351\235\242\345\260\272\345\257\270\350\241\250", nullptr));
        text_sub_L->setText(QString());
        text_sub_L->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\345\210\206\346\265\201\351\201\223\351\225\277\345\272\246", nullptr));
        text_sub_volume->setText(QString());
        text_sub_volume->setPlaceholderText(QCoreApplication::translate("MainWindow", "\345\210\206\346\265\201\351\201\223\345\207\235\346\226\231\344\275\223\347\247\257", nullptr));
        text_sub_size->setText(QString());
        text_sub_size->setPlaceholderText(QCoreApplication::translate("MainWindow", "\345\210\206\346\265\201\351\201\223\345\260\272\345\257\270", nullptr));
        btn_calc_gating_system->setText(QCoreApplication::translate("MainWindow", "\350\256\241\347\256\227", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\345\210\206\346\265\201\351\201\223\350\256\276\350\256\241", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\345\206\267\345\215\264\347\263\273\347\273\237\350\256\241\347\256\227", nullptr));
        text_Qs->setText(QString());
        text_Qs->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\346\237\245\350\241\250\350\276\223\345\205\245Qs", nullptr));
        tbl5->setText(QCoreApplication::translate("MainWindow", "\345\270\270\347\224\250\345\241\221\346\226\231\347\206\224\344\275\223\345\215\225\344\275\215\347\203\255\345\256\271\351\207\217Qs\350\241\250", nullptr));
        text_l->setText(QString());
        text_l->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\345\260\217l", nullptr));
        text_theta_m->setText(QString());
        text_theta_m->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\316\270_m", nullptr));
        text_X->setText(QString());
        text_X->setPlaceholderText(QCoreApplication::translate("MainWindow", "\347\256\241\351\201\223\346\225\260\347\233\256", nullptr));
        text_area->setText(QString());
        text_area->setPlaceholderText(QCoreApplication::translate("MainWindow", "\344\274\240\347\203\255\346\200\273\351\235\242\347\247\257", nullptr));
        text_theta_1->setText(QString());
        text_theta_1->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\316\270_1", nullptr));
        text_theta_2->setText(QString());
        text_theta_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\316\2702", nullptr));
        text_rho->setText(QString());
        text_rho->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\317\201", nullptr));
        text_v->setText(QString());
        text_v->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245v", nullptr));
        text_traffic->setText(QString());
        text_traffic->setPlaceholderText(QCoreApplication::translate("MainWindow", "\345\206\267\345\215\264\346\260\264\347\232\204\344\275\223\347\247\257\346\265\201\351\207\217", nullptr));
        text_time->setText(QString());
        text_time->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\346\237\245\350\241\250\350\276\223\345\205\245\345\206\267\345\215\264\346\227\266\351\227\264", nullptr));
        text_quantity->setText(QString());
        text_quantity->setPlaceholderText(QCoreApplication::translate("MainWindow", "\346\257\217\346\254\241\351\234\200\350\246\201\347\232\204\346\263\250\345\260\204\351\207\217", nullptr));
        tbl6->setText(QCoreApplication::translate("MainWindow", "\345\270\270\347\224\250\345\241\221\346\226\231\345\243\201\345\216\232\344\270\216\345\206\267\345\215\264\346\227\266\351\227\264\350\241\250", nullptr));
        text_f->setText(QString());
        text_f->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\346\237\245\350\241\250\350\276\223\345\205\245f", nullptr));
        tbl7->setText(QCoreApplication::translate("MainWindow", "\346\260\264\346\270\251\344\270\216f", nullptr));
        text_factor->setText(QString());
        text_factor->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\206\234\344\274\240\347\203\255\347\263\273\346\225\260", nullptr));
#if QT_CONFIG(tooltip)
        text_dia->setToolTip(QCoreApplication::translate("MainWindow", "\350\257\267\346\237\245\350\241\250\350\276\223\345\205\245\345\206\267\345\215\264\346\260\264\351\201\223\347\233\264\345\276\204", "\350\257\267\346\237\245\350\241\250\350\276\223\345\205\245\345\206\267\345\215\264\346\260\264\351\201\223\347\233\264\345\276\204"));
#endif // QT_CONFIG(tooltip)
        text_dia->setText(QString());
        text_dia->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\346\237\245\350\241\250\350\276\223\345\205\245\345\206\267\345\215\264\346\260\264\351\201\223\347\233\264\345\276\204", nullptr));
        tbl8->setText(QCoreApplication::translate("MainWindow", "\345\206\267\345\215\264\346\260\264\347\250\263\345\256\232\346\271\215\346\265\201\351\200\237\345\272\246\344\270\216\346\265\201\351\207\217", nullptr));
        text_flow_rate->setText(QString());
        text_flow_rate->setPlaceholderText(QCoreApplication::translate("MainWindow", "\345\206\267\345\215\264\346\260\264\345\234\250\347\256\241\345\206\205\347\232\204\346\265\201\351\200\237", nullptr));
        btn_calc_cool_system->setText(QCoreApplication::translate("MainWindow", "\350\256\241\347\256\227", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\345\206\267\345\215\264\347\263\273\347\273\237\346\240\241\351\252\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
