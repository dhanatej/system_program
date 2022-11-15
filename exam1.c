#include<sqlite3.h>
#include<stdio.h>
int main(void) {
        sqlite3 *db;
        char *err_msg = 0;
        int rc = sqlite3_open("test.db",&db);
        if(rc != SQLITE_OK) {
                fprintf(stderr,"Cannot open database: %s\n", sqlite3_errmsg(db));
                sqlite3_close(db);
                return 1;
        }
        char *sql = "DROP TABLE IF EXISTS Cars;"
                    "CREATE TABLE Cars(Id INT,Name TEXT, Price INT);"
                    "INSERT INTO Cars VALUES(1,'Audi',52642);"
                    "INSERT INTO Cars VALUES(1,'Mercedes',52127);"
                    "INSERT INTO Cars VALUES(1,'Skoda',9000);"
                    "INSERT INTO Cars VALUES(1,'Volvo',20000);"
                    "INSERT INTO Cars VALUES(1,'Bentley',350000);"
                    "INSERT INTO Cars VALUES(1,'Citroen',21000);"
                    "INSERT INTO Cars VALUES(1,'Hummer',41400);"
                    "INSERT INTO Cars VALUES(1,'Volkswagen',21600);";
        rc = sqlite3_exec(db,sql,0,0,&err_msg);
        if(rc != SQLITE_OK) {
                fprintf(stderr,"SQL error:%s\n",err_msg);
                sqlite3_free(err_msg);
                sqlite3_close(db);
                return 1;
        }
        sqlite3_close(db);
        return 0;
}
