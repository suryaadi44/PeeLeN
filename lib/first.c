#include "first.h"

void directoryCheck() {
    struct stat st = { 0 };

    if (stat("db_cust", &st) == -1) {
        mkdir("db_cust");
    }

    if (stat("db_user", &st) == -1) {
        mkdir("db_user");
    }

    if (stat("config", &st) == -1) {
        mkdir("config");
    }
}

void fileCheck() {
    FILE* userDB, *custDB, *rate;

    userDB = fopen(USER_DB_PATH, "a+");
    custDB = fopen(CUST_DB_PATH, "a+");
    rate = fopen(RATE_PATH, "a+");

    int baris = countLine(USER_DB_PATH);
    if (baris == 0) 
        fprintf(userDB, "1,admin,admin\n");
    
    baris = countLine(RATE_PATH);
    if (baris == 0){
        fprintf(rate, "1,450,200\n");
        fprintf(rate, "2,900,1400\n");
        fprintf(rate, "3,1300,1600\n");
        fprintf(rate, "4,2200,1900\n");
        fprintf(rate, "5,3100,2300\n");
    }
        
    fclose(userDB);
    fclose(custDB);
    fclose(rate);
}
