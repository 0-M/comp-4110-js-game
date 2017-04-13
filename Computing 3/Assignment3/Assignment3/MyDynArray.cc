#include <iostream>
#include <cstring>
#include <algorithm>
#include "MyDynArray.h"

using  std::cout;
using  std::cin;
using  std::endl;


// constructor; default size is 100 items
MyDynArray::MyDynArray(size_t size_)
{
    cout << "The constructor was called with: " << size_ << endl;
    size = size_;
    array_ptr = new T[size](); //dynamic allocation
}

// get the current array size
size_t MyDynArray::getSize() const
{
    return size;
}

// put the element at the position specified by index
// if the position is out of range, increase the size of array accordingly
bool MyDynArray::set(T element, size_t index)
{

    cout << "Function set() called with element: " << element << " and index: " << index << "." << endl;
    if(index < size) //if space needs to be added to the array
    {
        array_ptr[index] = element;
        return true;
    }
    else
    {
        T *temp_ptr = new T[index + 1]();
        std::copy(array_ptr,array_ptr + size,temp_ptr);
        delete[] array_ptr;
        array_ptr = temp_ptr;
        size = index + 1;
        array_ptr[index] = element;
        return true;
    }

    return false;
}

// get the value at the position specified by index
T MyDynArray::get(size_t index) const
{
    return array_ptr[index];
}

// copy constructor: should do a deep copy
MyDynArray::MyDynArray(const MyDynArray& arg)
{
    cout << "The copy constructor was called. " << endl;
    size = arg.size;
    if(arg.array_ptr)
    {
        array_ptr = new T[size];
        std::copy(arg.array_ptr,arg.array_ptr + size,array_ptr);
    }
    else
    {
        array_ptr = NULL;
    }


}

//// assignment operator: should do a deep copy
MyDynArray& MyDynArray::operator=(const MyDynArray& rhs)
{
    cout << "The assignment operator was called. " << endl;
    if(this == &rhs) //check for self assignment
    {
        return *this;
    }

    if(array_ptr) //deallocate whatever the lhs is holding
    {
        delete[] array_ptr;
    }

    size = rhs.size; //can be shallow copied

    if(rhs.array_ptr)//deep copy
    {
        array_ptr = new T[size]();
    }
    std::copy(rhs.array_ptr,rhs.array_ptr + size,array_ptr);

    return *this;
}

//// destructor
MyDynArray::~MyDynArray()
{
    cout << "The destructor was called. " << endl;
    delete[] array_ptr;
}
