#include "Sierpinski.h"
int main(int argc, char* argv[]) {
    sf::RenderWindow window(sf::VideoMode(atoi(argv[2]), atoi(argv[2])), "Sierpinski triangle");
    Sierpinski st(atoi(argv[1]),atof(argv[2]));
    while (window.isOpen()) {
        sf::Color backgroundColor(sf::Color::Black);
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(backgroundColor);
        window.draw(st);
        window.display();
    }

    return 0;
}
