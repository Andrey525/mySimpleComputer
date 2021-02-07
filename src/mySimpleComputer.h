#include <stdbool.h>
#include <stdio.h>

#ifndef COMP_H
#define COMP_H
#define SIZE_OF_MEMORY 100
#define BIT_CHECK(REG, RANK) ((REG >> RANK) & 0x1)
#define BIT_SET(REG, RANK) ((REG = ((REG) | (0x1 << RANK))))
#define BIT_DELETE(REG, RANK) (REG = ((REG) & (~(0x1 << RANK))))
int RAM[SIZE_OF_MEMORY];
int registr_of_flags; // регистр флагов(переменная хранящая флаги (32 штуки))

int sc_memoryInit();
int sc_memorySet(int adress, int value);
int sc_memoryGet(int adress, int* value);
int sc_memorySave(char* filename);
int sc_memoryLoad(char* filename);
int sc_regInit();
int sc_regSet(int rank, int value); // rank - разряд от 0 до 31, value - значение бита (либо 0, либо 1)
int sc_regGet(int rank, int* value);
int sc_commandEncode(int command, int operand, int* value);
int sc_commandDecode(int value, int* command, int* operand);

#endif