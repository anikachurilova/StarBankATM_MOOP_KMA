#pragma once
#include <string>
#include <iostream>
#include "User.h"

using namespace std;
class AccountOld
{
private:
    User _owner;
    string _cardnumber;
    string _PIN;
    bool _blocked;
    int _limit;
    int _balance;

public:

    Account(const User&, const string&, const string&, const bool, const int, const int);
    ~Account();

    void increase(const int);
    void decrease(const int);

    const User getUser() const {
        return _owner;
    }

    int getLimit()const { return _limit; }
    int getBalance()const { return _balance; }
    void setLimit(const int);
    string getCardNumber() const { return _cardnumber; }
    string getPin() const { return _PIN; }
    bool isBlocked() const { return _blocked; }
};

ostream& operator<<(ostream&, const Account&);



