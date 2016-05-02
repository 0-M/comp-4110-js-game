#include "space.hpp"
//#include <SFML/Graphics.hpp>
#include <stdio.h>

int main(int argc, char* argv[]) {
double t_time,d_t_time;
sscanf(argv[1],"%lf",&t_time);
sscanf(argv[2],"%lf",&d_t_time);
space::Universe y(t_time,d_t_time,"planets.txt",800,800);
y.translateCoordinates();
 sf::RenderWindow window(sf::VideoMode(800, 800), "Universe");
 //space::Body b(2.0,0.0,0.0,0.0,0.0,0,0,0,0,"sun.gif");
 while (window.isOpen())
    {
 sf::Event event;
while(window.pollEvent(event))
{
  if (event.type == sf::Event::Closed)
                window.close();
        }
			  window.clear();
			//  window.draw(b);
			  window.draw(y);
			  window.display();
	}

return 0;
}
