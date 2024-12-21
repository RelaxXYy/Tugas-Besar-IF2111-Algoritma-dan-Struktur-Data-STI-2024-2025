#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"
#include "help.h"

void help() {
    if (is_session_started == false) {
        printf("=================================================================\n");
        printf("||                    WELCOME TO PURRMART                     ||\n");
        printf("=================================================================\n");
        printf("|| Berikut adalah Command yang dapat Anda lakukan:            ||\n");
        printf("|| ---------------------------------------------------------- ||\n");
        printf("|| 1. START                                                   ||\n");
        printf("||    Memulai sesi baru                                       ||\n");
        printf("|| 2. LOAD                                                    ||\n");
        printf("||    Memulai sesi berdasarkan file konfigurasi               ||\n");
        printf("|| 3. QUIT                                                    ||\n");
        printf("||    Keluar dari program                                     ||\n");
        printf("=================================================================\n");
    } else if (is_session_started == true && is_user_logged_in == false) {
        printf("=================================================================\n");
        printf("||                     LOGIN MENU HELP                        ||\n");
        printf("=================================================================\n");
        printf("|| Berikut adalah Command yang dapat Anda lakukan:            ||\n");
        printf("|| ---------------------------------------------------------- ||\n");
        printf("|| 1. REGISTER                                                ||\n");
        printf("||    Mendaftarkan akun baru                                  ||\n");
        printf("|| 2. LOGIN                                                   ||\n");
        printf("||    Masuk ke akun dan memulai sesi                          ||\n");
        printf("|| 3. QUIT                                                    ||\n");
        printf("||    Keluar dari program                                     ||\n");
        printf("=================================================================\n");
    } else if (is_session_started == true && is_user_logged_in == true) {
        printf("=================================================================\n");
        printf("||                    MAIN MENU HELP                          ||\n");
        printf("=================================================================\n");
        printf("|| Berikut adalah Command yang dapat Anda lakukan:            ||\n");
        printf("|| ---------------------------------------------------------- ||\n");
        printf("|| 1. PROFILE                                                 ||\n");
        printf("||    Untuk menampilkan data diri user                        ||\n");
        printf("|| 2. WORK                                                    ||\n");
        printf("||    Bekerja untuk mendapatkan uang                          ||\n");
        printf("|| 3. WORK CHALLENGE                                          ||\n");
        printf("||    Mengerjakan tantangan                                   ||\n");
        printf("|| 4. STORE LIST                                              ||\n");
        printf("||    Melihat barang-barang di toko                           ||\n");
        printf("|| 5. STORE REQUEST                                           ||\n");
        printf("||    Meminta penambahan barang                               ||\n");
        printf("|| 6. STORE SUPPLY                                            ||\n");
        printf("||    Menambahkan barang dari permintaan                     ||\n");
        printf("|| 7. STORE REMOVE                                            ||\n");
        printf("||    Menghapus barang dari toko                              ||\n");
        printf("|| 8. CART ADD <nama barang> <jumlah barang>                 ||\n");
        printf("||    Untuk menambahkan barang ke dalam keranjang            ||\n");
        printf("|| 9. CART REMOVE <nama barang> <jumlah barang>              ||\n");
        printf("||    Untuk mengurangi/menghapus barang dari keranjang        ||\n");
        printf("|| 10. CART SHOW                                              ||\n");
        printf("||    Untuk menampilkan barang yang ada di keranjang          ||\n");
        printf("|| 11. CART PAY                                               ||\n");
        printf("||    Untuk membeli barang yang ada di keranjang             ||\n");
        printf("|| 12. HISTORY <n>                                            ||\n");
        printf("||    Untuk menampilkan n riwayat pembelian terakhir          ||\n");
        printf("|| 13. WISHLIST ADD                                           ||\n");
        printf("||    Untuk menambahkan barang ke dalam wishlist             ||\n");
        printf("|| 14. WISHLIST SWAP <i> <j>                                 ||\n");
        printf("||    Untuk menukar posisi dua barang pada wishlist           ||\n");
        printf("|| 15. WISHLIST REMOVE <i>                                   ||\n");
        printf("||    Untuk menghapus sebuah barang pada wishlist            ||\n");
        printf("||    berdasarkan posisi barang di wishlist                  ||\n");
        printf("|| 16. WISHLIST REMOVE                                       ||\n");
        printf("||    Untuk menghapus sebuah barang pada wishlist            ||\n");
        printf("||    berdasarkan nama barang                                ||\n");
        printf("|| 17. WISHLIST CLEAR                                        ||\n");
        printf("||    Untuk menghapus semua barang pada wishlist             ||\n");
        printf("|| 18. WISHLIST SHOW                                         ||\n");
        printf("||    Untuk melihat semua barang pada wishlist               ||\n");
        printf("|| 19. LOGOUT                                                ||\n");
        printf("||    Keluar dari sesi                                         ||\n");
        printf("|| 20. SAVE                                                  ||\n");
        printf("||    Menyimpan state ke dalam file                           ||\n");
        printf("|| 21. QUIT                                                  ||\n");
        printf("||    Keluar dari program                                     ||\n");
        printf("=================================================================\n");
    }
}
