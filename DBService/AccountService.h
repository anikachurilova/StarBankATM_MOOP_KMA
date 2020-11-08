#ifndef STARBANKATM_MOOP_KMA_ACCOUNTSERVICE_H
#define STARBANKATM_MOOP_KMA_ACCOUNTSERVICE_H
#include "../models/accounts/Account.h"
#include "../models/accounts/CreditAccount.h"
#include "../models/accounts/DepositAccount.h"
#include "../models/accounts/UniversalAccount.h"
#include <cstdio>
#include <sqlite3.h>
#include <vector>

//static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
//    int i;
//    for(i = 0; i<argc; i++) {
//        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
//    }
//    printf("\n");
//    return 0;
//}
UniversalAccount createUniversalAccount(size_t userId, string cardNumber, string pin, string cvv, double sumOnBalance,
                                        size_t limit,string expiryDate,  bool isBlocked){

    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("ATM.db", &DB);

   // cout << "STATE OF TABLE BEFORE INSERT" << endl;


    UniversalAccount ua(userId,cardNumber,pin,cvv,sumOnBalance,limit,isBlocked,expiryDate);
    expiryDate = ua.expiryDate();
    string sql("INSERT INTO UNIVERSAL_ACCOUNT (account_number,pin,expiry_date, cvv_number, sum_on_balance, user_id)"
               " VALUES('"  + cardNumber + "', '" + pin+ "', '" + expiryDate  + "', '" + cvv + "', "+ to_string(sumOnBalance) + ", "+ to_string(userId) + ");"
    );


    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messaggeError);
        printf(messaggeError);
    }
   // else
     //   std::cout << "Records created Successfully!" << std::endl;

   // cout << "STATE OF TABLE AFTER INSERT" << endl;

    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);

    return ua;

}


CreditAccount createCreditAccount(size_t creditTerm, double creditDept, size_t userId, string cardNumber, string pin, string cvv,
                                  double sumOnBalance, size_t limit, bool isBlocked, string expiryDate,
                                  string creditExpiryDate){

    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("ATM.db", &DB);

   // cout << "STATE OF TABLE BEFORE INSERT" << endl;


    CreditAccount ca(creditTerm,creditDept,userId,cardNumber,pin,cvv,sumOnBalance,limit,isBlocked,"");
    expiryDate = ca.expiryDate();
    creditExpiryDate = ca.creditExpiryDate();
    sumOnBalance = ca.sumOnBalance();
    string sql("INSERT INTO CREDIT_ACCOUNT (account_number,pin,expiry_date, cvv_number, sum_on_balance,credit_term,credit_expiry_date,credit_debt, user_id)"
               " VALUES('"  + cardNumber + "', '" + pin+ "', '" + expiryDate  + "', '" + cvv + "', "+ to_string(sumOnBalance) + ", "+ to_string(creditTerm)+", '"+ creditExpiryDate+ "', " + to_string(creditDept)+ ", "+ to_string(userId) + ");"
    );


    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messaggeError);
        printf(messaggeError);
    }
//    else
//        std::cout << "Records created Successfully!" << std::endl;

   // cout << "STATE OF TABLE AFTER INSERT" << endl;

    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);

    return ca;
}


DepositAccount createDepositAccount(size_t userId, string cardNumber, string pin, string cvv, double sumOnBalance,
                                    size_t limit,string expiryDate,  bool isBlocked,size_t depositTerm, size_t depositPercentage,
                                    string depositExpiryDate){

    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("ATM.db", &DB);

    //cout << "STATE OF TABLE BEFORE INSERT" << endl;
    DepositAccount da(userId,cardNumber,pin,cvv,sumOnBalance,limit,"",false,depositTerm,depositPercentage,"");
    expiryDate = da.expiryDate();
    depositExpiryDate = da.depositExpiryDate();
    sumOnBalance = da.sumOnBalance();
    string sql("INSERT INTO DEPOSIT_ACCOUNT (account_number,pin,expiry_date, cvv_number, sum_on_balance,deposit_term,deposit_expiry_date,deposit_percentage, user_id)"
               " VALUES('"  + cardNumber + "', '" + pin+ "', '" + expiryDate  + "', '" + cvv + "', "+ to_string(sumOnBalance) + ", "+ to_string(depositTerm)+", '"+ depositExpiryDate+ "', " + to_string(depositPercentage)+ ", "+ to_string(userId) + ");"
    );


    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messaggeError);
        printf(messaggeError);
    }
