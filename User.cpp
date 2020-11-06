#include "User.h"


User::User(const string& firstName,
           const string& lastName) :
        _firstName(firstName), _lastName(lastName){

}

User::~User()
{

}

void putMoneyInAnotherAccount();
void withdrawMoneyFromAccount();

ostream& operator<<(ostream& os, const User& a) {
    os << "name: " << a.getFirstName() << endl;
    os << "surname: " << a.getLastName() << endl;
    return os;
}