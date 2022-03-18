//
// Created by Administrator on 14/03/2022.
//
//#ifndef GLOG_NO_ABBREVIATED_SEVERITIES
//#define GLOG_NO_ABBREVIATED_SEVERITIES // 如果不加这个宏定义代码就会报错
//#endif

#include "gloger.h"

int main(int argc , char *argv[]) {
    std::cout << "ddd";
    Gloger gloger(R"(C:\Projects\artistic_work\inspiration\loger\log_config.json)" , "config_info");
    int x = 12;
    CHECK(x == 12) << "x == 12";
    CHECK_NE(1 , 2) << ": The world must be ending!"; //不等于
    DLOG(INFO) << "Found cookies";
    LOG_IF(INFO , 11 > 10) << "Got lots of cookies";
    CHECK_EQ(std::string("abc")[1] , 'b');
    return 0;
}
