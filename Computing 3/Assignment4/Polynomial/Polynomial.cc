#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <cmath>
#include <typeinfo>
#include "Polynomial.h"
using  std::cout;
using  std::cin;
using  std::endl;
using  std::vector;
using  std::string;
using std::ostream;
using std::sort;

//Term
Term::Term(double c) //constructor with no exponent given, assume it's 1
{
    coefficient = c;
    exponent = 0;
}
Term::Term(double c,double e) //constructor with coefficient and exponent given
{
    coefficient = c;
    exponent = e;
}
void Term::setCoefficient(double arg) //setter for coefficient
{
    coefficient = arg;
}
void Term::setExponent(double arg) //setter for exponent
{
    exponent = arg;
}
double Term::getCoefficient() //getter for coefficient
{
    const double x = coefficient;
    return x;
}
double Term::getExponent() //getter for exponent
{
    return exponent;
}
ostream& operator<<(ostream &os,const Term &p)
{
    if(p.coefficient != 0)
    {
        os << p.coefficient;
        if(p.exponent != 0 && p.exponent != 1)
        {
            os << "x^" << p.exponent;
        }
        else if(p.exponent == 1)
        {
            os << "x";
        }
    }
    return os;
}

//Polynomial


vector<Term> * Polynomial::getPoly()
{
    return &poly;
}
vector<Term>   Polynomial::getPoly2()
{
    return poly;
}

void Polynomial::setPoly(vector<Term> arg)
{
    poly = arg;
}

void Polynomial::addTerm(Term arg)
{
    poly.push_back(arg);
}
void Polynomial::likeTerms() //combine like terms
{
    //vector<Term> newPoly; //will be set to poly at the end
    unsigned int x = poly.size();
    for(unsigned int i = 0; i < x; i++) //go through each entry in the polynomial
    {
        //  cout << "i: " << i << endl;
        double coEff = 0;
        double num = poly[i].getExponent();
        vector<unsigned int> hasNum {i};
        for(unsigned int z = i + 1; z < poly.size(); z++)
        {
            //   cout << "num: " << num << endl;
            //  cout << "poly[z] exponent: " << poly[z].getExponent() << endl;
            if(poly[z].getExponent() == num)
            {
                hasNum.push_back(z);
            }
        }
//        for(unsigned int b = 0; b < hasNum.size(); b++)
//        {
//            cout << "hasNum[" << b << "]: " << hasNum[b] << endl;
//        }

        for(unsigned int y = i; y < hasNum.size(); y++)
        {
            //  cout << "testing: " << poly[hasNum[y]].getCoefficient() << endl;
            // cout << "testing2: " << coEff << endl;
            coEff = poly[hasNum[y]].getCoefficient() + coEff;
        }
        if(hasNum.size() > 1)
        {
            for(signed int t = hasNum.size() - 1; t > -1; t--)
            {
                poly.erase(poly.begin() + hasNum[t]);
                x = x - 1;
            }

            //  cout << "coeff: " << coEff << " exp: " << num << endl;
            Term temp(coEff,num);
            this->addTerm(temp);
            i = i - 1;
            // cout << *this << endl;
        }
        // cout << "*****: " << *this;
        x = poly.size();
    }

}
void Polynomial::combine(Polynomial p1,Polynomial p2)
{
    //Polynomial temp;
    vector<Term> t1 = p1.getPoly2(),t2 = p2.getPoly2();
    for(unsigned int i = 0; i < t1.size(); i++)
    {
        poly.push_back(t1[i]);
    }
    for(unsigned int t = 0; t < t2.size(); t++)
    {
        poly.push_back(t2[t]);
    }
}
void Polynomial::sortPoly()
{
    sort(poly.begin(),poly.end(),isGreater);
}

bool isGreater(Term a,Term b)
{
    return (a.getExponent() > b.getExponent());
}

Polynomial operator+(const Polynomial &a,const Polynomial &b)
{
    Polynomial temp;
    temp.combine(a,b);
    temp.likeTerms();
    temp.sortPoly();
    return temp;
}

Polynomial& Polynomial::operator+=(const Polynomial &rhs)
{
    Polynomial temp;
    temp.combine(*this,rhs);
    temp.likeTerms();
    temp.sortPoly();
    *this = temp;
    return *this;
}
Polynomial operator-(const Polynomial &a,const Polynomial &b)
{
    Polynomial tempPol,tempPol2;
    tempPol = b;
    for(size_t i = 0; i < tempPol.poly.size(); i++)
    {
        tempPol.poly[i].setCoefficient(tempPol.poly[i].getCoefficient() * -1);
    }
    tempPol2.combine(a,tempPol);
    tempPol2.likeTerms();
    tempPol2.sortPoly();
    return tempPol2;
}
Polynomial& Polynomial::operator-=(const Polynomial &rhs)
{
    Polynomial tempPol,tempPol2;
    tempPol = rhs;
    for(size_t i = 0; i < tempPol.poly.size(); i++)
    {
        tempPol.poly[i].setCoefficient(tempPol.poly[i].getCoefficient() * -1);
    }
    tempPol2.combine(*this,tempPol);
    tempPol2.likeTerms();
    tempPol2.sortPoly();
    *this = tempPol2;
    return *this;
}

