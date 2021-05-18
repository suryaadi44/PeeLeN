#include "cust_func.h"

void viewCust() {
    FILE* database;
    customer cust;

    long id;
    int max = countLine(CUST_DB_PATH);

    database = fopen(CUST_DB_PATH, "r");

    clear();
    header();
    printf(" --> TAMPILKAN PELANGGAN \n");
    printf("==============================================================================\n");
    printf("                 Masukan ID Pelanggan yang Ingin Ditampilkan                  \n");
    printf("==============================================================================\n");
    printf(" ID Pelanggan    : ");
    fflush(stdin);
    scanf("%ld", &id);
    printf("==============================================================================\n");
    for (int i = 0; i < max; i++) {
        fscanf(database, "%ld,%[^,],%[^,],\"%[^\"]\",%[^,],%f,%d\n", &cust.id, cust.namaDepan, cust.namaBelakang, cust.address, cust.telp, &cust.usage, &cust.price);
        if (cust.id == id) {
            printf(" ID            : %ld\n", cust.id);
            printf(" Nama Depan    : %s\n", cust.namaDepan);
            printf(" Nama Belakang : %s\n", cust.namaBelakang);
            printf(" Alamat        : %s\n", cust.address);
            printf(" No Telepon    : %s\n", cust.telp);
            printf(" Tarif         : %d\n", cust.price);
        }
    }
    printf("==============================================================================\n");
    fclose(database);
}

void addCust() {
    FILE* database;
    customer cust;

    int max = countLine(CUST_DB_PATH);
    database = fopen(CUST_DB_PATH, "a+");

    clear();
    header();

    if (max == 0) {
        cust.id = 1000000;
    } else {
        for (int i = 0; i < max; i++) 
            fscanf(database, "%ld,%[^,],%[^,],\"%[^\"]\",%[^,],%f,%d\n", &cust.id, cust.namaDepan, cust.namaBelakang, cust.address, cust.telp, &cust.usage, &cust.price);
        cust.id += 1;
    }

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
    printf("==============================================================================\n");
    printf(" Berhasil Menambahkan Pelanggan Baru dengan ID : %ld ", cust.id);
    printf("==============================================================================\n");

    fprintf(database, "%ld,%s,%s,\"%s\",%s,0.0,%d\n", cust.id, cust.namaDepan, cust.namaBelakang, cust.address, cust.telp, cust.price);
    fclose(database);
}

void editCust() {
    FILE* database, * tempFile;
    customer cust, newData;

    long id;
    int pil;
    int max = countLine(CUST_DB_PATH);

    database = fopen(CUST_DB_PATH, "r");
    tempFile = fopen(TEMP_CUST_DB_PATH, "w");

    clear();
    header();
    printf(" --> UBAH DATA PELANGGAN \n");
    printf("==============================================================================\n");
    printf("                    Masukan ID Pelanggan yang Ingin Diubah                    \n");
    printf("==============================================================================\n");
    printf(" ID Pelanggan    : ");
    fflush(stdin);
    scanf("%ld", &id);
    printf("==============================================================================\n");
    printf("                         Pilih Data yang Ingin Diubah                         \n");
    printf("==============================================================================\n");
    printf(" Data :  \n");
    printf(" --> 1. Nama \n");
    printf(" --> 2. Alamat \n");
    printf(" --> 3. Nomor Telepon \n");
    printf(" --> 4. Tarif \n");
    printf(" Pilihan : ");
    fflush(stdin);
    scanf("%d", &pil);

    while (pil > 4 && pil < 1) {
        printf(" Pilihan Tidak Tersedia\n");
        printf(" Masukan Kembali : ");
        fflush(stdin);
        scanf("%d", &pil);
    }

    printf("==============================================================================\n");
    printf("                    Masukan Dat Pelanggan yang Ingin Diubah                   \n");
    printf("==============================================================================\n");

    switch (pil) {
    case 1:
        printf(" Nama Depan    : ");
        fflush(stdin);
        scanf("%[^\n]%*c", newData.namaDepan);
        printf(" Nama Belakang : ");
        fflush(stdin);
        scanf("%[^\n]%*c", newData.namaBelakang);
        break;
    case 2:
        printf(" Alamat        : ");
        fflush(stdin);
        scanf("%[^\n]%*c", newData.address);
        break;
    case 3:
        printf(" No Telepon    : ");
        fflush(stdin);
        scanf("%[^\n]%*c", newData.telp);
        break;
    }
    printf("==============================================================================\n");


    for (int i = 0; i < max; i++) {
        fscanf(database, "%ld,%[^,],%[^,],\"%[^\"]\",%[^,],%f,%d\n", &cust.id, cust.namaDepan, cust.namaBelakang, cust.address, cust.telp, &cust.usage, &cust.price);
        if (cust.id == id) {
            switch (pil) {
            case 1:
                fprintf(tempFile, "%ld,%s,%s,\"%s\",%s,%f,%d\n", cust.id, newData.namaDepan, newData.namaBelakang, cust.address, cust.telp, cust.usage, cust.price);
                break;
            case 2:
                fprintf(tempFile, "%ld,%s,%s,\"%s\",%s,%f,%d\n", cust.id, cust.namaDepan, cust.namaBelakang, newData.address, cust.telp, cust.usage, cust.price);
                break;
            case 3:
                fprintf(tempFile, "%ld,%s,%s,\"%s\",%s,%f,%d\n", cust.id, cust.namaDepan, cust.namaBelakang, cust.address, newData.telp, cust.usage, cust.price);
                break;
            }
        } else {
            fprintf(tempFile, "%ld,%s,%s,\"%s\",%s,%f,%d\n", cust.id, cust.namaDepan, cust.namaBelakang, cust.address, cust.telp, cust.usage, cust.price);
        }
    }

    fclose(database);
    fclose(tempFile);

    remove(CUST_DB_PATH);
    rename(TEMP_CUST_DB_PATH, CUST_DB_PATH);
}

void delCust() {
    FILE* database, * tempFile;
    customer cust;

    long id;
    int max = countLine(CUST_DB_PATH);

    database = fopen(CUST_DB_PATH, "r");
    tempFile = fopen(TEMP_CUST_DB_PATH, "w");

    clear();
    header();
    printf(" --> HAPUS PELANGGAN \n");
    printf("==============================================================================\n");
    printf("                   Masukan ID Pelanggan yang Ingin Dihapus                    \n");
    printf("==============================================================================\n");
    printf(" ID Pelanggan    : ");
    fflush(stdin);
    scanf("%ld", &id);
    printf("==============================================================================\n");

    for (int i = 0; i < max; i++) {
        fscanf(database, "%ld,%[^,],%[^,],\"%[^\"]\",%[^,],%f,%d\n", &cust.id, cust.namaDepan, cust.namaBelakang, cust.address, cust.telp, &cust.usage, &cust.price);
        if (cust.id != id)
            fprintf(tempFile, "%ld,%s,%s,\"%s\",%s,%f,%d\n", cust.id, cust.namaDepan, cust.namaBelakang, cust.address, cust.telp, cust.usage, cust.price);
    }

    fclose(database);
    fclose(tempFile);

    remove(CUST_DB_PATH);
    rename(TEMP_CUST_DB_PATH, CUST_DB_PATH);
}