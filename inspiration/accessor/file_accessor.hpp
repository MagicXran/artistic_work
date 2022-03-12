//
// Created by Administrator on 27/02/2022.
//

#ifndef INSPIRATION_FILE_ACCESSOR_HPP
#define INSPIRATION_FILE_ACCESSOR_HPP

#include <iostream>
#include <fstream>
#include <thread>
#include <algorithm>
#include <cstring>
#include "windows.h"
#include <bits/stdc++.h>
#include <conio.h> ///非标准输入输出

namespace ins_file_accessor {

    class __attribute__((unused)) FileAccessor {
    private:
        bool state_;
    public:
        bool state() const {
            return state_;
        }

    private:
        std::ifstream ifs_;
        size_t row_count_ {0};
        clock_t total_time_ {0};
    public:
        size_t getRowCount() const {
            return row_count_;
        }

        void beep();

    private:
        const char *file_;

    public:
        __attribute__((unused)) explicit FileAccessor(std::ifstream &ifs , const char *file ,
                                                      std::ios_base::openmode mode = std::ios::in) {
            ifs_ = std::move(ifs);
            ifs_.open(file , mode);
            state_ = ifs_.is_open();
            row_count_ = 0;
            file_ = file;
        }

        ~FileAccessor() = default;;


        /**
         *
         * @param keyword
         * @param infinite
         * @param span
         * @param info_visible
         * @param mode
         */
        void listen(const char *keyword , bool infinite = true , size_t span = 2 , bool info_visible = true ,
                    unsigned short mode = 2) {
            if (state()) {
                std::fpos<int> seek /** = 8000000 **/ ;
                std::string row;
                char buf[2048] = {0};
                clock_t cstart , cends;
                cstart = clock();
                do {
                    if (ifs_.peek() == EOF) {
                        cends = clock();
                        if (!infinite) {
                            total_time_ = cends - cstart;
                            std::cout << "耗费时间:" << (cends - cstart) << std::endl;
                            break;
                        }
                        // 此时扫描到头, 暂停 2s ,继续扫描
                        ifs_.clear();
                        ifs_.seekg(seek);
//                        std::cout << span << "s gone!";
//                        std::cout << "耗费时间:" << (cends - cstart) << "\t" << seek << std::endl;
                        total_time_ = cends - cstart;
                        std::this_thread::sleep_for(std::chrono::seconds(span));
                        continue;
                    } else if (ifs_.bad()) {
                        ifs_.clear();
                        ifs_.close();
                        std::cout << "读写过程中出错:例如：如对一个不是打开为写状态的文件进行写入，或者我们要写入的设备没有剩余空间" << std::endl;
                        break;
                    } else if (ifs_.fail()) {
                        ifs_.clear();
                        ifs_.close();
                        std::cout << "加上格式错误:例如当想要读入一个整数，而获得了一个字母的时候。" << std::endl;
                        break;
                    }
                    if (keyword != nullptr) {
                        std::string key_str(keyword);
                        if (mode == 1) {
                            // 利用char[] 缓存
                            ifs_.getline(buf , sizeof buf);
                            if (std::strstr(buf , keyword) != nullptr) {
                                if (info_visible) std::cout << buf << std::endl;
                                row_count_++;
                            }
                        } else if (mode == 2) {
                            //2. 利用string 缓存: 更快
                            std::getline(ifs_ , row);
//                        查找方式1.
                            auto pos = row.find(keyword);
                            if (key_str.empty() || pos != std::string::npos) {
                                if (info_visible) std::cout << row << std::endl;
                                row_count_++;
                                Beep(2066 , 242);
                            }

                            //查找方式2.
//                    if (key_str.empty() ||
//                        (std::search(row.begin() , row.end() , key_str.begin() , key_str.end()) != row.end())) {
//                        if (info_visible) std::cout << row << std::endl;
//                    }
                        }
                    } else if (info_visible) std::cout << row << std::endl;

                    seek = ifs_.tellg();
                } while (!ifs_.eof());
            }
        }

