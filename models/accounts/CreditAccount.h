#ifndef STARBANKATM_MOOP_KMA_CREDITACCOUNT_H
#define STARBANKATM_MOOP_KMA_CREDITACCOUNT_H
#include "Account.h"
class CreditAccount : public Account{
private:
    size_t _creditTerm;
    size_t _creditDept;
    char* _creditExpiryDate;
public:
    CreditAccount(size_t creditTerm, size_t creditDept, size_t userId, size_t cardNumber, size_t pin, size_t cvv, double sumOnBalance, size_t limit, bool isBlocked, char* expiryDate, char* creditExpiryDate = nullptr);
    ~CreditAccount();

    size_t& creditTerm();
    size_t& creditDept();

    const size_t& creditTerm() const;
    const size_t& creditDept() const;

    void putMoney(double amount);
    void close();
    void withdrawMoney(size_t amount);
};

#endif //STARBANKATM_MOOP_KMA_CREDITACCOUNT_H
