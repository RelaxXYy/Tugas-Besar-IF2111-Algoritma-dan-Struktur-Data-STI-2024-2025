#include "../include/all_library_headers.h"
#include "../include/all_ADT_headers.h"
#include "../include/boolean.h"
#include "../include/config.h"

QueueBarang qbarangs;
ListBarang barangs;
ListUser users;
User current_user;
boolean is_user_logged_in = false;
boolean is_session_started = false;
char *wordlist[] = {
        "apple", "grape", "melon", "peach", "berry",
        "mango", "lemon", "plums", "bread", "toast",
        "chair", "table", "block", "brick", "cloud",
        "grass", "field", "stone", "river", "ocean",
        "light", "sound", "heart", "brain", "mouth",
        "space", "earth", "plain", "cross", "house",
        "world", "dream", "happy", "smile", "write",
        "smart", "learn", "think", "start", "plant",
        "fresh", "drink", "laugh", "quiet", "north",
        "south", "beach", "shore", "watch", "story",
        "water", "flame", "sweet", "candy", "sugar",
        "honey", "crisp", "shine", "storm", "track",
        "peace", "power", "unity", "truth", "focus",
        "glass", "peace", "tiger", "eagle", "zebra",
        "crown", "spark", "flock", "night", "early",
        "smoke", "paint", "write", "dance", "house",
        "brain", "hands", "bloom", "clock", "world",
        "magic", "small", "clean", "press", "skill",
        "angle", "frame", "shape", "drift", "winds",
        "float", "align", "layer", "build", "stone"
    };

int main(){
    char command[MAX_LEN];
    create_list_barang(&barangs);
    create_queue_barang(&qbarangs);
    create_list_user(&users);
    create_user(&current_user);

    printf("___       __      ______                                       _____               ________ _____  __________ ________ ______  __________ ________ ________\n");
    printf("__ |     / /_____ ___  /_____________ _______ ___ _____        __  /_______        ___  __ \\__  / / /___  __ \\___  __ \\___   |/  /___    |___  __ \\___  __/\n");
    printf("__ | /| / / _  _ \\__  / _  ___/_  __ \\__  __ `__ \\_  _ \\       _  __/_  __ \\       __  /_/ /_  / / / __  /_/ /__  /_/ /__  /|_/ / __  /| |__  /_/ /__  /   \n");
    printf("__ |/ |/ /  /  __/_  /  / /__  / /_/ /_  / / / / //  __/       / /_  / /_/ /       _  ____/ / /_/ /  _  _, _/ _  _, _/ _  /  / /  _  ___ |_  _, _/ _  /    \n");
    printf("____/|__/   \\___/ /_/   \\___/  \\____/ /_/ /_/ /_/ \\___/        \\__/  \\____/        /_/      \\____/   /_/ |_|  /_/ |_|  /_/  /_/   /_/  |_|/_/ |_|  /_/     \n");
    printf("\n");
    printf("\n");
    printf("****************************************\n");
    printf("*      Selamat Datang di PURRMART      *\n");
    printf("****************************************\n");
    printf("*   1. START                           *\n");
    printf("*   2. LOAD                            *\n");
    printf("*   3. QUIT                            *\n");
    printf("****************************************\n");
    printf("*   Pilih Command atau ketik 'HELP'!   *\n");
    printf("****************************************\n");
    execute_command();
}