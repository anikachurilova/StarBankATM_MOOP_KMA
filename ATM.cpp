//#include "ATM.h"
//#include <map>
//
//ATM::ATM()
//        : _dispenser(*this), _cardScanner(*this), _storage(*this),_sessionManager(*this)
//{
//
//}
//
//ATM::~ATM()
//{
//
//}
//void ATM::startSession() {
//    CardScanner& cs = getCardScanner();
//    getDispenser();
//    cout << "ENTER YOUR CARD NUMBER: ";
//    string card;
//    getline(cin, card);
//    cs.readCard(card);
//    cout << endl;
//    cs.checkPin();
//    Account& activeAccount = getStorage().getAccount(card);
//    if (cs.isSecure()) {
//        getManager().setActiveAccount(activeAccount);
//        getManager().startSession();
//    }
//    else {
//        cout << "NOT SECURE";
//    }
//}