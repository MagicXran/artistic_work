//
// Created by Administrator on 09/03/2022.
//

#ifndef INSPIRATION_NETWORK_SOCKET_H
#define INSPIRATION_NETWORK_SOCKET_H

#include <QWidget>

namespace version_0_1 {
    QT_BEGIN_NAMESPACE
    namespace Ui { class network_socket; }
    QT_END_NAMESPACE

    class network_socket : public QWidget {
    Q_OBJECT

    public:
        explicit network_socket(QWidget *parent = nullptr);

        ~network_socket() override;

    private:
        Ui::network_socket *ui;
    };
} // version_0_1

#endif //INSPIRATION_NETWORK_SOCKET_H
