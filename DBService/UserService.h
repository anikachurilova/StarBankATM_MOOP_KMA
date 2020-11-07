//
// Created by Valerie Luniakina on 08.11.2020.
//

#ifndef STARBANKATM_MOOP_KMA_USERSERVICE_H
#define STARBANKATM_MOOP_KMA_USERSERVICE_H
//
// Created by Valerie Luniakina on 07.11.2020.
//

#include <cstdio>
#include <sqlite3.h>
#include "../models/User.h"
static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for(i = 0; i<argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void createUser(size_t iduser, string firstname, string lastname, string middlename){
//    sqlite3 *db;
//    char *zErrMsg = 0;
//    int rc;
//    char *sql;
//    const char* data = "Callback function called";
//    sqlite3_stmt *stmt = NULL;
//
//    /* Open database */
//    rc = sqlite3_open("ATM.db", &db);
//
//    if( rc ) {
//        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//        //  return(0);
//    } else {
//        fprintf(stdout, "Opened database successfully\n");
//    }
//
//    sql = "INSERT INTO USER (id_user,first_name,last_name,middle_name) "  \
//         "VALUES (" << to_string(id_user) << ", ?, 'last_name', 'middle_name'); " ;


    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("ATM.db", &DB);
    string query = "SELECT * FROM PERSON;";

    cout << "STATE OF TABLE BEFORE INSERT" << endl;

    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    string sql("INSERT INTO USER (`id_user`,`first_name`,`last_name`,`middle_name`)"
               " VALUES(" + to_string(iduser) + ", '" + firstname + "', '" + lastname + "', '" + middlename + "');"
               );

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messaggeError);
        printf(messaggeError);
    }
    else
        std::cout << "Records created Successfully!" << std::endl;

    cout << "STATE OF TABLE AFTER INSERT" << endl;

    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);


//    sql+= id_user;
//    sql +=',';
//    sql += first_name;

//    rc = sqlite3_prepare_v2(db, sql, strlen(sql)+1, &stmt, NULL);
//    if (rc != SQLITE_OK) {
//        printf("Failed to prepare statement: %s\n\r", sqlite3_errstr(rc));
//        sqlite3_close(db);
//        //return 1;
//    }
//    else {
//        printf("SQL statement prepared: OK\n\n\r");
//    }
//
//    rc = sqlite3_bind_int(stmt, 1, id_user);
//
//
//    if (rc != SQLITE_OK) {
//        printf("Failed to bind parameter: %s\n\r", sqlite3_errstr(rc));
//        sqlite3_close(db);
//      //  return 1;
//    }
//    else {
//        printf("SQL bind integer param: OK\n\n\r");
//    }

//    /* Execute SQL statement */
//    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
//
//    if( rc != SQLITE_OK ){
//        fprintf(stderr, "SQL error: %s\n", zErrMsg);
//        sqlite3_free(zErrMsg);
//    } else {
//        fprintf(stdout, "Records created successfully\n");
//    }

 //   sqlite3_close(db);

    sqlite3_close(DB);

}


void selectUserById(size_t id){
    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("ATM.db", &DB);
  //  string query = "SELECT * FROM PERSON;";

    cout << "STATE OF TABLE BEFORE INSERT" << endl;

   // sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    string sql("SELECT * FROM USER WHERE id_user=" + to_string(id) +";");

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messaggeError);
        printf(messaggeError);
    }
    else
        std::cout << "Records created Successfully!" << std::endl;

    cout << "STATE OF TABLE AFTER INSERT" << endl;

    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);


    sqlite3_close(DB);
}

void getAllUsers(){// make not void
    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("ATM.db", &DB);
    //string query = "SELECT * FROM PERSON;";

    cout << "STATE OF TABLE BEFORE INSERT" << endl;

   // sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    string sql("SELECT * FROM USER;");

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error SELECT" << std::endl;
        sqlite3_free(messaggeError);
        printf(messaggeError);
    }
    else
        std::cout << "Records selected Successfully!" << std::endl;

    cout << "STATE OF TABLE AFTER SELECT" << endl;

    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);

}


void deleteUsers(size_t iduser){
    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("ATM.db", &DB);
   // string query = "SELECT * FROM PERSON;";

    cout << "STATE OF TABLE BEFORE INSERT" << endl;

  //  sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    string sql("DELETE FROM USER WHERE id_user = " + to_string(iduser) + ";");

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error DELETE" << std::endl;
        sqlite3_free(messaggeError);
        printf(messaggeError);
    }
    else
        std::cout << "Records deleted Successfully!" << std::endl;

    cout << "STATE OF TABLE AFTER delete" << endl;

    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);

}
#endif //STARBANKATM_MOOP_KMA_USERSERVICE_H
