/************************************************************************/
/*           ͨ�ù����� V1.0											*/
/*								--by renaissancer(xgz)					*/
/************************************************************************/

#ifndef _COMMON_TOOL_BOX_
#define _COMMON_TOOL_BOX_

#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <sstream>
#include <cstring>
#include <cmath>
#include <time.h>
#include <float.h>



/**
* @description	: ȡ���͵�ÿ��λ,���λ��0��ʼ.
* @param		: x:ԭʼ����, y:��yλ
* @return		: ����x�ĵ�y+1 λ�ϵ�����.
* @exception	:
*/
#define getBit(x , y)   ((x) >> (y)&1)

namespace uni_box {
    /**
    * @description	: ����NС��(��������): ע��:cout��Ĭ�Ͼ���(.2),�������printf��ӡ.
    * @param		: dst:ԭʼ��ֵ֮����, N:����λ��
    * @return		: dst(.N)
    * @exception	:
    */
    template<typename T , unsigned short N>
    T setPrecision(T &dst) {
        dst = floor(dst * pow(10.0 , N) + 0.5) / pow(10.0 , N);
        return dst;
    }


    /**
    * @description	:	string --> �����������: ���ڸ������������double����float.
    * @param		:	str:ԭʼ�ַ�������ֵ֮����, T:Ŀ������
    * @return		:	����ΪT��ֵt
    * @exception	:	������ĸ��ͷ,������.
    */
    template<typename T>
    T StrtoT(std::string &str) {
        T t;
        std::istringstream iss(str);
        iss >> t;
        return t;
    }

    /**
    * @description  :	string --> �����������: ���ڸ������������double����float.
    * @param		:	chr:ԭʼ�ַ�����, T:Ŀ������
    * @return		:	����ΪT��ֵt
    * @exception	:	������ĸ��ͷ,������.
    */
    template<typename T>
    T StrtoT(char *chr) {
        T t;
        std::string temp_str(chr);
        std::istringstream iss(temp_str);
        iss >> t;
        return t;
    }


    /**
    * @description	: �����������ת��Ϊstring
    * @param		: t:������ֵ����֮����
    * @return		: string������ֵ
    * @exception	:
    */
    template<typename T>
    std::string TtoStr(const T &t) {
        std::ostringstream oss;
        oss << t;
        return oss.str();
    }


    /**
    * @description	: ��ȡ��ǰʱ��,��ָ����ʽ���
    * @param		: format:Ĭ�������ʽ:char[20]=2021-12-06 10:56:53
    * @return		: string���͵�ǰʱ��
    * @exception	:
    */
    void getCurrentTime(char *curTime , const char *format = "%Y-%m-%d %H:%M:%S") {
        char current_sec[20] {0x00};
        time_t seconds;
        tm *today;

        time(&seconds);
        today = localtime(&seconds);
        memset(current_sec , 0x00 , sizeof(current_sec));
        strftime(current_sec , sizeof(current_sec) , format , today);
        sprintf_s(curTime , sizeof(current_sec) , "%s" , current_sec);
    }


    template<typename T>
    bool CharNonEmptyCheck(const T &t1) {
        std::cout << (typeid(t1).name()) << ":" << t1 << std::endl;
        //char
        if (typeid(t1).hash_code() == typeid(const char *).hash_code() ||
            typeid(t1).hash_code() == typeid("char *").hash_code())
            if (strncmp("PKc" , typeid(t1).name() , 4) == 0) {
                // �ж�char* or char[] �Ƿ�Ϊ��
                if (t1 == NULL || t1[0] == '\0' || strlen(t1) < 1) {
                    std::cout << "传递值为空: " << t1 << std::endl;
                    return false;
                } else return true;
            }

        return false;
    }

    template<typename T>
    bool NumberNonEmptyCheck(const T &t1 , T min_value = 0 , T max_value = 10000) {
        std::cout << (typeid(t1).name()) << ":" << t1 << std::endl;

        if ((std::strncmp("float" , typeid(t1).name() , 5) == 0) ||
            (std::strncmp("double" , typeid(t1).name() , 5) == 0)) {
            if (t1 < min_value && t1 > max_value) {
                return false;
            } else return true;
        }

        if (std::strncmp("int" , typeid(t1).name() , 3) == 0) {
            if (t1 < min_value && t1 > max_value) {
                return false;
            } else return true;
        }

        return false;
    }




    /*FILE* operateFile(const char* path)
    {
    FILE *f;
    if((f = fopen("C:\\Temps\\a.csv" , "w+")) != NULL)
    {
    fprintf(f,"name,age,holiby\n");
    fprintf(f,"xran ,25 ,ϲ��");
    fprintf(f,"\n");
    fprintf(f,"cc ,22 ,reading");
    fprintf(f,"\n");
    fflush(f);
    fclose(f);
    }
    }*/

}

#endif
