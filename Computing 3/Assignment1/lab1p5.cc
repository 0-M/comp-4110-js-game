//Author: Zachary Krausman
//Filename: lab1p5
//Date: 9/6/15

#include <iostream>
#include <cstdlib>
#include <cmath>

int main()
{
    double base = 0; //holds the base
    double power = 0; //holds the exponent
    double res = 0;
    std::cout << "Please enter a base: ";
    std::cin >> base;
    std::cout << "Please enter an exponent: ";
    std::cin >> power;
    res = pow(base,power);
    std::cout << base << " raised to the power of " << power << " is " << res << ".\n";


    return 0;
}
