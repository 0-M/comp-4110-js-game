//Author: Zachary Krausman
//Filename: lab1p2
//Date: 9/3/15

#include <iostream> // input/output

int main(int argc, char* argv[]) // argc = # of arguments ~~ argv - contains said arguments
{
    for(int i = 0; i < argc; i++)
    {
        std::cout << i + 1 << ". "<< argv[i] << "\n"; //print out all of the arguments numbered on their own lines
    }
    return 0;
}