        /**
         * 效率最佳的遍历方式,时间复杂度最低.
         * @param path
         * @param keyword
         */
        void listen_find(const char *path , const char *keyword) {
            clock_t cstart , cends;
            cstart = clock();
            if (state()) {
                std::fpos<int> seek;
                std::string row;
                do {
                    if (ifs_.peek() == EOF) {
                        break;
                    } else if (ifs_.bad()) {
                        ifs_.clear();
                        ifs_.close();
                        std::cout << "读写过程中出错:例如：如对一个不是打开为写状态的文件进行写入，或者我们要写入的设备没有剩余空间" << std::endl;
                        break;
                    } else if (ifs_.fail()) {
                        ifs_.clear();
                        ifs_.close();
                        std::cout << "加上格式错误:例如当想要读入一个整数，而获得了一个字母的时候。" << std::endl;
                        break;
                    }
                    std::getline(ifs_ , row);
                    auto pos = row.find(keyword);
                    if (pos != std::string::npos) {
                        ++row_count_;
//                        std::cout << row;
//                        printf("%s" , row.c_str());
//                        std::cout << row << std::endl;
                    }
                    seek = ifs_.tellg();
                } while (!ifs_.eof());
                cends = clock();
                total_time_ = cends - cstart;
//                std::cout << "耗费时间:" << (cends - cstart) << std::endl;

            } else std::cout << "连接远程文件失败, 地址:" << path << std::endl;

        }
    };

    void FileAccessor::beep() {
        Beep(554 , 200);
        Beep(622 , 200);
        Beep(682 , 200);
        Beep(740 , 200);
        Beep(831 , 200);
        Beep(932 , 200);
        Beep(1046 , 200);
    }

    /**
     * 根据指定路径,
     * @param path : seems: "\\\\PCS/pcs/JinGang1580/Log/LogData(2022-02-27) - Copy.txt"
     */
    void access_find(const char *path , const char *keyword = nullptr) {
        clock_t cstart , cends;
        std::ifstream ifs_(path , std::ios::in);
        std::cout << "is_open:" << ifs_.is_open() << std::endl;
        cstart = clock();
        if (ifs_.is_open()) {
//            std::fpos<int> seek;
            std::string row;
            bool isFound = false;

            do {
                if (ifs_.peek() == EOF) {
                    std::cout << "文件到达文件末尾" << std::endl;
                    break;
                } else if (ifs_.bad()) {
                    ifs_.clear();
                    ifs_.close();
                    std::cout << "读写过程中出错:例如：如对一个不是打开为写状态的文件进行写入，或者我们要写入的设备没有剩余空间" << std::endl;
                    break;
                } else if (ifs_.fail()) {
                    ifs_.clear();
                    ifs_.close();
                    std::cout << "加上格式错误:例如当想要读入一个整数，而获得了一个字母的时候。" << std::endl;
                    break;
                }
                std::getline(ifs_ , row);
                auto pos = row.find(keyword);
                if (pos != std::string::npos) {
                    std::cout << row << std::endl;
                    isFound = true;
                }

            } while (!ifs_.eof());
            cends = clock();
            std::cout << "find 耗费时间:" << (cends - cstart) << std::endl;

            if (isFound) std::cout << "找到指定关键字: " << keyword << std::endl;
            else std::cout << "未找到指定关键字:" << keyword << std::endl;
        } else std::cout << "连接远程文件失败, 地址:" << path << std::endl;

    }

    void access_search(const char *path , const char *keyword = nullptr) {
        clock_t cstart , cends;
        std::ifstream ifs_(path , std::ios::in);
        std::cout << "is_open:" << ifs_.is_open() << std::endl;
        cstart = clock();
        if (ifs_.is_open()) {
//            std::fpos<int> seek;
            std::string row;
            bool isFound = false;

            do {
                if (ifs_.peek() == EOF) {
                    std::cout << "文件到达文件末尾" << std::endl;
                    break;
                } else if (ifs_.bad()) {
                    ifs_.clear();
                    ifs_.close();
                    std::cout << "读写过程中出错:例如：如对一个不是打开为写状态的文件进行写入，或者我们要写入的设备没有剩余空间" << std::endl;
                    break;
                } else if (ifs_.fail()) {
                    ifs_.clear();
                    ifs_.close();
                    std::cout << "加上格式错误:例如当想要读入一个整数，而获得了一个字母的时候。" << std::endl;
                    break;
                }
                std::string key_str(keyword);
                std::getline(ifs_ , row);
                if ((std::search(row.begin() , row.end() , key_str.begin() , key_str.end()) != row.end())) {
                    isFound = true;
                }

            } while (!ifs_.eof());
            cends = clock();
            std::cout << "search 耗费时间:" << (cends - cstart) << std::endl;

            if (isFound) std::cout << "找到指定关键字: " << keyword << std::endl;
            else std::cout << "未找到指定关键字:" << keyword << std::endl;
        } else std::cout << "连接远程文件失败, 地址:" << path << std::endl;

    }

}

#endif //INSPIRATION_FILE_ACCESSOR_HPP
