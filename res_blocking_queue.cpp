#include "res_blocking_queue.h"
#include "empty_exception.h"
#include <utility>

ResBlockingQueue::ResBlockingQueue() : isClosed(false) {}

void ResBlockingQueue::push(const Resource &res) {
    std::unique_lock<std::mutex> lk(mux);
    this->resQueue.emplace(std::move(res));
    this->condVar.notify_all();
}

const Resource ResBlockingQueue::pop() {
    std::unique_lock<std::mutex> lk(mux);

    while (this->resQueue.empty()) {
        if (this->isClosed) {
            throw EmptyException();
        }
        condVar.wait(lk);
    }

    const Resource element(std::move(this->resQueue.front()));
    this->resQueue.pop();
    return std::move(element);
}

void ResBlockingQueue::close() {
    std::unique_lock<std::mutex> lk(mux);
    this->isClosed = true;
    this->condVar.notify_all();
}

bool ResBlockingQueue::isEmpty() {
    std::unique_lock<std::mutex> lk(mux);
    return this->resQueue.empty();
}

ResBlockingQueue::~ResBlockingQueue() {}
