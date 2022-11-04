#ifndef _TLX_DBHLPER_HEADER_
#define _TLX_DBHLPER_HEADER_

#include "stdafx.h"

namespace utils
{

	class IDBHelper
	{
	public:

		/// <summary>
		/// 适用于update,insert,delete
		/// </summary>
		/// <param name="sql"></param>
		/// <returns>int : 影响行数</returns>
		virtual int  NonSelectOpr(std::string sql) = 0;

		/// @brief 适用于 select 语句
		/// @param sql 
		/// @return 
		virtual RESULT_SET_TYPE SelectOpr(std::string sql) = 0;
	};


	/// <summary>
	/// 公共代理 select 函数
	/// </summary>
	/// <param name="idb"></param>
	/// <param name="sql"></param>
	static void Select(IDBHelper& idb, std::string sql) {
		idb.SelectOpr(sql);
	}
}


#endif
