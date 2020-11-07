#include "Account.h"
#ifndef STARBANKATM_MOOP_KMA_UNIVERSALACCOUNT_H
#define STARBANKATM_MOOP_KMA_UNIVERSALACCOUNT_H
class UniversalAccount : public Account {
public:
    void withdrawMoney(size_t amount);
};
#endif //STARBANKATM_MOOP_KMA_UNIVERSALACCOUNT_H
