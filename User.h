#pragma once

#include <string>
#include <iostream>
#include <list>
#include "Account.h"
using namespace std;

class User {


private:
	size_t _ID;
	string _firstName;
	string _lastName;
	list<Account> _allAccounts;
public:
	User();
	User(const size_t id, const string& firstName,
		const string& lastName, list<Account> _allAccounts);
	
	User(const User&);
	~User();
	Account& operator=(const Account&);
	void setAccounts(list<Account>& _allAccounts);
	void setFirstName(const string& firstName);
	void setLastName(const string& lastName);
	void setID(const string& lastName);//???

	size_t getID() { return _ID; };
	string getFirstName() const { return _firstName; };
	string getLastName() const { return _lastName; };
	list<Account> getAllAccounts()const { return _allAccounts; };

	void seeAllTransactions();
	void createTransaction();
	void stopAutomatedTransaction();
	void putMoneyInMyAccount();
	void putMoneyInAnotherAccount();
	void withdrawMoneyFromAccount();
	void checkBalance();
	void takeCredit();
	void openDeposit();
	void closeDeposit();
};