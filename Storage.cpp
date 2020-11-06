#include "Storage.h"


void Storage::removeAccount(const string& card) {
    _accounts.erase(card);
}
void Storage::addAccount(const Account& a) {
    _accounts.insert({ a.getCardNumber(), a });
}

Account& Storage::getAccount(const string& card) {
    Account* _account = 0;
    map<string, Account> ::iterator acc;
    for (acc = _accounts.begin(); acc != _accounts.end(); acc++) {
        if (acc->first == card) {
            _account = &acc->second;
            return *_account;
        }
    }
    if (!_account)
        throw string("Not found account with number: ") + card;
}

