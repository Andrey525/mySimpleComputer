#ifndef COMP_H
#define COMP_H

int sc_memoryInit();
int sc_memorySet(int adress, int value);
int sc_memoryGet(int adress, int* value);
int sc_memorySave(char* filename);
int sc_memoryLoad(char* filename);
int sc_regInit(void);
int sc_regSet(int register, int value);
int sc_regGet(int register, int* value);
int sc_commandEncode(int command, int operand, int* value);
int sc_commandDecode(int value, int* command, int* operand);

#endif