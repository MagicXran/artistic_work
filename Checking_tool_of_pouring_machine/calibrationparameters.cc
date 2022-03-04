//
// Created by Administrator on 26/02/2022.
//

#include "calibrationparameters.h"
#include <iostream>
#include <cmath>

using namespace std;


// 在此定义, 在.h中声明.
extern const NUMBER_TYPE rho = 1;
extern const NUMBER_TYPE v_main_factor = 1.2;
extern const NUMBER_TYPE k1_factor = 1.3;  //1.25~ 1.4
extern const NUMBER_TYPE k2_factor = 1.15;  //1.1~ 1.2
extern const NUMBER_TYPE r_factor = 0.8;  //0.5~1
extern const NUMBER_TYPE SR_factor = 1.5;  //1~2
extern const NUMBER_TYPE h_factor = 0.386;  //0.3333 ~ 0.4
extern const NUMBER_TYPE alfa_factor = 3;  //2~4
extern const NUMBER_TYPE sub_factor = 0.2654;

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
    f_zhang_ = v_main_factor * a_su_ * p * k2_factor * n_;
    return f_zhang_;
}

double calibration_parameters::getMainL() const {
    return main_l_;
}

void calibration_parameters::setMainL(double mainL) {
    main_l_ = mainL;
}

double calibration_parameters::getMainr() const {
    return main_r_;
}

void calibration_parameters::setMainr(double mainR) {
    main_r_ = mainR;
}

double calibration_parameters::getMainR() const {
    return main_R_;
}

void calibration_parameters::setMainR(double mainR) {
    main_R_ = mainR;
}

double calibration_parameters::getMainSr() const {
    return main_sr_;
}

void calibration_parameters::setMainSr(double mainSr) {
    main_sr_ = mainSr;
}

double calibration_parameters::getMainH() const {
    return main_h_;
}

void calibration_parameters::setMainH(double mainH) {
    main_h_ = mainH;
}

double calibration_parameters::getMainV() const {
    return main_v_;
}

void calibration_parameters::setMainV(double mainV) {
    main_v_ = mainV;
}

double calibration_parameters::getMainRn() const {
    return main_Rn_;
}

void calibration_parameters::setMainRn(double mainRn) {
    main_Rn_ = mainRn;
}

double calibration_parameters::getSubL() const {
    return sub_l_;
}

void calibration_parameters::setSubL(double subL) {
    sub_l_ = subL;
}

double calibration_parameters::getSubA() const {
    return sub_A_;
}

void calibration_parameters::setSubA(double subA) {
    sub_A_ = subA;
}

double calibration_parameters::getSubV() const {
    return sub_v_;
}

void calibration_parameters::setSubV(double subV) {
    sub_v_ = subV;
}

CALC_TYPE calibration_parameters::calc_main_r(NUMBER_TYPE hole_size) {
    setMainr((hole_size + r_factor) / 2);
    return main_r_;
}

CALC_TYPE calibration_parameters::calc_main_R() {
    setMainR((getMainr() + getMainL() * tan(alfa_factor / 2)));
    return main_R_;
}

CALC_TYPE calibration_parameters::calc_main_SR(double sphere_size) {
    setMainSr(sphere_size + SR_factor);
    return main_sr_;
}

CALC_TYPE calibration_parameters::calc_main_h() {
    setMainH(getMainSr() * h_factor);
    return main_h_;
}

CALC_TYPE calibration_parameters::calc_main_v() {
    NUMBER_TYPE temp = (3.1415926 * main_l_ * (pow(main_R_ , 2) + pow(main_r_ , 2) + main_r_ * main_R_)) / 3;
    std::cout << "主流道的凝料体积:" << temp << std::endl;
    setMainV(temp);
    return temp;
}

CALC_TYPE calibration_parameters::calc_main_Rn() {
    setMainRn((main_r_ + main_R_) / 2);
    return getMainRn();
}

CALC_TYPE calibration_parameters::calc_subD() {
    return (sub_factor * sqrt(getMSu()) * pow(sub_l_ , 1 / 4));
}

CALC_TYPE calibration_parameters::calc_subV() {
    setSubV(sub_l_ * sub_A_);
    return sub_v_;
}

