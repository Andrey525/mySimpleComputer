#include "mySimpleComputer.h"
int main()
{
    sc_memoryInit();
    for (int i = 0; i < SIZE_OF_MEMORY; i++) {
        printf("%d ", RAM[i]);
    }
    printf("\n\n");
    sc_memorySet(95, 1);
    sc_memorySet(24, 12);
    sc_memorySet(54, 17);
    for (int i = 0; i < SIZE_OF_MEMORY; i++) {
        printf("%d ", RAM[i]);
    }
    printf("\n\n");
    int value;
    sc_memoryGet(24, &value);
    printf("value == %d\n", value);

    sc_memorySave("mem.bin");
    sc_memoryInit();

    sc_memoryLoad("mem.bin");
    for (int i = 0; i < SIZE_OF_MEMORY; i++) {
        printf("%d ", RAM[i]);
    }
    printf("\n\n");
    // printf("registr_of_flags == %d\n", registr_of_flags);
    sc_regInit();
    printf("registr_of_flags == %d\n", registr_of_flags);
    sc_regSet(2, 1);
    sc_regSet(6, 1);
    sc_regSet(5, 1);
    printf("registr_of_flags == %d\n", registr_of_flags);
    sc_regGet(5, &value);
    printf("value == %d\n", value);
    return 0;
}
