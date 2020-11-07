#include <string>
#include <iostream>
#include "../User.h"

using namespace std;
#ifndef STARBANKATM_MOOP_KMA_ACCOUNT_H
#define STARBANKATM_MOOP_KMA_ACCOUNT_H
class Account{
private:
    size_t _userId; //&||*????
    size_t _cardNumber;
    size_t _pin;
    char* _expiryDate; // maybe just date without time? find how to compare DateTime with Date
    size_t _cvvNumber;
    double _sumOnBalance;
    size_t _limit;
    bool _isBocked;

public:
    class BadAmount;
    // class BadAccount;
    class BadPIN;

    Account(size_t userId, size_t cardNumber, size_t pin, size_t cvv, double sumOnBalance, size_t limit, char* expiryDate, bool isBlocked);
    ~Account();

    size_t& userId();
    size_t& cardNumber();
    size_t& pin();
    char * expiryDate();//????
    size_t& cvvNumber();
    double& sumOnBalance();
    size_t& limit();
    bool isBlocked();

    const size_t& userId() const;
    const size_t& cardNumber() const;
    const size_t& pin() const;
    const char* expiryDate() const;//????
    const size_t& cvvNumber() const;
    const double& sumOnBalance() const;
    const size_t& limit() const;
    const bool isBlocked() const;

    virtual void putMoney(double amount) = 0;
    //void blockCard(); // sho delaem tyt?
};
ostream& operator<<(ostream&, const Account&);

class Account::BadAmount
{
private:
    const string _reason;
    const int _number;

public:
    BadAmount(string reason, const int num)
            :_reason(reason), _number(num)
    {
        return;
    }

    ~BadAmount() { }

    void diagnose() const{
        cerr << _reason << endl;
        cerr << ' ' << _number << endl;
    }
};

class Account::BadPIN
{
private:
    const string _reason;

public:
    BadPIN(string& reason)
            :_reason(reason)
    {
        return;
    }

    ~BadPIN() { }

    inline const string& reason() const { return _reason; }
};
#endif //STARBANKATM_MOOP_KMA_ACCOUNT_H
