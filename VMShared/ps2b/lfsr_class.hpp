/**
 *  @file    lfsr_class.hpp
 *  @author  Zachary Krausman
 *  @date    2/14/16
 *  @version 1.0
 *  @copyright 2016
 *  @brief Assignment 2-a-a
 *
 *  @section DESCRIPTION
 *
 *  Linear feedback shift register.
 *
 */


#ifndef LSFR_HPP_INCLUDED
#define LSFR_HPP_INCLUDED

#include <stdlib.h>
#include <cstring>
#include <vector>
#include <iostream>

using std::vector;
using std::ostream;

/**
*  @brief Class for linear feedback shift register
*/

class LFSR {
 public:
    /**
    *   @brief  Constructor
    *
    *   @param  seed is a character array which
    *   @param  t is an integer
    *   @return nothing
    */
    LFSR(const char* seed, const int t);
    /**
    *   @brief  simulate one step
    *
    *   @return the new bit as 0 or 1
    */
    int step();
    /**
    *   @brief simulate k steps and return k-bit integer
    *
    *   @param  k is the number of steps and the number of bits the integer should be
    *   @return returns k-bit integer
    */
    int generate(const int k);

    friend ostream& operator << (ostream &out, LFSR &lfsr);

 private:
    /**
    *   @brief  Copy constructor -- want to make non-copyable
    *
    *   @return nothing
    */
    explicit LFSR(const LFSR& other);
    /**
    *   @brief  Overloaded assignment operator -- want to make non-copyable
    *
    *   @param  LFSR is the object you want to copy
    *   @return copied LFSR object
    */
    LFSR& operator=(const LFSR&);

 protected:
    vector<int> registers_;  ///< vector of integers
    int tap_;
};


#endif  // LSFR_HPP_INCLUDED

