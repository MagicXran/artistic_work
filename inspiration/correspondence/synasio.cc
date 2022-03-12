//
// Created by Administrator on 07/03/2022.
//

#include "synasio.h"
#include "iostream"
syn_asio::syn_asio() {
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
