/* Copyright 2016 Zachary Krausman */
#ifndef LSFR_HPP_INCLUDED
#define LSFR_HPP_INCLUDED

#include <stdlib.h>
#include <cstring>
#include <vector>
#include <iostream>
using std::vector;
using std::ostream;

class LFSR {
  protected:
    vector<int> registers;
    int tap;
  public:
    LFSR(const char* seed, int t);   // constructor to create LFSR
    int step();  // simulate one step and return the new bit as 0 or 1
    int generate(int k);  // simulate k steps and return k-bit integer
    unsigned int getSize();
    friend ostream& operator << (ostream &out, LFSR &lfsr);
};


#endif  // LSFR_HPP_INCLUDED
