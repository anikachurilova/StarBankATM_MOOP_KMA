#include "CashDispencer.h"
CashDispencer::CashDispencer(ATM& atm)
        : _atm(atm)
{

}

CashDispencer::~CashDispencer()
{

}
bool CashDispencer::isCorrectAmount(int n) {
    if(n%50==0 && n>=CashDispencer::_MIN_AMOUNT && n<=_totalCashAmount){
    return true;
}else{
        return false;
    }

}
void CashDispencer::initialiseNotes() {
   _notesMap[50]=100;
 _notesMap[100]=100;
   _notesMap[200]=100;
   _notesMap[500]=100;
}

void CashDispencer::setTotalCashAmount(){
    int total = 0;
    total += _notesMap[50] * 50;
    total += _notesMap[100] * 100;
    total += _notesMap[200] * 200;
    total += _notesMap[500] * 500;
   _totalCashAmount=total;
}

const map<int, int> CashDispencer::calculateNotesOut(const int m){
    if(!isCorrectAmount(m)){
        throw BadAmount(string("ATM hasn't enough money: "), m);
    }

        int n = m;
        int amount = m;
        int _50(0),
                _100(0),
                _200(0),
                _500(0);
        while (n >= 500 && has500(_500)) {
            _500++;
            n -= 500;
        }
        if (_500 > 0 && n % 200 != 0 && !has100()) {
            _500--;
            n += 500;
        }
        while (n >= 200 && has200(_200)) {
            _200++;
            n -= 200;
        }
        while (n >= 100 && has100(_100)) {
            _100++;
            n -= 100;
        }
        while (n >= 50 && has50(_50)) {
            _50++;
            n -= 50;
        }

        if (n != 0){
            throw BadAmount(string("ATM hasn't required set of banknotes: "), amount);
        }
        map<int, int> cashOutMap;
        cashOutMap[50] = _50;
        cashOutMap[100] = _100;
        cashOutMap[200] = _200;
        cashOutMap[500] = _500;

        return cashOutMap;
}

void CashDispencer::updateNotesMap(map<int,int> m){
    _notesMap[50]  = _notesMap[50]  - m[50];
    _notesMap[100]  = _notesMap[100]  - m[100];
    _notesMap[200]  = _notesMap[200]  - m[200];
    _notesMap[500]  = _notesMap[500]  - m[500];
}
const map<int, int> CashDispencer::getNotesOut(const int n){
    try
    {

        map<int, int> notesOutMap(calculateNotesOut(n));
        updateNotesMap(notesOutMap);
        setTotalCashAmount();
        return notesOutMap;
    }
    catch(const BadAmount& ba)
    {

        if(getTotalCashAmount() < _MIN_AMOUNT) {
          _blocked=true;
        }
        throw ba;

    }

}


