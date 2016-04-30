#include "space.hpp"

namespace space {

Body::Body(double x_velocity, double y_velocity, double ux_velocity,
  double uy_velocity, double mass, double x, double y, double ux,
  double uy, std::string file_name) : SpaceObject(x_velocity, 
  y_velocity, ux_velocity, uy_velocity, mass,
  x, y, ux, uy) {
  image_.loadFromFile(file_name);

  texture_.loadFromImage(image_);

  sprite_.setTexture(texture_);
  sprite_.setPosition(sf::Vector2f(x, y));
}

void Body::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(sprite_);
}


}  // namespace space


int main(){
  sf::RenderWindow window(sf::VideoMode(400,400), "test");
  
  space::Body b(0.0,0.0,0.0,0.0,0.0, 25.0,25.0, 0.0,0.0, "sun.png");

  while(window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed)
        window.close();
    }
    window.clear();
    window.draw(b);
    window.display();
  }

  return 0;
}
