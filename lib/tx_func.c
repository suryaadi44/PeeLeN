#include "tx_func.h"

void viewUsage() {
    FILE* database, * config;
    customer cust;
    rate rates;

    long id;
    int max = countLine(CUST_DB_PATH);
    int configMax = countLine(RATE_PATH);

    config = fopen(RATE_PATH, "r");
    database = fopen(CUST_DB_PATH, "r");

    clear();
    header();
    printf(" --> TAMPILKAN DATA PENGGUNAAN \n");
    printf("==============================================================================\n");
    printf("                             Masukan ID Pelanggan                             \n");
    printf("==============================================================================\n");
    printf(" ID Pelanggan    : ");
    fflush(stdin);
    scanf("%ld", &id);
    printf("==============================================================================\n");

    for (int i = 0; i < max; i++) {
        fscanf(database, "%ld,%[^,],%[^,],\"%[^\"]\",%[^,],%f,%d\n", &cust.id, cust.namaDepan, cust.namaBelakang, cust.address, cust.telp, &cust.usage, &cust.price);
        if (cust.id == id)
            break;
    }

    for (int i = 0; i < configMax; i++) {
        fscanf(config, "%d,%d,%d", &rates.id, &rates.limit, &rates.perKWH);
        if (rates.id == cust.price)
            break;
    }

    if (cust.id == id) {
        printf(" ID          : %ld\n", cust.id);
        printf(" Nama        : %s %s\n", cust.namaDepan, cust.namaBelakang);
        printf(" Tarif       : %d\n", cust.price);
        printf(" Batas Daya  : %d VA\n", rates.limit);
        printf(" Penggunaan  : %.4f KWH\n", cust.usage);
        printf(" Tagihan     : Rp.%.2f\n", cust.usage * rates.perKWH);
    }
    printf("==============================================================================\n");

    fclose(config);
    fclose(database);
}

void addUsage() {
    FILE* database, * tempFile;
    customer cust;

    long id;
    float add;
    int max = countLine(CUST_DB_PATH);

    database = fopen(CUST_DB_PATH, "r");
    tempFile = fopen(TEMP_CUST_DB_PATH, "a");

    clear();
    header();
    printf(" --> TAMBAH PENGGUNAAN \n");
    printf("==============================================================================\n");
    printf("                             Masukan ID Pelanggan                             \n");
    printf("==============================================================================\n");
    printf(" ID Pelanggan    : ");
    fflush(stdin);
    scanf("%ld", &id);
    printf("==============================================================================\n");
    printf(" Penggunaan      : ");
    fflush(stdin);
    scanf("%f", &add);
    printf("==============================================================================\n");

    for (int i = 0; i < max; i++) {
        fscanf(database, "%ld,%[^,],%[^,],\"%[^\"]\",%[^,],%f,%d\n", &cust.id, cust.namaDepan, cust.namaBelakang, cust.address, cust.telp, &cust.usage, &cust.price);
        if (cust.id == id) {
            cust.usage += add;
            logTX(cust.id, 0, -1, add, cust.usage);
        }
        fprintf(tempFile, "%ld,%s,%s,\"%s\",%s,%f,%d\n", cust.id, cust.namaDepan, cust.namaBelakang, cust.address, cust.telp, cust.usage, cust.price);
    }


    fclose(database);
    fclose(tempFile);

    remove(CUST_DB_PATH);
    rename(TEMP_CUST_DB_PATH, CUST_DB_PATH);
}