//    else
//        std::cout << "Records created Successfully!" << std::endl;

   // cout << "STATE OF TABLE AFTER INSERT" << endl;

    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);

    return da;
}


UniversalAccount getUniversalAccountByUserId(size_t id){

    sqlite3 *db;
    sqlite3_stmt * stmt;

    if (sqlite3_open("ATM.db", &db) == SQLITE_OK)
    {
        sqlite3_prepare( db, "SELECT * FROM UNIVERSAL_ACCOUNT;", -1, &stmt, NULL );//preparing the statement
        sqlite3_step( stmt );//executing the statement
        char * str = (char *) sqlite3_column_text( stmt, 0 );///reading the 1st column of the result
    }
    else
    {
        cout << "Failed to open db\n";
    }

    vector<vector < string > > result;

    for( int i = 0; i < 6; i++ )
        result.push_back(vector<string >());

    while( sqlite3_column_text( stmt, 0 ) )
    {
        for( int i = 0; i < 6; i++ )
            result[i].push_back( std::string( (char *)sqlite3_column_text( stmt, i ) ) );
        sqlite3_step( stmt );
    }


    try{ for(int i = 0;i<result.size();i++){
            if(stoi(result[5][i]) == id){
                sqlite3_finalize(stmt);
                sqlite3_close(db);
                return UniversalAccount(stoi(result[5][i]), result[0][i],result[1][i], result[3][i], stoi(result[4][i]), 10000,false, result[2][i]);

            }
        }} catch (exception e) {
    }


    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return UniversalAccount();
}

UniversalAccount getUniversalAccountByCardAndPin(string card, string pin){

    sqlite3 *db;
    sqlite3_stmt * stmt;

    if (sqlite3_open("ATM.db", &db) == SQLITE_OK)
    {
        sqlite3_prepare( db, "SELECT * FROM UNIVERSAL_ACCOUNT;", -1, &stmt, NULL );//preparing the statement
        sqlite3_step( stmt );//executing the statement
        char * str = (char *) sqlite3_column_text( stmt, 0 );///reading the 1st column of the result
    }
    else
    {
        cout << "Failed to open db\n";
    }

    vector<vector < string > > result;

    for( int i = 0; i < 6; i++ )
        result.push_back(vector<string >());

    while( sqlite3_column_text( stmt, 0 ) )
    {
        for( int i = 0; i < 6; i++ )
            result[i].push_back( std::string( (char *)sqlite3_column_text( stmt, i ) ) );
        sqlite3_step( stmt );
    }


    try{ for(int i = 0;i<result.size();i++){
            if(result[0][i] == card && result[1][i] == pin){
                sqlite3_finalize(stmt);
                sqlite3_close(db);
                return UniversalAccount(stoi(result[5][i]), result[0][i],result[1][i], result[3][i], stoi(result[4][i]), 10000,false, result[2][i]);

            }
        }} catch (exception e) {
    }


    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return UniversalAccount();
}

