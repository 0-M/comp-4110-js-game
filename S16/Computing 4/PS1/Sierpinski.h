#ifndef SIERPINSKI_H_INCLUDED
#define SIERPINSKI_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <vector>

class Sierpinski : public sf::Drawable {
  private:
    double n1,x1,y1,s1,windSize;
    std::vector<sf::ConvexShape> triangles;
  public:
    Sierpinski(int num,double winSize);
    void filledTriangle(double x,double y,double s); // draw shaded equilateral triangle with bottom vertex (x, y), side length s
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void sierpinski(int n,double x, double y,double s); // draw one triangle, bottom vertex (x, y), side s; recursively call itself three times to generate the next order Sierpinski triangles above, left and right of current triangle. n is the order

};


#endif // SIERPINSKI_H_INCLUDED
