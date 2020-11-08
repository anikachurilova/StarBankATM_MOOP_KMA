
#include <iostream>
#include <time.h>
#include "ATM.h"
#include "models/Transaction.h"
#include "models/accounts/CreditAccount.h"
#include "models/accounts/DepositAccount.h"
#include "models/accounts/UniversalAccount.h"

#include "DBService/UserService.h"
#include "DBService/TransactionService.h"
#include "DBService/AccountService.h"
#include <cstdio>
#include <sqlite3.h>
#include <stdlib.h>


using namespace std;

int main(int argc, char **argv)
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







//    time_t my_time1 = time(NULL);
//    my_time1 += 2134563;
//    time_t my_time2 = time(NULL);
//
//    string a = ctime(&my_time2);
//    string b = ctime(&my_time1);
//
//    DepositAccount acc(111, 222, 222, 222, 3000,500, a,false,200000000,2,b);
//    cout << (acc.depositExpiryDate() == "" ? "*" : acc.depositExpiryDate()) << endl;
//    cout << "1: " <<acc.depositExpiryDate() << endl;
//    cout << "2: " <<acc.expiryDate() << endl;
//
//    acc.close();
//    acc.openNew(2000000,2);
//    cout << (acc.depositExpiryDate() == "" ? "*" : acc.depositExpiryDate()) << endl;
//    cout << "1: " <<acc.depositExpiryDate() << endl;
//    cout << "2: " <<acc.expiryDate() << endl;
//cout << "charge: " << acc.chargePercentageOfCost();

//    sqlite3 *db;
//    char *zErrMsg = 0;
//    int rc;
//    char *sql;
//    const char* data = "Callback function called";
//
//    /* Open database */
//    rc = sqlite3_open("ATM.db", &db);
//
//    if( rc ) {
//        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//        return(0);
//    } else {
//        fprintf(stdout, "Opened database successfully\n");
//    }


//    sql = "INSERT INTO USER (id_user,first_name,last_name,middle_name) "  \
//         "VALUES (1, 'Paul', 'Green', 'Jason'); " ;
//
//
//
//    /* Execute SQL statement */
//    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
//
//    if( rc != SQLITE_OK ){
//        fprintf(stderr, "SQL error: %s\n", zErrMsg);
//        sqlite3_free(zErrMsg);
//    } else {
//        fprintf(stdout, "Records created successfully\n");
//    }




//    sql = "SELECT * from USER";
//
//    /* Execute SQL statement */
//    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
//
//    if( rc != SQLITE_OK ) {
//        fprintf(stderr, "SQL error: %s\n", zErrMsg);
//        sqlite3_free(zErrMsg);
//    } else {
//        fprintf(stdout, "Operation done successfully\n");
//    }


//    sql = "UPDATE USER set last_name = 'White' where id_user=1; " \
//         "SELECT * from USER";
//
//    /* Execute SQL statement */
//    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
//
//    if( rc != SQLITE_OK ) {
//        fprintf(stderr, "SQL error: %s\n", zErrMsg);
//        sqlite3_free(zErrMsg);
//    } else {
//        fprintf(stdout, "Operation done successfully\n");
//    }



