#include "Original.h"
int main(int argc, char* argv[])
{
    sf::RenderWindow window(sf::VideoMode(atoi(argv[2]), atoi(argv[2])), "Original work");
    Original recursive(atoi(argv[1]),atof(argv[2]));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(recursive);
        window.display();
    }

    return 0;
}
