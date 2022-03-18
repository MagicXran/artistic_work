//
// Created by Administrator on 16/03/2022.
//

#ifndef INSPIRATION_GLOGER_H
#define INSPIRATION_GLOGER_H

#include <iostream>
#include "glog/logging.h"
#include "tools/utils.hpp"

/**
 * 简单的将 glog 初始化简化, 通常将此类作为全局变量, 当结束时, 通过析构函数, 自动释放资源.
 * 报警等级: INFO,WARNING , ERROR , FATAL
 */
class Gloger {
private:
    // 文件输出路径
    std::string ouput_path_ {};

    //配置文件路径
    std::string config_file_path_ {};

    //root name
    std::string root_name_ {};

    common_tools::ParseJson parseJson_ {};

public:
    explicit Gloger(const char *config_file_path , const char *root);

    Gloger() = default;

    ~Gloger();
};


#endif //INSPIRATION_GLOGER_H
