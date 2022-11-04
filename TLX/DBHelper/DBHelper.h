#ifndef _TLX_DBHELPER_HPP_
#define _TLX_DBHELPER_HPP_


#include <string>
#include <vector>
#include <iostream>
#include <memory.h>

#include <mysql.h>

/// @brief  mysql 结果集类型
using RESULT_SET_TYPE = MYSQL_RES*;
/// @brief mysql 结果集转二维向量存储.
using RECORD_TYPE = std::vector<std::vector<std::string>>;

namespace utils {

	/// @brief
	class IDBHelper
	{
	public:
		/// @brief suitable for operations of update,insert,delete
		/// @param sql
		/// @return affected row nums
		virtual long long NonSelect(std::string sql) = 0;

		/// @brief suitable for select statements
		/// @param sql
		/// @return
		virtual RESULT_SET_TYPE Select(std::string sql) = 0;
	};

	static void Select(IDBHelper& idb, std::string sql) {
		idb.Select(sql);
	}

	class DBHelper : public std::enable_shared_from_this<DBHelper>, public virtual IDBHelper
	{
	private:
		MYSQL mysql_;
		MYSQL_RES* res_; //查询结果集
		MYSQL_ROW row_;	 //从结果集读取数据，拆分成行数

		std::string db_;
		std::string host_;
		std::string user_;
		std::string pwd_;
		std::string db_name_;
		int port_;
		int columns_;

	public:
		DBHelper(const char* host, const char* user, const char* pwd, const char* db_name, unsigned int port);
		~DBHelper();

		// static bool test_connect_mysql();

		// static void test_multi_result_set();

		inline virtual long long NonSelect(std::string sql) override {
			auto status = mysql_real_query(&mysql_, sql.c_str(), sql.length());
			if (status)
			{
				printf("Could not execute statement(s)");
				mysql_close(&mysql_);
				exit(0);
			}

			return mysql_affected_rows(&mysql_);
		}

		inline virtual RESULT_SET_TYPE Select(std::string sql) override {
			auto status = mysql_real_query(&mysql_, sql.c_str(), sql.length());
			if (status)
			{
				printf("Could not execute statement(s)");
				mysql_close(&mysql_);
				exit(-2);
			}

			//获取结果集
			res_ = mysql_store_result(&mysql_);
			std::cout << "row nums：" << mysql_affected_rows(&mysql_) << std::endl;
			std::cout << "row nums：" << mysql_num_rows(res_) << std::endl;
			std::cout << "col nums: " << mysql_num_fields(res_) << std::endl;

			// 字段列数组
			MYSQL_FIELD* field = nullptr;
			//mysql_fetch_field() //返回下一个表字段的类型。
			while (field = mysql_fetch_field(res_))
			{
				std::cout << field->name << "\t" << field->catalog;
			}
			std::cout << std::endl;

			//存放一行的数据
			//for (auto row_index = 0; row_index < mysql_num_rows(res_); ++row_index)
			//{
			//	mysql_data_seek(res_, row_index);
			//	auto row = mysql_fetch_row(res_); //从结果集合中取得下一行。
			//	//std::cout << *(row + 3) << std::endl;
			//	printf("%s\t", *(row + 2));

			//	//auto cols = mysql_fetch_fields(res_);
			//	//std::cout << cols[0].name << std::endl;
			//}


			while ((row_ = mysql_fetch_row(res_)) != NULL)
				std::cout << row_[3] << std::endl;

			//int columns = mysql_num_fields(res_);
			//RECORD_TYPE records_;
			//while (auto row = mysql_fetch_row(res_))
			//{
			//	std::vector<std::string> row_;

			//	for (int i = 0; i < columns; ++i)
			//	{
			//		std::cout << row[i] << "\t";
			//		//row_.push_back(row[i] == NULL ? "" : row[i]);
			//	}

			//	//records_.push_back(row_);
			//	//std::cout  << row[0] << "===" << row[1];
			//}


			return res_;
		}
	};

	inline DBHelper::DBHelper(const char* host, const char* user, const char* pwd, const char* db_name, unsigned int port) {
		host_ = host;
		user_ = user_;
		pwd_ = pwd;
		db_name_ = db_name;
		port_ = port_;

		res_ = nullptr;
		row_ = nullptr;
		columns_ = 0;

		mysql_init(&mysql_);

		int utf8;
		utf8 = mysql_query(&mysql_, "set character_set_results=utf8");
		//printf("utf8=%d\n", utf8);
		//assert(utf8 == 0);

		mysql_options(&mysql_, MYSQL_SET_CHARSET_NAME, "utf8");
		mysql_query(&mysql_, "SET NAMES utf8"); //设置编码格式,否则在cmd下无法显示中文
		//mysql_set_character_set(&mysql_, "GBK");

		if (mysql_real_connect(&mysql_, host, user, pwd, db_name, port, nullptr, 0) == nullptr)
		{
			printf(" failed link to the database, reason %s\n", mysql_error(&mysql_));
			exit(-1);
		}
	}

	inline DBHelper::~DBHelper() {
		//注意用完数据库要及时回收资源
		if (res_ != nullptr)
			mysql_free_result(res_); //释放结果资源
		mysql_close(&mysql_);		 //关闭MySQL连接
		mysql_library_end();		 //关闭MySQL库
	}

}

#endif // _TLX_DBHELPER_HPP_