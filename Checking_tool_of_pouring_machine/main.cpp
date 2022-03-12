#define CONSOLE 1
#define DEBUG 0

#include "mainwindow.h"
#include <QApplication>
#include <cmath>
#include "HellQt_Clion.h"
#include "boost/asio.hpp"

#if DEBUG == 1

//#include "windows.h"
//#include <bits/stdc++.h>
//#include <conio.h> ///非标准输入输出
[[noreturn]] void test() {
    using namespace boost::asio;
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::socket socket(io_service);
    boost::system::error_code err;
    boost::asio::ip::tcp::endpoint server_endpoint(boost::asio::ip::address_v4::from_string("10.1.0.158" , err) , 9110);
    std::cout << err.value() << " " << err.message() << std::endl;

    // 连接服务器
    socket.connect(server_endpoint , err);
    std::cout << err.value() << " " << err.message() << std::endl;

    // 如果出错，打印出错信息
    if (err) {
        std::cout << boost::system::system_error(err).what() << std::endl;
        return;
    }

    while (true) {
        // 接收数据
        char buf[100];
        size_t len = socket.read_some(buffer(buf) , err);
        std::cout.write(buf , len);

    }

}

#endif


int main(int argc , char *argv[]) {

#if (CONSOLE == 1)
    setbuf(stdout , nullptr);
#endif

#if DEBUG == 0
    QApplication a(argc , argv);
    MainWindow w;
    w.show();
    return QApplication::exec();

#else
    test();

#endif
}
