// Copyright 2016 Zachary Krausman and Daniel MacMillan
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "space.hpp"

namespace space {
Star::Star(double x, double y, double mass, double radius) {
  x_ = x;
  y_ = y;
  radius_ = radius;
  star_.move(x_, y_);
  star_.setPointCount(60);
  col_.r = 252;
  col_.g = 232;
  col_.b = 56;
  star_.setFillColor(col_);
  star_.setRadius(radius_);
}
void Star::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(star_);
}


}  // namespace space
