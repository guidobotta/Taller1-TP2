#include "res_blocking_queue.h"

ResBlockingQueue::ResBlockingQueue() : isClosed(false) {}

void ResBlockingQueue::push(const Resource* res) {
    std::unique_lock<std::mutex> lk(mux);
    this->resQueue.push(res);
    this->condVar.notify_all();
}

const Resource* ResBlockingQueue::pop() {
    std::unique_lock<std::mutex> lk(mux);

    while (this->resQueue.empty()) {
        if (this->isClosed) {
            return NULL;
        }
        condVar.wait(lk);
    }

    const Resource* element = this->resQueue.front();
    this->resQueue.pop();
    return element;
}

void ResBlockingQueue::close() {
    this->isClosed = true;
    this->condVar.notify_all();
}

bool ResBlockingQueue::isEmpty() {
    std::unique_lock<std::mutex> lk(mux);
    return this->resQueue.empty();
}
