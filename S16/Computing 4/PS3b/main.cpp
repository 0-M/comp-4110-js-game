#include "ring_buffer_class.hpp"


int main(int argc, char* argv[])
{
    ringbuffer::ringBuffer<int,5> test;
    test.push_back(5);
    test.push_back(10);
    test.push_back(15);
    test.push_back(20);
    test.push_back(25);
    ringbuffer::ringBuffer<int,5>::iterator begin = test.begin();
    std::cout << *begin << std::endl;
    ++begin;
    std::cout << *begin << std::endl;

}
