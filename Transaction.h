#pragma once

#include <string>
#include <iostream>
#include <list>

using namespace std;

class Transaction {


private:
int _transactionID;
int _transactionSum;
string _cardSourceNumber;
string _cardDestinationNumber;
string _transactionDateTime;
public:
Transaction();
void makeTransaction();


};
