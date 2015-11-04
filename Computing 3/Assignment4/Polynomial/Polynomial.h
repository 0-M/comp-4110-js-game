#ifndef POLYNOMIAL_H_INCLUDED
#define POLYNOMIAL_H_INCLUDED
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

class Term //a term -- an array of which will form a polynomial
{
protected:
    double coefficient;
    double exponent;
public:
    Term(double c); //constructor with no exponent given, assume it's 0, the value is just the coefficient
    Term(double c,double e); //constructor with coefficient and exponent given
    void setCoefficient(double arg); //setter for coefficient
    void setExponent(double arg); //setter for exponent
    double getCoefficient(); //getter for coefficient
    double getExponent(); //getter for exponent
    friend ostream& operator<<(ostream &os,const Term &p);
};

class Polynomial //a polynomial
{
protected:
    vector<Term> poly;
public:
    vector<Term> * getPoly();
    vector<Term>   getPoly2();
    void setPoly(vector<Term> arg);
    void addTerm(Term arg); //add a term to the polynomial
    void likeTerms(); //combine like terms
    void combine(Polynomial p1,Polynomial p2);
    void sortPoly();
    friend ostream& operator<<(ostream &os,Polynomial &p);
    friend Polynomial operator+(const Polynomial &a,const Polynomial &b); //a + b
    Polynomial& operator+=(const Polynomial &rhs); // a = a + rhs
    friend Polynomial operator-(const Polynomial &a,const Polynomial &b); //a - b
    Polynomial& operator-=(const Polynomial &rhs); // a = a + rhs
    friend Polynomial operator*(const Polynomial &a,const Polynomial &b); //a * b
    Polynomial operator*=(const Polynomial &rhs);
};

bool isGreater(Term a,Term b);

#endif // POLYNOMIAL_H_INCLUDED

