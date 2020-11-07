#include <string>
#include <iostream>
#include "Account.h"
using namespace std;
#ifndef STARBANKATM_MOOP_KMA_DEPOSITACCOUNT_H
#define STARBANKATM_MOOP_KMA_DEPOSITACCOUNT_H

class DepositAccount : public Account{
private:
    size_t _depositTerm;
    char* _depositExpiryDate;//now+term в конструкторе
    size_t _depositPercentage;
public:
    DepositAccount(size_t userId, size_t cardNumber, size_t pin, size_t cvv, double sumOnBalance,
                   size_t limit,char* expiryDate,  bool isBlocked,size_t depositTerm, size_t depositPercentage,
                   char* depositExpiryDate = nullptr);
    ~DepositAccount();

    size_t& depositTerm();
    char* depositExpiryDate();
    size_t& depositPercentage();

    const size_t& depositTerm() const;
    const char* depositExpiryDate() const;
    const size_t& depositPercentage() const;

    void putMoney(double amount) override;
    double chargePercentageOfCost();
    void close();// + транзекшн с этого на юниверсал!!!!!!!!!!!
    void openNew(size_t depositTerm, size_t depositPercentage);
};
ostream& operator<<(ostream&, const DepositAccount&);
#endif //STARBANKATM_MOOP_KMA_DEPOSITACCOUNT_H
