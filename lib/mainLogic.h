#ifndef MAINLOGIC_H_
#define MAINLOGIC_H_

#include <stdlib.h>   
#include <stdio.h>
#include <string.h>
#include <time.h> 

#define USER_DB_PATH "./db_user/name_pass.csv"
#define TEMP_USER_DB_PATH "./db_user/temp.csv"
#define CUST_DB_PATH "./db_cust/data_cust.csv"
#define TEMP_CUST_DB_PATH "./db_cust/temp.csv"

struct tm* waktu;

typedef struct customer {
    int id;
    long noPelanggan;
    char namaDepan[20];
    char namaBelakang[20];
    long usage;
    float rate;
} customer;

typedef struct account {
    int rank;
    char uname[20];
    char pass[20];
}account;

void header();
int pause();
int countLine(char file[]);
void clear();

extern int session;
extern int sessionRank;

#endif
