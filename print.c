#include <stdio.h>

/*
 * Funzione di stampa del file input come riportato da specifiche di progetto
*/

void print_input(FILE *fp){

    char line[2];

    while(fgets(line,2,fp)){
        printf("%s",line);
    }
    printf ("File created\n");
}