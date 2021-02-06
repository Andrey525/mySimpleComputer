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