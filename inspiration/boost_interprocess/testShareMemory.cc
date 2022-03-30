//
// Created by Administrator on 12/03/2022.
//
//#define BOOST_INTERPROCESS_BOOTSTAMP_IS_SESSION_MANAGER_BASED
//#define BOOST_INTERPROCESS_BOOTSTAMP_IS_LASTBOOTUPTIME

#include <iostream>
#include <thread>
#include <chrono>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/windows_shared_memory.hpp>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>
#include <boost/interprocess/file_mapping.hpp>
//#include <boost/interprocess/sync/named_condition.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include <boost/interprocess/ipc/message_queue.hpp>
#include <boost/date_time.hpp>

#define DATA_SIZE  100

struct test_datas {
    char name[128];
    char sender[128];
    union u_data {
        char s1_[1024];
        long l1_;
        double d_;
    } u_member;
};

void write_shared_memory(const char *shared_name) {
    using namespace boost::interprocess;
    shared_memory_object shdmem(open_or_create , shared_name , read_write);
//    windows_shared_memory shdmem(open_or_create , shared_name , read_write , sizeof(test_datas));
    //此共享内存区域的大小被初始化为0.为了使用这块区域，需要调用 truncate() 函数，以字节为单位传递请求的共享内存的大小
    //truncate() 函数只能在共享内存以 boost::interprocess::read_write 方式打开时调用
    //为了调整共享内存的大小，truncate() 函数可以被重复调用
    shdmem.truncate(DATA_SIZE);
    //查询共享内存的名称和大小。
    std::cout << shdmem.get_name() << std::endl;
    boost::interprocess::offset_t size;
    if (shdmem.get_size(size))
        std::cout << size << std::endl;

    // 将共享内存映射到进程的地址空间, 此种映射两次.
    mapped_region region(shdmem , read_write);
    std::memset(region.get_address() , 1 , region.get_size());

//    std::cout << std::hex << "共享内存映射到进程地址空间的首地址: " << region.get_address() << std::endl;
//    std::cout << std::dec << region.get_size() << std::endl;
//    auto *data_ptr = static_cast<int *>(region.get_address());
//    *data_ptr = 3;
//    sprintf(data_ptr->name , "%s" , "徐国zh");
//    sprintf(data_ptr->sender , "%s" , "我爱你");
//    data_ptr->u_member.d_ = 66.890;


//    boost::interprocess::mapped_region region2(shdmem , boost::interprocess::read_only);
//    std::cout << std::hex << "共享内存映射到进程地址空间的首地址: " << region2.get_address() << std::endl;
//    std::cout << std::dec << region2.get_size() << std::endl;

//    auto ptr_data = static_cast<test_datas *>(region2.get_address());
//    std::cout << ptr_data->name << std::endl;
//    std::cout << ptr_data->sender << std::endl;
//    std::cout << ptr_data->u_member.d_ << std::endl;

}

void read_shared_mem(const char *mem_name) {
    using namespace boost::interprocess;
    shared_memory_object win_mem(open_only , mem_name , read_only);
    mapped_region region(win_mem , read_only);
    auto ptr_data = static_cast<test_datas *>(region.get_address());

    std::cout << ptr_data->name << std::endl;
    std::cout << ptr_data->sender << std::endl;
    std::cout << ptr_data->u_member.d_ << std::endl;
}

void release(const char *mem_name) {
    //如果 remove() 没有被调用, 那么，即使进程终止，共享内存还会一直存在，而不论共享内存的删除是否依赖底层操作系统。
    //在 Windows 或 Mac OS X上，remove() 必须调用，这两种系统实际上将共享内存存储在持久化的文件上，此文件在系统重启后还是存在的。
    bool isRemove = boost::interprocess::shared_memory_object::remove(mem_name);
    if (isRemove)
        std::cout << "释放成功!" << std::endl;
}

/**
 * 创建和管理共享的 boost::interprocess::shared_memory_object 类。
 * 实际上，由于这个类需要按单个字节的方式读写共享内存，所以这个类几乎不用。
 * 概念上来讲，C++改善了类对象的创建并隐藏了它们存储在内存中哪里，是怎们存储的这些细节。
 *
 * 名为“托管共享内存" managed_shared_memory
 * 这个类的目的是，对于需要分配到共享内存上的对象，它能够以内存申请的方式初始化，并使其自动为使用同一个共享内存的其他应用程序可用
 * @param name
 */
