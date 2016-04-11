#ifndef GUITARSTRING_HPP_INCLUDED
#define GUITARSTRING_HPP_INCLUDED


/**
 * @file
 * @copyright
 * @author
 * @date
 * @version
 *
 * @brief
 *
 */
#include <vector>
#include "ring_buffer_class.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <algorithm>

/**
 * @brief namespace for the whole assignment
 */
namespace GuitarHero {

class GuitarString {
public:

    GuitarString(double frequency);
    GuitarString(const std::vector<sf::Int16> & init);

    void pluck();

    void tic();

    sf::Int16 sample();

    int time();

private:
    ring_buffer<sf::Int16> rb;
    int ticCount;


};

}


#endif // GUITARSTRING_HPP_INCLUDED
