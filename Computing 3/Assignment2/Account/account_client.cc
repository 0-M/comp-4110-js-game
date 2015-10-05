//Author: Zachary Krausman
//Filename: account_client.cc
//Date: 9/24/15

#include <iostream>
#include <cstdlib>
#include "Account.h"

using  std::cout;
using  std::cin;
using  std::endl;

int main(int argc, char* argv[])
{
    Account account1;
    Account account2(100);
    double userInput = 0 ;

    cout << "How much would you like to deposit into account one? ";
    cin >> userInput;
    account1.credit(userInput);
    cout << endl << "The balance of account one is " << account1.getBalance() << "." << endl << endl;

    cout << "How much would you like to deposit into account two? ";
    cin >> userInput;
    account2.credit(userInput);
    cout << endl << "The balance of account two is " << account2.getBalance() << "." << endl << endl;

    cout << "How much would you like to withdraw from account one? ";
    cin >> userInput;
    account1.debit(userInput);
    cout << endl << "The balance of account one is " << account1.getBalance() << "." << endl << endl;

    cout << "How much would you like to withdraw from account two? ";
    cin >> userInput;
    account2.debit(userInput);
    cout << endl << "The balance of account two is " << account2.getBalance() << "." << endl << endl;

    cout << "The sum of the balances in accounts one and two is: " << account1.addAccountBalance(account2) << endl;
    return 0;
}
