cmake_minimum_required(VERSION 3.17)
project(StarBankATM_MOOP_KMA)

set(CMAKE_CXX_STANDARD 14)

add_executable(StarBankATM_MOOP_KMA main.cpp AccountOld.h ATM.h CashDispencer.h CardScanner.h SessionManager.h User.h
        Transaction.cpp Transaction.h Account.h Account.cpp Storage.h Storage.cpp ATM.cpp CardScanner.cpp CashDispencer.cpp SessionManager.cpp User.cpp)