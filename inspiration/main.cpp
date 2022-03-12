

#include <iostream>
#include <sstream>
//#include "correspondence/synasio.h"
#define BOOST_ASIO_ENABLE_HANDLER_TRACKING
#define PY_SSIZE_T_CLEAN

#include <thread>
#include <boost/asio.hpp>
#include <Python.h>
//#include <boost/python.hpp>
using boost::asio::ip::tcp;

template<typename T>
std::string TtoStr(const T &t) {
    std::ostringstream oss;
    oss << t;
    return (oss.str());
}

template<typename T>
const char *TtoStr_(const T &t) {
    std::ostringstream oss;
    oss << t;
    return (oss.str().c_str());
}
//
//void syn_client() {
////    using boost::asio;
//    boost::system::error_code err;
//    boost::asio::io_context service;
//    boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string("127.0.0.1") , 12345);
//    boost::asio::ip::tcp::socket sock(service);
//    sock.connect(ep , err);
//    std::cout << err.value() << ": " << err.message() << std::endl;
//
//    // 如果出错，打印出错信息
//    if (err) {
//        std::cout << boost::system::system_error(err).what() << std::endl;
////        return;
//    }
//
////    sock.write_some(boost::asio::buffer("hello" , 6) , err);
//    boost::asio::write(sock , boost::asio::buffer("hello") , err);
//    std::cout << "wriet" << err.value() << err.message() << std::endl;
//}
//
//typedef std::shared_ptr<boost::asio::ip::tcp::socket> socket_ptr;
//
//[[noreturn]] void client_session(socket_ptr sock) {
//    while (true) {
//        char data[512];
////        size_t len = sock->read_some(boost::asio::buffer(data));
////        if (len > 0)
//        boost::asio::write(*sock , boost::asio::buffer("ok" , 2));
//    }
//}
//
//[[noreturn]] void syn_server() {
//    boost::system::error_code err;
//    boost::asio::io_context ioContext;
//    boost::asio::ip::tcp::endpoint ep(boost::asio::ip::tcp::v4() , 2001); // listen on 2001
//    boost::asio::ip::tcp::acceptor acceptor(ioContext , ep);
//    while (true) {
//        socket_ptr sock(new boost::asio::ip::tcp::socket(ioContext));
//        acceptor.accept(*sock , err);
//        std::cout << err.value() << ": " << std::endl;
//        std::thread(client_session , sock);
//    }
//}
//
//
//void asyn_client() {
//    boost::asio::io_context ioContext;
////    boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string("127.0.0.1") , 8888);
//    tcp::resolver resolver(ioContext);
//    auto ep = resolver.resolve("127.0.0.1" , "12345");
//    boost::asio::ip::tcp::socket tcp_sock(ioContext);
//    boost::asio::async_connect(tcp_sock , ep ,
//                               [&](boost::system::error_code err , const boost::asio::ip::tcp::endpoint &) {
//                                   std::cout << err.value() << err.message() << std::endl;
////                                   boost::asio::async_write(tcp_sock , boost::asio::buffer("我爱你哦\n") , []() {
////                                       std::cout << "ok 写完" << std::endl;
////                                   });
//                               });
//
//
//
////    tcp_sock.async_connect(ep , [=](boost::system::error_code err) {
////        std::cout << err.value() << err.message() << std::endl;
////    });
//
//    ioContext.run();
//}
//
//void handler(const boost::system::error_code &error , // Result of operation.
//
//             std::size_t bytes_transferred           // Number of bytes copied into the
//        // buffers. If an error occurred,
//        // this will be the  number of
//        // bytes successfully transferred
//        // prior to the error.
//);
//
//void accept_handler(const boost::system::error_code &error , boost::asio::ip::tcp::socket peer);
//
//void do_acceptor();
//
//char datas[512] = "init";
//
//void accept_handler(const boost::system::error_code &error , boost::asio::ip::tcp::socket peer) {
//    if (!error) {
//        //利用新的socket处理请求
//        boost::asio::async_read(peer , boost::asio::buffer(datas , sizeof datas) , boost::asio::transfer_all() ,
//                                [&](const boost::system::error_code &err , std::size_t bytes_transferred) {
//                                    if (!err) {
//                                        std::cout << datas << std::endl;
//                                    }
//                                    std::cout << err.value() << err.message() << std::endl;
//                                    std::cout << bytes_transferred << std::endl;
//                                });
//
//    } else
//        // 继续尝试重新连接
//        std::cout << error.value() << error.message() << std::endl;
//    do_acceptor();
//}
//
//void do_acceptor() {
//    acc.async_accept(accept_handler);
//}
//
//void asyn_server() {
//    boost::asio::io_context ioContext;
////tcp::endpoint endpoint(tcp::v4() , 12345);
//    tcp::endpoint endpoint(boost::asio::ip::address::from_string("127.0.0.1") , 12345);
////    tcp::acceptor acc(ioContext , endpoint);
//    do_acceptor();
////    ioContext.dispatch(do_acceptor);
//    ioContext.run();
//}
#define MAX_DATA_SIZE 150
#define MIN_DATA_SIZE 3
#define SLEEP_TIME  2

