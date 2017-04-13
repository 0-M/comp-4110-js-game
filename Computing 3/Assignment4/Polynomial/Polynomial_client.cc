#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include "Polynomial.h"
#define MACRO \
{\
    Polynomial test;\
    Polynomial test2;\
    Polynomial test3;\
    Term a(4,2),b(3,2),c(-7,0),d(2,3),e(-1,2),f(-4,1),g(2,0); \
    test.addTerm(a); \
    test.addTerm(b); \
    test.addTerm(c);\
    test2.addTerm(d); \
    test2.addTerm(e); \
    test2.addTerm(f); \
    test2.addTerm(g); \
}
using  std::cout;
using  std::cin;
using  std::endl;
using  std::vector;
using  std::string;

void reset(Polynomial *testa,Polynomial *test2a,Polynomial *test3a)
{
    Polynomial test;
    Polynomial test2;
    Polynomial test3;
    Term a(4,2),b(3,2),c(-7,0),d(2,3),e(-1,2),f(-4,1),g(2,0);
    test.addTerm(a);
    test.addTerm(b);
    test.addTerm(c);
    test2.addTerm(d);
    test2.addTerm(e);
    test2.addTerm(f);
    test2.addTerm(g);
    *testa = test;
    *test2a = test2;
    *test3a = test3;
}


int main(int argc, char* argv[])
{
    Polynomial test,test2,test3;
    Term a(4,2),b(3,2),c(-7,0),d(2,3),e(-1,2),f(-4,1),g(2,0);
    test.addTerm(a);
    test.addTerm(b);
    test.addTerm(c);
    test2.addTerm(d);
    test2.addTerm(e);
    test2.addTerm(f);
    test2.addTerm(g);
    cout << "Testing + : [" << test << "] + [" << test2 << "]" << endl << endl;
    test3 = test + test2; //addition
    cout << "Result: " << test3 << endl << endl;
    reset(&test,&test2,&test3);
    cout << "Testing += :  [" << test << "] + [" << test2 << "]" << endl << endl;
    test += test2; //Addition assignment -- test = test + test2
    cout << "Result: " << test << endl << endl;
    reset(&test,&test2,&test3);
    cout << "Testing - :  [" << test << "] - [" << test2 << "]" << endl << endl;
    test3 = test - test2; //subtraction
    cout << "Result: " << test3 << endl << endl;
    reset(&test,&test2,&test3);
    cout << "Testing -=:  [" << test << "] - [" << test2 << "]" << endl << endl;
    test -= test2; //Subtraction assignment -- test = test - test2
    cout << "Result: " << test << endl << endl;
    reset(&test,&test2,&test3);
    cout << "Testing *:  [" << test << "] * [" << test2 << "]" << endl << endl;
    test3 = test2 * test; //Multiplication
    cout << "Result: " << test3 << endl << endl;
    reset(&test,&test2,&test3);
    cout << "Testing *=:  [" << test << "] * [" << test2 << "]" << endl << endl;
    test *= test2; //Multiplication assignment
    cout << "Result: " << test << endl << endl;
    reset(&test,&test2,&test3);
    cout << "Testing =:  [" << test3 << "] = [" << test2 << "]" << endl << endl;
    test3 = test2; //Multiplication assignment
    cout << "Result: " << test3 << endl << endl;






// Things I did to get a hang of vectors and do trials for this assignment
//    vector<int> test {-1,2,-3,4,-5};
//    vector<int> test2;
//test.erase(test.begin() + 1); -- remove the first element from a vector
//cout << test.size() << endl;
//    for (vector<int>::iterator i = test.begin(); i != test.end(); ++i)
//       cout << *i << ' ';
//    for(unsigned int i = 0; i < test.size(); i++)
//    {
//        if(test[i] < 0)
//        {
//            test2.push_back(test[i]);
//            test.erase(test.begin() + i);
//        }
//    }
//    for(unsigned int i = 0; i < test.size(); i++)
//    {
//        if(test[i] < 0)
//        {
//            test2.push_back(test[i]);
//            test.erase(test.begin() + i);
//        }
//    }
//    for(unsigned int i = 0; i < test.size(); i++)
//    {
//        cout << test[i] << ' ';
//    }
//
//    cout << endl;
//
//    for(unsigned int i = 0; i < test2.size(); i++)
//    {
//        cout << test2 [i] << ' ';
//    }
//    for (vector<int>::iterator i = test.begin(); i != test.end(); ++i)
//    {
//        if (*i < 0)
//        {
//            test2.push_back(*i);
//            test.erase(test.begin() + *i);
//        }
//
//    }
//
//    for (vector<int>::const_iterator i = test2.begin(); i != test2.end(); ++i)
//    {
//  cout << *i << ' ';
//    }
//      cout << endl;
//
//    for (vector<int>::iterator i = test.begin(); i != test.end(); ++i)
//    {
//       cout << *i << ' ';
//    }

}
