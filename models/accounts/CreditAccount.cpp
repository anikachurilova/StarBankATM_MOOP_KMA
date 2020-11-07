#include <time.h>
#include "CreditAccount.h"

CreditAccount::CreditAccount(size_t creditTerm, double creditDept, size_t userId, size_t cardNumber, size_t pin,
                             size_t cvv, double sumOnBalance, size_t limit, bool isBlocked, char *expiryDate,
                             char *creditExpiryDate) : Account(userId,cardNumber,pin,cvv,sumOnBalance,limit,expiryDate,isBlocked),
                             _creditDept(creditDept), _creditTerm(creditTerm)
                             {
    if(creditExpiryDate == nullptr){
        _sumOnBalance = creditDept;
        time_t now = time(0);
        char* dt = ctime(&now);
        _creditExpiryDate = dt + creditTerm;
    }else{
        _creditExpiryDate = creditExpiryDate;
    }
}

CreditAccount::~CreditAccount(){}

size_t& CreditAccount::creditTerm(){
    return _creditTerm;
}

double& CreditAccount::creditDept(){
    return _creditDept;
}

char* CreditAccount::creditExpiryDate(){
    return _creditExpiryDate;
}

const size_t& CreditAccount::creditTerm() const{
    return _creditTerm;
}

const double& CreditAccount::creditDept() const{
    return _creditDept;
}

const char* CreditAccount::creditExpiryDate() const{
    return _creditExpiryDate;
}

void CreditAccount::putMoney(double amount) {
    _creditDept -= amount;
}

void CreditAccount::withdrawMoney(size_t amount) {
    _sumOnBalance -= amount;
}

void CreditAccount::close() {
    _creditTerm = 0;
    _creditDept = 0;
    _creditExpiryDate = nullptr;
}

void CreditAccount::openNew(size_t creditTerm, double creditDept) {
    _creditTerm = creditTerm;
    _creditDept = creditDept;
    _sumOnBalance = creditDept;

    time_t now = time(0);
    char* dt = ctime(&now);
    _creditExpiryDate = dt + creditTerm;
}