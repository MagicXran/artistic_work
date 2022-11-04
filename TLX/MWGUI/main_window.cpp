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
		//���������ڴ����ʱ�����СΪ 0��Ҫ���ù����ڴ�Ĵ�С���û����������Զ�д���Դ򿪵Ĺ����ڴ���ʹ�� truncate �������ã�
		shm_obj.truncate(share_mem_size_);


		//һ��������򿪣�����ֻ�轫�����ڴ����ӳ�䵽���̵ĵ�ַ�ռ��С��û�����ӳ�����������ڴ��ֻ�����е�һ���֡�ӳ�������ʹ�� mapped_region ����ɵġ������ʾ�Ѵӹ����ڴ��Ҳ����ӳ�书�ܵ������豸�������ļ���ӳ����ڴ����� mapped_region ���Դ��κ� memory_mappable ���󴴽������������������������shared_memory_object ��һ�� memory_mappable ����
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
