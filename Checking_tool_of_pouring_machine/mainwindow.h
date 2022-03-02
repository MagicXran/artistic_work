//
// Created by Administrator on 22/02/2022.
//

#ifndef HELLOQT_CLION_MAINWINDOW_H
#define HELLOQT_CLION_MAINWINDOW_H


#include <QMainWindow>
#include "memory"
#include "calibrationparameters.h"
#include "utils.hpp"
#define  JSON_PATH "C:/Projects/Qt/HelloQt_Clion/res/Injection_machine_meter.json"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

    void handle_machine_type();

protected:
    bool eventFilter(QObject *target , QEvent *e) override;

public slots:

private:
    Ui::MainWindow *ui;
    std::shared_ptr<calibration_parameters> calc_;
    std::shared_ptr<common_tools::ParseJson> parser_;
};

#endif //HELLOQT_CLION_MAINWINDOW_H
