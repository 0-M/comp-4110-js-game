#include "Sierpinski.h"
Sierpinski::Sierpinski(int num,double winSize) {
    n1 = num;
    x1 = winSize/4;
    y1 = winSize/2;
    s1 = winSize/4;
    windSize = winSize;
    sierpinski(n1,x1,y1,s1);
}
void Sierpinski::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::Color bigTriangleColor(sf::Color::White);
    sf::Color bigTriangleFill(sf::Color::White);
    sf::ConvexShape bigTriangle;
    bigTriangle.setPointCount(3);
    bigTriangle.setPoint(0,sf::Vector2f(2,windSize-2));
    bigTriangle.setPoint(1,sf::Vector2f(windSize/2,2));
    bigTriangle.setPoint(2,sf::Vector2f(windSize-2,windSize-2));
    bigTriangle.setFillColor(bigTriangleColor);
    bigTriangle.setOutlineColor(bigTriangleFill);
    bigTriangle.setOutlineThickness(2);
    target.draw(bigTriangle);
    for (unsigned int i = 0; i < triangles.size(); i++) {
        target.draw(triangles[i],states);
    }
}
void Sierpinski::filledTriangle(double x,double y,double s) {
    sf::Color trianglesColor(sf::Color::Black);
    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0,sf::Vector2f(x+1,y));
    triangle.setPoint(1,sf::Vector2f(x+(s*2)-1,y));
    triangle.setPoint(2,sf::Vector2f(x+s,y+2*s-1));
    triangle.setFillColor(trianglesColor);
    triangles.push_back(triangle);
}
void Sierpinski::sierpinski(int n,double x, double y,double s) {
    if(n == 0) {
        return;
    }

    filledTriangle(x,y,s);

    sierpinski(n-1,x+s/2,y-s,s/2); // Top triangle

    sierpinski(n-1,x-s/2,y+s,s/2); // Bottom left triangle

    sierpinski(n-1,x+(s * 1.5),y+s,s/2); // Bottom left triangle

    return;
}
