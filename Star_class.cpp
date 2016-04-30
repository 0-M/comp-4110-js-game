#include "space.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
namespace space {
    Star::Star(double x, double y, double mass){
    ux_ = x;
    uy_ = y;
    mass_ = mass;
    }
    void Star::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {

    }

}  // namespace space