void payUsage() {
    FILE* database, * tempFile, * config;
    customer cust;
    rate rates;

    long id;
    int pay;
    int max = countLine(CUST_DB_PATH);
    int configMax = countLine(RATE_PATH);

    config = fopen(RATE_PATH, "r");
    database = fopen(CUST_DB_PATH, "r");
    tempFile = fopen(TEMP_CUST_DB_PATH, "a");

    clear();
    header();
    printf(" --> BAYAR TAGIHAN \n");
    printf("==============================================================================\n");
    printf("                             Masukan ID Pelanggan                             \n");
    printf("==============================================================================\n");
    printf(" ID Pelanggan      : ");
    fflush(stdin);
    scanf("%ld", &id);
    printf("==============================================================================\n");
    printf(" Jumlah Pembayaran : ");
    fflush(stdin);
    scanf("%d", &pay);
    printf("==============================================================================\n");

    for (int i = 0; i < max; i++) {
        fscanf(database, "%ld,%[^,],%[^,],\"%[^\"]\",%[^,],%f,%d\n", &cust.id, cust.namaDepan, cust.namaBelakang, cust.address, cust.telp, &cust.usage, &cust.price);
        if (cust.id == id) {
            for (int i = 0; i < configMax; i++) {
                fscanf(config, "%d,%d,%d", &rates.id, &rates.limit, &rates.perKWH);
                if (rates.id == cust.price)
                    break;
            }
            float usageKWH = ((float)pay / (float)rates.perKWH);
            cust.usage -= usageKWH;
            logTX(cust.id, 1, pay, usageKWH, cust.usage);
        }
        fprintf(tempFile, "%ld,%s,%s,\"%s\",%s,%f,%d\n", cust.id, cust.namaDepan, cust.namaBelakang, cust.address, cust.telp, cust.usage, cust.price);
    }

    fclose(config);
    fclose(database);
    fclose(tempFile);

    remove(CUST_DB_PATH);
    rename(TEMP_CUST_DB_PATH, CUST_DB_PATH);
}

void logTX(long id, int type, int idr,float txKWH, float kwh) {
    FILE* logAcc, * log;

    time_t mentah;
    struct tm* waktu;
    time(&mentah);
    waktu = localtime(&mentah);

    char convert[8];
    char* format = ".csv";
    char* dir = "./tx_log/";
    snprintf(convert, 8, "%ld", id);

    int mem = strlen(convert) + strlen(format) + strlen(dir);
    char file[mem];

    strcpy(file, dir);
    strcat(file, convert);
    strcat(file, format);

    log = fopen(ALL_LOG_PATH, "a");
    logAcc = fopen(file, "a");

    int maxLog = countLine(ALL_LOG_PATH);
    int maxLogAcc = countLine(file);

    if (maxLogAcc == 0) {
        fprintf(logAcc, "No,Waktu,Jenis Transaksi,Jumlah Transaksi,KWH,Total KWH\n");
        maxLogAcc = countLine(file);
    }

    switch (type) {
    case 0:
        fprintf(log, "%d,%02d:%02d:%02d-%02d/%02d/%d,%ld,TAMBAH PENGGUNAAN,-,%.4f,%.4f\n", maxLog, waktu->tm_hour, waktu->tm_min, waktu->tm_sec, waktu->tm_mday, waktu->tm_mon + 1, waktu->tm_year + 1900, id, txKWH, kwh);
        fprintf(logAcc, "%d,%02d:%02d:%02d-%02d/%02d/%d,TAMBAH PENGGUNAAN,-,%.4f,%.4f\n", maxLog, waktu->tm_hour, waktu->tm_min, waktu->tm_sec, waktu->tm_mday, waktu->tm_mon + 1, waktu->tm_year + 1900, txKWH, kwh);
        break;
    case 1:
        fprintf(log, "%d,%02d:%02d:%02d-%02d/%02d/%d,%ld,PEMBAYARAN TAGIHAN,%d,%.4f,%.4f\n", maxLog, waktu->tm_hour, waktu->tm_min, waktu->tm_sec, waktu->tm_mday, waktu->tm_mon + 1, waktu->tm_year + 1900, id, idr, txKWH, kwh);
        fprintf(logAcc, "%d,%02d:%02d:%02d-%02d/%02d/%d,PEMBAYARAN TAGIHAN,%d,%.4f,%.4f\n", maxLog, waktu->tm_hour, waktu->tm_min, waktu->tm_sec, waktu->tm_mday, waktu->tm_mon + 1, waktu->tm_year + 1900, idr, txKWH, kwh);
        break;
    }

    fclose(log);
    fclose(logAcc);
}
