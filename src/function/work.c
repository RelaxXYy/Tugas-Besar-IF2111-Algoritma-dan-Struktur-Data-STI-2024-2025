#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"

typedef struct {
    char name[MAX_LEN];
    int income;
    int duration;
} Job;

void wait_time(int seconds) {
    time_t start_time = time(NULL);
    while (time(NULL) - start_time < seconds) {
        // Busy-waiting for the specified duration
    }
}

void handle_work(User *current_user) {
    if ((*current_user).name[0] == '\0') {
        printf("Tidak ada pengguna yang sedang login. Silakan LOGIN terlebih dahulu.\n");
        return;
    }

    // Daftar pekerjaan
    Job jobs[] = {
        {"Evil Lab Assistant", 100, 14},
        {"OWCA Hiring Manager", 4200, 21},
        {"Cikapundunginator Caretaker", 7000, 30},
        {"Mewing Specialist", 10000, 22},
        {"Inator Connoisseur", 997, 15}
    };
    int job_count = sizeof(jobs) / sizeof(jobs[0]);

    // Tampilkan daftar pekerjaan
    printf("Daftar pekerjaan:\n");
    for (int i = 0; i < job_count; i++) {
        printf("%d. %s (pendapatan=%d, durasi=%ds)\n", 
               i + 1, jobs[i].name, jobs[i].income, jobs[i].duration);
    }

    // Pilih pekerjaan
    printf("\nMasukkan pekerjaan yang dipilih: ");
    get_line();

    // Cari pekerjaan berdasarkan nama yang dimasukkan
    int selected_job_index = -1;
    for (int i = 0; i < job_count; i++) {
        if (is_same_word(string_to_word(jobs[i].name), current_word)) {
            selected_job_index = i;
            break;
        }
    }

    if (selected_job_index == -1) {
        printf("Pekerjaan yang dipilih tidak valid. Silakan coba lagi.\n");
        return;
    }

    // Mulai pekerjaan
    Job selected_job = jobs[selected_job_index];
    printf("Anda sedang bekerja sebagai %s... harap tunggu.\n", selected_job.name);
    wait_time(selected_job.duration); // Waktu tunggu sesuai durasi pekerjaan

    // Tambahkan pendapatan ke akun pengguna
    add_money(&users, (*current_user).name, selected_job.income);
    printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", selected_job.income);
}