#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "VM.h"

int main(int argc, char *argv[]) {

    int *input_array = 0;
    char *input_name = NULL;
    char *instruction_name = NULL;
    int input_array_size = 0;
    VM *virtual_stack;
    virtual_stack=(VM*)malloc (sizeof (struct virtual_machine));
    virtual_stack->sp=0;
    virtual_stack->ip=0;
    instruction_name = argv[1];
    input_name = argv[2];

    if (strcmp(instruction_name, "print") == 0) {
        printf("Stampa\n");
        input_array_size = input_to_array(input_name, input_array);
        print_assembly(input_array, input_array_size);
    } else if (strcmp(instruction_name, "execute") == 0) {
        printf("Esegui\n");
        input_array_size=input_to_array(input_name, input_array);
        execute (input_array, input_array_size, virtual_stack);
    } else {
        printf("Istruzione scorretta.\n");
    }

    free (virtual_stack);
    free(input_array);
    void (argc);
    return 0;
}