void write_mem_by_manager(const char *name) {
    using namespace boost::interprocess;
    try {
        bool flag = shared_memory_object::remove(name);
        managed_shared_memory manage_mem(open_or_create , name , sizeof(test_datas) + 1000);
        // 禁用STL模板类, 只能用primary type 数据.
        auto ptr_data = manage_mem.construct<test_datas>(name)();
        named_mutex name_mtx(open_only , name);
        name_mtx.lock();
        if (ptr_data)
            ptr_data->u_member.d_ = 345.12;
        name_mtx.unlock();
//        name_mtx.remove(name);

//如果给定名称的对象已经在托管的共享内存中存在，那么 construct() 将会失败。 在这种情况下，construct() 返回值是0
//        manage_mem.construct<int>(name)[30](666);
//        std::pair<int * , std::size_t> p = manage_mem.find<int>(name);
//        if (p.first) {
//            //a memory buffer
//            std::cout << *p.first << std::endl;
//            //the object count
//            std::cout << p.second << std::endl;
//        }
    } catch (boost::interprocess::bad_alloc &ex) {
        release(name);
        std::cerr << ex.what() << std::endl;
    }

}

void read_mem_by_manager(const char *name) {
    using namespace boost::interprocess;
    managed_shared_memory manage_mem(open_read_only , name);
    auto p = manage_mem.find<test_datas>(name);
    if (p.first) {
        //a memory buffer
        std::cout << p.first->name << std::endl;
        std::cout << p.first->sender << std::endl;
        std::cout << p.first->u_member.d_ << std::endl;
        //the object count
        std::cout << p.second << std::endl;
    }
}

void writei_mem_by_manager(const char *name , double i) {
    using namespace boost::interprocess;
    try {
        bool flag = shared_memory_object::remove(name);
        managed_shared_memory manage_mem(open_or_create , name , sizeof(test_datas) + 1000);
        // 禁用STL模板类, 只能用primary type 数据.
        auto ptr_data = manage_mem.construct<test_datas>(name)();
        named_mutex name_mtx(open_or_create , name);
        {
//            boost::interprocess::scoped_lock<boost::interprocess::named_mutex> lock(name_mtx);
            if (ptr_data)
                ptr_data->u_member.d_ = i;
            std::cout << std::this_thread::get_id() << ": " << i << std::endl;
        }


//如果给定名称的对象已经在托管的共享内存中存在，那么 construct() 将会失败。 在这种情况下，construct() 返回值是0
//        manage_mem.construct<int>(name)[30](666);
//        std::pair<int * , std::size_t> p = manage_mem.find<int>(name);
//        if (p.first) {
//            //a memory buffer
//            std::cout << *p.first << std::endl;
//            //the object count
//            std::cout << p.second << std::endl;
//        }
    } catch (boost::interprocess::bad_alloc &ex) {
        release(name);
        std::cerr << "dfd我" << ex.what() << std::endl;
    }

}

void create_shared_mem_by_win(const char *name) {
    using namespace boost::interprocess;
    //Create a native windows shared memory object.
    windows_shared_memory shm(create_only , name , read_write , DATA_SIZE);

    //Map the whole shared memory in this process
    mapped_region region(shm , read_write);

    //Write all the memory to 1
    //windows_shared_memory is destroyed when the last attached process dies...
    std::memset(region.get_address() , 1 , region.get_size());

    char *mem = static_cast<char *>(region.get_address());
    for (std::size_t i = 0 ; i < region.get_size() ; ++i) {
        if (*mem++ != 1)
            return;
        std::cout << *mem << std::endl;
    }
}

void read_shared_mem_win(const char *name) {
    using namespace boost::interprocess;
    //Open already created shared memory object.
    windows_shared_memory shm(open_only , name , read_only);

    //Map the whole shared memory in this process
    mapped_region region(shm , read_only);

    //Check that memory was initialized to 1
    char *mem = static_cast<char *>(region.get_address());
    for (std::size_t i = 0 ; i < region.get_size() ; ++i) {
        if (*mem++ != 1)
            return;
        std::cout << mem << std::endl;
    }
}

void create_file_mapping(const char *filename) {
    using namespace boost::interprocess;

    file_mapping m_file(filename , read_write);
    //Map the second half of the file
    mapped_region region(m_file                   //Memory-mappable object
            , read_write               //Access mode
            //, FileSize / 2               //Offset from the beginning of shm
            //, FileSize - FileSize / 2      //Length of the region
    );
//Get the address of the region
//    auto addr = static_cast<mappedData *>(region.get_address());
//    sprintf_s(addr->name , sizeof(addr->name) , "%s" , "This is a book");
//    sprintf_s(addr->sender , sizeof(addr->sender) , "%s" , "xuguozhu");
//    addr->u_member.d_ = 4334.22;
//    addr->u_member.l1_ = 1;
//Get the size of the region
    std::cout << region.get_size() << std::endl;
    //Flush the whole region
    region.flush();
}

void read_file_mapping(const char *filename) {
    using namespace boost::interprocess;
    file_mapping m_file(filename , read_only);

    mapped_region region(m_file , read_only);

    //Get the address of the mapped region
//    auto *addr = static_cast<mappedData *>(region.get_address());
//    std::size_t size = region.get_size();
//    std::cout << size << std::endl;
//    std::cout << addr->name << std::endl;
//    std::cout << addr->sender << std::endl;
//    std::cout << addr->u_member.d_ << std::endl;
//    std::cout << addr->u_member.l1_ << std::endl;

}

