#include <iostream>
#include <cstdlib>

using  std::cout;
using  std::cin;
using  std::endl;

class MyObject
{
private:
    int num;
public:
    MyObject(int x)
    {
        num = x;
    }
    int getNum()
    {
        return num;
    }

    void setNum(int x)
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
    MyObject test(15);
    test.setNum(incr(test.getNum()));
    cout << test.getNum() << endl;


}
