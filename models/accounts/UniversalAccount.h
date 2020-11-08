#include "Account.h"
#ifndef STARBANKATM_MOOP_KMA_UNIVERSALACCOUNT_H
#define STARBANKATM_MOOP_KMA_UNIVERSALACCOUNT_H


class UniversalAccount : public Account {

public:
    UniversalAccount(){}
    UniversalAccount(size_t userId, string cardNumber, string pin, string cvv, double sumOnBalance,
                     size_t limit,  bool isBlocked,string expiryDate);
    ~UniversalAccount();
    UniversalAccount& operator=(const UniversalAccount&){}
    void putMoney(double amount) override;
    void withdrawMoney(size_t amount);
};


#endif //STARBANKATM_MOOP_KMA_UNIVERSALACCOUNT_H
