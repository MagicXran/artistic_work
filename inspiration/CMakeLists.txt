cmake_minimum_required(VERSION 3.21)
project(inspiration)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(MAIN_PATH ${PROJECT_SOURCE_DIR})

################################################## qt 配置
set(CMAKE_AUTOMOC ON)                        # 启用 qt moc 的支持
set(CMAKE_AUTORCC ON)                        # 启用 qrc 资源文件的支持
set(CMAKE_AUTOUIC ON)                        # 启用 qt uic 的支持

find_package(Qt5Widgets)
find_package(Qt5Core)
find_package(Qt5Gui)

set(UI_FILES)
set(RC_FILES)
set(QRC_FILES)


###########################################################Boost
set(Boost_DEBUG on)
set(Boost_DETAILED_FAILURE_MSG ON)
set(BOOST_ROOT C:\\boost_1_69_0)
set(BOOST_INCLUDEDIR ${BOOST_ROOT})
set(BOOST_LIBRARYDIR C:\\boost_1_69_0\\stage\\lib)
set(Boost_NO_SYSTEM_PATHS ON) #只搜索上语句设置的搜索路径

find_package(Boost COMPONENTS REQUIRED date_time regex system python39)
message(${Boost_FOUND})
#message(${Boost_LIBRARIES})
if (Boost_FOUND)
    include_directories(${BOOST_ROOT})
endif ()

###################################################################################python
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
# 添加Python.h头文件路径
#include_directories(C:/Apps/Python/include)
# 添加python动态链接库文件目录
#link_directories(C:/Apps/Python/libs)

####################################################################################loger
find_package (glog 0.6.0 REQUIRED)
# 添加头文件路径
include_directories("C:/Program Files (x86)/glog/include")
# 添加动态链接库文件目录
link_directories("C:/Program Files (x86)/glog/lib")

###################################################################################json

################################################## 配置 json解析器: rapidjson

set(INC_DIR include)
set(LINK_DIR libs)

include_directories(${INC_DIR})
link_directories(${LINK_DIR})
link_libraries(libjsoncpp.a)


set(SOURCE_FILES  asio/asyn_asio.cc)
#set(SOURCE_FILES main.cpp accessor/file_accessor.hpp correspondence/synasio.cc correspondence/synasio.h correspondence/communication.h correspondence/chat_message.hpp correspondence/chat_client.cc correspondence/chat_server.cc ui/network_socket.cc ui/network_socket.h ui/network_socket.ui boost_interprocess/testShareMemory.cc loger/glog_test.cc)
add_executable(inspiration ${RC_FILES} ${SOURCE_FILES} ${UI_FILES} ${QRC_FILES})
target_link_libraries(inspiration
                      Qt5::Widgets
                      ${Boost_LIBRARIES}
                      ${Python3_LIBRARIES}
                      glog::glog
                      libjsoncpp.a
                      )

# 解决 Windows 使用 asio库 报错: undefined reference to `__imp_WSAStartup'
if (MINGW)
    target_link_libraries(inspiration
                          ws2_32  # Winsock 2.lib Winsock2.h
                          wsock32 # wsock32.lib winsock2.h
                          )
endif ()

target_include_directories(inspiration PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           ${Python3_INCLUDE_DIRS}
                           )

# 把对应Qt模块的库链接进程序
qt5_use_modules(inspiration Core Widgets Gui)