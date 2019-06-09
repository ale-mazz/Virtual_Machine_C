/*
 * File prodotto da Davide Vio
 *
 * P1G95
 * Alessandro Mazzon - 877443
 * Davide Vio - 858687
 *
 * VM.h contiene tutte le librerie utilizzate nei vari programmi atti a far funzionare la "virtual machine".
 * MEMSIZE è settato a 64kb di int. Ho utilizzato una struct per non dover passare 6 parametri alla funzione execute.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

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
