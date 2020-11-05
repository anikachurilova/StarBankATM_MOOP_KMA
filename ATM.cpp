void ATM::setTotalCashAmount(){
    int total = 0;
    total += CashDispencer::_notesMap[] * 50;
    total += CashDispencer::_notesMap[] * 100;
    total += CashDispencer::_notesMap[] * 200;
    total += CashDispencer::_notesMap[] * 500;
    CashDispencer::_totalCashAmount=total;
}

