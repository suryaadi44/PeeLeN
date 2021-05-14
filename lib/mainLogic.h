#ifndef MAINLOGIC_H_
#define MAINLOGIC_H_

#include <stdlib.h>   
#include <stdio.h>
#include <string.h>
#include <time.h> 

struct tm* waktu;

typedef struct customer {
    int id;
    long noPelanggan;
    char namaDepan[20];
    char namaBelakang[20];
    long usage;
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

#endif //MAINLOGIC_H_