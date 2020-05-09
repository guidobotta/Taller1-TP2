#ifndef __RES_BLOCKING_QUEUE_H__
#define __RES_BLOCKING_QUEUE_H__

#include <condition_variable>
#include <mutex>
#include <queue>
#include "resource.h"

class ResBlockingQueue {
    private:
        std::queue<const Resource*> resQueue;
        std::mutex mux;
        std::condition_variable condVar;
        bool isClosed;

    public:
        ResBlockingQueue();
        void push(const Resource* res);
        const Resource* pop();
        void close();
        bool isEmpty();
};

#endif
