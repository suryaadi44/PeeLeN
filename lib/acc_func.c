#include "acc_func.h" 

#define USER_DB_PATH "./db_user/name_pass.csv"
#define TEMP_USER_DB_PATH "./db_user/temp.csv"

int login() {
    FILE* database;
    account acc;

    char user[20];
    char pass[20];
    int i, status = 0;

    int line = countLine(USER_DB_PATH);
    database = fopen(USER_DB_PATH, "r");

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

void addAcc() {
    FILE* database;
    account acc;
    char rank;

    database = fopen(USER_DB_PATH, "a+");

    clear();
    header();

    if (sessionRank != 1) {
        printf("Anda tidak memiliki ijin untuk mengakses menu ini");
        return;
    }

    printf(" --> BUAT AKUN BARU \n");
	printf("==============================================================================\n");
    printf("                         Masukan Data untuk Akun Baru                         \n");
    printf("==============================================================================\n");
    printf("Username : ");
    fflush(stdin);
    scanf("%[^\n]%*c", acc.uname);
    printf("Password : ");
    fflush(stdin);
    scanf("%[^\n]%*c", acc.pass);

    while (rank != 'y' && rank != 'n') {
        printf("\nJadikan User Sebagai admin? (y/n) : ");
        fflush(stdin);
        scanf("%d", &rank);
    }
    
    if(rank == 'y')
        acc.rank = 1;
    else 
        acc.rank = 2;

    fprintf(database, "%d,%s,%s\n", acc.rank, acc.uname, acc.pass);
}

void delAcc(){
    FILE* database, *tempFile;
    account acc;
    char rank;

    database = fopen(USER_DB_PATH, "a+");
    tempFile = fopen(TEMP_USER_DB_PATH, "a+");
    clear();
    header();
}