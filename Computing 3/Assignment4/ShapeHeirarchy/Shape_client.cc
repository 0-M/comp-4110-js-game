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
    Circle testCircle(2.84,6.35,7); //[x1,y1,radius]
    double arr[] = {0,0,0,5.5,5.5,5.5,5.5,0}; // [x1,y1,x2,y2,x3,y3,x4,y4]
    Square testSquare(arr);
    double arr2[] = {22,21,7,28,32,15};
    Triangle testTriangle(arr2); // [x1,y1,x2,y2,x3,y3]
    Sphere testSphere(0,0,0,6.3); //[x1,y1,z1,radius]
    double arr3[] = {0,0,0,0,10,0,10,10,0,10,0,0,0,0,10,0,10,10,10,10,10,10,0,10}; // [x1,y1,z1,x2,y2,z2,x3,y3,z3...x8,y8,z8]
    Cube testCube(arr3);
    double arr4[] = {-4,-3,5,2,-1,2,0,-5,0,-2,0,0}; //[x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4]
    //double arr[] = {0,0,0,0,1,1,1,1,0,1,0,1};
    Tetrahedron testTetrahedron(arr4);
    Shape* x[6];
    x[0] = &testCircle;
    x[1] = &testSquare;
    x[2] = &testTriangle;
    x[3] = &testSphere;
    x[4] = &testCube;
    x[5] = &testTetrahedron;
    for(int i = 0; i < 6; i++)
    {
        cout << "Name: " << x[i]->getName() << endl;
        cout << "Area: " << x[i]->getArea() << endl;
        if(x[i]->getType() == 2)
        {
            cout << "Volume: " << x[i]->getVolume() << endl;
        }
        cout << endl << endl;
    }

}
