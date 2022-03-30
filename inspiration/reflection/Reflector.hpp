//
// Created by Administrator on 30/03/2022.
//

#ifndef INSPIRATION_REFLECTOR_HPP
#define INSPIRATION_REFLECTOR_HPP

#include <map>
#include <memory>
#include <iostream>

typedef void *(*constructorPtr)();

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

template<class T>
class reflector {
private:
    static const std::shared_ptr<T> obj_ptr_;

    reflector() = default;

public:

};

#endif //INSPIRATION_REFLECTOR_HPP