Polynomial operator*(const Polynomial &a,const Polynomial &b)
{
    Polynomial temp = a,temp2 = b,temp3,temp4;
    double x,y,exp,coeff;
    temp.sortPoly();
    temp2.sortPoly();
    temp.likeTerms();
    temp2.likeTerms();
    //cout << "capacity: " << temp3.poly.capacity();
    //cout << "Temp: " << temp;
    //cout << "Temp2: " << temp2;
    if(temp.poly.size() > temp2.poly.size())
    {
        //cout << "here 2" << endl;
        y = temp.poly.size();
        x = temp2.poly.size();
        for(size_t i = 0; i < x; i++)
        {
            for(size_t j = 0; j < y; j++)
            {
                exp = temp2.poly[i].getExponent() + temp.poly[j].getExponent();
                // cout << endl << "exp: " << exp << endl;
                coeff = temp2.poly[i].getCoefficient() * temp.poly[j].getCoefficient();
                // cout << endl << "coeff: " << coeff << endl;
                Term tempT(coeff,exp);
                temp3.addTerm(tempT);
                //cout << temp3 << endl;
            }
        }
        temp4 = temp3;
        temp4.likeTerms();
        temp4.sortPoly();
    }
    else
    {
        //cout << "here 1" << endl;;
        x = temp.poly.size();
        y = temp2.poly.size();
        for(size_t i = 0; i < x; i++)
        {
            for(size_t j = 0; j < y; j++)
            {
                exp = temp.poly[i].getExponent() + temp2.poly[j].getExponent();
                // cout << endl << "exp: " << exp << endl;
                coeff = temp.poly[i].getCoefficient() * temp2.poly[j].getCoefficient();
                // cout << endl << "coeff: " << coeff << endl;
                Term tempT(coeff,exp);
                temp3.addTerm(tempT);
                //cout << temp3 << endl;
            }
        }
        temp4 = temp3;
        temp4.likeTerms();
        temp4.sortPoly();
    }
    //cout << "x: " << x << endl;
    //cout << "y: " << y << endl;

    return temp4;
}
Polynomial Polynomial::operator*=(const Polynomial &rhs)
{
    Polynomial temp = *this,temp2 = rhs,temp3,temp4;
    double x,y,exp,coeff;
    temp.sortPoly();
    temp2.sortPoly();
    temp.likeTerms();
    temp2.likeTerms();
    //cout << "capacity: " << temp3.poly.capacity();
    //cout << "Temp: " << temp;
    //cout << "Temp2: " << temp2;
    if(temp.poly.size() > temp2.poly.size())
    {
        //cout << "here 2" << endl;
        y = temp.poly.size();
        x = temp2.poly.size();
        for(size_t i = 0; i < x; i++)
        {
            for(size_t j = 0; j < y; j++)
            {
                exp = temp2.poly[i].getExponent() + temp.poly[j].getExponent();
                // cout << endl << "exp: " << exp << endl;
                coeff = temp2.poly[i].getCoefficient() * temp.poly[j].getCoefficient();
                // cout << endl << "coeff: " << coeff << endl;
                Term tempT(coeff,exp);
                temp3.addTerm(tempT);
                //cout << temp3 << endl;
            }
        }
        temp4 = temp3;
        temp4.likeTerms();
        temp4.sortPoly();
        *this = temp4;
    }
    else
    {
        //cout << "here 1" << endl;;
        x = temp.poly.size();
        y = temp2.poly.size();
        for(size_t i = 0; i < x; i++)
        {
            for(size_t j = 0; j < y; j++)
            {
                exp = temp.poly[i].getExponent() + temp2.poly[j].getExponent();
                // cout << endl << "exp: " << exp << endl;
                coeff = temp.poly[i].getCoefficient() * temp2.poly[j].getCoefficient();
                // cout << endl << "coeff: " << coeff << endl;
                Term tempT(coeff,exp);
                temp3.addTerm(tempT);
                //cout << temp3 << endl;
            }
        }
        temp4 = temp3;
        temp4.likeTerms();
        temp4.sortPoly();
        *this = temp4;
    }
    //cout << "x: " << x << endl;
    //cout << "y: " << y << endl;

    return *this;
}


ostream& operator<<(ostream &os,Polynomial &p)
{
    for(unsigned int i = 0; i < p.poly.size(); i++)
    {
        if(i == p.poly.size() - 1)
        {
            if((p.poly[i]).getCoefficient() < 0)
            {
                cout << "(" << p.poly[i] << ")";
            }
            else
            {
                cout << p.poly[i];
            }
        }
        else
        {
            if((p.poly[i]).getCoefficient() < 0)
            {
                cout << "(" << p.poly[i] << ")" << " + ";
            }
            else if(p.poly[i].getCoefficient() != 0)
            {
                cout << p.poly[i] << " + ";
            }
            else
            {
                cout << "0";
            }

        }
    }
    return os;
}
