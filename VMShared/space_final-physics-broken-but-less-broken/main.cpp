// Copyright 2016 Zachary Krausman and Daniel MacMillan
#include "space.hpp"
#include <stdio.h>

int main(int argc, char* argv[]) {
    double t_time, d_t_time;
    sf::Font font;
    if(!font.loadFromFile("arial.ttf")) {
        std::cout << "no font found" << std::endl;
    }


    //sf::Text text("test",font);
   // sf::Text text;
   // text.setFont(font);
   // text.setString("test");
   // text.setCharacterSize(24);
   // text.setStyle(sf::Text::Bold);
   // text.setColor(sf::Color::White);
   // text.move(50, 50);
    sscanf(argv[1], "%lf", &t_time);
    sscanf(argv[2], "%lf", &d_t_time);
    space::Universe y(t_time, d_t_time, "planets.txt", 800, 800);
    y.translateCoordinates();
    sf::RenderWindow window(sf::VideoMode(800, 800), "Universe");
    while (window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(y);
      //  window.draw(text);
        y.updateUniverse();
        window.display();
    }

    return 0;
}
