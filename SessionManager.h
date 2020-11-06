
#include <iostream>
using namespace std;

#include "AccountOld.h"

class ATM;
class SessionManager
{
private:
	AccountOld& _account;
	ATM& _atm;
	SessionManager(const SessionManager&);
	SessionManager& operator=(const SessionManager&);

public:
	SessionManager(AccountOld&, ATM&);
	~SessionManager();


	void startSession();
	void closeSession();
	
	void handleInvalidPin();
	void handleFailedTransaction();

	
};

