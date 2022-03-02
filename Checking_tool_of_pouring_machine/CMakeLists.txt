cmake_minimum_required(VERSION 3.21)
project(HelloQt_Clion VERSION 6.6)

#指定c++版本
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(MAIN_PATH ${PROJECT_SOURCE_DIR})


#option(OPEN_CONSOLE "是否启用控制台调试" ON)
set(OPEN_CONSOLE 0)

#当前工程目录
message(${HelloQt_Clion_SOURCE_DIR})
configure_file(
        "${HelloQt_Clion_SOURCE_DIR}/HellQt_Clion.h.in"
        "${HelloQt_Clion_SOURCE_DIR}/HellQt_Clion.h"
)

set(CMAKE_PREFIX_PATH C:/Qt/Qt5.14.2/5.14.2/mingw73_64) #这里需要填入自己安装的路径,选择 gun 编译器
#set(CMAKE_PREFIX_PATH C:/Qt/Qt5.14.2/5.14.2/msvc2017_64) #这里需要填入自己安装的路径, 选择 msvc编译器

################################################## qt 配置

set(CMAKE_AUTOMOC ON)                        # 启用 qt moc 的支持
set(CMAKE_AUTORCC ON)                        # 启用 qrc 资源文件的支持
set(CMAKE_AUTOUIC ON)                        # 启用 qt uic 的支持


find_package(Qt5Widgets)
find_package(Qt5Core)
find_package(Qt5Gui)

set(UI_FILES)
set(RC_FILES)
set(QRC_FILES res.qrc)
##################################################

################################################## boost 配置


set(Boost_DEBUG on)
set(Boost_DETAILED_FAILURE_MSG ON)
set(BOOST_ROOT C:\\boost_1_69_0)


## 版本1.
#set(Boost_INCLUDE_DIR  ${BOOST_ROOT})
#set(Boost_LIBRARY_DIR  C:\\boost_1_69_0\\stage\\lib)
## 版本2.
set(BOOST_INCLUDEDIR ${BOOST_ROOT})
set(BOOST_LIBRARYDIR C:\\boost_1_69_0\\stage\\lib)

set(Boost_NO_SYSTEM_PATHS ON) #只搜索上语句设置的搜索路径

find_package(Boost COMPONENTS REQUIRED date_time regex system)
#message(${Boost_FOUND})
message(${Boost_LIBRARIES})
if (Boost_FOUND)
    include_directories(${BOOST_ROOT})
endif ()

##################################################

################################################## 配置 json解析器: rapidjson

find_package(rapidjson)
include_directories(${CMAKE_SOURCE_DIR}/rapidjson)


set(INC_DIR include)
#set(LINK_DIR C:/Third_party_library/jsoncpp-1.9.5/build/debug/lib)
set(LINK_DIR libs)

include_directories(${INC_DIR})
link_directories(${LINK_DIR})
link_libraries(libjsoncpp.a)


##################################################

set(SOURCE_FILES main.cpp mainwindow.cpp mainwindow.h calibrationparameters.cc calibrationparameters.h utils.hpp universal_toolbox.hpp )

#message("${PROJECT_SOURCE_DIR}")
#message(${CMAKE_SOURCE_DIR})

add_executable(HelloQt_Clion ${RC_FILES} ${SOURCE_FILES} ${UI_FILES} ${QRC_FILES})
#add_executable(HelloQt_Clion WIN32 ${RC_FILES} ${SOURCE_FILES} ${UI_FILES} ${QRC_FILES})

#必须跟上面find_packge中添加的模块名称一致哦。
target_link_libraries(HelloQt_Clion Qt5::Widgets ${Boost_LIBRARIES}
                      libjsoncpp.a
                      )

# 解决 Windows 使用 asio库 报错: undefined reference to `__imp_WSAStartup'
#if (MINGW)
#    target_link_libraries(HelloQt_Clion ws2_32)
#endif ()

# 把对应Qt模块的库链接进程序
qt5_use_modules(HelloQt_Clion Core Widgets Gui)


target_include_directories(HelloQt_Clion PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
#message("${PROJECT_BINARY_DIR}")