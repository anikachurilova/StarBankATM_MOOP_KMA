#include <iostream>
#include <string>
#include "models/accounts/Account.h"
#include <map>
using namespace std;

class ATM;

class CardScanner {
private:
    ATM& _atm;
    Account* _account;
    static const size_t NUMBER_TRIALS=3;
    size_t _currNumOfTrials;
    CardScanner(const CardScanner&);
    CardScanner& operator=
            (const CardScanner&);
    bool _secure = false;
    string _currentPin;
public:
    CardScanner(ATM&);
    ~CardScanner();
    Account activeAccount() const {return *_account;}
    bool isActiveAccount() const{ return _account;}
    bool isSecure() const {return _secure;}
    //if password is correct then accept the card
    bool pinIsCorrect(string);
    //scan data,check if card number is in database(valid)
    void readCard(string);
    //if 3 times pin is incorrect or if card number incorrect => eject card
    void ejectCard();
    //if pin is incorrect => try again
    void checkPin();
    string getCurrentPin()const { return _currentPin; }
    size_t getCurrNumOfTrials() const { return _currNumOfTrials; }
    ATM& getATM() { return _atm; }
};

