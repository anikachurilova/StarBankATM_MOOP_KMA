
#include <iostream>
#include <string>
using namespace std;

#include "Account.h"

class ATM;
class CardScanner
{
private:
	ATM& _atm;
	Account* _account;
	static const size_t NUMBER_TRIALS = 3;
	size_t currNumOfTrials;
	CardScanner(const CardScanner&);
	CardScanner& operator=
		(const CardScanner&);

public:
	CardScanner(ATM&);
	~CardScanner();

	//if password is correct then accept the card
	bool acceptCard();
	//scan data,check if card number is in database(valid)
	void readCard(string);
	//if 3 times pin is incorrect or if card number incorrect => eject card
	void ejectCard();
	//if pin is incorrect => reject card
	void retractCard(string);

	void setCurrNumOfTrials();
	size_t getCurrNumOfTrials() const;

};

