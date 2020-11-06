#include <iostream>
#include <string>
#include "Account.h"
#include "ATM.h"
#include <map>
using namespace std;

class ATM;
class CardScanner
{
private:
	ATM& _atm;
	Account* _account;
	static const size_t NUMBER_TRIALS = 3;
	size_t _currNumOfTrials;
	CardScanner(const CardScanner&);
	CardScanner& operator=
		(const CardScanner&);

public:
	CardScanner(ATM&);
	~CardScanner();
	Account* activeAccount() const
    { return _account; }
     bool isActiveAccount() const
    { return _account; }

	//if password is correct then accept the card
	bool pinIsCorrect(string s){return _account->getPin()==s;}
	//scan data,check if card number is in database(valid)
	void readCard(string);
	//if 3 times pin is incorrect or if card number incorrect => eject card
	void ejectCard();
	//if pin is incorrect => retract card
	void retractCard(string);
    void checkPin(string);
	size_t getCurrNumOfTrials() const{return _currNumOfTrials;}

};

