cmake_minimum_required(VERSION 3.17)
project(StarBankATM_MOOP_KMA)

set(CMAKE_CXX_STANDARD 14)

add_executable(StarBankATM_MOOP_KMA main.cpp models/accounts/AccountOld.h ATM.h CashDispencer.h CardScanner.h SessionManager.h models/User.h
        models/Transaction.cpp models/Transaction.h models/accounts/Account.h models/accounts/Account.cpp Storage.h Storage.cpp ATM.cpp CardScanner.cpp
        CashDispencer.cpp SessionManager.cpp models/User.cpp models/accounts/AccountOld.cpp models/accounts/CreditAccount.cpp models/accounts/CreditAccount.h
        models/accounts/DepositAccount.cpp models/accounts/DepositAccount.h models/accounts/UniversalAccount.cpp models/accounts/UniversalAccount.h
        models/UserOld.h models/UserOld.cpp)