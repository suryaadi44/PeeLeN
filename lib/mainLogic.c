#include "mainLogic.h"

int session = -1;
int sessionRank = 0;

void header() {
	time_t mentah;
	struct tm* waktu;
	time(&mentah);
	waktu = localtime(&mentah);

	printf("==============================================================================");
	printf("|                                                                            |");
	printf("|   /$$$$$$$  /$$$$$$$$       /$$$$$$$$ /$$             /$$$$$$$$ /$$   /$$  |");
	printf("|  | $$__  $$| $$_____/      | $$_____/| $$            | $$_____/| $$$ | $$  |");
	printf("|  | $$    $$| $$            | $$      | $$            | $$      | $$$$| $$  |");
	printf("|  | $$$$$$$/| $$$$$         | $$$$$   | $$            | $$$$$   | $$ $$ $$  |");
	printf("|  | $$____/ | $$__/         | $$__/   | $$            | $$__/   | $$  $$$$  |");
	printf("|  | $$      | $$            | $$      | $$            | $$      | $$   $$$  |");
	printf("|  | $$      | $$$$$$$$      | $$$$$$$$| $$$$$$$$      | $$$$$$$$| $$    $$  |");
	printf("|  |__/      |________/      |________/|________/      |________/|__/   __/  |");
	printf("|                                                                            |");
	printf("|                             %02d/%02d/%d %02d:%02d:%02d                            |\n", waktu->tm_mday, waktu->tm_mon + 1, waktu->tm_year + 1900, waktu->tm_hour, waktu->tm_min, waktu->tm_sec);
	printf("==============================================================================");
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