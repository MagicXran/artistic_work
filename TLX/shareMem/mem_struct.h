
#ifndef _TABLE_STRUCT_MEM_HPP_
#define _TABLE_STRUCT_MEM_HPP_

#define  FIELD_INTEGER_VALUE  long
#define  FIELD_FLOAT_VALUE    double


union FIELD_VALUE
{
	FIELD_INTEGER_VALUE l_;
	FIELD_FLOAT_VALUE d_;
};

#define MAX_FIELD_NANME_LEN   60
#define MAX_RECORD_SIZE   1024

typedef struct _FIELD_
{
	//char* field_name;
	char field_name[MAX_FIELD_NANME_LEN];
	void* field_value;
	//union field_value_u
	//{
	//	void* c_val;
	//	int	 i_val;
	//	long l_val;
	//	float f_val;
	//	double d_cal;
	//} field_value;

}FIELD, * FIELD_PTR;


/// @brief 定义内存二维表结构
struct MEM_TBL
{
	FIELD p_data[MAX_RECORD_SIZE];
	long  record_no;
	long  record_num;
	long  record_len;
};

struct TEST
{
	char ch[30];
	long l1;
};

template<typename T>
class MemTblAccessor
{
private:
	//FIELD field_;
public:
	FIELD field_;
	MemTblAccessor(const char* name) {
		field_.field_value = static_cast<T*>(std::move(new T()));
		sprintf_s(field_.field_name, MAX_FIELD_NANME_LEN, "%s", name);
	}

	MemTblAccessor(const char* name, T* t) {
		field_.field_value = static_cast<T*>(t);
		sprintf_s(field_.field_name, MAX_FIELD_NANME_LEN, "%s", name);
	}
};


#include <iostream>
void test()
{
	using namespace std;
	TEST  ta{ "ddd",45 };
	//FIELD p_data;


	//sprintf_s(p_data.field_name, MAX_FIELD_NANME_LEN, "%s", "我爱你");
	//p_data.field_value = (void*)&ta;
	//auto ddd = static_cast<TEST*>(p_data.field_value);

	MemTblAccessor<TEST> memtbl("test", &ta);
	cout << memtbl.field_.field_name << endl;

	auto aa = static_cast<TEST*>(memtbl.field_.field_value);
	cout << aa->ch << endl;
}
#endif

