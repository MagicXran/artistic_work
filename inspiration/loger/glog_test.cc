//
// Created by Administrator on 14/03/2022.
//
#ifndef GLOG_NO_ABBREVIATED_SEVERITIES
#define GLOG_NO_ABBREVIATED_SEVERITIES // 如果不加这个宏定义代码就会报错
#endif

#include <iostream>
#include <chrono>
#include <thread>
//#include "config.h"
#include "glog/logging.h"
//using namespace GOOGLE_NAMESPACE;


static std::string getCurrentTimeStr() {
    time_t t = time(nullptr);
    char ch[64] = {0};
    strftime(ch , sizeof(ch) - 1 , "%Y_%m_%d" , localtime(&t));     //年-月-日 时-分-秒
    return ch;
}

void init_log() {

    std::string file_path = "C:/Projects/artistic_work/inspiration/loger";
    FLAGS_log_dir = file_path;
    google::InitGoogleLogging("test");
    FLAGS_logbufsecs = 0; //缓冲日志输出，默认为30秒，此处改为立即输出
    FLAGS_max_log_size = 100; //最大日志大小为 100MB
    FLAGS_stop_logging_if_full_disk = true; //当磁盘被写满时，停止日志输出

    FLAGS_alsologtostderr = true;//是否将日志输出到文件和stderr
    //设置将指定等级及其以上等级的日志输出到标准错误，默认为 ERROR
    FLAGS_colorlogtostderr = true; //设置输出到屏幕的日志显示相应颜色
    FLAGS_stderrthreshold = 2;
    FLAGS_log_prefix = true; //是否输出前缀
    FLAGS_log_year_in_prefix = false; //是否输出年月日前缀
    FLAGS_timestamp_in_logfile_name = false; //设置文件名称是否含有时间前缀, false 可以防止以PID名称建立文件.

    google::SetLogDestination(google::GLOG_FATAL ,
                              (file_path + "/log_fatal_").c_str()); // 设置 google::FATAL 级别的日志存储路径和文件名前缀
    google::SetLogDestination(google::GLOG_ERROR ,
                              (file_path + "/log_error_").c_str()); //设置 google::ERROR 级别的日志存储路径和文件名前缀
    google::SetLogDestination(google::GLOG_WARNING ,
                              (file_path + "/log_warning_").c_str()); //设置 google::WARNING 级别的日志存储路径和文件名前缀
    google::SetLogDestination(google::GLOG_INFO , (file_path + "/log_info_").c_str()); //设置 google::INFO 级别的日志存储路径和文件名前缀
    google::SetLogFilenameExtension(getCurrentTimeStr().c_str()); // 设置文件名称后缀


    LOG(INFO) << "THIS IS A INFO";
    LOG(WARNING) << "WARN";
    LOG(ERROR) << "ERROR";

    google::ShutdownGoogleLogging();//当要结束glog时必须关闭库，否则会内存溢出
}

int main(int argc , char *argv[]) {
    init_log();
    std::thread t(init_log);
    t.join();
    return 0;
}
