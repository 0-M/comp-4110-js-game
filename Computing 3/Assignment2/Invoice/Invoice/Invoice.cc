//Author: Zachary Krausman
//Filename: Invoice.cc
//Date: 9/24/15


#include "Invoice.h"
#include <iostream>
#include <string>

using  std::cout;
using  std::cin;
using  std::endl;
using  std::string;

Invoice::Invoice(string partNum,string desc,int invQty,double price)
{
    partNumber = partNum;
    partDescription = desc;
    if(invQty < 0)
    {
        cout << "The quantity was invalid!" << endl;
        qty = 0;
    }
    else
    {
        qty = invQty;
    }

    if(price < 0)
    {
        cout << "The price was invalid!" << endl;
        pricePer = 0;
    }
    else
    {
        pricePer = price;
    }

}

double Invoice::getInvoiceAmount()
{
    return (qty * pricePer);
}

void Invoice::setPartNumber(string s)
{
    partNumber = s;
}

void Invoice::setPartDescription(string s)
{
    partDescription = s;
}

void Invoice::setQty(int s)
{
    qty = s;
}

void Invoice::setPricePer(double s)
{
    pricePer = s;
}

string Invoice::getPartNumber()
{
    return partNumber;
}

string Invoice::getPartDescription()
{
    return partDescription;
}

int Invoice::getQty()
{
    return qty;
}

double Invoice::getPricePer()
{
    return pricePer;
}
