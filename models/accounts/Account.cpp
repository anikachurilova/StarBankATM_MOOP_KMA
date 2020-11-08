#include "Account.h"

Account::Account(size_t userId, string cardNumber, string pin, string cvv, double sumOnBalance, size_t limit,
                 string expiryDate, bool isBlocked):_userId(userId), _cardNumber(cardNumber), _pin(pin),
                 _cvvNumber(cvv), _sumOnBalance(sumOnBalance), _limit(limit), _expiryDate(expiryDate), _isBocked(isBlocked){}

Account::~Account() {}

size_t&  Account::userId(){
    return _userId;
}
string&  Account::cardNumber(){
    return _cardNumber;
}
string&  Account::pin(){
    return _pin;
}

string& Account::expiryDate(){
    return _expiryDate;
}

string&  Account::cvvNumber(){
    return _cvvNumber;
}
double&  Account::sumOnBalance(){
    return _sumOnBalance;
}
size_t&  Account::limit(){
    return _limit;
}

bool Account::isBlocked(){
    return _isBocked;
}

const size_t&  Account::userId() const{
    return _userId;
}
const string&  Account::cardNumber() const{
    return _cardNumber;
}
const string&  Account::pin() const{
    return _pin;
}

const string& Account::expiryDate() const{
    return _expiryDate;
}

const string&  Account::cvvNumber() const{
    return _cvvNumber;
}
const double&  Account::sumOnBalance() const{
    return _sumOnBalance;
}
const size_t&  Account::limit() const{
    return _limit;
}

const bool Account::isBlocked() const{
    return _isBocked;
}

ostream& operator<<(ostream& os, const Account& acc){
    os << "userID" << acc.userId() << ", cardNumber" << acc.cardNumber() << ", isBlocked? : " << acc.isBlocked() << ", ExpDate: " << acc.expiryDate() << endl;
    return os;
}