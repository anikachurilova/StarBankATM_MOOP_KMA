#include "ATM.h"

ATM::ATM()
        : _cardScanner(*this), _dispenser(*this), _sessionManager(0)
{

}

ATM::~ATM()
{
    delete _sessionManager;
}

void ATM::startSession()
{


    if (_sessionManager)
        throw "Something is going wrong in _sessionManager";

    try
    {
        cout << "ENTER YOUR CARD NUMBER:" << endl << "> ";
        string cardNum;
        getline(cin, cardNum);
        getCardScanner().readCard(cardNum);


        _sessionManager = new SessionManager(*_cardScanner.activeAccount(), *this);
        _sessionManager->startSession();
    }
    catch (const Account::BadAccount& ba)
    {
        cout << "Error!" << endl;
        cout << ba.reason() << '.' << endl << endl;
    }
    catch (const Account::BadPIN& bp)
    {
        cout << "Error!" << endl;
        cout << bp.reason() << '.' << endl << endl;
    }
    catch (const string& mess)
    {
        cout << mess << endl << endl;
    }

    closeSession();
    _cardScanner.ejectCard();
}

void ATM::closeSession()
{
    delete _sessionManager;
    _sessionManager = 0;
}