#define MESSAGE_NUM  1024

void send_message_queue(const char *msg_name) {
    using namespace boost::interprocess;

    try {
        //Erase previous message queue
        message_queue::remove(msg_name);

        //Create a message_queue.
        message_queue mq(open_or_create               //only create
                , msg_name         //name
                , MESSAGE_NUM                       //max message number
                , DATA_SIZE               //max message size
        );

        //Send 100 numbers
//        for (int i = 0 ; i < 20 ; ++i) {
        int i = 0;
        while (true) {
            mq.send(&i , sizeof(i) , 0);
//                std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }

        std::cout << "发送陈公公" << std::endl;
//        char aa[122];
//        std::cin >> aa;

    } catch (interprocess_exception &e) {
        message_queue::remove(msg_name);
        std::cout << e.what() << std::endl;
    }

}

void rec_msgQueue(const char *name) {
    using namespace boost::interprocess;
    using namespace std;
    try {

        message_queue mq(open_only , name);
        unsigned int priority;
        message_queue::size_type recvd_size;
//        boost::posix_time::ptime time_(boost::gregorian::date(2022 , 3 , 14));
        //Receive 100 numbers
//        for (int i = 0 ; i < 100 ; ++i) {
        while (true) {
            int number;
            mq.timed_receive(&number , DATA_SIZE , recvd_size , priority , boost::date_time::pos_infin);
            cout << number << endl;
        }

//            cout << recvd_size << endl;
//            cout << priority << endl;
        //if (number != i || recvd_size != sizeof(number))
//            message_queue::remove(name);

    } catch (interprocess_exception &e) {
        message_queue::remove(name);
        cout << e.what() << endl;
    }

}

void send_message_queue_DIY(const char *msg_name) {
    using namespace boost::interprocess;

    try {
        //Erase previous message queue
        message_queue::remove(msg_name);

        //Create a message_queue.
        message_queue mq(open_or_create               //only create
                , msg_name         //name
                , MESSAGE_NUM                       //max message number
                , sizeof(test_datas)               //max message size
        );

        test_datas datas {};
        for (int i = 0 ; i < 100 ; ++i) {
            sprintf_s(datas.name , sizeof(datas.name) , "%s" , "午休啊");
            sprintf_s(datas.sender , sizeof(datas.sender) , "%s" , "许哦住");
            datas.u_member.d_ = 111.3;

//            while (mq.try_send(&datas , sizeof(datas) , 0)) {
            mq.send(&datas , sizeof(test_datas) , 1);
            std::cout << "发送成功:" << i << std::endl;
//            }

            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }

//        char aa[122];
//        std::cin >> aa;

    } catch (interprocess_exception &e) {
        message_queue::remove(msg_name);
        std::cout << e.what() << std::endl;
    }

}

void rec_msgQueue_DIY(const char *name) {
    using namespace boost::interprocess;
    using namespace std;
    try {
//        message_queue mq(open_only , name);
        message_queue mq(open_only , name);
        unsigned int priority;
        message_queue::size_type recvd_size;

        test_datas rec {};
        while (true) {
            mq.timed_receive(&rec , sizeof(test_datas) , recvd_size , priority , boost::date_time::pos_infin);
            cout << rec.name << endl;
            cout << rec.sender << endl;
            cout << rec.u_member.d_ << endl;
        }

//            cout << recvd_size << endl;
//            cout << priority << endl;
        //if (number != i || recvd_size != sizeof(number))
//            message_queue::remove(name);

    } catch (interprocess_exception &e) {
        message_queue::remove(name);
        cout << e.what() << endl;
    }

}

int main_shm(int argc , char **argv) {
//    const char *name = "monika";
    const char *name = "Global\\monika";
//    write_shared_memory(name);
//    read_shared_mem(name);
//

//    write_mem_by_manager(name);

//    read_mem_by_manager(name);

//    std::thread t1(writei_mem_by_manager , name , 34.5);
//    std::thread t2(writei_mem_by_manager , name , 789);
//    std::thread t3(writei_mem_by_manager , name , 895);
//    t1.join();
//    t2.join();
//    t3.join();

//    read_mem_by_manager(name);

//    create_shared_mem_by_win(name);
//    read_shared_mem_win(name);
//    release(name);

//    const char *filename = R"(C:\Projects\artistic_work\inspiration\boost_interprocess\mapped_file.h)";
//    create_file_mapping(filename);
//    read_file_mapping(filename);
//    if (boost::interprocess::file_mapping::remove(filename))
//        std::cout << "释放成功" << std::endl;
//
//    send_message_queue(name);
//    rec_msgQueue(name);

//    send_message_queue_DIY(name);
//    std::thread send(send_message_queue_DIY , name);
//    rec_msgQueue_DIY(name);

//    send.join();
//    if (boost::interprocess::message_queue::remove(name))
//        std::cout << "释放成功" << std::endl;
    std::cout << name << std::endl;

}