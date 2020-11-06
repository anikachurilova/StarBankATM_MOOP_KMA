#include "ATM.h"
#include <map>
#include <string>
CardScanner::CardScanner(ATM& atm)
        : _atm(atm), _account(0)
{

}

CardScanner::~CardScanner()
{

}

void CardScanner::readCard(string card) {
    if (_atm.getStorage().getAccount(card).isBlocked()) {
        throw string("Account is blocked with number: ") + card;
    }
    _account = &_atm.getStorage().getAccount(card);
    _currentPin = _account->getPin();
    //cout << *_account;
}

void CardScanner::ejectCard()
{
    _account = 0;
    _currNumOfTrials = 0;
    cout << "end session" << endl;
    throw  string("Pin is wrong");
    //alert incorrect pin
}

bool CardScanner::pinIsCorrect(string pin) {
    if (isActiveAccount()) {
        if (getCurrentPin() == pin) {
            return true;
        }
        else return false;
    }
}
void CardScanner::checkPin() {
    for (int i(0);i < NUMBER_TRIALS;i++) {
        cout << "ENTER YOU PIN: " << endl;
        string pin;
        getline(cin, pin);
        if (!pinIsCorrect(pin)) {
            cout << "Wrong pin." << endl;
        }
        else {
            _secure = true;
            return;
        }
    }
    ejectCard();
}
