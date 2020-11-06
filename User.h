#pragma once

#include <string>
#include <iostream>
using namespace std;
#include <list>
#include "AccountOld.h"

class User {


private:
	size_t _ID;
	string _firstName;
	string _lastName;
	list<AccountOld> _allAccounts;
public:
	User();
	User(const size_t id, const string& firstName,
		const string& lastName, list<AccountOld> _allAccounts);
	
	User(const User&);
	~User();
	AccountOld& operator=(const AccountOld&);
	void setAccounts(list<AccountOld>& _allAccounts);
	void setFirstName(const string& firstName);
	void setLastName(const string& lastName);
	void setID(const string& lastName);//???

	size_t getID() { return _ID; };
	string getFirstName() const { return _firstName; };
	string getLastName() const { return _lastName; };
	list<AccountOld> getAllAccounts()const { return _allAccounts; };

	void seeAllTransactions();
	void createTransaction();
	//............write all methods..
};