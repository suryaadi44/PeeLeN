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
#define RATE_PATH "./config/config.csv"
#define TEMP_RATE_PATH "./config/temp.csv"

struct tm* waktu;

typedef struct customer {
    long id;
    char namaDepan[20];
    char namaBelakang[20];
    char address[70];
    char telp[15];
    float usage;
    int price;
} customer;

typedef struct account {
    int rank;
    char uname[20];
    char pass[20];
}account;

typedef struct rate {
    int id;
    int limit;
    int perKWH;
} rate;

void header();
void viewRate();
int pause();
int countLine(char file[]);
void clear();

extern int session;
extern int sessionRank;

#endif
