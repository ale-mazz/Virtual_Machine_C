#include <string.h>
#include <stdlib.h>
#include "VM.h"

int main(int argc, char *argv[]) {

    FILE *fp;
    int *input_array = 0;
    char *input_name = NULL;
    char *instruction_name = NULL;
    unsigned int input_array_size = 0;
    VM *virtual_stack;
    virtual_stack=(VM*)malloc (sizeof (struct virtual_machine));
    virtual_stack->sp=0;
    virtual_stack->ip=0;
    instruction_name = argv[1];
    input_name = argv[2];


    if (!(fp = fopen(input_name, "r"))) {
        printf("File non trovato.\n");
        return 0;
    }

    if (strcmp(instruction_name, "stampa") == 0) {

        input_array_size = input_to_array(fp, &input_array);
        print_assembly(input_array, input_array_size);
    } else if (strcmp(instruction_name, "esegui") == 0) {

        input_array_size = input_to_array(fp, &input_array);
        execute (input_array, input_array_size, virtual_stack);
    } else {

        printf("Istruzione scorretta.\n");
    }

    free (virtual_stack);
    free(input_array);
    (void) argc;
    return 0;
}