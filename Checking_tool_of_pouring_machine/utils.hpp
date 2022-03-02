//
// Created by Administrator on 26/02/2022.
// 工具类
//

#ifndef HELLOQT_CLION_UTILS_HPP
#define HELLOQT_CLION_UTILS_HPP

#include <fstream>
#include <iostream>
#include "json/json.h"

namespace common_tools {


    class ParseJson : public std::enable_shared_from_this<ParseJson> {

    private:

        std::ifstream ifs_;
        Json::Reader reader_;
        Json::Value root_;
        std::vector<Json::Value> values_ {};


    public:
        ParseJson();

        ~ParseJson();

        std::vector<Json::Value> &getJsonModelValuesFromArray(const char *key);

        bool Open(const char *file);

//        void operator[](const char *property);
        void ope(const char *);

        Json::Value &operator[](int index);

        Json::Value &getModel(int index);

        Json::Value &getFormula();

        static QStringList vectorToQStringList(const std::vector<Json::Value> &);
    };


    inline bool ParseJson::Open(const char *file) {
        ifs_.open(file);
        if (reader_.parse(ifs_ , root_)) {
            std::cout << "初始化,解析成功" << std::endl;
            return true;
        } else return false;
    }

    inline std::vector<Json::Value> &ParseJson::getJsonModelValuesFromArray(const char *key) {
        if (key == nullptr) {
            std::cout << "键不能为空!" << std::endl;
        } else {
            if (!root_["model"].empty()) {
//                std::cout << root_["model"].size() << std::endl;
                for (int i = 0 ; i < root_["model"].size() ; ++i) {
                    values_.push_back(root_["model"][i][key]);
                }
            }
        }
        return values_;
    }

    inline ParseJson::~ParseJson() {
        ifs_.clear();
        ifs_.close();
    }

    inline QStringList ParseJson::vectorToQStringList(const std::vector<Json::Value> &vs) {
        QStringList _list_;
        for (const auto &var : vs) {
            _list_ << QString(var.asCString());
        }
        return _list_;
    }

    inline void ParseJson::ope(const char *key) {
//        for (const auto &var : root_["model"]) {
//            std::cout << var << std::endl;
//        }
//        getJsonModelValuesFromArray(key);
        if (!root_["model"].empty()) {
//                std::cout << root_["model"].size() << std::endl;
            for (int i = 0 ; i < root_["model"].size() ; ++i) {
                if (root_["model"][i][key]) {

                }
            }
        }


    }

    inline Json::Value &ParseJson::operator[](int index) {
        return root_["model"][index];
    }

    inline Json::Value &ParseJson::getModel(int index) {
        return root_["model"][index];
    }

    inline Json::Value &ParseJson::getFormula() {
        return root_["formula"];
    }

    inline ParseJson::ParseJson() = default;


}

#endif //HELLOQT_CLION_UTILS_HPP
