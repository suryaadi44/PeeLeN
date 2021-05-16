#include "cust_func.h"

void viewCust(){

}

void addCust(){
    FILE* database;
    customer cust;

    database = fopen(CUST_DB_PATH, "a+");

    clear();
    header();
    printf(" --> TAMBAH PELANGGAN \n");
    printf("==============================================================================\n");
    printf("                      Masukan Data untuk Pelanggan Baru                       \n");
    printf("==============================================================================\n");
    printf(" Nama Depan    : ");
    fflush(stdin);
    scanf("%[^\n]%*c", cust.namaDepan);
    printf(" Nama Belakang : ");
    fflush(stdin);
    scanf("%[^\n]%*c", cust.namaBelakang);
    printf(" Alamat        : ");
    fflush(stdin);
    scanf("%[^\n]%*c", cust.address);
    printf(" No Telepon    : ");
    fflush(stdin);
    scanf("%[^\n]%*c", cust.telp);
    printf("==============================================================================\n");
    viewRate();
    printf(" Pilih Tarif         : ");
    fflush(stdin);
    scanf("%d", &cust.price);

    cust.id = 1000000 + countLine(CUST_DB_PATH);

    fprintf(database, "%ld,%s,%s,\"%s\",%s,0.0,%d\n", cust.id, cust.namaDepan, cust.namaBelakang, cust.address, cust.telp, cust.price);
    fclose(database);
}

void editCust(){

}

void delCust(){

}

void viewRate(){
    FILE* database;
    rate rates;

    database = fopen(RATE_PATH, "r");
    int max = countLine(RATE_PATH);

    printf(" +----+-----------+---------------+\n");
    printf(" | ID | Batas KWH | Tarif Per-KWH |\n");
    printf(" +----+-----------+---------------+\n");
    for (int i = 0; i < max; i++) {
        fscanf(database, "%d,%d,%d", &rates.id, &rates.limit, &rates.perKWH);
        printf(" | %-2d | %-8d  |  Rp.%-8d  |\n", rates.id, rates.limit, rates.perKWH);
    }
    printf(" +----+-----------+---------------+\n");
    fclose(database);
}