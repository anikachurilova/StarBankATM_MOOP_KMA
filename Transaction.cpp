#include "Transaction.h"

Transaction::Transaction(size_t transactionSum, size_t cardSourceNumber, size_t cardDestinationNumber, char* transactionDateTime, size_t transactionId):
                            _transactionSum(transactionSum), _cardSourceNumber(cardSourceNumber), _cardDestinationNumber(cardDestinationNumber){
    if(transactionId == 0){
        //create id and time
    }else{
        _transactionId = transactionId;
        _transactionDateTime = transactionDateTime;
    }
    return;
}

Transaction::~Transaction() {
    return;
}

size_t& Transaction::transactionId() {
    return _transactionId;
}

size_t& Transaction::transactionSum() {
    return _transactionSum;
}

size_t& Transaction::cardDestinationNumber() {
    return _cardDestinationNumber;
}

size_t& Transaction::cardSourceNumber() {
    return _cardSourceNumber;
}

char* Transaction::transactionDateTime() {
    return _transactionDateTime;
}






const size_t& Transaction::transactionId() const{
    return _transactionId;
}

const size_t& Transaction::transactionSum() const{
    return _transactionSum;
}

const size_t& Transaction::cardDestinationNumber() const{
    return _cardDestinationNumber;
}

const size_t& Transaction::cardSourceNumber() const{
    return _cardSourceNumber;
}

const char* Transaction::transactionDateTime() const{
    return _transactionDateTime;
}