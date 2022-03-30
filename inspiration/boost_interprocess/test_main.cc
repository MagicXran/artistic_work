//
// Created by Administrator on 29/03/2022.
//

#include "thread"
#include <iostream>
#include <fstream>
//#include <boost/interprocess/ipc/message_queue.hpp>
//#include "boost_interprocess/messages_queue.h"
#include "boost_interprocess/file_mapped.hpp"
#include "boost_interprocess/mapped_file.h"

void test_queue() {
    //    const char *name = "Global\\monika";
    const char *name = "monika";
//    char name[] = "monika";

//    MessageQueues::sendMsg(name);

//    MessageQueues::recMsg(name);
//    std::cout << "main=" << std::this_thread::get_id() << std::endl;

//    std::thread t1([=] {
//        using namespace boost::interprocess;
//        BOOST_TRY {
//                //Open a message queue.
//                message_queue mq(open_only        //only open
//                        , name //name
//                );
//
//                unsigned int priority;
//                message_queue::size_type recvd_size;
//
//                //Receive 100 numbers
//                for (int i = 0 ; i < 25 ; ++i) {
//                    int number;
//                    mq.receive(&number , sizeof(number) , recvd_size , priority);
//
//                    if (number != i || recvd_size != sizeof(number))
//
//                        std::cout << std::this_thread::get_id() << " , priority: " << priority << " ,recvd_size: "
//                                  << recvd_size << " ,number: " << number << std::endl;
//                }
//            } BOOST_CATCH(interprocess_exception &ex) {
//                message_queue::remove("message_queue");
//                std::cout << ex.what() << std::endl;
//            }BOOST_CATCH_END
//    });
//    std::cout << "t1 id=" << t1.get_id() << std::endl;

//    boost::interprocess::message_queue::remove(name);
//    t1.join();
}

void test_file_mapping() {
    std::cout << sizeof(CSU) << std::endl;
    const char *file = "C:\\Projects\\artistic_work\\inspiration\\boost_interprocess\\mapped_file.h";
    MappingFile::mapping(file);
}

int main(int argc , char **argv) {
    test_file_mapping();
}

int main22(int argc , char *argv[]) {
    using namespace boost::interprocess;

    //Define file names
//    const char *FileName = R"(C:\Projects\artistic_work\inspiration\boost_interprocess\mapped_file.h)";
//    const char *FileName = "C:\\Projects\\artistic_work\\inspiration\\boost_interprocess\\file.txt";

    const char *FileName = "file.bin";
    const std::size_t FileSize = 281;

    if (argc == 1) { //Parent process executes this
        {  //Create a file
            file_mapping::remove(FileName);
            std::filebuf fbuf;
            fbuf.open(FileName , std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
            //Set the size
            fbuf.pubseekoff(FileSize - 1 , std::ios_base::beg);
//            fbuf.sputc(3);
            fbuf.sputn("world" , 6);
        }

        //Remove on exit
        struct file_remove {
            explicit file_remove(const char *FileName) : FileName_(FileName) {}

            ~file_remove() { file_mapping::remove(FileName_); }

            const char *FileName_;
        } remover(FileName);

        //Create a file mapping
        file_mapping m_file(FileName , read_write);

        //Map the whole file with read-write permissions in this process
        mapped_region region(m_file , read_write);

        //Get the address of the mapped region
        void *addr = region.get_address();
        std::size_t size = region.get_size();

        //Write all the memory to 1
        std::memset(addr , 1 , size);

        //Launch child process
        std::string s(argv[0]);
        s += " child ";
        if (0 != std::system(s.c_str()))
            return 1;
    } else {  //Child process executes this
        {  //Open the file mapping and map it as read-only
            file_mapping m_file(FileName , read_only);

            mapped_region region(m_file , read_only);

            //Get the address of the mapped region
            void *addr = region.get_address();
            std::size_t size = region.get_size();

            //Check that memory was initialized to 1
            const char *mem = static_cast<char *>(addr);
            for (std::size_t i = 0 ; i < size ; ++i)
                if (*mem++ != 1)
                    return 1;   //Error checking memory
        }
        {  //Now test it reading the file
            std::filebuf fbuf;
            fbuf.open(FileName , std::ios_base::in);

            //Read it to memory
            std::vector<char> vect(FileSize , 0);
            fbuf.sgetn(&vect[0] , std::streamsize(vect.size()));

            //Check that memory was initialized to 1
            const char *mem = static_cast<char *>(&vect[0]);
            for (std::size_t i = 0 ; i < FileSize ; ++i)
                std::cout << *mem++ << std::endl;
//                if (*mem++ != 1)
//                    return 1;   //Error checking memory
        }
    }

    return 0;
}