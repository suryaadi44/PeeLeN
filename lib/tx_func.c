#include "tx_func.h"

void addUsage(){
	
	clear();
	header();
	
	customer a;
	FILE*file;
	file=fopen(CUST_DB_PATH,"a+");
	
	int urut=countLine(CUST_DB_PATH);
	
	printf("==========================================================================================\n");
	printf("						              MENU TAMBAH PENGGUNAAN\n");
	printf("==========================================================================================\n");
	printf("ID Pelanggan  : ");
	scanf("%d",a.id);
	printf("Nama Depan    : ");
	fflush(stdin);
	scanf("%[^\n]s",a.namaDepan);
	printf("Nama Belakang : ");
	fflush(stdin);
	scanf("%[^\n]s",a.namaBelakang);
	menu();
	printf("Jumlah KWH    : ");
	scanf("%d",&a.usage);
	printf("No Pelanggan  : %d\n",urut+1);
	a.noPelanggan=urut+1;
	printf("==========================================================================================\n");
	
	fprintf(file,"%d,%s,%s,%d,%d",a.id,a.namaDepan,a.namaBelakang,a.usage,a.noPelanggan);
	
	fclose(file);
	
}

void menu(){
	int i,line,no,jml,tar;
	FILE*file;
	file=fopen(TEMP_CUST_DB_PATH,"r");
	line=countLine(TEMP_CUST_DB_PATH);
	printf("+--------------------------------+\n");
	printf("|    MENU HARGA TARIF PER KWH    |\n");
	printf("+----+------------+--------------+\n");
	printf("| No |  Jmlh KWH  |    Harga     |\n");
	printf("+----+------------+--------------+\n");
	for(i=0;i<line;i++){
		fscanf(file,"%d,%d,%d",no,jml,tar);
		printf("| %-2d |  %-8d  |  Rp.%-8d |\n",no,jml,tar);
	}
	printf("+----+------------+--------------+\n");
	fclose(file);
}