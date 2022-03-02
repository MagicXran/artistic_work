//
// Created by Administrator on 26/02/2022.
//
//#pragma comment(lib , "ws2_32.lib")

#include <QStringList>
#include <QString>
#include <iostream>
#include "calibrationparameters.h"
#include "utils.hpp"
#include "universal_toolbox.hpp"

#define  JSON_PATH "C:/Projects/Qt/HelloQt_Clion/res/Injection_machine_meter.json"
using namespace std;
using namespace common_tools;

int main__(int argc , char *argv[]) {
#ifdef OPEN_CONSOLE
    setbuf(stdout , NULL);
#endif

    calibration_parameters calc;

    QStringList sss;
    ParseJson parseJson;
//    if (parseJson.Open(R"(C:\Projects\Qt\HelloQt_Clion\res\Injection_machine_meter.json)")) {
    if (parseJson.Open(JSON_PATH)) {
        for (const auto &var : parseJson.getJsonValuesFromArray("name")) {
//            std::cout << var << std::endl;
            sss << QString(var.asCString());
        }
    }

    for (auto item : sss) {
//        std::cout << item.toStdString() << std::endl;
    }

    const char aaa[30] = "dd";
    const char *const pa = "dd";
    const char *paa = "dd";

    return 0;
}

