#include "acc_func.h" 

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
        scanf("%c", &rank);
    }

    if (rank == 'y')
        acc.rank = 1;
    else
        acc.rank = 2;

    fprintf(database, "%d,%s,%s\n", acc.rank, acc.uname, acc.pass);

    fclose(database);
}

void delAcc() {
    FILE* database, * tempFile;
    account acc;
    char rank;

    int max = countLine(USER_DB_PATH);
    int del;

    database = fopen(USER_DB_PATH, "a+");
    tempFile = fopen(TEMP_USER_DB_PATH, "w");

    clear();
    header();

    if (sessionRank != 1) {
        printf("Anda tidak memiliki ijin untuk mengakses menu ini");
        return;
    }

    printf(" --> HAPUS AKUN \n");
    printf("==============================================================================\n");
    viewAcc();
    printf("\n Pilih ID Akun yang akan Dihapus : ");
    scanf("%d", &del);

    while (del < 1 && del > max) {
        printf("\n Pilihan Tidak Tersedia");
        printf("\n Pilih ID Akun yang akan Dihapus : ");
        scanf("%d", &del);
    }

    for (int i = 0; i < max; i++) {
        if (i != (del - 1)) {
            fscanf(database, "%d,%[^,],%[^\n]", &acc.rank, acc.uname, acc.pass);
            fprintf(tempFile, "%d,%s,%s\n", acc.rank, acc.uname, acc.pass);
        }
    }

    fclose(database);
    fclose(tempFile);

    remove(USER_DB_PATH);
    rename(TEMP_USER_DB_PATH, USER_DB_PATH);
}

void accPassword() {
    FILE* database, * tempFile;
    account acc;
    char newUser[20];
    char newPassword[20];

    int max = countLine(USER_DB_PATH);
    int accID;

    database = fopen(USER_DB_PATH, "a+");
    tempFile = fopen(TEMP_USER_DB_PATH, "w");

    clear();
    header();

    printf(" --> GANTI PASSWORD \n");
    printf("==============================================================================\n");
    if (sessionRank != 1) {
        printf("\n Masukan Password Baru");
        printf("\n Password : ");
        scanf("\n");
        scanf("%[^\n]%*c", newPassword);
        accID = session;
    } else {
        viewAcc();
        printf("\n Pilih ID Akun yang akan Diganti Password : ");
        scanf("%d", &accID);

        while (accID < 1 && accID > max) {
            printf("\n Pilihan Tidak Tersedia");
            printf("\n Pilih ID Akun yang akan Dihapus : ");
            scanf("%d", &accID);
        }
        accID -= 1;

        printf("\n Masukan Password Baru");
        printf("\n Password : ");
        scanf("\n");
        scanf("%[^\n]%*c", newPassword);

    }


    for (int i = 0; i < max; i++) {
        fscanf(database, "%d,%[^,],%[^\n]", &acc.rank, acc.uname, acc.pass);
        if (i == accID) {
            fprintf(tempFile, "%d,%s,%s\n", acc.rank, acc.uname, newPassword);
        } else {
            fprintf(tempFile, "%d,%s,%s\n", acc.rank, acc.uname, acc.pass);
        }
    }

    fclose(database);
    fclose(tempFile);

    remove(USER_DB_PATH);
    rename(TEMP_USER_DB_PATH, USER_DB_PATH);
}

void viewAcc() {
    FILE* database;
    account acc;

    int max = countLine(USER_DB_PATH);
    database = fopen(USER_DB_PATH, "r");

    printf(" +----+--------------------+\n");
    printf(" | ID |      Username      |\n");
    printf(" +----+--------------------+\n");
    for (int i = 0; i < max; i++) {
        fscanf(database, "%d,%[^,],%[^\n]", &acc.rank, acc.uname, acc.pass);
        printf(" | %-2d | %-18s |\n", i + 1, acc.uname);
    }
    printf(" +----+--------------------+\n");
    fclose(database);
}