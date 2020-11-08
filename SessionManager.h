//
//#include <iostream>
//using namespace std;
//
//#include "Accounts/Account.h"
//
//class ATM;
//class SessionManager
//{
//private:
//    Account* _account;
//    ATM& _atm;
//    int _activeOperation;
//    bool _secure = true;
//
//    SessionManager(const SessionManager&);
//    SessionManager& operator=(const SessionManager&);
//
//public:
//    bool isSecure() {
//        return _secure;
//    }
//    SessionManager(ATM&);
//    ~SessionManager() {}
//
//    const Account getAccount() {
//        return *_account;
//    }
//
//    void setActiveAccount( Account&);
//    void startSession();
//    void closeSession();
//
//};
