#ifndef _TLX_DBHLPER_HPP_
#define  _TLX_DBHLPER_HPP_
//#pragma execution_character_set("utf-8") 

#include "IDBHelper.h"

namespace utils
{
	//using namespace  std;
	class DBHelper : public std::enable_shared_from_this<DBHelper>, public virtual IDBHelper
	{

	private:
		MYSQL mysql_;
		MYSQL_RES* res_;  //��ѯ�����
		MYSQL_ROW row_;	//�ӽ������ȡ���ݣ���ֳ�����

		std::string db_;
		std::string host_;
		std::string user_;
		std::string pwd_;
		std::string db_name_;
		int			port_;
		int			columns_;

	public:
		DBHelper(const char* host, const char* user, const char* pwd, const char* db_name, unsigned int port);
		~DBHelper();

		inline static bool test_connect_mysql();

		inline static void test_multi_result_set();

		int  NonSelectOpr(std::string sql);

		RESULT_SET_TYPE  SelectOpr(std::string sql);
		//void SelectOpr(std::string sql);

	private:
		/// <summary>
		/// ��ʼ��, mysql���ӵ�
		/// </summary>
		void init();

		/// <summary>
		/// �� config.json �л�ȡ MySQL ���ݿ�������Ϣ.
		/// </summary>
		void GetJson();
	};
	inline DBHelper::DBHelper(const char* host, const char* user, const char* pwd, const char* db_name, unsigned int port = 3306)
	{
		host_ = host;
		user_ = user_;
		pwd_ = pwd;
		db_name_ = db_name;
		port_ = port_;

		res_ = nullptr;
		row_ = nullptr;
		columns_ = 0;
		mysql_init(&mysql_);
		mysql_options(&mysql_, MYSQL_SET_CHARSET_NAME, "gbk");	//�޸���һ���ַ���������gbk����
		if (mysql_real_connect(&mysql_, host, user, pwd, db_name, port, nullptr, 0) == nullptr)
		{
			printf(" failed link to the database, reasons�� %s\n", mysql_error(&mysql_));
			exit(-1);
		}
	}
	inline DBHelper::~DBHelper()
	{
		//ע���������ݿ�Ҫ��ʱ������Դ  
		if (res_ != nullptr) mysql_free_result(res_);//�ͷŽ����Դ  
		mysql_close(&mysql_);//�ر�MySQL����  
		mysql_library_end();//�ر�MySQL��  
	}
	//���ⶨ��
	inline bool DBHelper::test_connect_mysql()
	{
		using namespace std;

		MYSQL mysql;	//����mysql����
		MYSQL_RES* res;  //��ѯ�����
		MYSQL_ROW row;	//�ӽ������ȡ���ݣ���ֳ�����
		char sql[256];	//����һ�����sql��������

		string username = "res";	//�û���
		string password = "res";	//����

		//mysql_library_init(); //���̻߳�����,not thread-safe in a multithreaded environment
		mysql_init(&mysql);	//��ʼ�����ݿ�

		//mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");	//�޸���һ���ַ���������gbk����

		//�������������ò���������ΪNULL���� 0;
		//mysql_error(MYSQL* mysql); ���������mysql�Լ���װ�õ�api�ӿڣ�����ֱ��ʹ�ü��ɣ�������ӡ������Ϣ��;
		//mysql_real_connect(&mysql,"127.0.0.1",���ݿ��˻�,���ݿ�����,Ҫ���ӵ����ݿ⣬�˿ں�һ��Ϊ3306��NULL��0)
		if (mysql_real_connect(&mysql, "127.0.0.1", "root", "Xu19960118", "djtu", 3306, nullptr, 0) == NULL)
		{
			printf("���ݿ����ӳ��� , ����ԭ�� %s\n", mysql_error(&mysql));
			exit(-1);
		}


		//snprintf�Ǹ�ʽ������ַ��� ���������͵ĺ���
		snprintf(sql, sizeof(sql), "select *  from userinfo where username='%s' and password='%s';", username.c_str(), password.c_str());

		//cout << sql << endl;
		if (mysql_query(&mysql, sql))
		{//ִ��sql��䣬�ɹ�����0;
			printf("���ݿ��ѯ����%s ����ԭ�� %s\n", sql, mysql_error(&mysql));
			mysql_close(&mysql);

		}

		res = mysql_store_result(&mysql);

		row = mysql_fetch_row(res);

		if (row == nullptr)
		{//û�в��ҵ���¼
			mysql_free_result(res);	//�ͷ���Դ
			mysql_close(&mysql);	//�ر����ݿ�
			return false;
		}

		// For each non-SELECT query (for example, INSERT, UPDATE, DELETE),
		/*const char* sql_insert = "insert into userinfo (username,password) values('r2','r2')";
		mysql_real_query(&mysql, sql_insert,strlen(sql_insert));
		cout << mysql_affected_rows(&mysql);*/

		// update
		//const char* sql_update = "update userinfo set PASSWORD = 'r2' where USERNAME='r2'";
		//mysql_real_query(&mysql, sql_update ,strlen(sql_update));
		//cout << mysql_affected_rows(&mysql) << endl;
		//cout << mysql_field_count(&mysql) << endl;
		//cout << mysql_error(&mysql)<< endl;

		/*cout << row[0] << endl;
		cout << row[1] << endl;
		cout << row[2] << endl;*/
	}

