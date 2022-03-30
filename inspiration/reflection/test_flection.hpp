//
// Created by Administrator on 30/03/2022.
//

#ifndef INSPIRATION_TEST_FLECTION_HPP
#define INSPIRATION_TEST_FLECTION_HPP

#include <map>
#include <iostream>
#include <string>

using namespace std;

//构造函数指针
//using constructorPtr = void *(*);
typedef void *(*constructorPtr)(void);

class ref_obj {
public:
    ref_obj() {
        std::cout << "construct" << std::endl;
    };

    ~ref_obj() {
        std::cout << "deconstruct" << std::endl;
    };
};

struct ref_struct {
    ref_struct() {
        std::cout << "construct" << std::endl;
    }

    char ca_[3];
    int it_;
};


#endif //INSPIRATION_TEST_FLECTION_HPP
