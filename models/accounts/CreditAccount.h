#ifndef STARBANKATM_MOOP_KMA_CREDITACCOUNT_H
#define STARBANKATM_MOOP_KMA_CREDITACCOUNT_H
#include "Account.h"
class CreditAccount : public Account{
private:
    size_t _creditTerm;
    double _creditDept;
    char* _creditExpiryDate;
public:
    CreditAccount(size_t creditTerm, double creditDept, size_t userId, size_t cardNumber, size_t pin, size_t cvv, double sumOnBalance, size_t limit, bool isBlocked, char* expiryDate, char* creditExpiryDate = nullptr);
    ~CreditAccount();

    size_t& creditTerm();
    double& creditDept();
    char* creditExpiryDate();

    const size_t& creditTerm() const;
    const double& creditDept() const;
    const char* creditExpiryDate() const;

    void putMoney(double amount) override;
    void close();
    void withdrawMoney(size_t amount);
    void openNew(size_t creditTerm, double creditDept);
};

#endif //STARBANKATM_MOOP_KMA_CREDITACCOUNT_H
