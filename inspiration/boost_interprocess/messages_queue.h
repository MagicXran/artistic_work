//
// Created by Administrator on 29/03/2022.
//

#ifndef INSPIRATION_MESSAGES_QUEUE_H
#define INSPIRATION_MESSAGES_QUEUE_H


class MessageQueues {
public:
    static void  sendMsg(const char* name);

    __attribute__((unused)) static bool  recMsg(const char* name);

};


#endif //INSPIRATION_MESSAGES_QUEUE_H
