#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "VM.h"
/*
 * Funzione di stampa del file input come riportato da specifiche di progetto
*/

void print_input(FILE *fp){
    /*char line[2];*/
    char *line;
    size_t linesize=1;
    ssize_t nchar;
    line=(char*)malloc (sizeof (char)*linesize);
    while((nchar=getline (&line,&linesize, fp))!=-1){
        char *p=strtok (line," ;");
        if (p[0]>='0' && p[0]<='9')
            printf("%s\n",p);
    }
    free (line);
    /*while (fgets(line,3,fp)){
        if (line[0]>='0' && line[0]<='9')
            printf ("%s\n",line);
    }*/
    printf ("File created\n");
}