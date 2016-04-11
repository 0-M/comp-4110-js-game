/**
 *  @file    ring_buffer_class.hpp
 *  @author  Zachary Krausman
 *  @date    3/2/16
 *  @version 1.0
 *  @copyright 2016
 *  @brief Assignment 3-b
 *
 *  @section RingBuffer class
 *
 *
 *
 */
#ifndef RING_BUFFER_CLASS_HPP_INCLUDED
#define RING_BUFFER_CLASS_HPP_INCLUDED
#include <stdexcept>
#include <iostream>
namespace ringbuffer {
template <typename T, int N> class ringBufferIterator;
template <typename T, int N>
class ringBuffer {
 public:
     friend class ringBufferIterator<T, N>;
     typedef ringBufferIterator<T, N> iterator;
    /** @brief constructor, initializes things
     *
     *
     */
    ringBuffer();
    /** @brief
     *
     * @param the element you want to push
     * @return nothing
     *
     */
    void push_back(const T &element);
    /** @brief Effectively removes the front element
     *
     * @return element removed
     *
     */
    T pop_front();
    /** @brief Returns whether or not the buffer is empty
     * @return boolean on whether or not the array is empty
     *
     */

    bool empty();
    /** @brief Returns whether or not the buffer is full
     * @return boolean on whether or not the buffer is full
     *
     */

    bool isFull();
    /** @brief destructor
     *
     * @return none
     *
     */
    ~ringBuffer();
    int size();
    T& front();
    iterator begin() {return ringBufferIterator<T, N>(this, 0); }
    iterator end() {return ringBufferIterator<T, N>(this,
    (begin_+size_)% capacity_);}

 private:
    /** @brief make class non copyable
    *
    * @param reference to another object of type ring buffer
    * @return none
    *
    */
    explicit ringBuffer(const ringBuffer &x);
    ringBuffer<T, N>& operator=(const ringBuffer<T, N> & rhs);
    T* buffer_;  ///< array
    int capacity_;  ///< capacity of array
    int begin_;  ///< beginning of aray
    int size_;  ///< current size of arrays
};
template<typename T, int N>
class ringBufferIterator : public std::iterator<std::forward_iterator_tag, T> {
    friend class ringBuffer<T, N>;

 public:
T& operator*();
const ringBufferIterator<T, N>& operator++();
bool operator!= (const ringBufferIterator<T, N> & other) const;

 private:
ringBuffer<T, N> *pointee_;
int x_;
bool started_;
ringBufferIterator(ringBuffer<T, N> *pointee, int x)
: pointee_(pointee), x_(x), started_(false) {}
};
template<typename T, int N>
T& ringBufferIterator<T, N>::operator*() {
return pointee_->buffer_[x_];
}
template<typename T, int N>
const ringBufferIterator<T, N>& ringBufferIterator<T, N>::operator++() {
x_ = x_ + 1;
return *this;
}
template<typename T, int N>
bool ringBufferIterator<T, N>::operator!=
(const ringBufferIterator<T, N> & other) const {
    return this->pointee_->buffer_[x_] != other.pointee_->buffer_[x_];
}


}  // namespace ringbuffer
typedef ringbuffer::ringBuffer<int, 0> RB0;
typedef ringbuffer::ringBuffer<int, 1> RB1;
typedef ringbuffer::ringBuffer<int, 2> RB2;
typedef ringbuffer::ringBuffer<int, 3> RB3;
typedef ringbuffer::ringBuffer<int, 4> RB4;
typedef ringbuffer::ringBuffer<int, 10> RB10;
#include "ring_buffer_class.cpp"
#endif  // RING_BUFFER_CLASS_HPP_INCLUDED
