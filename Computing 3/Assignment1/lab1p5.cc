//Author: Zachary Krausman
//Filename: lab1p5
//Date: 9/6/15

#include <iostream>
#include <cstdlib>
#include <cmath>

using  std::cout;
using  std::cin;
using  std::endl;
using  std::abs;

int main()
{
    double base = 0; //holds the base
    double power = 0; //holds the exponent
    double res = 0;
    cout << "Please enter a base: ";
    cin >> base;
    cout << "Please enter an exponent: ";
    cin >> power;
    res = pow(base,power);
    cout << base << " raised to the power of " << power << " is " << res << "." << endl;


    return 0;
}
