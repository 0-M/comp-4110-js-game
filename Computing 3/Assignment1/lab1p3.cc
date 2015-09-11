//Author: Zachary Krausman
//Filename: lab1p3
//Date: 9/6/15

#include <iostream>
#include <cstdlib>
#include <cmath>

using  std::cout;
using  std::cin;
using  std::endl;
using  std::abs;
long long factorial(int num) //works for any number one through 20, any more is over a 64 bit integer
{
    long long fact = num; //holds the resulting factorial -- initially set to given number
    for(int i = num - 1; i > 0; i--)
    {
        fact = fact * (i);
    }
    return fact;
}

int main()
{
    int num = 0; //user input number
    long long res = 0; //result
    cout << "Please input an number, it will be turned into a positive integer: ";
    cin >> num;
    num = abs(num);
    res = factorial(num);
    cout << "The factorial of " << num << " is " << res << endl;
    return 0;
}


