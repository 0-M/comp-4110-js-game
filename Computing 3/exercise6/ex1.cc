#include <iostream>
#include <cstdlib>

using  std::cout;
using  std::cin;
using  std::endl;

int increment(int x)
{
    return x + 1;
}

int decrement(int x)
{
    return x - 1;
}
int apply(int x,int(*ptr)(int))
{
    return ptr(x);
}
int main(int argc, char* argv[])
{
    int (*fptr)(int);
    fptr = &increment;
    cout << fptr(25) << endl;
    cout << apply(5,fptr) << endl;
    fptr = &decrement;
    cout << fptr(25) << endl;
    cout << apply(5,fptr) << endl;
}
