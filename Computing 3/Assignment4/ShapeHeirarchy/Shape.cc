#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
#include <typeinfo>
#include "Shape.h"
using  std::cout;
using  std::cin;
using  std::endl;
using  std::vector;
using  std::string;
const double PI = 3.14159;

// Point2d
Point2d::Point2d() //default constructor
{
    x = 0;
    y = 0;
}
Point2d::Point2d(double argX,double argY)//constructor with coords given
{
    x = argX;
    y = argY;
}
void Point2d::setX(double arg) // setter for x
{
    x = arg;
}
void Point2d::setY(double arg) // setter for y
{
    y = arg;
}
double Point2d::getX() // getter for x
{
    return x;
}
double Point2d::getY() // getter for y
{
    return y;
}
ostream &operator<<(ostream &os,const Point2d &p)
{
    os << "X: " << p.x << " Y:" << p.y << endl;
    return os;
}

// Point3d
Point3d::Point3d() //default constructor
{
    x = 0;
    y = 0;
    z = 0;
}
Point3d::Point3d(double argX,double argY,double argZ) : Point2d(argX,argY) //constructor with coords given
{
    z = argZ;
}
void Point3d::setZ(double arg) //setter for z
{
    z = arg;
}
double Point3d::getZ() // getter for z
{
    return z;
}
ostream &operator<<(ostream &os,const Point3d &p)
{
    os << "X: " << p.x << " Y:" << p.y << " Z: " << p.z << endl;
    return os;
}

// Shape
Shape::Shape() //default constructor
{
    name = "Shape";
}
Shape::Shape(string argName) : type(0) //constructor with name given
{
    name = argName;
}
string Shape::getName() //getter for name
{
    return name;
}
int Shape::getType()
{
    return type;
}

//Shape 2d
Shape2d::Shape2d(string name) : Shape(name) //constructor with name for shape
{
    type = 1;
// doesn't do anything
}
//Shape 3d
Shape3d::Shape3d(string name) : Shape(name) //constructor with name for shape
{
    type = 2;
//doesn't do anything
}


//Circle
Circle::Circle(double x,double y,double r) : Shape2d("Circle")
{
    dimensions.resize(1);
    dimensions[0].setX(x);
    dimensions[0].setY(y);
    radius = r;

}
double Circle::getRadius()
{
    return radius;
}
double Circle::getArea()
{
    double area;
    area = PI * pow(radius,2); //uses 3.14159 for pi
    return area;
}

//Square
Square::Square(double *arr) : Shape2d("Square") //constructor will all the points
{
    dimensions.resize(4);
    int z = 0;
    for(int i = 0; i < 4; i++)
    {
        dimensions[i].setX(arr[z]);
        dimensions[i].setY(arr[z + 1]);
        z = z + 2;
    }
    length = fabs(dimensions[0].getX() - dimensions[3].getX());
    width = fabs(dimensions[0].getY() - dimensions[1].getY());
}
double Square::getLength()
{
    return length;
}
double Square::getWidth()
{
    return width;
}
double Square::getArea()
{
    double area;
    area = length * width;
    return area;
}

//Triangle
Triangle::Triangle(double *arr) : Shape2d("Triangle") //constructor with all the points
{
    dimensions.resize(3);
    int z = 0;
    for(int i = 0; i < 3; i++)
    {
        dimensions[i].setX(arr[z]);
        dimensions[i].setY(arr[z + 1]);
        z = z + 2;
    }
}
Triangle::Triangle(Point3d a,Point3d b,Point3d c) : Shape2d("Triangle")
{
    dimensions.resize(3);
    dimensions[0].setX(a.getX());
    dimensions[0].setY(a.getY());
    dimensions[1].setX(b.getX());
    dimensions[1].setY(b.getY());
    dimensions[2].setX(c.getX());
    dimensions[2].setY(c.getY());
}

double Triangle::getArea()
{
    double area,p1,p2,p3;
    p1 = dimensions[0].getX() * (dimensions[1].getY() - dimensions[2].getY());
    p2 = dimensions[1].getX() * (dimensions[2].getY() - dimensions[0].getY());
    p3 = dimensions[2].getX() * (dimensions[0].getY() - dimensions[1].getY());
    area = fabs((p1 + p2 + p3)/2);
    return area;
}

