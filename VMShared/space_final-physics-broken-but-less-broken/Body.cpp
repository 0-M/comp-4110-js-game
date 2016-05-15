// Copyright 2016 Zachary Krausman and Daniel MacMillan
#include <string>
#include "space.hpp"

namespace space {
Body::Body(double x_velocity, double y_velocity, double ux_velocity,
           double uy_velocity, double mass, double x, double y, double ux,
           double uy, std::string file_name) : SpaceObject(x_velocity,
                       y_velocity, ux_velocity, uy_velocity, mass,
                       x, y, ux, uy) {
    texture_.loadFromFile(file_name);
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
}
void Body::step(double seconds) {
    if(x_ > 400 && y_ <= 400) {
        x_ = x_ + (x_velocity_ * seconds * 2);
        y_ = y_ - (y_velocity_ * seconds / 2);
    }
//    if(x_ < 400 && y_ <= 400) {
//        x_ = x_ + (x_velocity_ * seconds * 2);
//        y_ = y_ - (-1 * y_velocity_ * seconds * 2);
//    }
//    if(x_ < 400 && y_ < 400) {
//        x_ = x_ + (x_velocity_ * seconds * 2);
//        y_ = y_ + (y_velocity_ * seconds / 2);
//    }
//    if(x_ < 400 && y_ < 400) {
//        x_ = x_ - (x_velocity_ * seconds * 2);
//        y_ = y_ + (y_velocity_ * seconds / 2);
//    }
//    if(x_ < 400 && y_ > 400) {
//        x_ = x_ - (x_velocity_ * seconds * 2);
//        y_ = y_ + (y_velocity_ * seconds / 2);
//    }



    //std::cout << x_velocity_ << "m/s " << y_velocity_ << "m/s " << seconds <<
              //std::endl;
   // std::cout << "X: " << x_ << " Y: " << y_ << std::endl;
    sprite_.setPosition(sf::Vector2f(x_, y_));
}
void Body::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite_);
}


}  // namespace space
