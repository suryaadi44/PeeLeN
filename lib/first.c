#include "first.h"

void directoryCheck() {
    struct stat st = { 0 };

    if (stat("db_cust", &st) == -1) {
        mkdir("db_cust");
    }

    if (stat("db_user", &st) == -1) {
        mkdir("db_user");
    }
}

void accCheck() {
    FILE* f, * rek;

    f = fopen("./db_user/name_pass.csv", "a+");
    rek = fopen("./db_cust/data_cust.csv", "a+");

    int baris = Hbaris("./db_user/name_pass.csv");

    if (baris == 0) {
        fprintf(f, "%d,%s,%s\n", 1, "admin", "admin");
    }
    fclose(rek);
    fclose(f);
}
