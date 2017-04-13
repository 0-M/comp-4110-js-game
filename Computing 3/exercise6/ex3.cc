#include <iostream>
#include <cstdlib>

using  std::cout;
using  std::cin;
using  std::endl;


template<class T>
class MyObject2
{
private:
    T num;
public:
    MyObject2(T x)
    {
        num = x;
    }
    T getNum()
    {
        return num;
    }

    void setNum(T x)
    {
        num = x;
    }
};

template<typename T>
T incr(T inp)
{
    return ++inp;
}


int main(int argc, char* argv[])
{
    MyObject2 <double> test(15.5);
    test.setNum(incr(test.getNum()));
    cout << test.getNum() << endl;


}
