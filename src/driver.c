#include "include/all_library_headers.h"
#include "include/all_ADT_headers.h"
#include "include/boolean.h"
#include "include/config.h"

void test_static_int_list();
void test_dynamic_int_list();
void test_static_char_list();
void test_dynamic_char_list();
void test_queue();
void test_circular_queue();
void test_user();
void test_barang();

int main() {
    test_static_int_list();
    test_dynamic_int_list();
    test_static_char_list();
    test_dynamic_char_list();
    test_queue();
    test_circular_queue();
    test_user();
    test_barang();
    return 0;
}

void test_static_int_list() {
    printf("Testing StaticIntList...\n");
    StaticIntList list;
    create_static_int_list(&list);
    insert_static_int_list(&list, 10);
    insert_static_int_list(&list, 20);
    insert_static_int_list(&list, 30);
    printf("List contains 20: %d\n", is_static_int_list_exist(&list, 20));
    printf("Index of 20: %d\n", index_static_int_list(&list, 20));
    delete_static_int_list(&list, 20);
    printf("List contains 20 after deletion: %d\n", is_static_int_list_exist(&list, 20));
}

void test_dynamic_int_list() {
    printf("Testing DynamicIntList...\n");
    DynamicIntList list;
    create_dynamic_int_list(&list, 2);
    insert_dynamic_int_list(&list, 10);
    insert_dynamic_int_list(&list, 20);
    insert_dynamic_int_list(&list, 30);
    printf("List contains 20: %d\n", is_dynamic_int_list_exist(&list, 20));
    printf("Index of 20: %d\n", index_dynamic_int_list(&list, 20));
    delete_dynamic_int_list(&list, 20);
    printf("List contains 20 after deletion: %d\n", is_dynamic_int_list_exist(&list, 20));
    free_dynamic_int_list(&list);
}

void test_static_char_list() {
    printf("Testing StaticCharList...\n");
    StaticCharList list;
    create_static_char_list(&list);
    insert_static_char_list(&list, 'a');
    insert_static_char_list(&list, 'b');
    insert_static_char_list(&list, 'c');
    printf("List contains 'b': %d\n", is_static_char_list_exist(&list, 'b'));
    printf("Index of 'b': %d\n", index_static_char_list(&list, 'b'));
    delete_static_char_list(&list, 'b');
    printf("List contains 'b' after deletion: %d\n", is_static_char_list_exist(&list, 'b'));
}

void test_dynamic_char_list() {
    printf("Testing DynamicCharList...\n");
    DynamicCharList list;
    create_dynamic_char_list(&list, 2);
    insert_dynamic_char_list(&list, 'a');
    insert_dynamic_char_list(&list, 'b');
    insert_dynamic_char_list(&list, 'c');
    printf("List contains 'b': %d\n", is_dynamic_char_list_exist(&list, 'b'));
    printf("Index of 'b': %d\n", index_dynamic_char_list(&list, 'b'));
    delete_dynamic_char_list(&list, 'b');
    printf("List contains 'b' after deletion: %d\n", is_dynamic_char_list_exist(&list, 'b'));
    free_dynamic_char_list(&list);
}

void test_queue() {
    printf("Testing Queue...\n");
    Queue queue;
    create_queue(&queue);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    int item;
    dequeue(&queue, &item);
    printf("Dequeued item: %d\n", item);
    printf("Front item: %d\n", front(&queue));
    printf("Rear item: %d\n", rear(&queue));
}

void test_circular_queue() {
    printf("Testing CircularQueue...\n");
    CircularQueue queue;
    create_circular_queue(&queue);
    enqueue_circular(&queue, 10);
    enqueue_circular(&queue, 20);
    enqueue_circular(&queue, 30);
    int item;
    dequeue_circular(&queue, &item);
    printf("Dequeued item: %d\n", item);
    printf("Front item: %d\n", front_circular(&queue));
    printf("Rear item: %d\n", rear_circular(&queue));
}

void test_user() {
    printf("Testing User...\n");
    User users[MAX_USER];
    add_user(users, "Alice", "password123", 1000);
    add_user(users, "Bob", "password456", 500);
    printf("User count: %d\n", user_count(users));
    printf("Is Alice valid: %d\n", is_user_valid(users, "Alice", "password123"));
    change_money(users, "Alice", 200);
    printf("Alice's money after change: %d\n", users[user_index(users, "Alice")].money);
}

void test_barang() {
    printf("Testing Barang...\n");
    Barang barangs[MAX_BARANG];
    add_barang(barangs, "Laptop", 1500);
    add_barang(barangs, "Mouse", 50);
    printf("Barang count: %d\n", barang_count(barangs));
    printf("Is Laptop exist: %d\n", is_barang_exist(barangs, "Laptop"));
    printf("Index of Mouse: %d\n", barang_index(barangs, "Mouse"));
}