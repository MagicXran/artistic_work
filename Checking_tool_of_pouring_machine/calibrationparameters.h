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


class calibration_parameters : public std::enable_shared_from_this<calibration_parameters> {

private:
    NUMBER_TYPE v_su_ {}  /** 输入的v塑 **/  , v_main_ {} /** 计算的v总 **/ ;
    NUMBER_TYPE m_su_ {} , suo_force_ {} , a_su_ {} , p0_ {} , n_ {} , f_zhang_ {} , p_mo{};
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

    /**
     *  设置注射机型号
     */
    void setMachineType(CHAR_TYPE type);

};


#endif //HELLOQT_CLION_CALIBRATIONPARAMETERS_H
