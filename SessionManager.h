
#include <iostream>
using namespace std;
#include "models/accounts/Account.h"
#include "models/accounts/CreditAccount.h"
#include "models/accounts/UniversalAccount.h"
#include "models/accounts/DepositAccount.h"

class ATM;
class SessionManager
{
private:
    CreditAccount* _creditAccount;
    UniversalAccount* _universalAccount;
    DepositAccount* _depositAccount;
    ATM& _atm;
    int _activeOperation;
    bool _secure = true;

    SessionManager(const SessionManager&);
    SessionManager& operator=(const SessionManager&);

public:
    bool isSecure() {
        return _secure;
    }
    SessionManager(ATM&);
    ~SessionManager() {}
    void makeOperation(Account& );
    const CreditAccount getCreditAccount() {
        return *_creditAccount;
    }
    const DepositAccount getDepositAccount() {
        return *_depositAccount;
    }
    const UniversalAccount getUniversalAccount() {
        return *_universalAccount;
    }

    void setActiveDepositAccount(DepositAccount&);
    void setActiveCreditAccount(CreditAccount&);
    void setActiveUniversalAccount(UniversalAccount&);
    void startSession();
    void closeSession();

};
