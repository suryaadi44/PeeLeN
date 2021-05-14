#include "lib/mainLogic.h"
#include "lib/login_func.h"
#include "lib/first.h" 

void mainMenu();
void user();
void usage();
void tx();
void setting();

int main() {
	int cek;
	clear();

	directoryCheck();
	accCheck();
	header();

	if (session == -1) cek = login();

	if (cek == 1 || session != -1) mainMenu();
	else printf("Username atau Password Salah!\n");

	return 0;
}

void mainMenu() {
	int pil;

	do {
		printf("==================================================");
		printf("|    APLIKASI PENGELOLA DATA PENGGUNA LISTRIK    |");
		printf("==================================================");
		printf("|                  MENU UTAMA                    |");
		printf("==================================================");
		printf(" --> 1. Pelanggan");
		printf(" --> 2. Data Pemakaian");
		printf(" --> 3. Transaksi");
		printf(" --> 4. Pengaturan");
		printf(" --> 5. Keluar");
		printf("==================================================");
		printf(" --> Pilih menu : ");
		scanf("%d", &pil);
		printf("==================================================");

		switch (pil) {
		case 1:
			user();
			break;
		case 2:
			usage();
			break;
		case 3:
			tx();
			break;
		case 4:
			setting();
			break;
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
		printf(" --> PELANGGAN");
		printf("==================================================");
		printf(" --> 1. Tampilkan Pelanggan");
		printf(" --> 2. Tambah Pelanggan");
		printf(" --> 3. Ubah Data Pelanggan");
		printf(" --> 4. Hapus Pelanggan");
		printf(" --> 5. Kembali");
		printf("==================================================");
		printf(" --> Pilih menu : ");
		scanf("%d", &pil);
		printf("==================================================");

		switch (pil) {
		case 1:

			lanjut = pause();
			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:
			break;
		default:
			break;
		}
	} while (pil != 5 && lanjut == 1);
}

void usage() {
	int pil, lanjut = 1;
	do {
		printf(" --> DATA PEMAKAIAN");
		printf("==================================================");
		printf(" --> 1. Tampilkan Data Penggunaan");
		printf(" --> 2. Tambah Penggunaan");
		printf(" --> 3. Kembali");
		printf("==================================================");
		printf(" --> Pilih menu : ");
		scanf("%d", &pil);
		printf("==================================================");

		switch (pil) {
		case 1:

			lanjut = pause();
			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:
			break;
		default:
			break;
		}
	} while (pil != 3 && lanjut == 1);
}

void tx() {
	int pil, lanjut = 1;
	do {
		printf(" --> DATA TRANSAKSI");
		printf("==================================================");
		printf(" --> 1. Tampilkan Data Transaksi");
		printf(" --> 2. Pembayaran Tagihan");
		printf(" --> 3. Kembali");
		printf("==================================================");
		printf(" --> Pilih menu : ");
		scanf("%d", &pil);
		printf("==================================================");

		switch (pil) {
		case 1:

			lanjut = pause();
			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:
			break;
		default:
			break;
		}
	} while (pil != 3 && lanjut == 1);
}

void setting() {
	int pil;
	do {
		printf(" --> PENGATURAN");
		printf("==================================================");
		printf(" --> 1. Ganti Passowrd");
		printf(" --> 2. Buat Akun Baru");
		printf(" --> 3. Hapus Akun");
		printf(" --> 4. Kembali");
		printf("==================================================");
		printf(" --> Pilih menu : ");
		scanf("%d", &pil);
		printf("==================================================");

		switch (pil) {
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:
			break;
		default:
			break;
		}
	} while (pil != 4);
}
