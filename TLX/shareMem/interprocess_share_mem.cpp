#include "interprocess_share_mem.h"
#include "file_struct.h"

#include <cstring>
#include <cstdlib>
#include <iostream>


/// @brief 使用 shared_memory_object 类来创建、打开和销毁可以被多个进程映射的共享内存段。我们可以指定该共享内存对象的访问模式（只读或读写），就像它是一个文件一样：
void interprocess_share_mem::shareMem01()
{
	using namespace boost::interprocess;
	using namespace std;
	this->name_ = "xran";
	MAPP_FILE ff{ 1,33,44,"tr" };
	ff.map1["tr"] = 24;

	this->share_mem_size_ = sizeof(MAPP_FILE);
	if (true)
	{
		shared_memory_object::remove(this->name_.c_str());
		shared_memory_object shm_obj(open_or_create, this->name_.c_str(), read_write);
		//创建共享内存对象时，其大小为 0。要设置共享内存的大小，用户必须在已以读写属性打开的共享内存中使用 truncate 函数调用：
		shm_obj.truncate(this->share_mem_size_);


		//一旦创建或打开，进程只需将共享内存对象映射到进程的地址空间中。用户可以映射整个共享内存或只是其中的一部分。映射过程是使用 mapped_region 类完成的。该类表示已从共享内存或也具有映射功能的其他设备（例如文件）映射的内存区域。 mapped_region 可以从任何 memory_mappable 对象创建，正如您可能想象的那样，shared_memory_object 是一个 memory_mappable 对象：
		 //Map the whole shared memory in this process
		mapped_region region(shm_obj, read_write);

		cout << "page size: " << mapped_region::get_page_size() << endl;
		cout << "region size: " << region.get_size() << endl;
		//initializes
		//std::memset(region.get_address(), 1, region.get_size());
		//memset(region.get_address(), 2, region.get_size());
		auto e = static_cast<MAPP_FILE*>(region.get_address());
		sprintf_s(e->c_, 24, "%s", "woai 你");
		e->l1 = 45;

	}

	try
	{
		//  另一个进程，读取
		shared_memory_object shm_read(open_only, this->name_.c_str(), read_only);

		//Map the whole shared memory in this process
		mapped_region region1(shm_read, read_only);

		//Check that memory was initialized to 1
		auto mem = static_cast<MAPP_FILE*>(region1.get_address());
		cout << mem->c_ << ", " << mem->l1 << endl;
		cout << mem->map1["tr"] << endl;
		//由于共享内存具有内核或文件系统持久性，因此用户必须明确销毁它。
		//如果共享内存对象不存在或被另一个进程打开，此函数可能会失败。请注意，此函数类似于标准 C int remove(const char* path) 函数。在 UNIX 系统中，shared_memory_object::remove 调用 shm_unlink：
		std::cout << shared_memory_object::remove(this->name_.c_str()) << std::endl;
	}
	catch (boost::interprocess::interprocess_exception& e)
	{
		cout << e.get_error_code() << ", " << e.what() << endl;
	}

}

#include <boost/interprocess/windows_shared_memory.hpp>
/// @brief Windows 操作系统也提供共享内存，但共享内存的生命周期与内核或文件系统的生命周期有很大不同。共享内存由页面文件创建，并在连接到共享内存的最后一个进程被销毁时自动销毁
/// 所以保证在最后一个服务端进程退出前，客户端不再使用共享内存; 否则客户端连接失败~~~
/// 在服务和用户应用程序之间共享内存也是不同的。要在服务和用户应用程序之间共享内存，共享内存的名称必须以全局命名空间前缀“Global\\”开头。此全局命名空间使多个客户端会话上的进程能够与服务应用程序进行通信。服务器组件可以在全局命名空间中创建共享内存。然后客户端会话可以使用“全局”前缀来打开该内存。
void interprocess_share_mem::native_windows_shared_memory()
{
	using namespace std;
	using namespace boost::interprocess;

	//Create a native windows shared memory object.
	windows_shared_memory shm(open_or_create, "xran", read_write, 10);

	//Map the whole shared memory in this process
	mapped_region region(shm, read_write);

	//Write all the memory to 1
	std::memset(region.get_address(), 3, region.get_size());

	//windows_shared_memory is destroyed when the last attached process dies...
}

#include <boost/interprocess/file_mapping.hpp>
void interprocess_share_mem::memory_mapped_files()
{
	using namespace std;
	using namespace boost::interprocess;

	//Define file names
	const char* FileName = "C:\\Projects\\C++\\boost_manuscript\\shareMem\\test.dat";
	const std::size_t FileSize = 24;

	//cout << argc << endl;
	//cout << argv[0] << endl;
	//cout << argv[1] << endl;
	//cout << argv[2] << endl;

	//if (argc == 1)
	{
		MAPP_FILE file{};
		file_mapping  m_file(FileName, read_write);

		mapped_region region(m_file, read_write, 0, sizeof(file));
		//Get the address of the region
		cout << region.get_address() << endl;;

		//Get the size of the region
		cout << region.get_size() << endl;

		auto ptr = static_cast<MAPP_FILE*>(region.get_address());
		ptr->l1 = 33;
		sprintf_s(ptr->c_, FileSize, "%s", "ilove 小鱼");

		//Launch child process
		//std::string s(argv[0]); s += " child ";
		//if (0 != std::system(s.c_str()))
			//return 1;
	}
	//else {  //Child process executes this
	//	{  //Open the file mapping and map it as read-only
	//		file_mapping m_file(FileName, read_only);

	//		mapped_region region(m_file, read_only);

	//		//Get the address of the mapped region
	//		void* addr = region.get_address();
	//		std::size_t size = region.get_size();

	//		//Check that memory was initialized to 1
	//		auto mem = static_cast<MAPP_FILE*>(addr);
	//		printf("%s,%d\n", mem->c_, mem->l1);
	//	}
	//	{  //Now test it reading the file
	//		std::filebuf fbuf;
	//		fbuf.open(FileName, std::ios_base::in | std::ios_base::binary);

	//		//Read it to memory
	//		std::vector<char> vect(FileSize, 0);
	//		fbuf.sgetn(&vect[0], std::streamsize(vect.size()));

	//		//Check that memory was initialized to 1
	//		const char* mem = static_cast<char*>(&vect[0]);
	//		for (std::size_t i = 0; i < FileSize; ++i)
	//			if (*mem++ != 1)
	//				return 1;   //Error checking memory
	//	}
	//}

	cout << file_mapping::remove(this->file_name_.c_str()) << endl;
}


