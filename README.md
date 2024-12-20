# PURRMART

## Deskripsi Program
**PURRMART** adalah aplikasi simulasi berbasis Command-Line Interface (CLI) yang mensimulasikan aktivitas jual beli pada e-commerce. Aplikasi ini memungkinkan pengguna untuk:
- Menampilkan barang yang tersedia di toko.
- Meminta dan menyuplai barang baru ke toko.
- Menyimpan dan membeli barang dalam keranjang.
- Menampilkan barang yang sudah dibeli.
- Membuat dan menghapus wishlist.
- Melakukan pekerjaan untuk mendapatkan uang.

Aplikasi ini dikembangkan sebagai bagian dari Tugas Besar IF2111 Algoritma dan Struktur Data. PURRMART dibuat menggunakan bahasa C dengan memanfaatkan berbagai struktur data, seperti List, Queue, dan Mesin Karakter.

---

## Anggota Kelompok
- Muhammad Aidan Fathullah/ 18223002
- Vandega Arozan Musholine/ 18223010
- Irdina Ilmuna Yosapat/ 18223060
- Vincentia Belinda Sumartoyo/ 18223078
- Gabriela Jennifer Sandy/ 18223092

---

## Command yang Tersedia
Berikut adalah daftar command yang dapat digunakan di PURRMART:

1. **START**  
   Memulai sesi baru menggunakan file konfigurasi.

2. **LOAD `<filename>`**  
   Memuat data dari file konfigurasi tertentu.

3. **LOGIN**  
   Masuk ke akun yang sudah didaftarkan.

4. **REGISTER**  
   Mendaftarkan akun baru ke dalam sistem.

5. **PROFILE**
   Menampilkan data diri pengguna, termasuk username dan informasi terkait.

6. **WORK**  
   Melakukan pekerjaan untuk mendapatkan uang.

7. **WORK CHALLENGE**  
   Menjalankan challenge untuk mendapatkan uang.

8. **STORE LIST**  
   Menampilkan daftar barang yang tersedia di toko.

9. **STORE REQUEST**  
   Meminta penambahan barang baru ke dalam toko.

10. **STORE SUPPLY**  
   Menambahkan barang baru ke toko dari antrian permintaan.

11. **STORE REMOVE**  
    Menghapus barang dari toko.

12. **CART REMOVE <nama> <n>**
    Mengurangi atau menghapus sejumlah (<n>) barang tertentu (<nama>) dari keranjang belanja.

13. **CART SHOW**
    Menampilkan semua barang yang ada di keranjang belanja pengguna.

14. **CART PAY**
    Membayar barang yang ada di keranjang belanja dan menyelesaikan transaksi.

15. **HISTORY <n>**
    Menampilkan <n> riwayat transaksi terakhir pengguna.

16. **WISHLIST**
    ADDMenambahkan barang ke dalam wishlist pengguna.

17. **WISHLIST SWAP <i> <j>**
    Menukar posisi dua barang dalam wishlist berdasarkan urutan <i> dan <j>.

18. **WISHLIST REMOVE <i>**
    Menghapus barang dari wishlist berdasarkan posisinya (<i>).

19. **WISHLIST REMOVE**
    Menghapus barang dari wishlist berdasarkan nama barangnya.

20. **WISHLIST CLEAR**
    Menghapus semua barang dari wishlist pengguna.

21. **WISHLIST SHOW**
    Menampilkan semua barang yang ada di wishlist pengguna.

22. **LOGOUT**
    Keluar dari sesi pengguna saat ini.

23. **SAVE `<filename>`**  
    Menyimpan state aplikasi ke dalam file tertentu.

24. **HELP**  
    Menampilkan daftar command yang tersedia beserta deskripsinya.

25. **QUIT**  
    Keluar dari aplikasi.

---

## Cara Kompilasi Program
Untuk mengkompilasi program ini, gunakan langkah-langkah berikut:

1. Pastikan Anda berada di direktori proyek.
2. Run makefile
3. Jalankan main.exe 
4. File akan berjalan menampilkan Welcome page
