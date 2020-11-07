
#include <string>
#include <iostream>
using namespace std;
#include <map>

class User {

private:
    size_t _id;
    string _firstName;
    string _lastName;
    string _middleName;

public:
    User(size_t id, string firstName,  string lastName, string middleName);
    ~User();


//	void setAccounts(map<string, Account>& _allAccounts);

    string getFirstName() const { return _firstName; };
    string getLastName() const { return _lastName; };
//	map<string, Account> getAllAccounts()const { return _allAccounts; };

    void seeAllTransactions();
    void createTransaction();
    void stopAutomatedTransaction();

    void putMoneyInAnotherAccount();



    void takeCredit();
    void openDeposit();
    void closeDeposit();
};
ostream& operator<<(ostream&, const User&);

