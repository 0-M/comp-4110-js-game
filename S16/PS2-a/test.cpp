#include "LFSR.hpp"

int main(int argc, char* argv[])
{
    LFSR lfsr("1110100100100100101001001110010010001110011100101000101010", 33);
    //cout << lfsr;
//    for (int i = 0; i < 20; i++)
//    {
//        int bit = lfsr.step();
//        cout << lfsr << "   " << bit << endl;
//    }
            int bit = lfsr.generate(33);
              cout << lfsr << "   " << bit << endl;
}
