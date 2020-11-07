#include <time.h>
#include "Transaction.h"

Transaction::Transaction(double transactionSum, size_t cardSourceNumber, size_t cardDestinationNumber, char* transactionDateTime, size_t transactionId):
                            _transactionSum(transactionSum), _cardSourceNumber(cardSourceNumber), _cardDestinationNumber(cardDestinationNumber){
    if(transactionId == 0){
        time_t now = time(0);
        char* dt = ctime(&now);
        _transactionDateTime = dt;
        //_transactionId =

        //create id and time
    }else{
        _transactionId = transactionId;//????????????????????
        _transactionDateTime = transactionDateTime;
    }
    return;
}

Transaction::~Transaction() {
    return;
}
Transaction::Transaction(const Transaction& t): _transactionId(t._transactionId),
_transactionDateTime(t._transactionDateTime), _transactionSum(t._transactionSum),
_cardSourceNumber(t._cardSourceNumber), _cardDestinationNumber(t._cardDestinationNumber){
    _transactionSum = t._transactionSum;
    _cardSourceNumber = t._cardSourceNumber;
    _cardDestinationNumber = t._cardDestinationNumber;
    _transactionId = t._transactionId;
    _transactionDateTime = t._transactionDateTime;
}

size_t& Transaction::transactionId() {
    return _transactionId;
}

double& Transaction::transactionSum() {
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

const double& Transaction::transactionSum() const{
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
