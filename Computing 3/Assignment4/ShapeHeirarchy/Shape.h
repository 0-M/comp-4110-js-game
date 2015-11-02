#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
using  std::cout;
using  std::cin;
using  std::endl;
using  std::vector;
using  std::string;
using std::ostream;


class Point2d // [x,y]
{
protected:

    double x;
    double y;

public:
    Point2d(); //default constructor
    Point2d(double argX,double argY); //constructor with coords given
    void setX(double arg); // setter for x
    void setY(double arg); // setter for y
    double getX(); // getter for x
    double getY(); // getter for y
    friend ostream& operator<<(ostream &os,const Point2d &p);

};

class Point3d : public Point2d // [x,y,z]
{
private:

    double z;

public:
    Point3d(); //default constructor
    Point3d(double argX,double argY,double argZ); //constructor with coords given
    void setZ(double arg); //setter for z
    double getZ(); // getter for z
    friend ostream& operator<<(ostream &os,const Point3d &p);
};

class Shape
{
protected:
    string name;
public:
    Shape(); //default constructor
    Shape(string argName); //constructor with name given
    virtual double getArea() = 0;
    string getName(); //getter for name
};

class Shape2d : public Shape
{
protected:
    vector<Point2d> dimensions; //holds the points that make up the shape
public:
    Shape2d(string name); //constructor with name for shape
    virtual double getArea() = 0;
};

class Shape3d : public Shape
{
protected:
    vector<Point3d> dimensions; //holds the points that make up the shape
public:
    Shape3d(string name); //constructor with name for shape
    virtual double getArea() = 0;
    virtual double getVolume() = 0;
};

class Circle : public Shape2d
{
private:
    double radius; //radius of the circle
public:
    Circle(double x,double y,double r); //constructor with origin x,y and circles radius
    double getRadius(); //returns radius
    virtual double getArea();
};

class Square : public Shape2d
{
private:
    double length;
    double width;
public:
    Square(double *arr); //constructor will all the points
    double getLength(); //returns length
    double getWidth(); //returns width
    virtual double getArea();

};

class Triangle : public Shape2d
{
private:

public:
    Triangle(double *arr); //constructor with all the points
    Triangle(Point3d a,Point3d b,Point3d c);
    virtual double getArea();
};

class Sphere : public Shape3d
{
private:
    double radius;
public:
    Sphere(double x,double y,double z,double r);
    double getRadius(); //returns radius
    virtual double getArea();
    virtual double getVolume();
};

class Cube : public Shape3d
{
private:
    double edge;
public:
    Cube(double *arr);
    double getEdge();
    virtual double getArea();
    virtual double getVolume();
};

class Tetrahedron : public Shape3d
{
private:
    //double a,b,c,d;
public:
    Tetrahedron(double *arr);
    double getA(); //returns a
    double getB(); //returns b
    double getC(); //returns c
    double getD(); //returns d
    double heronsFormula(double x,double y,double z);
    virtual double getArea();
    virtual double getVolume();
};
#endif // SHAPE_H_INCLUDED

