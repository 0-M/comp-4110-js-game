// Copyright 2016 Zachary Krausman and Daniel MacMillan
#include <stdio.h>
#include "space.hpp"

int main(int argc, char* argv[]) {
  double t_time, d_t_time;

  // Font for the time display
  sf::Font font;
  if (!font.loadFromFile("arial.ttf")) {
    std::cout << "no font found" << std::endl;
  }
  sscanf(argv[1], "%lf", &t_time);
  sscanf(argv[2], "%lf", &d_t_time);
  space::Universe y(t_time, d_t_time, "planets.txt", 800, 800);
  y.translateCoordinates();
  // Window begins here
  sf::RenderWindow window(sf::VideoMode(800, 800), "Universe");
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    window.clear();
    window.draw(y);
    y.updateUniverse();
    y.translateCoordinates();
    window.display();
  }

  return 0;
}
