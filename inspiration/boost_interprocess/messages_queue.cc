//
// Created by Administrator on 29/03/2022.
//

#include "messages_queue.h"
#include <boost/interprocess/ipc/message_queue.hpp>
#include <iostream>
#include <thread>

//#define  BOOST_INTERPROCESS_SHARED_DIR_PATH  C:/boost_1_69_0/stage/temp_memory

void MessageQueues::sendMsg(const char *name) {
    using namespace boost::interprocess;
    BOOST_TRY {
            //Erase previous message queue
            message_queue::remove(name);

            //Create a message_queue.
            message_queue mq(create_only               //only create
                    , name           //name
                    , 100                       //max message number
                    , sizeof(int)               //max message size
            );

            //Send 100 numbers
            for (int i = 0 ; i < 100 ; ++i) {
                mq.send(&i , sizeof(i) , 0);
            }
            std::cout << "send success !" << std::endl;
        } BOOST_CATCH(interprocess_exception &ex) {
            std::cout << ex.what() << std::endl;
            std::cout << ex.get_error_code() << std::endl;
            std::cout << ex.get_native_error() << std::endl;
        }BOOST_CATCH_END

}

__attribute__((unused)) bool MessageQueues::recMsg(const char *name) {
    using namespace boost::interprocess;
    BOOST_TRY {
            //Open a message queue.
            message_queue mq(open_only        //only open
                    , name //name
            );

            unsigned int priority;
            message_queue::size_type recvd_size;

            //Receive 100 numbers
            for (int i = 0 ; i < 12 ; ++i) {
                int number;
                mq.receive(&number , sizeof(number) , recvd_size , priority);

                if (number != i || recvd_size != sizeof(number))
                    return false;

                std::cout << std::this_thread::get_id() << " , priority: " << priority << " ,recvd_size: " << recvd_size
                          << " ,number: " << number << std::endl;
//                return true;
            }
        } BOOST_CATCH(interprocess_exception &ex) {
            message_queue::remove("message_queue");
            std::cout << ex.what() << std::endl;
            return false;
        }BOOST_CATCH_END
//    message_queue::remove("message_queue");
}
