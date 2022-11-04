#ifndef _SHARE_MEME_HEADER_
#define _SHARE_MEME_HEADER_

#include <map>
struct MAPP_FILE
{
	int i_; //4
	long l1, l2; //8
	char  c_[24]; //24
	std::map<std::string, int> map1; //12
};

#endif // _SHARE_MEME_HEADER_

