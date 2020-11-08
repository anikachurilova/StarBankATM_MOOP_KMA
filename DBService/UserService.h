////
//// Created by Valerie Luniakina on 08.11.2020.
////
//
//#ifndef STARBANKATM_MOOP_KMA_USERSERVICE_H
//#define STARBANKATM_MOOP_KMA_USERSERVICE_H
////
//// Created by Valerie Luniakina on 07.11.2020.
////
//
//#include <cstdio>
//#include <sqlite3.h>
//#include <vector>
//#include "../models/User.h"
//static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
//    int i;
//    for(i = 0; i<argc; i++) {
//        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
//    }
//    printf("\n");
//    return 0;
//}
//
//void createUser(size_t iduser, string firstname, string lastname, string middlename){
////    sqlite3 *db;
////    char *zErrMsg = 0;
////    int rc;
////    char *sql;
////    const char* data = "Callback function called";
////    sqlite3_stmt *stmt = NULL;
////
////    /* Open database */
////    rc = sqlite3_open("ATM.db", &db);
////
////    if( rc ) {
////        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
////        //  return(0);
////    } else {
////        fprintf(stdout, "Opened database successfully\n");
////    }
////
////    sql = "INSERT INTO USER (id_user,first_name,last_name,middle_name) "  \
////         "VALUES (" << to_string(id_user) << ", ?, 'last_name', 'middle_name'); " ;
//
//
//    sqlite3* DB;
//    char* messaggeError;
//    int exit = sqlite3_open("ATM.db", &DB);
//    string query = "SELECT * FROM PERSON;";
//
//    cout << "STATE OF TABLE BEFORE INSERT" << endl;
//
//    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
//
//    string sql("INSERT INTO USER (`id_user`,`first_name`,`last_name`,`middle_name`)"
//               " VALUES(" + to_string(iduser) + ", '" + firstname + "', '" + lastname + "', '" + middlename + "');"
//               );
//
//    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
//    if (exit != SQLITE_OK) {
//        std::cerr << "Error Insert" << std::endl;
//        sqlite3_free(messaggeError);
//        printf(messaggeError);
//    }
//    else
//        std::cout << "Records created Successfully!" << std::endl;
//
//    cout << "STATE OF TABLE AFTER INSERT" << endl;
//
//    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
//
//
////    sql+= id_user;
////    sql +=',';
////    sql += first_name;
//
////    rc = sqlite3_prepare_v2(db, sql, strlen(sql)+1, &stmt, NULL);
////    if (rc != SQLITE_OK) {
////        printf("Failed to prepare statement: %s\n\r", sqlite3_errstr(rc));
////        sqlite3_close(db);
////        //return 1;
////    }
////    else {
////        printf("SQL statement prepared: OK\n\n\r");
////    }
////
////    rc = sqlite3_bind_int(stmt, 1, id_user);
////
////
////    if (rc != SQLITE_OK) {
////        printf("Failed to bind parameter: %s\n\r", sqlite3_errstr(rc));
////        sqlite3_close(db);
////      //  return 1;
////    }
////    else {
////        printf("SQL bind integer param: OK\n\n\r");
////    }
//
////    /* Execute SQL statement */
////    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
////
////    if( rc != SQLITE_OK ){
////        fprintf(stderr, "SQL error: %s\n", zErrMsg);
////        sqlite3_free(zErrMsg);
////    } else {
////        fprintf(stdout, "Records created successfully\n");
////    }
//
// //   sqlite3_close(db);
//
//    sqlite3_close(DB);
//
//}
//
//
//User selectUserById(size_t id){
////    sqlite3* DB;
////    char* messaggeError;
////    int exit = sqlite3_open("ATM.db", &DB);
////  //  string query = "SELECT * FROM PERSON;";
////
////    cout << "STATE OF TABLE BEFORE INSERT" << endl;
////
////   // sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
////
////    string sql("SELECT first_name FROM USER WHERE id_user=" + to_string(id) +";");
////
////
////
////
////
////    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
////    if (exit != SQLITE_OK) {
////        std::cerr << "Error Insert" << std::endl;
////        sqlite3_free(messaggeError);
////        printf(messaggeError);
////    }
////    else
////        std::cout << "Records created Successfully!" << std::endl;
////
////    cout << "STATE OF TABLE AFTER INSERT" << endl;
////
////    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);
////    sqlite3_close(DB);
//
//
//
//    sqlite3 *db;
//    sqlite3_stmt * stmt;
//
//    if (sqlite3_open("ATM.db", &db) == SQLITE_OK)
//    {
//        sqlite3_prepare( db, "SELECT * FROM USER;", -1, &stmt, NULL );//preparing the statement
//        sqlite3_step( stmt );//executing the statement
//        char * str = (char *) sqlite3_column_text( stmt, 0 );///reading the 1st column of the result
//    }
//    else
//    {
//        cout << "Failed to open db\n";
//    }
//
//
//
//
//    vector<vector < string > > result;
//
//    for( int i = 0; i < 4; i++ )
//        result.push_back(vector<string >());
//
//    while( sqlite3_column_text( stmt, 0 ) )
//    {
//        for( int i = 0; i < 4; i++ )
//            result[i].push_back( std::string( (char *)sqlite3_column_text( stmt, i ) ) );
//        sqlite3_step( stmt );
//    }
//
//
//    try{ for(int i = 0;i<result.size();i++){
//            if(stoi(result[0][i]) == id){
//                cout << stoi(result[0][i]) << endl;
//                return User(id,result[1][i], result[2][i], result[3][i]);
//            }
//        }} catch (exception e) {
//    }
//
//
//    sqlite3_finalize(stmt);
//    sqlite3_close(db);
//}
//
//User selectUserByCard(string card){
//
//    sqlite3 *db;
//    sqlite3_stmt * stmt;
//    size_t userId = 0;
//
//    if (sqlite3_open("ATM.db", &db) == SQLITE_OK)
//    {
//        sqlite3_prepare( db, "SELECT account_number, user_id FROM CREDIT_ACCOUNT;", -1, &stmt, NULL );//preparing the statement
//        sqlite3_step( stmt );//executing the statement
//        char * str = (char *) sqlite3_column_text( stmt, 0 );///reading the 1st column of the result
//    }
//    else
//    {
//        cout << "Failed to open db\n";
//    }
//
//
//    vector<vector < string > > result;
//
//    for( int i = 0; i < 4; i++ )
//        result.push_back(vector<string >());
//
//    while( sqlite3_column_text( stmt, 0 ) )
//    {
//        for( int i = 0; i < 4; i++ )
//            result[i].push_back( std::string( (char *)sqlite3_column_text( stmt, i ) ) );
//        sqlite3_step( stmt );
//    }
//
//
//    try{ for(int i = 0;i<result.size();i++){
//            if(result[0][i] == card){
//                userId = stoi(result[1][i]);
//               // cout << stoi(result[0][i]) << endl;
//                //return User(id,result[1][i], result[2][i], result[3][i]);
//            }
//        }} catch (exception e) {
//    }
//
//
//
//    sqlite3_stmt * stmt1;
//
//
//    if (sqlite3_open("ATM.db", &db) == SQLITE_OK)
//    {
//        sqlite3_prepare( db, "SELECT account_number, user_id FROM DEPOSIT_ACCOUNT;", -1, &stmt1, NULL );//preparing the statement
//        sqlite3_step( stmt1 );//executing the statement
//        char * str = (char *) sqlite3_column_text( stmt, 0 );///reading the 1st column of the result
//    }
//    else
//    {
//        cout << "Failed to open db\n";
//    }
//
//
//    vector<vector < string > > result1;
//
//    for( int i = 0; i < 4; i++ )
//        result1.push_back(vector<string >());
//
//    while( sqlite3_column_text( stmt1, 0 ) )
//    {
//        for( int i = 0; i < 4; i++ )
//            result1[i].push_back( std::string( (char *)sqlite3_column_text( stmt1, i ) ) );
//        sqlite3_step( stmt1 );
//    }
//
//
//    try{ for(int i = 0;i<result1.size();i++){
//            if(result1[0][i] == card){
//                userId = stoi(result[1][i]);
//                // cout << stoi(result[0][i]) << endl;
//                //return User(id,result[1][i], result[2][i], result[3][i]);
//            }
//        }} catch (exception e) {
//    }
//
//
//
//
//
//
//
//    sqlite3_stmt * stmt2;
//
//
//    if (sqlite3_open("ATM.db", &db) == SQLITE_OK)
//    {
//        sqlite3_prepare( db, "SELECT account_number, user_id FROM UNIVERSAL_ACCOUNT;", -1, &stmt2, NULL );//preparing the statement
//        sqlite3_step( stmt2 );//executing the statement
//        char * str = (char *) sqlite3_column_text( stmt2, 0 );///reading the 1st column of the result
//    }
//    else
//    {
//        cout << "Failed to open db\n";
//    }
//
//
//    vector<vector < string > > result2;
//
//    for( int i = 0; i < 4; i++ )
//        result2.push_back(vector<string >());
//
//    while( sqlite3_column_text( stmt2, 0 ) )
//    {
//        for( int i = 0; i < 4; i++ )
//            result2[i].push_back( std::string( (char *)sqlite3_column_text( stmt2, i ) ) );
//        sqlite3_step( stmt2 );
//    }
//
//
//    try{ for(int i = 0;i<result2.size();i++){
//            if(result2[0][i] == card){
//                userId = stoi(result[1][i]);
//                // cout << stoi(result[0][i]) << endl;
//                //return User(id,result[1][i], result[2][i], result[3][i]);
//            }
//        }} catch (exception e) {
//    }
//
//
//    sqlite3_finalize(stmt);
//    sqlite3_close(db);
//
//
//
//    return selectUserById(userId);
//
//
//
//
//
//
//}
//
//
//void getAllUsers(){// make not void
//    sqlite3* DB;
//    char* messaggeError;
//    int exit = sqlite3_open("ATM.db", &DB);
//    //string query = "SELECT * FROM PERSON;";
//
//    cout << "STATE OF TABLE BEFORE INSERT" << endl;
//
//   // sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
//
//    string sql("SELECT * FROM USER;");
//
//    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
//    if (exit != SQLITE_OK) {
//        std::cerr << "Error SELECT" << std::endl;
//        sqlite3_free(messaggeError);
//        printf(messaggeError);
//    }
//    else
//        std::cout << "Records selected Successfully!" << std::endl;
//
//    cout << "STATE OF TABLE AFTER SELECT" << endl;
//
//    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);
//
//    sqlite3_close(DB);
//
//
//
//
//
//
//
//
//
//    //--------------------
//
//
//}
//
//
//void deleteUsers(size_t iduser){
//    sqlite3* DB;
//    char* messaggeError;
//    int exit = sqlite3_open("ATM.db", &DB);
//   // string query = "SELECT * FROM PERSON;";
//
//    cout << "STATE OF TABLE BEFORE INSERT" << endl;
//
//  //  sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
//
//    string sql("DELETE FROM USER WHERE id_user = " + to_string(iduser) + ";");
//
//    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
//    if (exit != SQLITE_OK) {
//        std::cerr << "Error DELETE" << std::endl;
//        sqlite3_free(messaggeError);
//        printf(messaggeError);
//    }
//    else
//        std::cout << "Records deleted Successfully!" << std::endl;
//
//    cout << "STATE OF TABLE AFTER delete" << endl;
//
//    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);
//
//    sqlite3_close(DB);
//
//}
//#endif //STARBANKATM_MOOP_KMA_USERSERVICE_H
