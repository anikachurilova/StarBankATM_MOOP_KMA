//
// Created by Anika on 07.11.2020.
//

#ifndef STARBANKATM_MOOP_KMA_CREDITACCOUNT_H
#define STARBANKATM_MOOP_KMA_CREDITACCOUNT_H
#include "Account.h"
class CreditAccount : public Account{
private:
    size_t _creditTerm;
    size_t _creditDept;
public:
    CreditAccount(size_t creditTerm, size_t creditDept);
    ~CreditAccount();

    size_t& creditTerm();
    size_t& creditDept();

    const size_t& creditTerm() const;
    const size_t& creditDept() const;

    void putMoney(size_t amount);
    void close();
    void withdrawMoney(size_t amount);
};

#endif //STARBANKATM_MOOP_KMA_CREDITACCOUNT_H
