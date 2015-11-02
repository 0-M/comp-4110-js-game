//Author: Zachary Krausman
//Filename: Shape.cc
//Date: 11/1/15

#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include "Shape.h"

using  std::cout;
using  std::cin;
using  std::endl;


int main(int argc, char* argv[])
{
//    Point3d test(2.84,6.35,7.172);
//    cout << test.getX() << endl;
//    cout << test.getY() << endl;
//    cout << test.getZ() << endl;
//    Circle test(2.84,6.35,7);
//    cout << test.getArea() << endl;
//    double arr[] = {0,0,0,5.5,5.5,5.5,5.5,0}; // [x1,y1,x2,y2,x3,y3,x4,y4]
//    Square test(arr);
//    cout << "Width: " << test.getWidth() << endl;
//    cout << "Length: " << test.getLength() << endl;
//    cout << "Area: " << test.getArea() << endl;
//    double arr[] = {22,21,7,28,32,15};
//    Triangle test(arr); // [x1,y1,x2,y2,x3,y3]
//    cout << "Area: " << test.getArea() << endl;
//    Sphere test(0,0,0,6.3);
//    cout << "Area: " << test.getArea() << endl;
//    cout << "Volume: " << test.getVolume() << endl;
//      double arr[] = {0,0,0,0,10,0,10,10,0,10,0,0,0,0,10,0,10,10,10,10,10,10,0,10}; // [x1,y1,z1,x2,y2,z2,x3,y3,z3...x8,y8,z8]
//      Cube test(arr);
//      cout << "Area: " << test.getArea() << endl;
//      cout << "Volume: " << test.getVolume() << endl;
//      double arr[] = {-4,-3,5,2,-1,2,0,-5,0,-2,0,0};
    //double arr[] = {0,0,0,0,1,1,1,1,0,1,0,1};
    //Tetrahedron test(arr);
    //cout << "Area: " << test.getArea() << endl;
    //cout << "Volume: " << test.getVolume() << endl;
    Shape* x[6];
    Circle test(2.84,6.35,7);
    Point3d test2(2.84,6.35,7.172);
    x[0] = &test;
    cout << typeid(*x[0]).name() << endl;
    cout << x[0]->getArea() << endl;

}
