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

void createUser(size_t id_user, string first_name, string last_name, string middle_name){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    const char* data = "Callback function called";

    /* Open database */
    rc = sqlite3_open("ATM.db", &db);

    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      //  return(0);
    } else {
        fprintf(stdout, "Opened database successfully\n");
    }

        sql = "INSERT INTO USER (id_user,first_name,last_name,middle_name) "  \
         "VALUES ( \'id_user\', \'first_name\', \'last_name\', \'middle_name\'); " ;



    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Records created successfully\n");
    }

    sqlite3_close(db);

}
