#include "DBHelper.hpp"

int main()
{
	std::shared_ptr<utils::IDBHelper> idb = std::make_shared<utils::DBHelper>("192.168.2.12", "isv", "igate123456", "gangtie_jiarelu", 30333);
	RESULT_SET_TYPE res = idb->SelectOpr("select * from gradetable");
	return 0;
}