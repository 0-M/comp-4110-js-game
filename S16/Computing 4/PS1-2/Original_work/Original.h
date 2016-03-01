#ifndef ORIGINAL_H_INCLUDED
#define ORIGINAL_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <vector>

class Original : public sf::Drawable
{
private:
double n1,s1,d1,x1,y1;
std::vector<sf::VertexArray> lineHolder;
public:
    Original(int num,double winSize);
    void shape(double x,double y,double d);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void original(int n,double x,double y,double d);

};


#endif // ORIGINAL_H_INCLUDED
