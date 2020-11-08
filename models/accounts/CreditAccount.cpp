#include <time.h>
#include "CreditAccount.h"

CreditAccount::CreditAccount(size_t creditTerm, double creditDept, size_t userId, string cardNumber, string pin,
                             string cvv, double sumOnBalance, size_t limit, bool isBlocked, string expiryDate,
                             string creditExpiryDate) : Account(userId,cardNumber,pin,cvv,sumOnBalance,limit,isBlocked,expiryDate),
                             _creditDept(creditDept), _creditTerm(creditTerm)
                             {
    if(creditExpiryDate.empty()){
        _sumOnBalance = creditDept;
        time_t now = time(0);
        now += creditTerm;
        char* dt1 = ctime(&now);
        _creditExpiryDate = dt1;
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

string& CreditAccount::creditExpiryDate(){
    return _creditExpiryDate;
}

const size_t& CreditAccount::creditTerm() const{
    return _creditTerm;
}

const double& CreditAccount::creditDept() const{
    return _creditDept;
}

const string& CreditAccount::creditExpiryDate() const{
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
    _creditExpiryDate = "";
}

void CreditAccount::openNew(size_t creditTerm, double creditDept) {
    _creditTerm = creditTerm;
    _creditDept = creditDept;
    _sumOnBalance = creditDept;

    time_t now = time(0);
    now += creditTerm;
    string dt = ctime(&now);
    _creditExpiryDate = dt;
}