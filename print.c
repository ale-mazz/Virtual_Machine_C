#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "VM.h"

/*
 * Funzione di stampa del file input come riportato da specifiche di progetto
*/


void print_input(FILE *fp) {

    int count_reg = 0;
    int count_line = -1;
    char *line;
    size_t linesize = 1;
    ssize_t nchar;
    line = (char *) malloc(sizeof(char) * linesize);
    while ((getline(&line, &linesize, fp)) != -1) {
        char *p = strtok(line, " ;");

        if (p[0] >= '0' && p[0] <= '9') {
            count_line++;

            if(!strcmp(p,"12")){
                printf("[ %d]  MOV ",count_line);
                count_reg = 2;
                while ((getline(&line, &linesize, fp)) != -1 && count_reg){
                    char *reg = strtok(line, " ;");
                    if(count_reg == 2){
                        printf("R%s ",reg);
                        count_line++;
                        count_reg--;
                    }
                    else{
                        printf("%s\n",reg);
                        count_line++;
                        count_reg--;
                    }
                }

            }

            if(!strcmp(p,"12")){
                printf("[ %d]  MOV ",count_line);
                count_reg = 2;
                while ((getline(&line, &linesize, fp)) != -1 && count_reg){
                    char *reg = strtok(line, " ;");
                    if(count_reg == 2){
                        printf("R%s ",reg);
                        count_line++;
                        count_reg--;
                    }
                    else{
                        printf("%s\n",reg);
                        count_line++;
                        count_reg--;
                    }
                }

            }

            if(!strcmp(p,"12")){
                printf("[ %d]  MOV ",count_line);
                count_reg = 2;
                while ((getline(&line, &linesize, fp)) != -1 && count_reg){
                    char *reg = strtok(line, " ;");
                    if(count_reg == 2){
                        printf("R%s ",reg);
                        count_line++;
                        count_reg--;
                    }
                    else{
                        printf("%s\n",reg);
                        count_line++;
                        count_reg--;
                    }
                }

            }

            if(!strcmp(p,"12")) {
                printf("[ %d]  MOV ", count_line);
                count_reg = 2;
                while ((getline(&line, &linesize, fp)) != -1 && count_reg) {
                    char *reg = strtok(line, " ;");
                    if (count_reg == 2) {
                        printf("R%s ", reg);
                        count_line++;
                        count_reg--;
                    } else {
                        printf("%s\n", reg);
                        count_line++;
                        count_reg--;
                    }
                }

            }
        }
    }
    free(line);
    printf("File created\n");
}