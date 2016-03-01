#include "Original.h"
#include <iostream>
#include <math.h>
Original::Original(int num,double winSize)
{
    n1 = num;
    x1 = winSize/2;
    y1 = winSize/2;
    d1 = winSize/4;
    original(n1,x1,y1,d1);
}
void Original::shape(double x,double y,double d) // draw shaded equilateral triangle with bottom vertex (x, y), side length s
{
    sf::VertexArray lines(sf::Lines,12);

    lines[0].position = sf::Vector2f(x+d,y); //line 1
    lines[0].color = sf::Color::White;
    lines[1].position = sf::Vector2f(x,y);
    lines[1].color = sf::Color::White;

    lines[2].position = sf::Vector2f(x+(d/2),y-((sqrt(3)/2)*d)); //line 2
    lines[2].color = sf::Color::White;
    lines[3].position = sf::Vector2f(x,y);
    lines[3].color = sf::Color::White;

    lines[4].position = sf::Vector2f(x-(d/2),y-((sqrt(3)/2)*d)); //line 3
    lines[4].color = sf::Color::White;
    lines[5].position = sf::Vector2f(x,y);
    lines[5].color = sf::Color::White;

    lines[6].position = sf::Vector2f(x-d,y); //line 4
    lines[6].color = sf::Color::White;
    lines[7].position = sf::Vector2f(x,y);
    lines[7].color = sf::Color::White;

    lines[8].position = sf::Vector2f(x-(d/2),y+((sqrt(3)/2)*d)); //line 5
    lines[8].color = sf::Color::White;
    lines[9].position = sf::Vector2f(x,y);
    lines[9].color = sf::Color::White;

    lines[10].position = sf::Vector2f(x+(d/2),y+((sqrt(3)/2)*d)); //line 6
    lines[10].color = sf::Color::White;
    lines[11].position = sf::Vector2f(x,y);
    lines[11].color = sf::Color::White;

    lineHolder.push_back(lines);



}

void Original::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(unsigned int i = 0; i < lineHolder.size(); i++)
    {
        target.draw(lineHolder[i],states);
    }

}
void Original::original(int n,double x,double y,double d) // draw one triangle, bottom vertex (x, y), side s; recursively call itself three times to generate the next order Sierpinski triangles above, left and right of current triangle. n is the order
{
    if(n == 0)
    {
        return;
    }

    shape(x,y,d);

    original(n-1,x+d/2,y-((sqrt(3)/2)*d),d/3); //line 1

    original(n-1,x+d,y,d/3); //line 2

    original(n-1,x+d/2,y+((sqrt(3)/2)*d),d/3); //line 3

    original(n-1,x-d/2,y+((sqrt(3)/2)*d),d/3); //line 4

    original(n-1,x-d,y,d/3); //line 5

    original(n-1,x-d/2,y-((sqrt(3)/2)*d),d/3); //line 6

}
