#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <stdlib.h>
int main()
{
    srand (time(NULL));
    float x = 250,y = 100,a = 0,b = 0,c = 0;
    sf::RenderWindow window(sf::VideoMode(500, 500), "Zachary Krausman");
    sf::CircleShape shape(100.f);
    shape.setPosition(150,150);
    shape.setFillColor(sf::Color::Green);
    sf::Texture texture;
    if (!texture.loadFromFile("sprite.png", sf::IntRect(0, 0, 25, 25)))
    {
        // error...
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.rotate(45);
    sprite.setPosition(x,y);
    while (window.isOpen())
    {
        sf::Color randCol(a,b,c);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        a = rand() % 256;
        b = rand() % 256;
        c = rand() % 256;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            sprite.move(0,-.01);
            sprite.setColor(randCol);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            sprite.move(0,.01);
            sprite.setColor(randCol);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            sprite.move(-.01,0);
            sprite.setColor(randCol);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            sprite.move(.01,0);
            sprite.setColor(randCol);
        }
        window.draw(shape);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
