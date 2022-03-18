//
// Created by Administrator on 16/03/2022.
//

#include "gloger.h"


Gloger::Gloger(const char *config_file_path , const char *root) {
    config_file_path_ = config_file_path;
    root_name_ = root;
    common_tools::ParseJson parseJson(config_file_path , root);
    parseJson_ = std::move(parseJson);

    const char *file_path = parseJson_["output_path"].asCString();
    ouput_path_ = file_path;
    FLAGS_log_dir = file_path;

    google::InitGoogleLogging(parseJson_["name"].asCString());
    FLAGS_logbufsecs = parseJson_["logbufsecs"].asInt(); //缓冲日志输出，默认为30秒，此处改为立即输出
    FLAGS_max_log_size = parseJson_["max_log_size"].asInt(); //最大日志大小为 100MB
    FLAGS_stop_logging_if_full_disk = parseJson_["stop_logging_if_full_disk"].asBool(); //当磁盘被写满时，停止日志输出
    FLAGS_alsologtostderr = parseJson_["alsologtostderr"].asBool();//是否将日志输出到文件和stderr
    //设置将指定等级及其以上等级的日志输出到标准错误，默认为 ERROR
    FLAGS_colorlogtostderr = parseJson_["colorlogtostderr"].asBool(); //设置输出到屏幕的日志显示相应颜色
    FLAGS_stderrthreshold = parseJson_["stderrthreshold"].asInt();
    FLAGS_log_prefix = parseJson_["log_prefix"].asBool(); //是否输出前缀
    FLAGS_log_year_in_prefix = parseJson_["log_year_in_prefi"].asBool(); //是否输出年月日前缀
    FLAGS_timestamp_in_logfile_name = parseJson_["timestamp_in_logfile_name"].asBool(); //设置文件名称是否含有时间前缀, false 可以防止以PID名称建立文件.

    google::SetLogDestination(google::GLOG_FATAL ,
                              (ouput_path_ + "/log_fatal_").c_str()); // 设置 google::FATAL 级别的日志存储路径和文件名前缀
    google::SetLogDestination(google::GLOG_ERROR ,
                              (ouput_path_ + "/log_error_").c_str()); //设置 google::ERROR 级别的日志存储路径和文件名前缀
    google::SetLogDestination(google::GLOG_WARNING ,
                              (ouput_path_ + "/log_warning_").c_str()); //设置 google::WARNING 级别的日志存储路径和文件名前缀
    google::SetLogDestination(google::GLOG_INFO ,
                              (ouput_path_ + "/log_info_").c_str()); //设置 google::INFO 级别的日志存储路径和文件名前缀
    google::SetLogFilenameExtension(common_tools::getCurrentTimeStr().c_str()); // 设置文件名称后缀
    google::InstallFailureSignalHandler();

}

Gloger::~Gloger() {
    google::ShutdownGoogleLogging();//当要结束glog时必须关闭库，否则会内存溢出
    std::cout << "成功释放 Glog 资源" << std::endl;
}
