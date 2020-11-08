
#include "ATM.h"

SessionManager::SessionManager(ATM& atm):
        _depositAccount(0),_universalAccount(0),_creditAccount(0), _atm(atm)
{
}
void SessionManager::startSession() {
    while (isSecure()) {
        cout << "CHOOSE ACCOUNT:" << endl;
        cout << "1 - UNIVERSAL ACCOUNT" << endl;
        cout << "2 - DEPOSIT ACCOUNT" << endl;
        cout << "3 - CREDIT ACCOUNT" << endl;
        int choosenAcc;
        cin >> choosenAcc;
        switch (choosenAcc) {
            case 1: {
                UniversalAccount universalAccount = getUniversalAccount();
                makeOperation(universalAccount);
                break;
            }
            case 2: {
                DepositAccount depositAccount = getDepositAccount();
                makeOperation(depositAccount);
                break;
            }
            case 3: {
                CreditAccount creditAccount = getCreditAccount();
                makeOperation(creditAccount);
                break;
            }
            default:
                cout << "YOU ENTERED INVALID OPERATION";
    }}



}

void SessionManager::makeOperation(Account& account){
    while (isSecure()) {
        cout << "CHOOSE OPERATION:" << endl;
        cout << "1 - WITHDRAW MONEY" << endl;
        cout << "2 - PUT MONEY" << endl;
        cout << "3 - CHECK BALANCE" << endl;
        cout << "4 - CHECK LIMIT" << endl;
        cout << "5 - CHANGE LIMIT" << endl;
        cout << "6 - CLOSE SESSION" << endl;
        int choosen;
        cin >> choosen;
        switch (choosen) {
            case 1:
                cout << "ENTER SUM TO WITHDRAW: "<<endl;
                int sum;
                cin >> sum;
                _atm.getDispenser().getNotesOut(sum);
                //account.decrease(sum);
                break;
            case 2:
                cout << "ENTER SUM TO PUT: " << endl;
                int sumPut;
                cin >> sumPut;
                _atm.getDispenser().incashMoney(sumPut);
                //account.increase(sumPut);
                break;
            case 3:
                cout << "YOUR BALANCE: " << account.sumOnBalance()<<endl;
                break;
            case 4:
                cout << "YOUR LIMIT: " << account.limit() << endl;
                break;
            case 5:
                cout << "ENTER NEW LIMIT: ";
                int limit;
                cin >> limit;
                account.limit() = limit;
                cout << "YOUR NEW LIMIT: " << account.limit() << endl;
                break;
            case 6:
                closeSession();
            default:
                cout << "YOU ENTERED INVALID OPERATION";
        }
        cout << endl;
    }
}
void SessionManager::closeSession() {
    cout << "Close Session" << endl;
}

void SessionManager::setActiveDepositAccount(DepositAccount& a){
    _depositAccount = &a;
}
void SessionManager::setActiveCreditAccount(CreditAccount& a){
    _creditAccount = &a;
}
void SessionManager::setActiveUniversalAccount(UniversalAccount& a){
    _universalAccount = &a;
}


