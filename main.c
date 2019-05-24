#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "VM.h"

/*#include "execute.c"*/
int main(int argc, char *argv[]) {

    int *input_array = 0;
    char *input_name = NULL;
    char *instruction_name = NULL;
    int input_array_size = 0;

    instruction_name = argv[1];
    input_name = argv[2];

    if (strcmp(instruction_name, "print") == 0) {
        input_array_size = input_to_array(input_name, input_array);
    }

    printf("Dimensione array = %d\n", input_array_size);
    printf("%d", input_array[1]);

    return 0;
}