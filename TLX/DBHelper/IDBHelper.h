#ifndef _TLX_DBHLPER_HEADER_
#define _TLX_DBHLPER_HEADER_

#include "stdafx.h"

namespace utils
{

	class IDBHelper
	{
	public:

		/// <summary>
		/// ������update,insert,delete
		/// </summary>
		/// <param name="sql"></param>
		/// <returns>int : Ӱ������</returns>
		virtual int  NonSelectOpr(std::string sql) = 0;

		/// @brief ������ select ���
		/// @param sql 
		/// @return 
		virtual RESULT_SET_TYPE SelectOpr(std::string sql) = 0;
	};


	/// <summary>
	/// �������� select ����
	/// </summary>
	/// <param name="idb"></param>
	/// <param name="sql"></param>
	static void Select(IDBHelper& idb, std::string sql) {
		idb.SelectOpr(sql);
	}
}


#endif
