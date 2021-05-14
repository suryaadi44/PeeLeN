#include "login_func.h" 

int login(){
    FILE *database;
    account acc;

    char user[20];
    char pass[20];
    int i, status = 0;

    int line = countLine("./db_user/name_pass.csv");
    database = fopen("./db_user/name_pass.csv", "r");

    printf("\nMasukan Username dan password");
    printf("\nUsername : ");
    scanf("\n");
    scanf("%[^\n]%*c", user);
    printf("Password : ");
    scanf("%[^\n]%*c", pass);


    for (i = 0; i < line && status == 0; i++) {
        fscanf(database, "%d,%[^,],%[^\n]", &acc.rank, acc.uname, acc.pass);
        int cekU = strcmp(acc.uname, user);
        int cekP = strcmp(acc.pass, pass);

        if (cekU == 0 && cekP == 0) {
            status = 1;
            session = i;
            sessionRank = acc.rank;
        }
    }

    fclose(database);
    return status;
}
