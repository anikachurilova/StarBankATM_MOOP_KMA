#include "Account.h"

Account::Account(size_t userId, size_t cardNumber, size_t pin, size_t cvv, double sumOnBalance, size_t limit,
                 char *expiryDate, bool isBlocked):_userId(userId), _cardNumber(cardNumber), _pin(pin),
                 _cvvNumber(cvv), _sumOnBalance(sumOnBalance), _limit(limit), _expiryDate(expiryDate), _isBocked(isBlocked){}

Account::~Account() {}

size_t&  Account::userId(){
    return _userId;
}
size_t&  Account::cardNumber(){
    return _cardNumber;
}
size_t&  Account::pin(){
    return _pin;
}

char * Account::expiryDate(){
    return _expiryDate;
}

size_t&  Account::cvvNumber(){
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
const size_t&  Account::cardNumber() const{
    return _cardNumber;
}
const size_t&  Account::pin() const{
    return _pin;
}

const char * Account::expiryDate() const{
    return _expiryDate;
}

const size_t&  Account::cvvNumber() const{
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