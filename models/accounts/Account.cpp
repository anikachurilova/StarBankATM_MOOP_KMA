#include "Account.h"

Account::Account(size_t userId, string cardNumber, string pin, string cvv, double sumOnBalance, size_t limit, bool isBlocked ,
                 string expiryDate):_userId(userId), _cardNumber(cardNumber), _pin(pin),
                 _cvvNumber(cvv), _sumOnBalance(sumOnBalance), _limit(limit), _isBocked(isBlocked){

    if(expiryDate.empty()){
        time_t now = time(0);
        now += 29384020;
        char* dt1 = ctime(&now);
        _expiryDate = dt1;
    }else{
        _expiryDate = expiryDate;
    }

}

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

string& Account::expiryDate(){
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

const string& Account::expiryDate() const{
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