CreditAccount getCreditAccountByUserId(size_t id){


    sqlite3 *db;
    sqlite3_stmt * stmt;

    if (sqlite3_open("ATM.db", &db) == SQLITE_OK)
    {
        sqlite3_prepare( db, "SELECT * FROM CREDIT_ACCOUNT;", -1, &stmt, NULL );//preparing the statement
        sqlite3_step( stmt );//executing the statement
        char * str = (char *) sqlite3_column_text( stmt, 0 );///reading the 1st column of the result
    }
    else
    {
        cout << "Failed to open db\n";
    }

    vector<vector < string > > result;

    for( int i = 0; i < 9; i++ )
        result.push_back(vector<string >());

    while( sqlite3_column_text( stmt, 0 ) )
    {
        for( int i = 0; i < 9; i++ )
            result[i].push_back( std::string( (char *)sqlite3_column_text( stmt, i ) ) );
        sqlite3_step( stmt );
    }


    try{ for(int i = 0;i<result.size();i++){
            if(stoi(result[8][i]) == id){
                sqlite3_finalize(stmt);
                sqlite3_close(db);
                return CreditAccount(stoi(result[5][i]),stoi(result[7][i]),id,result[0][i],result[1][i],result[3][i],stoi(result[4][i]),10000,false,result[2][i],result[6][i]);

            }
        }} catch (exception e) {
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return CreditAccount();
}

CreditAccount getCreditAccountByCardAndPin(string card, string pin){


    sqlite3 *db;
    sqlite3_stmt * stmt;

    if (sqlite3_open("ATM.db", &db) == SQLITE_OK)
    {
        sqlite3_prepare( db, "SELECT * FROM CREDIT_ACCOUNT;", -1, &stmt, NULL );//preparing the statement
        sqlite3_step( stmt );//executing the statement
        char * str = (char *) sqlite3_column_text( stmt, 0 );///reading the 1st column of the result
    }
    else
    {
        cout << "Failed to open db\n";
    }

    vector<vector < string > > result;

    for( int i = 0; i < 9; i++ )
        result.push_back(vector<string >());

    while( sqlite3_column_text( stmt, 0 ) )
    {
        for( int i = 0; i < 9; i++ )
            result[i].push_back( std::string( (char *)sqlite3_column_text( stmt, i ) ) );
        sqlite3_step( stmt );
    }


    try{ for(int i = 0;i<result.size();i++){
            if(result[0][i] == card && result[1][i] == pin){
                return CreditAccount(stoi(result[5][i]),stoi(result[7][i]),stoi(result[8][i]),result[0][i],result[1][i],result[3][i],stoi(result[4][i]),10000,false,result[2][i],result[6][i]);
                sqlite3_finalize(stmt);
                sqlite3_close(db);
            }
        }} catch (exception e) {
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return CreditAccount();
}

DepositAccount getDepositAccountByUserId(size_t id){

    DepositAccount da();
    sqlite3 *db;
    sqlite3_stmt * stmt;
    if (sqlite3_open("ATM.db", &db) == SQLITE_OK)
    {
        sqlite3_prepare( db, "SELECT * FROM DEPOSIT_ACCOUNT;", -1, &stmt, NULL );//preparing the statement
        sqlite3_step( stmt );//executing the statement
        char * str = (char *) sqlite3_column_text( stmt, 0 );///reading the 1st column of the result
    }
    else
    {
        cout << "Failed to open db\n";
    }

    vector<vector < string > > result;

    for( int i = 0; i < 9; i++ )
        result.push_back(vector<string >());

    while( sqlite3_column_text( stmt, 0 ) )
    {
        for( int i = 0; i < 9; i++ )
            result[i].push_back( std::string( (char *)sqlite3_column_text( stmt, i ) ) );
        sqlite3_step( stmt );
    }


    try{ for(int i = 0;i<result.size();i++){
            if(stoi(result[8][i]) == id){
                return DepositAccount(id,result[0][i],result[1][i],result[3][i],stoi(result[4][i]),10000,result[2][i],false,stoi(result[5][i]),stoi(result[7][i]),result[8][i]);
                sqlite3_finalize(stmt);
                sqlite3_close(db);
            }
        }} catch (exception e) {
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return DepositAccount();
}

DepositAccount getDepositAccountByCardAndPin(string card, string pin){

    DepositAccount da();
    sqlite3 *db;
    sqlite3_stmt * stmt;
    if (sqlite3_open("ATM.db", &db) == SQLITE_OK)
    {
        sqlite3_prepare( db, "SELECT * FROM DEPOSIT_ACCOUNT;", -1, &stmt, NULL );//preparing the statement
        sqlite3_step( stmt );//executing the statement
        char * str = (char *) sqlite3_column_text( stmt, 0 );///reading the 1st column of the result
    }
    else
    {
        cout << "Failed to open db\n";
    }

    vector<vector < string > > result;

    for( int i = 0; i < 9; i++ )
        result.push_back(vector<string >());

    while( sqlite3_column_text( stmt, 0 ) )
    {
        for( int i = 0; i < 9; i++ )
            result[i].push_back( std::string( (char *)sqlite3_column_text( stmt, i ) ) );
        sqlite3_step( stmt );
    }


    try{ for(int i = 0;i<result.size();i++){
            if(result[0][i] == card && result[1][i] == pin){
                return DepositAccount(stoi(result[8][i]),result[0][i],result[1][i],result[3][i],stoi(result[4][i]),10000,result[2][i],false,stoi(result[5][i]),stoi(result[7][i]),result[8][i]);
                sqlite3_finalize(stmt);
                sqlite3_close(db);
            }
        }} catch (exception e) {
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return DepositAccount();
}

void withdrawMoneyFromCreditAccount(size_t amount, CreditAccount& ca){
    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("ATM.db", &DB);

  //  cout << "STATE OF TABLE BEFORE INSERT" << endl;

    string card = ca.cardNumber();
    double sum = ca.sumOnBalance() - amount;
    ca.withdrawMoney(amount);
    string sql("UPDATE CREDIT_ACCOUNT set sum_on_balance ="+ to_string(sum) + " where account_number ='" + card + "';"
    );


    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messaggeError);
        printf(messaggeError);
    }
//    else
//        std::cout << "Records created Successfully!" << std::endl;
//
//    cout << "STATE OF TABLE AFTER INSERT" << endl;

    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);
}



void withdrawMoneyFromUniversalAccount(size_t amount, UniversalAccount& ua){
    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("ATM.db", &DB);

  //  cout << "STATE OF TABLE BEFORE INSERT" << endl;

    string card = ua.cardNumber();
    double sum = ua.sumOnBalance() - amount;
    ua.withdrawMoney(amount);
    string sql("UPDATE UNIVERSAL_ACCOUNT set sum_on_balance ="+ to_string(sum) + " where account_number ='" + card + "';"
    );


    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messaggeError);
        printf(messaggeError);
    }
