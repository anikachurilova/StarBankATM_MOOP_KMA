#pragma once
#include <iostream>
using namespace std;

#include "CardScanner.h"
#include "CashDispencer.h"
#include "SessionManager.h"
#include "Notes.h"

class ATM
{
private:
	
	const size_t _id;

	CardScanner _cardScanner;
	CashDispencer  _dispenser;
	SessionManager* _sessionManager;

	ATM(const ATM&);				//this is not using
	ATM& operator=(const ATM&);		//this is not using

public:
	ATM();
	~ATM();
	 size_t getId() const { return _id; }
	 CashDispencer& getDispenser() { return _dispenser; }
	 CardScanner& getCardReader() { return _cardScanner; }


	//Dispenser's API
	 bool isCorrectAmount(int amount) const {
		return _dispenser.isCorrectAmount(amount);
	}
	
	 map<Notes, int> outcash(int total)
	{
		//return _dispenser.outcash(total);
	}
	 map<Notes, int> incash(int _50 = 1000, int _100 = 1000, int _200 = 400,
		int _500 = 500)
	{
		//return _dispenser.incash(_50, _100, _200, _500);
	}

	
	 void    readCard() { _cardScanner.readCard(); }
	 void pushOutCard() { _cardScanner.ejectCard(); }
	 void declineCard() { _cardScanner.retractCard(); }

	 void printCheck();
	 void showMenu();
	 string getPin(string&);
	 void checkPin(string&);

	 

	//Start session
	void startSession();
	//Close session
	void closeSession();
};

ostream& operator<<(ostream&, const ATM&);

