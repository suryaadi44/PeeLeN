# **PeeLeN**

```
 /$$$$$$$  /$$$$$$$$       /$$$$$$$$ /$$             /$$$$$$$$ /$$   /$$  
| $$__  $$| $$_____/      | $$_____/| $$            | $$_____/| $$$ | $$  
| $$    $$| $$            | $$      | $$            | $$      | $$$$| $$  
| $$$$$$$/| $$$$$         | $$$$$   | $$            | $$$$$   | $$ $$ $$  
| $$____/ | $$__/         | $$__/   | $$            | $$__/   | $$  $$$$  
| $$      | $$            | $$      | $$            | $$      | $$   $$$  
| $$      | $$$$$$$$      | $$$$$$$$| $$$$$$$$      | $$$$$$$$| $$    $$  
|__/      |________/      |________/|________/      |________/|__/   __/  
```

---

Aplikasi Pengelolaan Data Pengguna Listrik Sederhana Berbasis CLI Sebagai Final Project Praktikum Algoritma dan Pemrograman Semester 2.

By :  
- I Komang Surya Adinandika (2008561040)  
- Muhammad Luqman Aristio (2008561022)  
- Made Yosfin Saputra (2008561023)  
- Ira Arituddiniyah (2008561027)  

---

## **Cara Menjalankan Program**

### 1. Vscode dan lainnya yang berbasis terminal

>Jalankan perintah berikut pada terminal :
>
>```
>cd "d:\For School\Kuliah\Semester II\Praktikum Algoritma & Pemrograman\PeeLeN\"  ; if ($?) { gcc "PeeLeN.c" "lib/first.c" "lib/acc_func.c" "lib/cust_func.c" "lib/tx_func.c" "lib/mainLogic.c" -o "PeeLeN" } ; if ($?) { & ".\PeeLeN" } 
>```
>
>*-Ubah chnage directory menjadi directory menyimpan code.*
>
>*-Tambah list .c file jika ada penambahan file lib baru, contoh :* **"lib/first.c"**  

### 2. Dev C++
>Ikuti Langkah-Langkah Berikut:
>
>1. Buat Blank Project.
>2. Tambahkan FPalpro.c ke Project
>3. Tambah Folder Baru di Project
>4. Tambahkan Semua File Dalam Folder Lib ke Folder Yang Telah Dibuat
>5. Buka Semua File ke Text Editor
>6. Build lalu Compile dan Run 

---

## Tambahan 
- Semua folder dan file yang dibutuhkan pertama kali akan di generate secara otomatis.
- Folder config berisi konfigurasi harga listrik sesuai rating VA pelanggan.
- Fodler db_cust berisi database pelanggan.
- Folder db_user berisi database pengguna program.
- Folder tx_log berisi database transaksi dari masing masing pelanggan.
- Folder lib berisi library dari fungsi yang akan digunakan.