	inline void DBHelper::test_multi_result_set()
	{
		using namespace std;
		MYSQL  mysql;
		char sql_[256];
		memset(sql_, 0x00, sizeof sql_);

		sprintf_s(sql_, sizeof sql_, "%s", "select * from userinfo");
		mysql_init(&mysql);

		if (mysql_real_connect(&mysql, "127.0.0.1", "root", "Xu19960118", "djtu", 3306, nullptr, 0) == NULL)
		{
			printf("���ݿ����ӳ��� , ����ԭ�� %s\n", mysql_error(&mysql));
			exit(-1);
		}

		auto status = mysql_real_query(&mysql, sql_, strlen(sql_));
		if (status)
		{
			printf("Could not execute statement(s)");
			mysql_close(&mysql);
			exit(0);
		}

		//��ȡ�����
		MYSQL_RES* result = mysql_store_result(&mysql);
		cout << "������" << mysql_affected_rows(&mysql) << endl;
		cout << "������" << mysql_num_rows(result) << endl;
		cout << "������" << mysql_num_fields(result) << endl;

		// �ֶ�������
		MYSQL_FIELD* field = nullptr;

		// mysql_fetch_field() ������һ�����ֶε����͡�
		while (field = mysql_fetch_field(result))
		{
			cout << field->name << "\t";
		}
		cout << endl;

		int columns = mysql_num_fields(result);
		//���һ�е�����
		MYSQL_ROW row;
		//mysql_fetch_row(MySQL_RES * result) �ӽ��������ȡ����һ�С�
		while (row = mysql_fetch_row(result))
		{
			for (int i = 0; i < columns; ++i)
			{
				cout << row[i] << "\t";
			}
			cout << endl;
		}

		//// ִ�ж����
		//do
		//{
		//	res = mysql_store_result(&mysql);
		//	//cout << res->row_count << endl;

		//	if (res)
		//	{
		//		// process rows and free results
		//		cout << res->current_field << endl;
		//		cout << res->current_row << endl;
		//		cout << res->fields->name << endl;
		//		cout << res->fields->table << endl;
		//		auto row = mysql_fetch_row(res);
		//		if (row == NULL)
		//		{
		//			cout << "row is null!" << endl;
		//			exit(0);
		//		}
		//		cout << row[0] << endl;
		//		//cout << res->current_field << endl;
		//		mysql_free_result(res);

		//	}
		//	else {
		//		/* no result set or error */
		//		if (mysql_field_count(&mysql) == 0) {
		//			printf("%lld rows affected\n", mysql_affected_rows(&mysql));
		//		}
		//		else /* some error occurred */ {
		//			printf("Could not retrieve result set\n"); break;
		//		}
		//	}
		//	/* more results? -1 = no, >0 = error, 0 = yes (keep looping) */
		//	//��ȡ�¸������
		//	if ((status = mysql_next_result(&mysql)) > 0)
		//		printf("Could not execute statement\n");
		//} while (status == 0);

		/*unsigned int num_fields;
		unsigned int i;
		MYSQL_FIELD* field;
		num_fields = mysql_num_fields(result);
		for (i = 0; i < num_fields; i++) {
			field = mysql_fetch_field_direct(result, i);
			printf("Field %u is %s\n", i, field->name);
		}*/


		//�ͷ��ڴ棬�Ͽ�����
		mysql_free_result(result);
		mysql_close(&mysql);
	}

	inline int DBHelper::NonSelectOpr(std::string sql)
	{
		auto status = mysql_real_query(&mysql_, sql.c_str(), sql.length());
		if (status)
		{
			printf("Could not execute statement(s)");
			mysql_close(&mysql_);
			exit(0);
		}

		return mysql_affected_rows(&mysql_);
	}

	inline RESULT_SET_TYPE DBHelper::SelectOpr(std::string sql)
	{
		auto status = mysql_real_query(&mysql_, sql.c_str(), sql.length());
		if (status)
		{
			printf("Could not execute statement(s)");
			mysql_close(&mysql_);
			exit(-2);
		}

		//��ȡ�����
		res_ = mysql_store_result(&mysql_);
		std::cout << "row nums��" << mysql_affected_rows(&mysql_) << std::endl;
		std::cout << "row nums��" << mysql_num_rows(res_) << std::endl;
		std::cout << "col nums: " << mysql_num_fields(res_) << std::endl;

		// �ֶ�������
		MYSQL_FIELD* field = nullptr;
		//mysql_fetch_field() //������һ�����ֶε����͡�
		while (field = mysql_fetch_field(res_)) {
			std::cout << field->name << "\t";
		}
		std::cout << std::endl;

		// ����
		columns_ = mysql_num_fields(res_);

		while ((row_ = mysql_fetch_row(res_)) != NULL)
			std::cout << row_[3] << std::endl;
		return res_;
	}

}

#endif // _TLX_DBHLPER_HPP_
