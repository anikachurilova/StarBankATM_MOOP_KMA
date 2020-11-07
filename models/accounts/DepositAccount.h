#include <string>
#include <iostream>
#include "Account.h"
using namespace std;
#ifndef STARBANKATM_MOOP_KMA_DEPOSITACCOUNT_H
#define STARBANKATM_MOOP_KMA_DEPOSITACCOUNT_H

class DepositAccount : public Account{
private:
    size_t _depositTerm;
    size_t _depositExpiryDate;
    size_t _depositPercentage;
public:
    size_t& depositTerm();
    size_t& depositExpiryDate();
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
