//
// Created by Administrator on 26/02/2022.
//

#include "calibrationparameters.h"
#include <iostream>

using namespace std;


// 在此定义, 在.h中声明.
extern const NUMBER_TYPE rho = 1;
extern const NUMBER_TYPE v_main_factor = 1.2;
extern const NUMBER_TYPE k1_factor = 1.3;  //1.25~ 1.4
extern const NUMBER_TYPE k2_factor = 1.15;  //1.1~ 1.2
extern const NUMBER_TYPE p_factor = 0.3;  //20%~40%

CALC_TYPE calibration_parameters::calc_m_suo(NUMBER_TYPE v_suo) {
    setVSu(v_suo);
    setMSu(rho * v_suo);
    return (rho * v_suo);
}

CALC_TYPE calibration_parameters::calc_v_main() {
    v_main_ = v_su_ * v_main_factor * n_;
    return v_main_;
}

void calibration_parameters::setMachineType(CHAR_TYPE type) {
    // 修改为使用智能指针. 否则需要保证在 machine_type_ 析构前, type指向内容不能为空.
    this->machine_type_ = (std::move(type));
}


NUMBER_TYPE calibration_parameters::getVSu() const {
    return v_su_;
}

void calibration_parameters::setVSu(NUMBER_TYPE vSuo) {
    v_su_ = vSuo;
}

NUMBER_TYPE calibration_parameters::getVMain() const {
    return v_main_;
}

void calibration_parameters::setVMain(NUMBER_TYPE vMain) {
    v_main_ = vMain;
}

NUMBER_TYPE calibration_parameters::getMSu() {
    m_su_ = v_su_ * rho;
    return m_su_;
}

void calibration_parameters::setMSu(NUMBER_TYPE mSuo) {
    m_su_ = mSuo;
}

NUMBER_TYPE calibration_parameters::getSuoForce() const {
    return suo_force_;
}

void calibration_parameters::setSuoForce(NUMBER_TYPE suoForce) {
    suo_force_ = suoForce;
}


CHAR_TYPE calibration_parameters::getMachineType() const {
    return machine_type_;
}

NUMBER_TYPE calibration_parameters::getASu() const {
    return a_su_;
}

void calibration_parameters::setASu(NUMBER_TYPE aSu) {
    a_su_ = aSu;
}

NUMBER_TYPE calibration_parameters::getP0() const {
    return p0_;
}

void calibration_parameters::setP0(NUMBER_TYPE p0) {
    p0_ = p0;
}

NUMBER_TYPE calibration_parameters::getN() const {
    return n_;
}

void calibration_parameters::setN(NUMBER_TYPE n) {
    n_ = n;
}

NUMBER_TYPE calibration_parameters::getFZhang() const {
    return f_zhang_;
}

void calibration_parameters::setFZhang(NUMBER_TYPE fZhang) {
    f_zhang_ = fZhang;
}

NUMBER_TYPE calibration_parameters::calc_F_zhang(double p) {
    f_zhang_ = v_main_factor * a_su_ * p * k2_factor*n_;
    return f_zhang_;
}


