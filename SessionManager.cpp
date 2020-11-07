//
//#include "ATM.h"
//SessionManager::SessionManager(ATM& atm):
//        _account(0), _atm(atm)
//{
//}
//void SessionManager::startSession() {
//    Account activeAccount = getAccount();
//    while (isSecure()) {
//        cout << "CHOOSE OPERATION:" << endl;
//        cout << "1 - WITHDRAW MONEY" << endl;
//        cout << "2 - PUT MONEY" << endl;
//        cout << "3 - CHECK BALANCE" << endl;
//        cout << "4 - CHECK LIMIT" << endl;
//        cout << "5 - CHANGE LIMIT" << endl;
//        int choosen;
//        cin >> choosen;
//        switch (choosen) {
//            case 1:
//                cout << "ENTER SUM TO WITHDRAW: "<<endl;
//                int sum;
//                cin >> sum;
//                _atm.getDispenser().getNotesOut(sum);
//                activeAccount.decrease(sum);
//                break;
//            case 2:
//                cout << "ENTER SUM TO PUT: " << endl;
//                int sumPut;
//                cin >> sumPut;
//                _atm.getDispenser().incashMoney(sumPut);
//                activeAccount.increase(sumPut);
//                break;
//            case 3:
//                cout << "YOUR BALANCE: " << activeAccount.getBalance()<<endl;
//                break;
//            case 4:
//                cout << "YOUR LIMIT: " << activeAccount.getLimit() << endl;
//                break;
//            case 5:
//                cout << "ENTER NEW LIMIT: ";
//                int limit;
//                cin >> limit;
//                activeAccount.setLimit(limit);
//                cout << "YOUR NEW LIMIT: " << activeAccount.getLimit() << endl;
//                break;
//        }
//        cout << endl;
//    }
//
//}
//void SessionManager::closeSession() {
//    cout << "Close Session" << endl;
//}
//void SessionManager::setActiveAccount( Account& a) {
//    _account = &a;
//}
//
