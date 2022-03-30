//
// Created by Administrator on 30/03/2022.
//

#include <map>
#include <iostream>
//#include "reflection/test_flection.hpp"
//#include "C:\Projects\artistic_work\inspiration\boost_interprocess\mapped_file.h"

//class ref_obj;
//typedef void *(*constructorPtr)(void);

typedef void *(*constructorPtr)();

typedef struct csu_data {
    char ic1[10];
    int it1;  //4
    short st1; //2
    char ic[2];
} CSU , *CSU_PTR;

template<typename T>
static T *getPtr(char *s) {
    static const auto conPtr = (constructorPtr) (new T);
    static std::map<std::string , constructorPtr> mp = {{s , conPtr}};
    auto iterator = mp.find(s);

    if (iterator == mp.end()) {
        std::cout << "null" << std::endl;
        return nullptr;
//        auto class_ptr = (T *) iterator->second;
    }
    static T *const ptr = (T *) iterator->second;
    return ptr;
}


int main(int argc , char **argv) {
    char struct_name[] = "CSU";
    getPtr<CSU>(struct_name)->it1 = 233;
    std::cout << getPtr<CSU>(struct_name)->it1 << std::endl;
    getPtr<CSU>(struct_name)->it1 = 118;
    std::cout << getPtr<CSU>(struct_name)->it1 << std::endl;
    delete (getPtr<CSU>(struct_name));



//    auto obj = (constructorPtr) (new CSU);
//
//    std::map<std::string , constructorPtr> cons_map;
//    cons_map.insert(std::pair<string , constructorPtr>(struct_name , obj));
//    std::map<std::string , constructorPtr>::const_iterator iter;
//    iter = cons_map.find(struct_name);
//    if (iter == cons_map.end())
//        std::cout << "this null" << std::endl;
////    auto ptr = (CSU_PTR) (iter->second);
//    auto ptr = (CSU_PTR) (iter->second);
//    ptr->it1 = 10;
//
//
//    std::map<std::string , constructorPtr> cons_map1 = {{struct_name , obj}};
//    std::map<std::string , constructorPtr>::const_iterator iter1;
//    iter1 = cons_map.find(struct_name);
//    auto ptr1 = (CSU_PTR) (iter->second);
//
//    std::cout << ptr1->it1 << std::endl;



    return 0;
}