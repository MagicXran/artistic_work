//
// Created by Administrator on 09/03/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_network_socket.h" resolved

#include "network_socket.h"
#include "Ui_network_socket.h"

namespace version_0_1 {
    network_socket::network_socket(QWidget *parent) :
            QWidget(parent) , ui(new Ui::network_socket) {
        ui->setupUi(this);
    }

    network_socket::~network_socket() {
        delete ui;
    }
} // version_0_1
