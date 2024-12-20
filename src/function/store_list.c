#include "../all_library_headers.h"
#include "../ADT/all_ADT_headers.h"
#include "../boolean.h"
#include "../config.h"


void store_list_main()
{
    if(barangs.size == 0)
    {
        printf("Tidak ada barang di toko.\n");
    }
    else{
        printf("Daftar barang di toko:\n");
        for (int index = 0; index < barangs.size; index++) {
        printf("- %s\n", barangs.buffer[index].name);
        }
    }
    execute_command();
}