#include "CardScanner.h"

CardScanner::CardScanner(ATM& atm)
        : _atm(atm)
{

}

CardScanner::~CardScanner()
{

}

void CardScanner::readCard(string s) {
    map<string,Account>::iterator it = _atm.getAccountList().find(s);
    if(it == _atm.getAccountList().end())
        throw string("Not found account with number: ") + s;
    if(_atm.getAccountList()[s].isBlocked())
        throw string("Account is blocked with number: ") + s;
    _account = _atm.getAccountList()[s];


}

void CardScanner::ejectCard()
{
    _account=0;
    _currNumOfTrials=0;
    throw  "Pin is wrong";
    //alert incorrect pin
    //end session
}

void CardScanner::retractCard(string s)
{
    if(_currNumOfTrials<=NUMBER_TRIALS){
        if(!pinIsCorrect(s)){
            _currNumOfTrials++;
           cout<<"wrong pin. try again"<<endl;
            //wrong pin - try again
        }
    }else{
        ejectCard();
    }
}