//    sql = "DELETE from USER where id_user=1; " \
//         "SELECT * from USER";
//
//    /* Execute SQL statement */
//    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
//
//    if( rc != SQLITE_OK ) {
//        fprintf(stderr, "SQL error: %s\n", zErrMsg);
//        sqlite3_free(zErrMsg);
//    } else {
//        fprintf(stdout, "Operation done successfully\n");
//    }



   // createUser(4,"Kim", "Kard","Frank");

   //cout << selectUserById(4) << endl;

   //createTransaction(320,"2222","1111","",2);

   //getAllTransactions();

    DepositAccount depositAccount;
    UniversalAccount universalAccount;
    CreditAccount creditAccount;
    User user;

    cout << "ENTER YOUR CARD NUMBER: ";
    string card,pin;
    getline(cin, card);
    // User user = selectUserByCard(card);

    cout << "ENTER YOUR PIN: ";
    getline(cin, pin);
    char accountType;
    if(!getDepositAccountByCardAndPin(card,pin).cardNumber().empty()){
        accountType = 'd';
//        User user = selectUserById(depositAccount.userId());
//        cout << user.firstName() << endl;
    }else if(!getUniversalAccountByCardAndPin(card,pin).cardNumber().empty()){
        accountType = 'u';
    } else if(!getCreditAccountByCardAndPin(card,pin).cardNumber().empty()){
        accountType = 'c';
    }else{
        cout << "WRONG CARD OR PIN!!!" << endl;
    }
    switch (accountType) {
        case 'd':{
            depositAccount = getDepositAccountByCardAndPin(card,pin);
            universalAccount = getUniversalAccountByUserId(depositAccount.userId());
            creditAccount = getCreditAccountByUserId(depositAccount.userId());
            cout << "WELCOME ";
            user = selectUserById(depositAccount.userId());
            cout << user.firstName() << endl;
            bool isWorking = true;
            while (isWorking) {
                cout << "CHOOSE OPERATION:" << endl;
                cout << "1 - PUT MONEY" << endl;
                cout << "2 - CHECK BALANCE" << endl;
                cout << "3 - CHECK LIMIT" << endl;
                cout << "4 - CHANGE LIMIT" << endl;
                cout << "5 - SHOW DEPOSIT TERM" << endl;
                cout << "6 - SHOW DEPOSIT PERCENTAGE" << endl;
                cout << "7 - SHOW DEPOSIT EXPIRY DATE" << endl;
                cout << "8 - SEE ALL TRANSACTIONS" << endl;
                cout << "9 - EXIT" << endl;
                int choosen;
                cin >> choosen;
                switch (choosen) {
                    case 1:
                        cout << "ENTER SUM TO PUT: " << endl;
                        int sumPut;
                        cin >> sumPut;
                        putMoneyOnDepositAccount(sumPut,depositAccount);
                        break;
                    case 2:
                        cout << "YOUR BALANCE: " << depositAccount.sumOnBalance() <<endl;
                        break;
                    case 3:
                        cout << "YOUR LIMIT: " << depositAccount.limit() << endl;
                        break;
                    case 4:
                        cout << "ENTER NEW LIMIT: ";
                        int limit;
                        cin >> limit;
                        depositAccount.limit() = limit;
                        cout << "YOUR NEW LIMIT: " << depositAccount.limit() << endl;
                        break;
                    case 5:
                        cout << "YOUR DEPOSIT TERM: " << depositAccount.depositTerm() << endl;
                        break;
                    case 6:
                        cout << "YOUR DEPOSIT PERCENTAGE: " << depositAccount.depositPercentage() << endl;
                        break;
                    case 7:
                        cout << "YOUR DEPOSIT EXPIRY DATE: " << depositAccount.depositExpiryDate() << endl;
                        break;
                    case 8:
                        getAllTransactionsByCard(depositAccount.cardNumber());
                        break;
                    case 9:
                        isWorking = false;
                        break;
                    default:
                        cout << "INVALID ENTER" << endl;
                        break;
                }
                cout << endl;
            }
        }
        case 'u':{
            universalAccount = getUniversalAccountByCardAndPin(card, pin);
            depositAccount = getDepositAccountByUserId(universalAccount.userId());
            creditAccount = getCreditAccountByUserId(universalAccount.userId());
            cout << "WELCOME ";
            user = selectUserById(universalAccount.userId());
            cout << user.firstName() << endl;
            bool isWorking = true;
            while (isWorking) {
                cout << "CHOOSE OPERATION:" << endl;
                cout << "1 - PUT MONEY" << endl;
                cout << "2 - WITHDRAW MONEY" << endl;
                cout << "3 - CHECK BALANCE" << endl;
                cout << "4 - CHECK LIMIT" << endl;
                cout << "5 - CHANGE LIMIT" << endl;
                cout << "6 - PUT MONEY TO ANOTHER ACCOUNT" << endl;
                cout << "7 - PUT MONEY TO MY ACCOUNT" << endl;
                cout << "8 - SEE ALL TRANSACTIONS" << endl;
                cout << "9 - EXIT" << endl;
                int choosen;
                cin >> choosen;
                switch (choosen) {
                    case 1:
                        cout << "ENTER SUM TO PUT: " << endl;
                        int sumPut;
                        cin >> sumPut;
                        putMoneyOnUniversalAccount(sumPut,universalAccount);
                        break;
                    case 2:
                        cout << "ENTER SUM TO WITHDRAW: " << endl;
                        int sumOut;
                        cin >> sumOut;
                        withdrawMoneyFromUniversalAccount(sumPut,universalAccount);
                    case 3:
                        cout << "YOUR BALANCE: " << universalAccount.sumOnBalance() <<endl;
                        break;
                    case 4:
                        cout << "YOUR LIMIT: " << universalAccount.limit() << endl;
                        break;
                    case 5:
                        cout << "ENTER NEW LIMIT: ";
                        int limit;
                        cin >> limit;
                        universalAccount.limit() = limit;
                        cout << "YOUR NEW LIMIT: " << universalAccount.limit() << endl;
                        break;
                    case 6: {
                        cout << "ENTER SUM TO PUT: " << endl;
                        int sumPut2;
                        cin >> sumPut2;
                        cout << "ENTER CARD NUMBER TO PUT: " << endl;
                        string cardPut;
                        cin >> cardPut;
                        makeTransactionFromUniversalToAnother(universalAccount, cardPut, sumPut2);
                    }
                    case 7:
                        cout << "ENTER SUM TO PUT: " << endl;
                        int sumPut3;
                        cin >> sumPut3;
                        cout << "WHICH ACCOUNT DO YOU WANT TO PUT MONEY TO? " << endl;
                        cout << "1 - DEPOSIT ACCOUNT" << endl;
                        cout << "2 - CREDIT ACCOUNT" << endl;
                        int acctype;
                        cin >> acctype;
                           if(acctype == '1') makeTransactionFromUniversalDeposit(universalAccount,depositAccount,sumPut3);
                           else if(acctype == '2')  makeTransactionFromUniversalToCredit(universalAccount,creditAccount,sumPut3);
                    case 8:
                        getAllTransactionsByCard(universalAccount.cardNumber());
                        break;
                    case 9:
                        isWorking = false;
                        break;
                    default:
                        cout << "INVALID ENTER" << endl;
                        break;
                }
                cout << endl;
            }
        }
        case 'c':{
            creditAccount = getCreditAccountByCardAndPin(card, pin);
            universalAccount = getUniversalAccountByUserId(creditAccount.userId());
            depositAccount = getDepositAccountByUserId(creditAccount.userId());
            cout << "WELCOME ";
            user = selectUserById(creditAccount.userId());
            cout << user.firstName() << endl;
            bool isWorking = true;
            while (isWorking) {
                cout << "CHOOSE OPERATION:" << endl;
                cout << "1 - PUT MONEY" << endl;
                cout << "2 - WITHDRAW MONEY" << endl;
                cout << "3 - CHECK BALANCE" << endl;
                cout << "4 - CHECK LIMIT" << endl;
                cout << "5 - CHANGE LIMIT" << endl;
                cout << "6 - PUT MONEY TO ANOTHER ACCOUNT" << endl;
                cout << "7 - PUT MONEY TO MY ACCOUNT" << endl;
                cout << "8 - SEE ALL TRANSACTIONS" << endl;
                cout << "9 - EXIT" << endl;
                int choosen;
                cin >> choosen;
                switch (choosen) {
                    case 1:
                        cout << "ENTER SUM TO PUT: " << endl;
                        int sumPut;
                        cin >> sumPut;
                        putMoneyOnCreditAccount(sumPut,creditAccount);
                        break;
                    case 2:
                        cout << "ENTER SUM TO WITHDRAW: " << endl;
                        int sumOut;
                        cin >> sumOut;
                        withdrawMoneyFromCreditAccount(sumPut,creditAccount);
                    case 3:
                        cout << "YOUR BALANCE: " << creditAccount.sumOnBalance() <<endl;
                        break;
                    case 4:
                        cout << "YOUR LIMIT: " << creditAccount.limit() << endl;
                        break;
                    case 5:
                        cout << "ENTER NEW LIMIT: ";
                        int limit;
                        cin >> limit;
                        creditAccount.limit() = limit;
                        cout << "YOUR NEW LIMIT: " << creditAccount.limit() << endl;
                        break;
                    case 6: {
                        cout << "ENTER SUM TO PUT: " << endl;
                        int sumPut2;
                        cin >> sumPut2;
                        cout << "ENTER CARD NUMBER TO PUT: " << endl;
                        string cardPut;
                        cin >> cardPut;
                        makeTransactionFromCreditToAnother(creditAccount, cardPut, sumPut2);
                    }
                    case 7:
                        cout << "ENTER SUM TO PUT: " << endl;
                        int sumPut3;
                        cin >> sumPut3;
                        cout << "WHICH ACCOUNT DO YOU WANT TO PUT MONEY TO? " << endl;
                        cout << "1 - DEPOSIT ACCOUNT" << endl;
                        cout << "2 - CREDIT ACCOUNT" << endl;
                        int acctype;
                        cin >> acctype;
                        if(acctype == '1') makeTransactionFromCreditToDeposit(creditAccount,depositAccount,sumPut3);
                        else if(acctype == '2')  makeTransactionFromCreditToUniversal(creditAccount,universalAccount,sumPut3);
                    case 8:
                        getAllTransactionsByCard(creditAccount.cardNumber());
                        break;
                    case 9:
                        isWorking = false;
                        break;
                    default:
                        cout << "INVALID ENTER" << endl;
                        break;
                }
                cout << endl;
            }
        }

    }


   //card.checkPin
   //card.getAllAccounts



  // getAllTransactionsByCard("1111");
   // getAllUsers();
   // sqlite3_close(db);
        return 0;
}

