#include "CardScanner.h"
#include "ATM.h"
#include "Account.h"

CardScanner::CardScanner(ATM& atm)
        : _atm(atm)
{

}

CardScanner::~CardScanner()
{

}

void CardScanner::readCard(string s)
{

}

void CardScanner::ejectCard()
{
  if(currNumOfTrials>NUMBER_TRIALS){
      cout<<"eject"<<endl;
      //alert incorrect pin
      //end session
  }
}

void CardScanner::retractCard(String s,Account a)
{
a.getPin();
}