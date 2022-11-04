#include "main_window.h"
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include "../shareMem/file_struct.h"

main_window::main_window(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	using namespace boost::interprocess;
	using namespace std;
	const char* name_ = "xran";
	auto share_mem_size_ = 12;

	MAPP_FILE ff{ 1,33,44,"tr" };
	ff.map1["tr"] = 24;

	if (true)
	{
		shared_memory_object::remove(name_);
		shared_memory_object shm_obj(open_or_create, name_, read_write);
		//创建共享内存对象时，其大小为 0。要设置共享内存的大小，用户必须在已以读写属性打开的共享内存中使用 truncate 函数调用：
		shm_obj.truncate(share_mem_size_);


		//一旦创建或打开，进程只需将共享内存对象映射到进程的地址空间中。用户可以映射整个共享内存或只是其中的一部分。映射过程是使用 mapped_region 类完成的。该类表示已从共享内存或也具有映射功能的其他设备（例如文件）映射的内存区域。 mapped_region 可以从任何 memory_mappable 对象创建，正如您可能想象的那样，shared_memory_object 是一个 memory_mappable 对象：
		 //Map the whole shared memory in this process
		mapped_region region(shm_obj, read_write);

		//initializes
		auto e = static_cast<MAPP_FILE*>(region.get_address());
		sprintf_s(e->c_, 24, "%s", "woaiddd");
		e->l1 = 45;

		ui.l1->setText(e->c_);
	}
}

main_window::~main_window()
{}
