
#include <string>
#include <iostream>
#include "User.h"
using namespace std;

class AccountOld
{
private:
	
	string _cardnumber;
	//User _owner;
	string _expiryDate;
	string _PIN;

	int _balance;
	int _attempts;
	bool _blocked;

	void increase(const int sum);
	void decrease(const int sum);

public:
	class BadAmount;
	class BadAccount;
	class BadPIN;

	AccountOld(const User& owner, const string& PIN,
               const string& cardnumber, const string& expiryDate, const int balance);

	AccountOld(const AccountOld&);
	~AccountOld();
	AccountOld& operator=(const AccountOld&);

	 int    balance() const { return _balance; }
	// User owner() const { return _owner; }
	 string getExpiryDate() const { return _expiryDate; }
	 string getCardNumber() const { return _cardnumber; }
	 bool isBlocked() const { return _blocked; }

	int  getAttempts();
	bool verifyPIN(const string&);

	void replenishment(const int);
	void withdrawal(const int);
	void transferTo(AccountOld& a, const int);
};







class AccountOld::BadAmount
{
private:
	const string _reason;
	const int _number;

public:
	BadAmount(string reason, const int num)
		:_reason(reason), _number(num)
	{
		return;
	}

	~BadAmount() { }

	void diagnose() const{
		cerr << _reason << endl;
		cerr << ' ' << _number << endl;
	}
};

class AccountOld::BadAccount
{
private:
	const string _reason;

public:
	BadAccount(string& reason)
		:_reason(reason)
	{
		return;
	}

	~BadAccount() { }

	inline const string& reason() const { return _reason; }
};

class AccountOld::BadPIN
{
private:
	const string _reason;

public:
	BadPIN(string& reason)
		:_reason(reason)
	{
		return;
	}

	~BadPIN() { }

	inline const string& reason() const { return _reason; }
};


ostream& operator<<(ostream&, const AccountOld&);