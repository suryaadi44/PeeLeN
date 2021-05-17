#include "mainLogic.h"

int session = -1;
int sessionRank = 0;

void header() {
	time_t mentah;
	struct tm* waktu;
	time(&mentah);
	waktu = localtime(&mentah);

	printf("\n==============================================================================\n");
	printf("|                                                                            |\n");
	printf("|   /$$$$$$$  /$$$$$$$$       /$$$$$$$$ /$$             /$$$$$$$$ /$$   /$$  |\n");
	printf("|  | $$__  $$| $$_____/      | $$_____/| $$            | $$_____/| $$$ | $$  |\n");
	printf("|  | $$    $$| $$            | $$      | $$            | $$      | $$$$| $$  |\n");
	printf("|  | $$$$$$$/| $$$$$         | $$$$$   | $$            | $$$$$   | $$ $$ $$  |\n");
	printf("|  | $$____/ | $$__/         | $$__/   | $$            | $$__/   | $$  $$$$  |\n");
	printf("|  | $$      | $$            | $$      | $$            | $$      | $$   $$$  |\n");
	printf("|  | $$      | $$$$$$$$      | $$$$$$$$| $$$$$$$$      | $$$$$$$$| $$    $$  |\n");
	printf("|  |__/      |________/      |________/|________/      |________/|__/   __/  |\n");
	printf("|                                                                            |\n");
	printf("|                             %02d/%02d/%d %02d:%02d:%02d                            |\n", waktu->tm_mday, waktu->tm_mon + 1, waktu->tm_year + 1900, waktu->tm_hour, waktu->tm_min, waktu->tm_sec);
	printf("==============================================================================\n");
}

int countLine(char file[]){
	FILE* cek;
    int i = 0;
    int cs;

    cek = fopen(file, "r");
    while (!feof(cek)) {               //Loop hingga EOF  1
        cs = fgetc(cek);               //simpan stream char ke c
        if (cs == '\n') i++;          //Jika dideteksi \n , tambah i
    }
    fclose(cek);
    return i;
}

int pause() {
    char pil;
    printf("\nLanjutkan? (y/t) : ");
    fflush(stdin);
    scanf("%c", &pil);

    if (pil == 'y') return 1;
    else return 0;
}

void clear() {
#ifdef _WIN32
    std : system("cls");
#else
std: system("clear");
#endif
}

void price(){
	FILE*file;
	file=fopen(TEMP_CUST_DB_PATH,"a+");
	
	int baris = countLine(TEMP_CUST_DB_PATH);
    if (baris == 0){
        fprintf(file, "1,450,200\n");
        fprintf(file, "2,900,1400\n");
        fprintf(file, "3,1300,1600\n");
        fprintf(file, "4,2200,1900\n");
        fprintf(file, "5,3100,2300\n");
    }
    fclose(file);
}