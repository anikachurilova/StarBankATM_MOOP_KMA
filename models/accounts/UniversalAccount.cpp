#include <time.h>
#include "UniversalAccount.h"



UniversalAccount::UniversalAccount(size_t userId, size_t cardNumber, size_t pin, size_t cvv, double sumOnBalance,
        size_t limit,char* expiryDate,  bool isBlocked):Account(userId,cardNumber,pin,cvv,sumOnBalance,limit,expiryDate,isBlocked){

}

UniversalAccount::~UniversalAccount(){}

void UniversalAccount::putMoney(double amount) {
       _sumOnBalance += amount;
}

void UniversalAccount::withdrawMoney(size_t amount){
    _sumOnBalance -= amount;
}