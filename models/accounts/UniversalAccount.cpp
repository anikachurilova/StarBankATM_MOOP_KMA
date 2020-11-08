#include <time.h>
#include "UniversalAccount.h"



UniversalAccount::UniversalAccount(size_t userId, string cardNumber, string pin, string cvv, double sumOnBalance,
        size_t limit,string expiryDate,  bool isBlocked):Account(userId,cardNumber,pin,cvv,sumOnBalance,limit,expiryDate,isBlocked){

}

UniversalAccount::~UniversalAccount(){}

void UniversalAccount::putMoney(double amount) {
       _sumOnBalance += amount;
}

void UniversalAccount::withdrawMoney(size_t amount){
    _sumOnBalance -= amount;
}