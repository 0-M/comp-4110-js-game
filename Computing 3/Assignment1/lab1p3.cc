//Author: Zachary Krausman
//Filename: lab1p3
//Date: 9/6/15

#include <iostream>
#include <cstdlib>
#include <cmath>

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
     std::cout << "Please input an number, it will be turned into a positive integer: ";
    std::cin >> num;
    num = std::abs(num);
    res = factorial(num);
    std::cout << "The factorial of " << num << " is " << res << ".\n";
    return 0;
}


