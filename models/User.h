
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


    size_t& id();
    string& firstName();
    string& lastName();
    string& middleName();


    const size_t& id() const;
    const string& firstName() const;
    const string& lastName() const;
    const string& middleName() const;
};
ostream& operator<<(ostream&, const User&);

