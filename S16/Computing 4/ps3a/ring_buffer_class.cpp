#ifndef RING_BUFFER_CLASS_CPP_INCLUDED
#define RING_BUFFER_CLASS_CPP_INCLUDED
#include "ring_buffer_class.hpp"

namespace ringbuffer {
template <typename T,int N>
ringBuffer<T,N>::ringBuffer() : capacity_(N), begin_(0),size_(0) {
    buffer_ = new T[N];
}

template <typename T,int N>
void ringBuffer<T,N>::push_back(const T &element) {
    try {
        buffer_[(begin_+size_)% capacity_] = element;
        size_ = size_ + 1;
    } catch(const std::runtime_error &e) {
        std::cout << "Ring is full, can't add" << std::endl;
    }

}

template <typename T,int N>
void ringBuffer<T,N>::pop_front() {
    try {
        size_ = size_ - 1;
        if(begin_ == capacity_) {
            begin_ = 0;
        } else {
            begin_ = begin_ + 1;
        }
    } catch(const std::runtime_error &e) {
        std::cout << "Ring is empty, can't check" << std::endl;
    }
}

template <typename T,int N>
ringBuffer<T,N>::~ringBuffer() {
    delete[] buffer_;
}

template <typename T,int N>
bool ringBuffer<T,N>::isEmpty() {
    if (size_ == 0 || capacity_ == 0) {
        return 1;
    }
    return 0;
}

template <typename T,int N>
bool ringBuffer<T,N>::isFull() {
    if(size_ == capacity_) {
        return 1;
    }
    return 0;
}
}
#endif // RING_BUFFER_CLASS_CPP_INCLUDED
