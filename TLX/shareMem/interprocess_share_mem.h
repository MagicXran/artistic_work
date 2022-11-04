#pragma once
#define BOOST_DATE_TIME_NO_LIB 

#include <string.h>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>

class interprocess_share_mem
{
public:
	void shareMem01();
	void native_windows_shared_memory();
	void memory_mapped_files();
private:
	long	share_mem_size_;
	std::string name_;
	std::string file_name_;
};

