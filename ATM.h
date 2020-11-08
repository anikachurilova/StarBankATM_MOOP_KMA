#pragma once

#include "CashDispencer.h"
#include "CardScanner.h"
#include "Storage.h"
#include "SessionManager.h"
class ATM
{
private:
    SessionManager _sessionManager;
    Storage _storage;
    CashDispencer  _dispenser;
    CardScanner _cardScanner;

    ATM(const ATM&);				//this is not using
    ATM& operator=(const ATM&);		//this is not using

    map<int, int> _notesMap;

public:

    ATM();
    ~ATM();
    SessionManager& getManager() { return _sessionManager; }
    Storage& getStorage() { return _storage; }
    CashDispencer& getDispenser() { return _dispenser; }
    CardScanner& getCardScanner() { return _cardScanner; }

    void startSession();
};
