#include "VM.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int input_to_array(char *input_name, int **input_array) {
    FILE *fp;
    char *line;
    int first = 0;
    int array_size = 0;
    int i = 0;
    size_t linesize = 1;


    line = (char *) malloc(sizeof(char) * linesize);

    if (!(fp = fopen(input_name, "r"))) {
        printf("FILE NOT FOUND\n");
        return 0;
    }

    while ((first == 0 && getline(&line, &linesize, fp)) > 0) {
        char *p = strtok(line, " ;");
        if (p[0] >= '0' && p[0] <= '9') {
            array_size = atoi(line);
            first = 1;
        }
    }
    *input_array = realloc(*input_array, array_size * sizeof(int));
    while ((getline(&line, &linesize, fp)) != -1) {
        char *p = strtok(line, " ;");

        if (p[0] >= '0' && p[0] <= '9') {
            (*input_array)[i] = atoi(p);
            i++;
        }
    }

    free(line);
    return array_size;
}

