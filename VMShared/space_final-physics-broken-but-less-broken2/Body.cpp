// Copyright 2016 Zachary Krausman and Daniel MacMillan
#include <string>
#include "space.hpp"

namespace space {
Body::Body(double x_velocity, double y_velocity, double ux_velocity,
  double uy_velocity, double mass, double x, double y, double ux,
  double uy, std::string gif_name) : SpaceObject(x_velocity,
         y_velocity, ux_velocity, uy_velocity, mass,
         x, y, ux, uy), gif_name_(gif_name) {
  if(!(texture_.loadFromFile(gif_name))) {
    throw("Failed to load texture from file name: ");
    std::cout << gif_name << std::endl;
    exit(1);
  }
  sprite_.setTexture(texture_);
  sprite_.setPosition(sf::Vector2f(x, y));
}
Body::Body(const Body &bSource) {
  texture_ = bSource.texture_;
  sprite_.setTexture(texture_);
  x_ = bSource.x_;
  y_ = bSource.y_;
  ux_ = bSource.ux_;
  uy_ = bSource.uy_;
  x_velocity_ = bSource.x_velocity_;
  y_velocity_ = bSource.y_velocity_;
  ux_velocity_ = bSource.ux_velocity_;
  uy_velocity_ = bSource.uy_velocity_;
  mass_ = bSource.mass_;
  radius_ = bSource.radius_;
  gif_name_ = bSource.gif_name_;
}
void Body::step(double seconds) {
  ux_ = ux_ - (ux_velocity_ * seconds);
  uy_ = uy_ - (uy_velocity_ * seconds);
  //std::cout << "ux_vel: " << ux_velocity_ << std::endl;
 // std::cout << "uy_vel: " << uy_velocity_ << std::endl;

  //sprite_.setPosition(sf::Vector2f(x_, y_));
}
std::string Body::getGifName()
{
        return gif_name_;
}
void Body::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(sprite_);
}

}  // namespace space
