#include "CardScanner.h"
CardScanner::CardScanner(ATM& atm)
        : _atm(atm)
{

}

CardScanner::~CardScanner()
{

}

void CardScanner::readCard(string s)
{
    map<string, Account>::iterator it = _atm.getAccountList().find(s);
    if(it == _atm.getAccountList().end())
        throw string("Not found account with number: ") + s;
    _account =  _atm.getAccountList()[s];
}

void CardScanner::ejectCard()
{
      _account=0;
      _currNumOfTrials=0;
      //alert incorrect pin
      //end session
}

void CardScanner::retractCard(string s)
{
    if(_currNumOfTrials<=NUMBER_TRIALS){
        if(_account->getPin()!=s){
            _currNumOfTrials++;
            //wrong pin - try again
        }
    }else{
        ejectCard();
    }
}
