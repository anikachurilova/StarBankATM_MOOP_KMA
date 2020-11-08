//
// Created by Valerie Luniakina on 08.11.2020.
//

#ifndef STARBANKATM_MOOP_KMA_ACCOUNTSERVICE_H
#define STARBANKATM_MOOP_KMA_ACCOUNTSERVICE_H
#include "../models/accounts/Account.h"
#include "../models/accounts/CreditAccount.h"
#include "../models/accounts/DepositAccount.h"
#include "../models/accounts/UniversalAccount.h"
#include <cstdio>
#include <sqlite3.h>
#include <vector>


void createUniversalAccount(size_t userId, string cardNumber, string pin, string cvv, double sumOnBalance,
                            size_t limit,string expiryDate,  bool isBlocked){



}

#endif //STARBANKATM_MOOP_KMA_ACCOUNTSERVICE_H
