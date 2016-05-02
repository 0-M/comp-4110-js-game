#include "space.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
namespace space {

Universe::Universe(double total_time, double change_time, std::string file_name,double win_x, double win_y) : total_time_(total_time), change_time_(change_time_), file_name_(file_name),win_x_(win_x),win_y_(win_y) {
std::cin >> number_planets_;
std::cout << number_planets_ << std::endl;
std::cin >> solar_system_size_;
for(int i = 0;i < number_planets_;i++)
{
 std::string temp_fname;
 double un_x_pos,un_y_pos,un_x_vel,un_y_vel,mass_temp;
 std::cin >> un_x_pos >> un_y_pos >> un_x_vel >> un_y_vel >> mass_temp >> temp_fname;
Body temp(0,0,un_x_vel,un_y_vel,mass_temp,0,0,un_x_pos,un_y_pos,temp_fname);
 planets_.push_back(temp);
}
}

void Universe::calcForces() {

}

void Universe::translateCoordinates() {
	for(int i = 0;i < number_planets_;i++)
	{
		std::cout << planets_[i].getUx() << std::endl;
		planets_[i].setX(((planets_[i].getUx() / solar_system_size_) * win_x_/2) + win_x_/2);
		planets_[i].setY(((planets_[i].getUy() / solar_system_size_) * win_y_/2) + win_y_/2);
		planets_[i].setSpritePos(planets_[i].getX(),planets_[i].getY()); 
	}
}

void Universe::monitorTime() {

}

void Universe::updateUniverse() {

}

std::istream& operator >> (std::istream& is, Universe& uni)
{
	is >> uni.temp_;
	return is;
}

void Universe::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for(int i = 0;i < number_planets_;i++)
{
	target.draw(planets_[i]);
}
}

}
