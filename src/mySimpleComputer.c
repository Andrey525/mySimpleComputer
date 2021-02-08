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
        sc_regSet(ERROR_EXIT_RANGE_MEMORY, 1);
        return ERROR_EXIT_RANGE_ARRAY;
    }
    RAM[adress] = value;
    return 0;
}

int sc_memoryGet(int adress, int* value)
{
    if (adress < 0 || adress >= SIZE_OF_MEMORY) {
        sc_regSet(ERROR_EXIT_RANGE_MEMORY, 1);
        return ERROR_EXIT_RANGE_ARRAY;
    }
    *value = RAM[adress];
    return 0;
}

int sc_memorySave(char* filename)
{
    FILE* file;
    if ((file = fopen(filename, "wb")) == NULL) {
        return ERROR_FWRITE; // ошибка записи в файл
    }
    fwrite(RAM, sizeof(int), SIZE_OF_MEMORY, file);
    fclose(file);
    return 0;
}

int sc_memoryLoad(char* filename)
{
    FILE* file;
    if ((file = fopen(filename, "rb")) == NULL) {
        return ERROR_FREAD; // ошибка чтения из файла
    }
    if (fread(RAM, sizeof(int), SIZE_OF_MEMORY, file) != SIZE_OF_MEMORY) {
        if (feof(file)) {
            return ERROR_FEOF;
        } else {
            return ERROR_FREAD;
        }
    }
    return 0;
}

int sc_regInit()
{
    registr_of_flags = 0;
    return 0;
}

int sc_regSet(int registr, int value)
{
    if (((value == 1) || (value == 0)) == false) { // проверка на допустимое значение
        return ERROR_VALUE;
    }
    if ((registr == OVERFLOW || registr == ERROR_DIVISION_BY_ZERO || registr == ERROR_EXIT_RANGE_MEMORY || registr == IGNORE_CLOCK_PULSES || registr == INVALID_COMMAND_SPECIFIED) == false) { // проверка на допустимый номер регистра
        return ERROR_RANK;
    }
    if (value == 1) {
        registr_of_flags = registr_of_flags | registr;
        // BIT_SET(registr_of_flags, registr);
    } else if (value == 0) {
        registr_of_flags = registr_of_flags & (~registr);
        // BIT_DELETE(registr_of_flags, registr);
    }
    return 0;
}

int sc_regGet(int registr, int* value)
{
    if ((registr == OVERFLOW || registr == ERROR_DIVISION_BY_ZERO || registr == ERROR_EXIT_RANGE_MEMORY || registr == IGNORE_CLOCK_PULSES || registr == INVALID_COMMAND_SPECIFIED) == false) { // проверка на допустимый разряд
        return ERROR_RANK;
    }
    if ((registr_of_flags & registr) != 0) {
        *value = 1;
    } else {
        *value = 0;
    }

    return 0;
}

int sc_commandEncode(int command, int operand, int *value)
{
	
}