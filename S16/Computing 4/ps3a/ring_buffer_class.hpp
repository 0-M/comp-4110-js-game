#ifndef RING_BUFFER_CLASS_HPP_INCLUDED
#define RING_BUFFER_CLASS_HPP_INCLUDED
#include <stdexcept>
#include <iostream>
namespace ringbuffer {

template <typename T,int N>
class ringBuffer {

  public:
    /** @brief constructor, initializes things
     *
     *
     */
    explicit ringBuffer();
    /** @brief
     *
     * @param the element you want to push
     * @return nothing
     *
     */
    void push_back(const T &element);
    /** @brief Effectively removes the front element
     *
     * @return nothing
     *
     */
    void pop_front();
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
    ringBuffer<T,N>& operator=(const ringBuffer<T,N> & rhs);
    T* buffer_; ///< array
    int capacity_; ///< capacity of array
    int begin_; ///< beginning of aray
    int size_; ///< current size of array

};

}
#include "ring_buffer_class.cpp"
#endif // RING_BUFFER_CLASS_HPP_INCLUDED
