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
    DepositAccount(size_t depositTerm, size_t _depositPercentage, char* _depositExpiryDate = nullptr);
    ~DepositAccount();

    size_t& depositTerm();
    char* depositExpiryDate();
    size_t& depositPercentage();

    const size_t& depositTerm() const;
    const size_t& depositExpiryDate() const;
    const size_t& depositPercentage() const;

    void putMoney(size_t amount);
    size_t chargePercentageOfCost();
    void close();
};
ostream& operator<<(ostream&, const DepositAccount&);
#endif //STARBANKATM_MOOP_KMA_DEPOSITACCOUNT_H
