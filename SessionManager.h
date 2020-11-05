#include <iostream>
using namespace std;
class ATM;
class SessionManager
{
private:
    Account& _account;
    ATM& _atm;
    SessionManager(const SessionManager&);
    SessionManager& operator=(const SessionManager&);

public:
    SessionManager(Account&, ATM&);
    ~SessionManager();


    void startSession();
    void closeSession();

//	void handleInvalidPin();
    void handleFailedTransaction();


};

