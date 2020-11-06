#include "User.h"

User::User(const size_t id, const string& firstName,
     const string& lastName, list<Account> allAccounts):
     _id(id),_firstName(firstName),_lastName(lastName),_allAccounts(allAccounts){

}
User::User(const User& u):_id(u._id),_firstName(u._firstName),_lastName(u._lastName),_allAccounts(u._allAccounts)

