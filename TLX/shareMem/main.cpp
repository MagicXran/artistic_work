/************************************************************************/
/*	FileName	:		main.cpp
/*	User		:		Administrator
/*	Time		:		10/31/2022 2:58:48 PM
/*	clr_version	:		4.0.30319.42000
/*	Description :
/*
/*
/*
/************************************************************************/

#include "interprocess_share_mem.h"
#include <iostream>
#include "mem_struct.h"
//#include "file_struct.h"
#include <map>
int main(int argc, char* argv[])
{
	interprocess_share_mem shm;
	shm.shareMem01();
	//shm.memory_mapped_files();

	//test();
	return 0;
}

