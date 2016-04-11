// "Copyright 2016 <Zachary Krausman>"
#include "guitar_string_class.hpp"
#include <math.h>
#include <iostream>
#include <vector>

namespace GuitarHero {

class RandSeed {
 public:
    explicit RandSeed(int x): seed(x) {}
    int operator()() {
        srand(seed);
        return (rand_r(&seed) % 65535) - 32767;
    }
 private:
    unsigned int seed;
};



GuitarString::GuitarString(double frequency)
: rb(ceil(44100/frequency)), ticCount(0) {
    for (int i = 0; i < ceil(44100/frequency); i++) {
        rb.push_back(0);
    }
}
GuitarString::GuitarString(const std::vector<sf::Int16> & init)
: rb(init.size()), ticCount(0) {
    for (int i = 0; i < init.size(); i++) {
        rb.push_back(init[i]);
    }
}

void GuitarString::pluck() {
    RandSeed x(rb.size());
    std::generate(rb.begin(), rb.end(), x);
}

void GuitarString::tic() {
    int add = rb.front();
    rb.pop_front();
    add = (0.5) * (add + rb.front()) * (0.996);
    rb.push_back(add);
    ticCount = ticCount + 1;
}

sf::Int16 GuitarString::sample() {
    return rb.front();
}

int GuitarString::time() {
    return ticCount;
}

}  // namespace GuitarHero

