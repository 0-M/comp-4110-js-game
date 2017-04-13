//Author: Zachary Krausman
//Filename: Account.cc
//Date: 9/24/15

#include "Account.h"
#include <iostream>

using  std::cout;
using  std::cin;
using  std::endl;

Account::Account()
{
    balance = 0;
}

Account::Account(double initBalance)
{
    if(initBalance < 0)
    {
        balance = 0;
        cout << "The inital balance was invalid." << endl;
    }
    else
    {
        balance = initBalance;
    }

}

void Account::credit(double toAdd)
{
    if(toAdd < 0)
    {
        cout << "The amount you tried to add is invalid." << endl;
    }
    else
    {
        balance = balance + toAdd;
    }
}

void Account::debit(double toRemove)
{
    if(toRemove < 0 || (balance < toRemove))
    {
        cout << "The amount you tried to remove is invalid." << endl;
    }
    else
    {
        balance = balance - toRemove;
    }
}

double Account::getBalance()
{
    return balance;
}

double Account::addAccountBalance(Account acc2)
{
    return (balance + acc2.getBalance());
}