class asynServer {
private:
    tcp::acceptor acceptor_;
    tcp::socket sock_;
    tcp::endpoint ep_;
    char data_[MAX_DATA_SIZE];

public:
    asynServer(boost::asio::io_context &io_context , const tcp::endpoint &endpoint , tcp::socket sock) : acceptor_(
            io_context , endpoint) , sock_(std::move(sock)) , ep_(endpoint) {
        do_acceptor();
    }

    void do_read() {
        boost::asio::async_read(sock_ , boost::asio::buffer(data_ , MAX_DATA_SIZE) ,
                                [this](const boost::system::error_code &error , std::size_t bytes_transferred) {
                                    if (!error) {
                                        std::cout << data_ << std::endl;
                                    }
                                    do_acceptor();
                                });
    }

private:
    void do_acceptor() {
        acceptor_.async_accept([this](const boost::system::error_code &error , boost::asio::ip::tcp::socket peer) {
            std::cout << "async_accept: " << error.value() << ": " << error.message() << std::endl;
//            peer.async_write_some(boost::asio::buffer("data" , 10) ,
//                                  [](const boost::system::error_code &err , // Result of operation.
//                                     std::size_t bytes_transferred) {
//                                      std::cout << err.value() << ": " << err.message() << std::endl;
//                                  });
            do_read();
        });
    }
};


class asynClient {

private:
    boost::asio::io_context &io_context_;
    tcp::socket socket_;
    char data[MAX_DATA_SIZE] {};
    char *ip_ {};
    char *port_ {};
public:
    asynClient(boost::asio::io_context &ioContext , const tcp::resolver::results_type &endpoints) : io_context_(
            ioContext) , socket_(ioContext) {
//        tcp::resolver resolver(ioContext);
//        auto endpoints = resolver.resolve(argv[1] , argv[2]);
        do_connect(endpoints);
    }

    asynClient(boost::asio::io_context &ioContext , const char *ip , const char *service) : io_context_(ioContext) ,
                                                                                            socket_(ioContext) ,
                                                                                            ip_(const_cast<char *>(ip)) ,
                                                                                            port_(const_cast<char *>(service)) {
        tcp::resolver r(ioContext);
        tcp::resolver::query q(ip , service);
        r.async_resolve(q , [this](const boost::system::error_code &ec , const tcp::resolver::results_type &results) {
            if (!ec) {
                do_connect(results);
            }
        });

    }

    void do_read() {
        boost::asio::async_read(socket_ , boost::asio::buffer(data , MAX_DATA_SIZE) ,
                                [&](const boost::system::error_code &error , std::size_t bytes_transferred) {
                                    if (!error)
                                        if (strlen(data) < MIN_DATA_SIZE) {
                                            std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
                                        }
                                    std::cout << data << std::endl;
                                    do_read();
                                });
    }

private:
    void do_connect(const tcp::resolver::results_type &endpoints) {
        boost::asio::async_connect(socket_ , endpoints , [this](boost::system::error_code ec , const tcp::endpoint &) {
            if (!ec) {
                do_read();
            }
        });
    }


};

void asio_test() {
    std::cout << "Hello 徐国猪" << std::endl;
    std::cout << boost::asio::ip::host_name() << std::endl;
//    syn_server();
//    syn_client();
//    asyn_client();
//    asyn_server();
    boost::asio::io_context ioContext;

    tcp::endpoint endpoint(tcp::v4() , 9110);
    boost::asio::ip::tcp::socket sock(ioContext);
//    asynServer server(ioContext , endpoint , std::move(sock));

    tcp::resolver resolver(ioContext);
    auto endpoints = resolver.resolve("10.1.0.158" , "9110");
//    auto endpoints = resolver.resolve(endpoint);
//    asynClient client(ioContext , endpoints);
//    asynClient client(ioContext , "10.1.0.158" , "9110");

//    tcp::iostream s("" , "");
//    ioContext.run();

}

int invokePython(int argc , char **argv) {

    //接下来，使用 Py_Initialize() 初始化 Python 解释器，
    Py_Initialize();
    // 检查初始化是否成功
    if (!Py_IsInitialized()) {
        return -1;
    }
    PyRun_SimpleString("import sys");
    //py 的路径一定要加上 否则下面的 PyObject 为NULL
    PyRun_SimpleString("sys.path.append('C:/Projects/artistic_work/inspiration')");

    PyObject *pObj = PyImport_ImportModule("circle");
    if (pObj == nullptr) {
        std::cout << "模块导入失败" << std::endl;
    }

    PyObject *pFunc = PyObject_GetAttrString(pObj , "main");
    if (pFunc == nullptr) std::cout << "函数错误" << std::endl;

    PyObject_CallFunction(pFunc , nullptr);
    Py_Finalize();
    return 0;
}
