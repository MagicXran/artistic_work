#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <memory.h>

#include <mysql.h>

/// @brief  mysql 结果集类型
using RESULT_SET_TYPE = MYSQL_RES*;
/// @brief mysql 结果集转二维向量存储.
using RECORD_TYPE = std::vector<std::vector<std::string>>;
