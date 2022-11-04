#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <memory.h>

#include <mysql.h>

/// @brief  mysql ���������
using RESULT_SET_TYPE = MYSQL_RES*;
/// @brief mysql �����ת��ά�����洢.
using RECORD_TYPE = std::vector<std::vector<std::string>>;
