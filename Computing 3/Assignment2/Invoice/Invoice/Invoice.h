//Author: Zachary Krausman
//Filename: Invoice.h
//Date: 9/24/15

#ifndef INVOICE_H_INCLUDED
#define INVOICE_H_INCLUDED

#include <iostream>
#include <string>

using std::string;

class Invoice
{
private:
string partNumber;
string partDescription;
int qty; //quantity being purchased
double pricePer; //price per unity

public:
    Invoice(string partNum,string desc,int invQty,double price);
    double getInvoiceAmount();
    void setPartNumber(string s);
    void setPartDescription(string s);
    void setQty(int s);
    void setPricePer(double s);
    string getPartNumber();
    string getPartDescription();
    int getQty();
    double getPricePer();

};

#endif // INVOICE_H_INCLUDED
