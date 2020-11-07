//
// Created by Valerie Luniakina on 06.11.2020.
//
#include <string>
#include <iostream>
using namespace std;
#ifndef STARBANKATM_MOOP_KMA_TRANSACTION_H
#define STARBANKATM_MOOP_KMA_TRANSACTION_H


class Transaction {
private:
    size_t _transactionId;
    size_t _transactionSum;
    size_t _cardSourceNumber;
    size_t _cardDestinationNumber;
    char* _transactionDateTime;
public:

    Transaction(size_t transactionSum, size_t cardSourceNumber, size_t cardDestinationNumber, char* transactionDateTime, size_t transactionId = 0);
    ~Transaction();

    //maybe copy-constructor if we want to repeat one transaction??
    //Transaction(Transaction&);

    size_t& transactionId();
    size_t& transactionSum();
    size_t& cardSourceNumber();
    size_t& cardDestinationNumber();
    char* transactionDateTime();


   const size_t& transactionId() const;
   const size_t& transactionSum() const;
   const size_t& cardSourceNumber() const;
   const size_t& cardDestinationNumber() const;
   const char* transactionDateTime() const;

   void makeTransaction();
};
ostream& operator<<(ostream& os, const Transaction&);

#endif //STARBANKATM_MOOP_KMA_TRANSACTION_H