//    else
//        std::cout << "Records created Successfully!" << std::endl;
//
//    cout << "STATE OF TABLE AFTER INSERT" << endl;

    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);
}


void putMoneyOnCreditAccount(size_t amount, CreditAccount& ca){
    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("ATM.db", &DB);

 //   cout << "STATE OF TABLE BEFORE INSERT" << endl;

    string card = ca.cardNumber();
    double sum = ca.creditDept() - amount;
    ca.putMoney(amount);
    string sql("UPDATE CREDIT_ACCOUNT set credit_debt ="+ to_string(sum) + " where account_number ='" + card + "';"
    );


    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messaggeError);
        printf(messaggeError);
    }
//    else
//        std::cout << "Records created Successfully!" << std::endl;
//
//    cout << "STATE OF TABLE AFTER INSERT" << endl;

    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);
}


void putMoneyOnUniversalAccount(size_t amount, UniversalAccount& ua){
    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("ATM.db", &DB);

  //  cout << "STATE OF TABLE BEFORE INSERT" << endl;
    string card = ua.cardNumber();
    double sum = ua.sumOnBalance() + amount;
    ua.putMoney(amount);
    string sql("UPDATE UNIVERSAL_ACCOUNT set sum_on_balance ="+ to_string(sum) + " where account_number ='" + card + "';"
    );


    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messaggeError);
        printf(messaggeError);
    }
//    else
//        std::cout << "Records created Successfully!" << std::endl;
//
//    cout << "STATE OF TABLE AFTER INSERT" << endl;

    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);
}

void putMoneyOnDepositAccount(size_t amount, DepositAccount& da){
    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("ATM.db", &DB);

 //   cout << "STATE OF TABLE BEFORE INSERT" << endl;

    string card = da.cardNumber();
    double sum = da.sumOnBalance() + amount;
    da.putMoney(amount);
    string sql("UPDATE DEPOSIT_ACCOUNT set sum_on_balance ="+ to_string(sum) + " where account_number ='" + card + "';"
    );


    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messaggeError);
        printf(messaggeError);
    }
//    else
//        std::cout << "Records created Successfully!" << std::endl;
//
//    cout << "STATE OF TABLE AFTER INSERT" << endl;

    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);
}



#endif //STARBANKATM_MOOP_KMA_ACCOUNTSERVICE_H