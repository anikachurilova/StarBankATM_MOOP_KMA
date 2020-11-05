#pragma once
#include <iostream>
#include <vector>
using namespace std;

#include "CardScanner.h"
#include "CashDispencer.h"
#include "SessionManager.h"


class ATM
{
private:
    map<string,Account> _accountList;
    CardScanner _cardScanner;
    CashDispencer  _dispenser;
    SessionManager* _sessionManager;

    ATM(const ATM&);				//this is not using
    ATM& operator=(const ATM&);		//this is not using

    map<int,int> _notesMap;

public:
    ATM();
    ~ATM();
    CashDispencer& getDispenser() { return _dispenser; }
    CardScanner& getCardScanner() { return _cardScanner; }
    map<string,Account> getAccountList(){return _accountList;}

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
