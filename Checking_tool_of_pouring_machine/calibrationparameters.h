//
// Created by Administrator on 26/02/2022.
//

#ifndef HELLOQT_CLION_CALIBRATIONPARAMETERS_H
#define HELLOQT_CLION_CALIBRATIONPARAMETERS_H

#include <memory>

#define CALC_TYPE double
#define NUMBER_TYPE  double
#define CHAR_TYPE  std::string

extern const NUMBER_TYPE rho;
extern const NUMBER_TYPE v_main_factor;
extern const NUMBER_TYPE k1_factor;
extern const NUMBER_TYPE k2_factor;
extern const NUMBER_TYPE r_factor;  //0.5~1
extern const NUMBER_TYPE SR_factor;  //1~2
extern const NUMBER_TYPE h_factor;  //1~2
extern const NUMBER_TYPE alfa_factor;  //2~4
extern const NUMBER_TYPE sub_factor;
extern const NUMBER_TYPE time_tuo;


class calibration_parameters : public std::enable_shared_from_this<calibration_parameters> {

private:
    NUMBER_TYPE v_su_ {}  /** 输入的v塑 **/  , v_main_ {} /** 计算的v总 **/ ;
    NUMBER_TYPE m_su_ {} , suo_force_ {} , a_su_ {} , p0_ {} , n_ {} , f_zhang_ {} , p_mo {};
    NUMBER_TYPE main_l_ {} , main_r_ {} , main_R_ {} , main_sr_ {} , main_h_ {} , main_v_ {} , main_Rn_ {} , sub_l_ {} , sub_A_ {} , sub_v_ {};
    NUMBER_TYPE v_ {} , t_ {} , w_ {} , qs_ {} , theta1_ {} , theta2_ {} , rhoc_ {} , qv_ {} , d_ {} , h_ {} , A_ {};
public:

    double calc_X(double l);

    double calc_A(double thetam);

    double calc_H(double f , double v);

    double calc_Speed(NUMBER_TYPE d);

    double calc_Qv(NUMBER_TYPE qs,double theta1 , double theta2 , double rhoc);

    double calc_t(NUMBER_TYPE t_cool , NUMBER_TYPE t_tbl);

    double calc_N();

    double calc_V();

    double calc_W(double N);

    double getMainL() const;

    void setMainL(double mainL);

    double getMainR() const;

    void setMainR(double mainR);

    double getMainr() const;

    void setMainr(double mainR);

    double getMainSr() const;

    void setMainSr(double mainSr);

    double getMainH() const;

    void setMainH(double mainH);

    double getMainV() const;

    void setMainV(double mainV);

    double getMainRn() const;

    void setMainRn(double mainRn);

    double getSubL() const;

    void setSubL(double subL);

    double getSubA() const;

    void setSubA(double subA);

    double getSubV() const;

    void setSubV(double subV);

public:
    NUMBER_TYPE getFZhang() const;

    void setFZhang(NUMBER_TYPE fZhang);

    NUMBER_TYPE calc_F_zhang(double p);


public:
    NUMBER_TYPE getN() const;

    void setN(NUMBER_TYPE n);

public:
    NUMBER_TYPE getP0() const;

    void setP0(NUMBER_TYPE p0);

public:
    NUMBER_TYPE getASu() const;

    void setASu(NUMBER_TYPE aSu);

public:
    calibration_parameters() = default;


    NUMBER_TYPE getMSu();

    void setMSu(NUMBER_TYPE mSuo);

    NUMBER_TYPE getSuoForce() const;

    void setSuoForce(NUMBER_TYPE suoForce);

public:
    NUMBER_TYPE getVSu() const;

    void setVSu(NUMBER_TYPE vSuo);

    NUMBER_TYPE getVMain() const;

    void setVMain(NUMBER_TYPE vMain);

private:
    CHAR_TYPE machine_type_ {};
public:
    CHAR_TYPE getMachineType() const;

public:
    CALC_TYPE calc_m_suo(NUMBER_TYPE v_suo);

    CALC_TYPE calc_v_main();

    CALC_TYPE calc_main_r(NUMBER_TYPE hole_size);

    CALC_TYPE calc_main_R();

    CALC_TYPE calc_main_SR(NUMBER_TYPE sphere_size);

    CALC_TYPE calc_main_h();

    CALC_TYPE calc_main_v();

    CALC_TYPE calc_main_Rn();

    CALC_TYPE calc_subD();

    CALC_TYPE calc_subV();

    /**
     *  设置注射机型号
     */
    void setMachineType(CHAR_TYPE type);

};


#endif //HELLOQT_CLION_CALIBRATIONPARAMETERS_H
