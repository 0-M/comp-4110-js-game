/**
 *  @file    ring_buffer_class.hpp
 *  @author  Zachary Krausman
 *  @date    3/2/16
 *  @version 1.0
 *  @copyright 2016
 *  @brief Assignment 2-3-a
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

template <typename T, int N>
class ringBuffer {
 public:
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

    bool isEmpty();
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

}  // namespace ringbuffer
#include "ring_buffer_class.cpp"
#endif  // RING_BUFFER_CLASS_HPP_INCLUDED
