#include "space.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
namespace space {

Universe::Universe(double total_time, double change_time, std::string file_name) : total_time_(total_time), change_time_(change_time_), file_name_(file_name) {

}

void Universe::calcForces() {

}

void Universe::translateCoordinates() {

}

void Universe::monitorTime() {

}

void Universe::updateUniverse() {

}

std::istream& operator >> (std::istream& is, Universe& uni)
{
	is >> uni.temp_;
	std::cout << uni.temp_;
	return is;
}

void Universe::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}

}
