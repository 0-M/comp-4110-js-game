/* Copyright 2016 Zachary Krausman */
#include "lfsr_class.hpp"

// constructor to create LFSR
LFSR::LFSR(const char* seed, const int t) : tap_(t) {
    int temp;  ///< will be pushed to vector
    for (int i = 0; i < strlen(seed); i++) {
        temp = seed[i] - '0';
        registers_.push_back(temp);
    }
}
int LFSR::step() {
    ///< xor of tap bit and shifted bit
    int newBit = registers_[registers_.size() - tap_ - 1] ^ registers_[0];
    registers_.erase(registers_.begin());
    registers_.push_back(newBit);
    return newBit;
}
int LFSR::generate(const int k) {  //  simulate k steps and return k-bit integer
    int x = 0;  ///< k-bit number to return
    for (int i = 0; i < k; i++) {
        int bit = step();
        x = (2 * x) + bit;
    }
    return x;
}

ostream& operator << (ostream& out, LFSR& lfsr) {  // stream insertion operator
    for (int i = 0; i < lfsr.registers_.size(); i++) {
        out << lfsr.registers_[i];
    }
    return out;
}


