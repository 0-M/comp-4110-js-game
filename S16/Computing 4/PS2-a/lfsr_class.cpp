#include "lfsr_class.hpp"


LFSR::LFSR(const char* seed,int t) : tap(t) { //  constructor to create LFSR with the given initial seed and tap
    int temp;
    for(unsigned int i = 0; i < strlen(seed); i++) { //put seed into an array
        temp = seed[i] - '0';
        registers.push_back(temp);
    }
}
int LFSR::step() { //  simulate one step and return the new bit as 0 or 1
    int tapBit = registers[registers.size() - tap - 1],shiftedBit = registers[0],newBit;
    newBit = tapBit ^ shiftedBit;
    registers.erase(registers.begin());
    registers.push_back(tapBit ^ shiftedBit);
    return newBit;
}
int LFSR::generate(int k) { //  simulate k steps and return k-bit integer
    int x = 0;
    for(int i = 0; i < k; i++) {
        int bit = step();
        x = (2 * x) + bit;
    }
    return x;
}

ostream& operator << (ostream& out, LFSR& lfsr) { // overloaded stream insertion operator
    for(unsigned int i = 0; i < lfsr.registers.size(); i++) {
        out << lfsr.registers[i];
    }
    return out;
}

