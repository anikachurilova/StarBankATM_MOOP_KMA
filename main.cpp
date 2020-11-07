
#include <iostream>
#include "ATM.h"
#include "models/Transaction.h"
#include "models/accounts/CreditAccount.h"

using namespace std;

int main()
{
//    User u1("A","B");
//    Account a1(u1,"3333","33",false,100,500);
//    Account a2(u1,"1111","11",false,1000,2000);
//    Account a3(u1,"2222","22",false,500,100);
//
//    try {
//        ATM atm;
//        atm.getStorage().addAccount(a1);
//        atm.getStorage().addAccount(a2);
//        atm.getStorage().addAccount(a3);
//
//        atm.startSession();
//
//        cout << endl << endl;
//        //TESTING STORAGE
//        map<string,Account>accounts = atm.getStorage().getAllAccountsInStorage();
//        map<string, Account> ::iterator acc;
//        for (acc = accounts.begin(); acc != accounts.end(); acc++) {
//            cout<<acc->second   // value
//                << endl;
//        }
//        cout << endl;
//
//
//        //TESTING CASH DISPENCER
//        cout << endl << endl;
//        map<int, int> cashSet = atm.getDispenser().howMuchMoneyAtmHas();
//        map<int, int>::iterator it1;
//        for (it1 = cashSet.begin(); it1 != cashSet.end(); it1++) {
//            cout << it1->first  // key
//                 << ':'
//                 << it1->second   // value
//                 << endl;
//        }
//        cout << endl << endl;
//        //TESTING CASH DISPENCER OUTCASH MONEY
//        map<int, int> cashSet1 = atm.getDispenser().getNotesOut(500);
//        map<int, int>::iterator it;
//        for (it = cashSet1.begin(); it != cashSet1.end(); it++) {
//            cout << it->first  // key
//                 << ':'
//                 << it->second   // value
//                 << std::endl;
//        }
//        cout << endl << endl;
//        map<int, int> cashSet2 = atm.getDispenser().howMuchMoneyAtmHas();
//        map<int, int>::iterator it2;
//        for (it2 = cashSet2.begin(); it2 != cashSet2.end(); it2++) {
//            cout << it2->first  // key
//                 << ':'
//                 << it2->second   // value
//                 << endl;
//        }
//        cout << endl << endl;
//
//        //TESTING CASH DISPENCER INCASH MONEY
//        atm.getDispenser().incashMoney(200);
//        map<int, int> cashSet3 = atm.getDispenser().howMuchMoneyAtmHas();
//        map<int, int>::iterator it3;
//        for (it3 = cashSet3.begin(); it3 != cashSet3.end(); it3++) {
//            cout << it3->first  // key
//                 << ':'
//                 << it3->second   // value
//                 << endl;
//        }
//    }
//    catch (string s) {
//        cout << s;
//    }

  //  time_t now = time(0);

    // convert now to string form
//    char* dt = ctime(&now);
//    cout << &dt << endl;
//
//
//    Transaction t1(100, 1111,2222,dt,1);
//    cout << t1.transactionDateTime() << endl;









//    time_t my_time1 = time(NULL);
//    my_time1 += 2134563;
//    time_t my_time2 = time(NULL);
//
//    string a = ctime(&my_time2);
//    string b = ctime(&my_time1);
//
//    CreditAccount ca1(9000000, 2000, 1, 1111, 000,123, 0, 500, false, b,a);
//
//    cout << "1: " <<ca1.creditExpiryDate() << endl;
//    cout << "2: " <<ca1.expiryDate() << endl;
//
//    ca1.close();
//
//    cout << ca1.expiryDate() << endl;
//    cout << (ca1.creditExpiryDate() == "" ? "*" : ca1.creditExpiryDate()) << endl;
//
//    ca1.openNew(2222,1111);
//
//    cout << ca1.expiryDate() << endl;
//    cout << ca1.creditExpiryDate() << endl;
//
//    cout << ca1.creditDept() << endl;
//    cout << ca1.sumOnBalance() << endl;
//
//    ca1.putMoney(100);
//    cout << ca1.creditDept() << endl;
//    cout << ca1.sumOnBalance() << endl;
//
//    ca1.withdrawMoney(1000);
//    cout << ca1.creditDept() << endl;
//    cout << ca1.sumOnBalance() << endl;

}

