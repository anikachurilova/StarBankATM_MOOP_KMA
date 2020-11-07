#include "Account.h"
#ifndef STARBANKATM_MOOP_KMA_UNIVERSALACCOUNT_H
#define STARBANKATM_MOOP_KMA_UNIVERSALACCOUNT_H
class UniversalAccount : public Account {
public:
    UniversalAccount(size_t userId, size_t cardNumber, size_t pin, size_t cvv, double sumOnBalance,
                     size_t limit,char* expiryDate,  bool isBlocked);
    ~UniversalAccount();
    void putMoney(double amount) override;
    void withdrawMoney(size_t amount);
};
#endif //STARBANKATM_MOOP_KMA_UNIVERSALACCOUNT_H
