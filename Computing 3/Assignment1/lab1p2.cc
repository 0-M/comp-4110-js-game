//Author: Zachary Krausman
//Filename: lab1p2
//Date: 9/3/15

#include <iostream> // input/output

int main(int argc, char* argv[])
{
    for(int i = 1; i < argc; i++)
    {
        std::cout << i << ". "<< argv[i] << "\n";
    }
    return 0;
}
