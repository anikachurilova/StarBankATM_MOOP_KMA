#include <time.h>
#include "DepositAccount.h"


DepositAccount::DepositAccount(size_t userId, size_t cardNumber, size_t pin, size_t cvv, double sumOnBalance,
                               size_t limit, char* expiryDate, bool isBlocked,size_t depositTerm, size_t depositPercentage,
                               char* depositExpiryDate): Account(userId,cardNumber,pin,cvv,sumOnBalance,limit,expiryDate,isBlocked){
    depositTerm = _depositTerm;
    depositPercentage = _depositPercentage;
     if(depositExpiryDate == nullptr){
         time_t now = time(0);
         char* dt = ctime(&now);
         depositExpiryDate = dt + depositTerm;
     } else{
         depositExpiryDate = _depositExpiryDate;
     }
}

DepositAccount::~DepositAccount() {

}

size_t& DepositAccount::depositTerm(){
    return _depositTerm;
}
char* DepositAccount::depositExpiryDate(){
    return _depositExpiryDate;
}
size_t& DepositAccount::depositPercentage(){
    return _depositPercentage;
}

const size_t& DepositAccount::depositTerm() const{
    return _depositTerm;
}
const char* DepositAccount::depositExpiryDate() const{
    return _depositExpiryDate;
}
const size_t& DepositAccount::depositPercentage() const{
    return _depositPercentage;
}

void DepositAccount::putMoney(double amount){
    _sumOnBalance += amount;
}

double DepositAccount::chargePercentageOfCost(){
    return (sumOnBalance() * depositPercentage()) / 100;
}

void DepositAccount::close(){ //+ транзекшн с этого на юниверсал !!!!!!!!!!!!!!!!!!! транзекшн(самон беленс + процент)
    _depositTerm = 0;
    _depositPercentage = 0;
    _depositExpiryDate = nullptr;
}

void DepositAccount::openNew(size_t depositTerm, size_t depositPercentage) {
    depositTerm = _depositTerm;
    depositPercentage = _depositPercentage;
    time_t now = time(0);
    char* dt = ctime(&now);
    _depositExpiryDate = dt + depositTerm;
}

