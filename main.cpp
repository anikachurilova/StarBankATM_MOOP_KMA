
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
    DepositAccount depositAccount;
    UniversalAccount universalAccount;
    CreditAccount creditAccount;
    User user;
    char accountType = ' ';
    string card, pin;

    bool notEntered = true;
    while(notEntered) {
        cout << "ENTER YOUR CARD NUMBER: ";
        getline(cin, card);
        for (int i = 0; i < 3; i++) {
            cout << "ENTER YOUR PIN: ";
            getline(cin, pin);

            if (!getDepositAccountByCardAndPin(card, pin).cardNumber().empty()) {
                accountType = 'd';
                notEntered = false;
                break;
            } else if (!getUniversalAccountByCardAndPin(card, pin).cardNumber().empty()) {
                accountType = 'u';
                notEntered = false;
                break;
            } else if (!getCreditAccountByCardAndPin(card, pin).cardNumber().empty()) {
                accountType = 'c';
                notEntered = false;
                break;
            } else {
                cout << "WRONG CARD OR PIN!!!" << endl;
            }
        }
        if(notEntered) cout << "REJECTING CARD..." << endl;

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
                        cout << "ENTER AMOUNT OF MONEY TO PUT: " << endl;
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
                        cout << "ENTER AMOUNT OF MONEY TO PUT: " << endl;
                        int sumPut;
                        cin >> sumPut;
                        putMoneyOnUniversalAccount(sumPut,universalAccount);
                        break;
                    case 2:
                        cout << "ENTER AMOUNT OF MONEY TO WITHDRAW: " << endl;
                        int sumOut;
                        cin >> sumOut;
                        if(sumOut <= universalAccount.limit()){
                            withdrawMoneyFromUniversalAccount(sumPut,universalAccount);
                        }else{
                            cout << "THE AMOUNT IS MORE THAN YOUR LIMIT"<< endl;
                            cout << "ENTER ANOTHER AMOUNT OR CHANGE YOUR LIMIT" << endl;
                        }
                        break;
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
                        break;}
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
                           break;
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
                        break;
                    }
                    case 7:
                        cout << "ENTER SUM TO PUT: " << endl;
                        int sumPut3;
                        cin >> sumPut3;
                        cout << "WHICH ACCOUNT DO YOU WANT TO PUT MONEY TO? " << endl;
                        cout << "1 - DEPOSIT ACCOUNT" << endl;
                        cout << "2 - UNIVERSAL ACCOUNT" << endl;
                        int acctype;
                        cin >> acctype;
                        if(acctype == '1') makeTransactionFromCreditToDeposit(creditAccount,depositAccount,sumPut3);
                        else if(acctype == '2')  makeTransactionFromCreditToUniversal(creditAccount,universalAccount,sumPut3);
                        break;
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

        default:
            break;

    }
        return 0;
}

