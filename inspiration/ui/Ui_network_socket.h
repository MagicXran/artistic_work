/********************************************************************************
** Form generated from reading UI file 'network_socket.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORK_SOCKET_H
#define UI_NETWORK_SOCKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

namespace version_0_1 {

class Ui_network_socket
{
public:

    void setupUi(QWidget *version_0_1__network_socket)
    {
        if (version_0_1__network_socket->objectName().isEmpty())
            version_0_1__network_socket->setObjectName(QString::fromUtf8("version_0_1__network_socket"));
        version_0_1__network_socket->resize(400, 300);

        retranslateUi(version_0_1__network_socket);

        QMetaObject::connectSlotsByName(version_0_1__network_socket);
    } // setupUi

    void retranslateUi(QWidget *version_0_1__network_socket)
    {
        version_0_1__network_socket->setWindowTitle(QCoreApplication::translate("version_0_1::network_socket", "network_socket", nullptr));
    } // retranslateUi

};

} // namespace version_0_1

namespace version_0_1 {
namespace Ui {
    class network_socket: public Ui_network_socket {};
} // namespace Ui
} // namespace version_0_1

#endif // UI_NETWORK_SOCKET_H
