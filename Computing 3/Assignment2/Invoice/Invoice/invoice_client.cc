//Author: Zachary Krausman
//Filename: invoice_client.cc
//Date: 9/24/15
#include <iostream>
#include <cstdlib>
#include <string>
#include <climits>
#include "Invoice.h"

using  std::cout;
using  std::cin;
using  std::endl;
using  std::string;
using  std::getline;

int main(int argc, char* argv[])
{
    Invoice invalidInvoice("3289275","invalid test",-34234,-34234);
    Invoice invoice1("23905821","32oz Waterbottle",17,3.20);
    string input;
    int numInput;
    double numInput2;

    cout << endl << "Part number: " << invalidInvoice.getPartNumber() << endl;
    cout << "Part description: " << invalidInvoice.getPartDescription() << endl;
    cout << "Quantity: " << invalidInvoice.getQty() << endl;
    cout << "Price per unit: " << invalidInvoice.getPricePer() << endl;
    cout << "The total cost of this purchase is: $" << invalidInvoice.getInvoiceAmount() << endl << endl;


    cout << endl << "Part number: " << invoice1.getPartNumber() << endl;
    cout << "Part description: " << invoice1.getPartDescription() << endl;
    cout << "Quantity: " << invoice1.getQty() << endl;
    cout << "Price per unit: " <<invoice1.getPricePer() << endl;
    cout << "The total cost of this purchase is: $" << invoice1.getInvoiceAmount() << endl << endl;
    cout << "What would you like to change the part number to? ";
    getline(cin,input);
    invoice1.setPartNumber(input);
    cout << "What would you like to change the description to? ";
    getline(cin,input);
    invoice1.setPartDescription(input);
    cout << "What would you like to change the quantity to? ";
    cin >> numInput;
    invoice1.setQty(numInput);
    cout << "What would you like to change the price per unit to? ";
    cin >> numInput2;
    invoice1.setPricePer(numInput2);
    cout << endl << "Part number: " << invoice1.getPartNumber() << endl;
    cout << "Part description: " << invoice1.getPartDescription() << endl;
    cout << "Quantity: " << invoice1.getQty() << endl;
    cout << "Price per unit: " <<invoice1.getPricePer() << endl;
    cout << "The total cost of this purchase is: $" << invoice1.getInvoiceAmount() << endl << endl;


}
