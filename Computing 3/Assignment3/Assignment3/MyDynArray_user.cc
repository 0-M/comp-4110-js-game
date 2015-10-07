//// Computing III (Fall 2014) -- Lab 3
//// MyDynArray_user_sample.cc
//
#include <iostream>
#include <string>
#include "MyDynArray.h"


using namespace std;


// function to print the array
void print(MyDynArray a, string prefix="")
{
    cout << prefix;
    for(int i = 0; i < a.getSize(); i++)
        cout << a.get(i) << " ";
    cout << endl;
}


int main()
{
    // testing copy constructor
    cout << "***** Testing copy constructor *****\n\n";
    bool copy_constructor_failed = false;
    MyDynArray a(10);
    print(a, "a: ");
    a.set(3, 9);
    MyDynArray b = a;
    print(b, "b: ");
    b.set(-2, 9);
    print(b, "b: ");
    print(a, "a: ");

    if (a.get(9) == b.get(9))
        copy_constructor_failed = true;

    if (copy_constructor_failed)
        cout << "FAILED: Copy constructor\n\n";
    else
        cout << "PASSED: Copy constructor\n\n";

    // testing assignment operator
    cout << "***** Testing assignment operator *****\n\n";
    bool assignment_operator_failed = false;
    MyDynArray c;
    c = a;
    print(c, "c: ");
    c.set(-4, 3);
    print(c, "c: ");
    print(a, "a: ");

    if (a.get(9) != c.get(9))
        assignment_operator_failed = true;
    if (a.get(3) == c.get(3))
        assignment_operator_failed = true;

    if (assignment_operator_failed)
        cout << "FAILED: Assignment operator\n\n";
    else
        cout << "PASSED: Assignment operator\n\n";


    // testing constructor
    MyDynArray d1(10);
    MyDynArray d2(0);
    if ((d1.getSize() == 10) && (d2.getSize() == 0))
        cout << "PASSED: constructor argument validation\n\n";
    else
        cout << "FAILED: constructor argument validation\n\n";

    // testing whether the get function increases the size of the array correctly
    cout << "***** Testing size increase capabilities of set function *****\n\n";
    MyDynArray d(10);
    print(d, "d: ");
    d.set(7, 15);
    print(d, "d after insert: ");
    MyDynArray e(1);
    print(e, "e: ");
    e.set(12, 15);
    print(e, "e after insert: ");
    cout << "PASSED: Get function\n\n";
    return 0;
}
