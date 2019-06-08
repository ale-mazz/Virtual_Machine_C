/*
 * File prodotto da Davide Vio
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MEMSIZE (1024*64)

struct virtual_machine {
    int stack[MEMSIZE];
    int reg[32];
    unsigned int sp;
    unsigned int ip;

};
typedef struct virtual_machine VM;

void print_assembly(int *input_array, unsigned int input_array_size);

int execute(int const *input_array, unsigned int input_array_size, VM *mem);

int input_to_array(FILE *fp, int **input_array);