//Sphere
Sphere::Sphere(double x,double y,double z,double r) : Shape3d("Sphere")
{
    dimensions.resize(1);
    dimensions[0].setX(x);
    dimensions[0].setY(y);
    dimensions[0].setZ(z);
    radius = r;
}
double Sphere::getRadius() //returns radius
{
    return radius;
}
double Sphere::getArea()
{
    double area;
    area = (4 * PI * pow(radius,2));
    return area;
}
double Sphere::getVolume()
{
    double volume;
    volume = (PI * pow(radius,3) * 4)/3;
    return volume;
}

//Cube
Cube::Cube(double *arr) : Shape3d("Cube")
{
    dimensions.resize(8);
    int z = 0;
    for(int i = 0; i < 8; i++)
    {
        dimensions[i].setX(arr[z]);
        dimensions[i].setY(arr[z+1]);
        dimensions[i].setZ(arr[z+2]);
        z = z + 3;
    }
    edge = fabs(dimensions[0].getX() - dimensions[3].getX());
}
double Cube::getEdge()
{
    return edge;
}
double Cube::getArea()
{
    double area;
    area = (6 * pow(edge,2));
    return area;
}
double Cube::getVolume()
{
    double volume;
    volume = pow(edge,3);
    return volume;
}

//Tetrahedron
Tetrahedron::Tetrahedron(double *arr) : Shape3d("Tetrahedron")
{
    dimensions.resize(4);
    int z = 0;
    for(int i = 0; i < 4; i++)
    {
        dimensions[i].setX(arr[z]);
        dimensions[i].setY(arr[z+1]);
        dimensions[i].setZ(arr[z+2]);
        z = z + 3;
    }
}

double heronsF(double x,double y,double z) //Herons formula
{
    double area;
    area = sqrt(((2 * pow(x,2)) * pow(y,2)) + ((2 * pow(x,2)) * pow(z,2)) + ((2 * pow(y,2)) * pow(z,2)) - pow(x,4) - pow(y,4) - pow(z,4))/4;
    return area;
}
double Tetrahedron::getArea()
{
    double area;
    double a,b,c,d,e,f;
    a = sqrt(pow(dimensions[2].getX() - dimensions[0].getX(),2) + pow(dimensions[2].getY() - dimensions[0].getY(),2) + pow(dimensions[2].getZ() - dimensions[0].getZ(),2));
    b = sqrt(pow(dimensions[2].getX() - dimensions[1].getX(),2) + pow(dimensions[2].getY() - dimensions[1].getY(),2) + pow(dimensions[2].getZ() - dimensions[1].getZ(),2));
    c = sqrt(pow(dimensions[1].getX() - dimensions[0].getX(),2) + pow(dimensions[1].getY() - dimensions[0].getY(),2) + pow(dimensions[1].getZ() - dimensions[0].getZ(),2));
    d = sqrt(pow(dimensions[3].getX() - dimensions[1].getX(),2) + pow(dimensions[3].getY() - dimensions[1].getY(),2) + pow(dimensions[3].getZ() - dimensions[1].getZ(),2));
    e = sqrt(pow(dimensions[3].getX() - dimensions[0].getX(),2) + pow(dimensions[3].getY() - dimensions[0].getY(),2) + pow(dimensions[3].getZ() - dimensions[0].getZ(),2));
    f = sqrt(pow(dimensions[3].getX() - dimensions[2].getX(),2) + pow(dimensions[3].getY() - dimensions[2].getY(),2) + pow(dimensions[3].getZ() - dimensions[2].getZ(),2));
    area = heronsF(a,b,c) + heronsF(a,e,f) + heronsF(b,d,f) + heronsF(c,d,e);
    return area;
}
double Tetrahedron::getVolume()
{
    double a,b,c,d,e,f,g,h,i,p,q,r,volume;
    a = dimensions[0].getX();
    b = dimensions[0].getY();
    c = dimensions[0].getZ();
    d = dimensions[1].getX();
    e = dimensions[1].getY();
    f = dimensions[1].getZ();
    g = dimensions[2].getX();
    h = dimensions[2].getY();
    i = dimensions[2].getZ();
    p = dimensions[3].getX();
    q = dimensions[3].getY();
    r = dimensions[3].getZ();
    volume = fabs((((a - p)*(e - q)*(i - r)) + ((d - p)*(h - q)*(c - r)) + ((g - p)*(b - q)*(f - r)) - ((g - p)*(e - q)*(c - r)) - ((a - p)*(h - q)*(f - r)) - ((d - p)*(b - q)*(i - r)))/6.0);
    return volume;
}
