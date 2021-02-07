#include "mySimpleComputer.h"

int sc_memoryInit()
{
    for (int i = 0; i < SIZE_OF_MEMORY; i++) {
        RAM[i] = 0;
    }
    return 0;
}

int sc_memorySet(int adress, int value)
{
    if (adress < 0 || adress >= SIZE_OF_MEMORY) {
        printf("\nОшибка выхода за границы памяти\n");
        return 1;
    }
    RAM[adress] = value;
    return 0;
}

int sc_memoryGet(int adress, int* value)
{
    if (adress < 0 || adress >= SIZE_OF_MEMORY) {
        printf("\nОшибка выхода за границы памяти\n");
        return 1;
    }
    *value = RAM[adress];
    return 0;
}

int sc_memorySave(char* filename)
{
    FILE* file;
    if ((file = fopen(filename, "wb")) == NULL) {
        printf("\nОшибка записи в файл\n");
        return 2; // ошибка записи в файл
    }
    fwrite(RAM, sizeof(int), SIZE_OF_MEMORY, file);
    fclose(file);
    return 0;
}

int sc_memoryLoad(char* filename)
{
    FILE* file;
    if ((file = fopen(filename, "rb")) == NULL) {
        printf("\nОшибка чтения из файла\n");
        return 3; // ошибка чтения из файла
    }
    if (fread(RAM, sizeof(int), SIZE_OF_MEMORY, file) != SIZE_OF_MEMORY) {
        if (feof(file)) {
            printf("\nПреждевременный конец файла\n");
        } else {
            printf("\nОшибка чтения из файла\n");
        }
    }
    return 0;
}

int sc_regInit()
{
    registr_of_flags = 0;
    return 0;
}

int sc_regSet(int rank, int value)
{
    if (((value == 1) || (value == 0)) == false) { // проверка на допустимое значение
        return 4;
    }
    if ((rank < 0) || (rank > 31)) { // проверка на допустимый разряд
        return 5;
    }
    if (value == 1) {
        // registr_of_flags = registr_of_flags | (0x1 << rank);
        BIT_SET(registr_of_flags, rank);
    } else if (value == 0) {
        // registr_of_flags = registr_of_flags & (~(0x1 << rank));
        BIT_DELETE(registr_of_flags, rank);
    }
    return 0;
}

int sc_regGet(int rank, int* value)
{
	if ((rank < 0) || (rank > 31)) { // проверка на допустимый разряд
        return 5;
    }
    *value = BIT_CHECK(registr_of_flags, rank);
    return 0;
}
