#include "Account.h"

Account::Account(const User& owner, const string& cardnumber, const string& pin,
                 const bool blocked, const int limit, const int balance):
        _owner(owner), _cardnumber(cardnumber),_PIN(pin),_blocked(blocked),_limit(limit),_balance(balance)
{

}
Account::~Account() {

}
void Account::setLimit(const int limit) {
    _limit = limit;
}
ostream& operator<<(ostream& os, const Account& a) {
    os << "card: "<<a.getCardNumber() << endl;
    os << "balance: "<<a.getBalance() << endl;
    os << "limit: "<<a.getLimit() << endl;
    os << "name: " << a.getUser().getFirstName() << endl;
    os << "surname: " << a.getUser().getLastName() << endl;
    return os;
}
void Account::increase(const int sum) {
    _balance += sum;
}
void Account::decrease(const int sum) {
    if (sum > getBalance())
        throw string("Not enough money to maintain operation!");
    if (sum > getLimit())
        throw string("Exceeding limit!");
    _balance -= sum;
}


