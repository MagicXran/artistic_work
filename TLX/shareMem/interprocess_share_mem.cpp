#include "interprocess_share_mem.h"
#include "file_struct.h"

#include <cstring>
#include <cstdlib>
#include <iostream>


/// @brief ʹ�� shared_memory_object �����������򿪺����ٿ��Ա��������ӳ��Ĺ����ڴ�Ρ����ǿ���ָ���ù����ڴ����ķ���ģʽ��ֻ�����д������������һ���ļ�һ����
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
		//���������ڴ����ʱ�����СΪ 0��Ҫ���ù����ڴ�Ĵ�С���û����������Զ�д���Դ򿪵Ĺ����ڴ���ʹ�� truncate �������ã�
		shm_obj.truncate(this->share_mem_size_);


		//һ��������򿪣�����ֻ�轫�����ڴ����ӳ�䵽���̵ĵ�ַ�ռ��С��û�����ӳ�����������ڴ��ֻ�����е�һ���֡�ӳ�������ʹ�� mapped_region ����ɵġ������ʾ�Ѵӹ����ڴ��Ҳ����ӳ�书�ܵ������豸�������ļ���ӳ����ڴ����� mapped_region ���Դ��κ� memory_mappable ���󴴽������������������������shared_memory_object ��һ�� memory_mappable ����
		 //Map the whole shared memory in this process
		mapped_region region(shm_obj, read_write);

		cout << "page size: " << mapped_region::get_page_size() << endl;
		cout << "region size: " << region.get_size() << endl;
		//initializes
		//std::memset(region.get_address(), 1, region.get_size());
		//memset(region.get_address(), 2, region.get_size());
		auto e = static_cast<MAPP_FILE*>(region.get_address());
		sprintf_s(e->c_, 24, "%s", "woai ��");
		e->l1 = 45;

	}

	try
	{
		//  ��һ�����̣���ȡ
		shared_memory_object shm_read(open_only, this->name_.c_str(), read_only);

		//Map the whole shared memory in this process
		mapped_region region1(shm_read, read_only);

		//Check that memory was initialized to 1
		auto mem = static_cast<MAPP_FILE*>(region1.get_address());
		cout << mem->c_ << ", " << mem->l1 << endl;
		cout << mem->map1["tr"] << endl;
		//���ڹ����ڴ�����ں˻��ļ�ϵͳ�־��ԣ�����û�������ȷ��������
		//��������ڴ���󲻴��ڻ���һ�����̴򿪣��˺������ܻ�ʧ�ܡ���ע�⣬�˺��������ڱ�׼ C int remove(const char* path) �������� UNIX ϵͳ�У�shared_memory_object::remove ���� shm_unlink��
		std::cout << shared_memory_object::remove(this->name_.c_str()) << std::endl;
	}
	catch (boost::interprocess::interprocess_exception& e)
	{
		cout << e.get_error_code() << ", " << e.what() << endl;
	}

}

#include <boost/interprocess/windows_shared_memory.hpp>
/// @brief Windows ����ϵͳҲ�ṩ�����ڴ棬�������ڴ�������������ں˻��ļ�ϵͳ�����������кܴ�ͬ�������ڴ���ҳ���ļ��������������ӵ������ڴ�����һ�����̱�����ʱ�Զ�����
/// ���Ա�֤�����һ������˽����˳�ǰ���ͻ��˲���ʹ�ù����ڴ�; ����ͻ�������ʧ��~~~
/// �ڷ�����û�Ӧ�ó���֮�乲���ڴ�Ҳ�ǲ�ͬ�ġ�Ҫ�ڷ�����û�Ӧ�ó���֮�乲���ڴ棬�����ڴ�����Ʊ�����ȫ�������ռ�ǰ׺��Global\\����ͷ����ȫ�������ռ�ʹ����ͻ��˻Ự�ϵĽ����ܹ������Ӧ�ó������ͨ�š����������������ȫ�������ռ��д��������ڴ档Ȼ��ͻ��˻Ự����ʹ�á�ȫ�֡�ǰ׺���򿪸��ڴ档
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
		sprintf_s(ptr->c_, FileSize, "%s", "ilove С��");

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


