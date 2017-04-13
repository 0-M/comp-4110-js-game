//Author: Zachary Krausman
//Filename: Account.h
//Date: 9/24/15


#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

#include <iostream>

class Account
{

private:
    double balance;

public:
    Account();
    Account(double initBalance);
    void credit(double toAdd);
    void debit(double toRemove);
    double getBalance();
    double addAccountBalance(Account acc2);
};

#endif // ACCOUNT_H_INCLUDED
