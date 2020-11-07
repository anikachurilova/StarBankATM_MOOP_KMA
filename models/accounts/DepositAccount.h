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
                   size_t limit,  bool isBlocked,size_t depositTerm, size_t depositPercentage, char* expiryDate,
                   char* depositExpiryDate = nullptr);
    ~DepositAccount();

    size_t& depositTerm();
    char* depositExpiryDate();
    size_t& depositPercentage();

    const size_t& depositTerm() const;
    const char* depositExpiryDate() const;
    const size_t& depositPercentage() const;

    void putMoney(double amount);//емаунт+беленс
    double chargePercentageOfCost();//баланс и процент и вычисл что должно сняться
    void close();//
};
ostream& operator<<(ostream&, const DepositAccount&);
#endif //STARBANKATM_MOOP_KMA_DEPOSITACCOUNT_H
