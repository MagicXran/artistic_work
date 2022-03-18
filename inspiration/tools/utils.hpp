//
// Created by Administrator on 26/02/2022.
// 工具类
//

#ifndef _INSPRIE_TOOLS_UTILS_
#define _INSPRIE_TOOLS_UTILS_

#include <ctime>
#include <fstream>
#include <iostream>
#include "json/json.h"

namespace common_tools {
    /**
     * 返回指定格式的时间字符串
     * @param format 默认:"%Y_%m_%d" 返回: 年_月_日
     * @return
     */
    static std::string getCurrentTimeStr(const char *format = "%Y_%m_%d") {
        time_t t = time(nullptr);
        char ch[64] = {0};
        strftime(ch , sizeof(ch) - 1 , format , localtime(&t));     //年-月-日 时-分-秒
        return ch;
    }

    /**
     * 解析json类
     * Open 后, 先 设置根元素 setRootName
     */
    class __attribute__((unused)) ParseJson : public std::enable_shared_from_this<ParseJson> {

    private:

        std::ifstream ifs_; //文件流
        Json::Reader reader_;
        Json::Value root_;
        std::vector<Json::Value> values_ {};
        std::string root_name_ {};
    public:
        const std::string &getRootName() const;

        void setRootName(const std::string &rootName);


    public:
        ParseJson();

        ParseJson(ParseJson &&parseJson) noexcept;

        ParseJson(const char *file , const char *root);

        ParseJson &operator=(ParseJson &&parse) noexcept;

        ~ParseJson();

        /**
         * 根据key 获取对应数组值集合.
         * @param key  数组对应的名称 key : [ x1,x2,...]
         * @return 返回值向量
         */
        std::vector<Json::Value> &getJsonModelValuesFromArray(const char *key);

        /**
         * 打开.json文件
         * @param file
         * @return 是否解析成功
         */
        bool Open(const char *file);

        Json::Value &operator[](int index);

        Json::Value &operator[](const char *element);

    };


    inline bool ParseJson::Open(const char *file) {
        ifs_.open(file);
        if (reader_.parse(ifs_ , root_)) {
            std::cout << "初始化解析 " << file << ",成功!" << std::endl;
            return true;
        } else return false;
    }

    inline std::vector<Json::Value> &ParseJson::getJsonModelValuesFromArray(const char *key) {
        if (key == nullptr) {
            std::cout << "键(key)不能为空!" << std::endl;
        } else {
            auto root = getRootName().c_str();
            if (!root_[root].empty()) {
                for (int i = 0 ; i < root_[root].size() ; ++i) {
                    values_.push_back(root_[root][i][key]);
                }
            }
        }
        return values_;
    }

    inline ParseJson::~ParseJson() {
        ifs_.clear();
        ifs_.close();
    }

    inline const std::string &ParseJson::getRootName() const {
        return root_name_;
    }

    inline void ParseJson::setRootName(const std::string &rootName) {
        root_name_ = rootName;
    }

    inline ParseJson::ParseJson() = default;

    inline Json::Value &ParseJson::operator[](int index) {
        return root_[getRootName().c_str()][index];
    }

    inline Json::Value &ParseJson::operator[](const char *element) {
        return root_[getRootName().c_str()][element];
    }

    inline  ParseJson::ParseJson(const char *file , const char *root) {
        Open(file);
        setRootName(root);
    }

    inline  ParseJson::ParseJson(ParseJson &&parseJson) noexcept {
        ifs_ = std::move(parseJson.ifs_);
        reader_ = std::move(parseJson.reader_);
        root_ = std::move(parseJson.root_);
        values_ = std::move(parseJson.values_);
        root_name_ = std::move(parseJson.root_name_);
    }

    inline ParseJson &ParseJson::operator=(ParseJson &&parse) noexcept {
        this->ifs_ = std::move(parse.ifs_);
        this->reader_ = std::move(parse.reader_);
        this->root_ = std::move(parse.root_);
        this->root_name_ = std::move(parse.root_name_);
        this->values_ = std::move(parse.values_);
    }

}

#endif
