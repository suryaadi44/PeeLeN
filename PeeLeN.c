#include "lib/first.h" 
#include "lib/mainLogic.h"
#include "lib/acc_func.h"
#include "lib/cust_func.h"
#include "lib/tx_func.h"

void mainMenu();
void user();
void tx();
void setting();

int main() {
	int cek;

	directoryCheck();
	fileCheck();

	clear();
	header();

	if (session == -1)
		cek = login();

	if (cek)
		mainMenu();
	else
		printf("Username atau Password Salah!\n");

	return 0;
}

void mainMenu() {
	int pil;

	do {
		clear();
		header();
		printf("==============================================================================\n");
		printf("|                  APLIKASI PENGELOLA DATA PENGGUNA LISTRIK                  |\n");
		printf("==============================================================================\n");
		printf("|                                MENU UTAMA                                  |\n");
		printf("==============================================================================\n");
		printf(" --> 1. Pelanggan\n");
		printf(" --> 2. Transaksi\n");
		printf(" --> 3. Pengaturan\n");
		printf(" --> 4. Log Out\n");
		printf(" --> 5. Keluar\n");
		printf("==============================================================================\n");
		printf(" --> Pilih menu : ");
		scanf("%d", &pil);
		printf("==============================================================================\n");

		switch (pil) {
		case 1:
			user();
			break;
		case 2:
			tx();
			break;
		case 3:
			setting();
			break;
		case 4:
			session = -1;
			sessionRank = 0;
			main();
			return;
		case 5:
			break;
		default:
			break;
		}
	} while (pil != 5);
}

void user() {
	int pil, lanjut = 1;
	do {
		clear();
		header();
		printf(" --> PELANGGAN\n");
		printf("==============================================================================\n");
		printf(" --> 1. Tampilkan Pelanggan\n");
		printf(" --> 2. Tambah Pelanggan\n");
		printf(" --> 3. Ubah Data Pelanggan\n");
		printf(" --> 4. Hapus Pelanggan\n");
		printf(" --> 5. Kembali\n");
		printf("==============================================================================\n");
		printf(" --> Pilih menu : ");
		scanf("%d", &pil);
		printf("==============================================================================\n");

		switch (pil) {
		case 1:
			viewCust();
			lanjut = pause();
			break;
		case 2:
			addCust();
			lanjut = pause();
			break;
		case 3:
			editCust();
			break;
		case 4:
			delCust();
			break;
		case 5:
			break;
		default:
			break;
		}
	} while (pil != 5 && lanjut == 1);
}


void tx() {
	int pil, lanjut = 1;
	do {
		clear();
		header();
		printf(" --> DATA TRANSAKSI\n");
		printf("==============================================================================\n");
		printf(" --> 1. Tampilkan Data Penggunaan\n");
		printf(" --> 2. Tambah Penggunaan\n");
		printf(" --> 3. Pembayaran Tagihan\n");
		printf(" --> 4. Kembali\n");
		printf("==============================================================================\n");
		printf(" --> Pilih menu : ");
		scanf("%d", &pil);
		printf("==============================================================================\n");

		switch (pil) {
		case 1:
			viewUsage();
			lanjut = pause();
			break;
		case 2:
			addUsage();
			break;
		case 3:
			payUsage();
			lanjut = pause();
			break;
		case 4:
			break;
		default:
			break;
		}
	} while (pil != 4 && lanjut == 1);
}

void setting() {
	int pil, lanjut;
	do {
		clear();
		header();
		printf(" --> PENGATURAN\n");
		printf("==============================================================================\n");
		printf(" --> 1. Ubah Password\n");
		printf(" --> 2. Buat Akun Baru\n");
		printf(" --> 3. Hapus Akun\n");
		printf(" --> 4. Ubah Tarif\n");
		printf(" --> 5. Kembali\n");
		printf("==============================================================================\n");
		printf(" --> Pilih menu : ");
		scanf("%d", &pil);
		printf("==============================================================================\n");

		switch (pil) {
		case 1:
			accPassword();
			break;
		case 2:
			addAcc();
			break;
		case 3:
			delAcc();
			lanjut = pause();
			break;
		case 4:
			editConfig();
			break;
		case 5:
			break;
		default:
			break;
		}
	} while (pil != 5);
}
