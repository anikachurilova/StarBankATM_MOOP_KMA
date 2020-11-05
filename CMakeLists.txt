cmake_minimum_required(VERSION 3.17)
project(StarBankATM_MOOP_KMA)

set(CMAKE_CXX_STANDARD 14)

add_executable(StarBankATM_MOOP_KMA main.cpp Account.h ATM.h CashDispencer.h CardScanner.h SessionManager.h User.h cmake-build-debug/CashDispencer.cpp cmake-build-debug/SessionManager.cpp CardScanner.cpp CashDispencer.cpp Transaction.h ATM.cpp SessionManager.cpp User.cpp)