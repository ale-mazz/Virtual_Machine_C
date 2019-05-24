#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "VM.h"

/*
 * Funzione di stampa del file input come riportato da specifiche di progetto
*/

void print_input(int *input_array) {
    /*
    int count_reg = 0;
    char *line;
    int count_line = -1;
    size_t linesize = 1;
    line = (char *) malloc(sizeof(char) * linesize);

    while ((getline(&line, &linesize, fp)) != -1 && line[0] >= '0' && line[0] <= '9') {
        count_line = -1;
    }

    while ((getline(&line, &linesize, fp)) != -1) {
        char *p = strtok(line, " ;");
        if (count_line >= 0 && p[0] >= '0' && p[0] <= '9') {
            if(!strcmp(p,"0")){
                printf("[%3d]  HALT \n",count_line);
                count_line++;
            }
            else if(!strcmp(p,"1")){
                printf("[%3d]  DISPLAY ",count_line);
                count_reg = 1;
                count_line++;
                while (count_reg!=0 && (getline(&line, &linesize, fp)) != -1){

                    char *reg = strtok(line, " ;");
                    if(count_reg == 1){
                        printf("R%s \n",reg);
                        count_line++;
                        count_reg--;
                    }
                }
            } else if (!strcmp(p, "2")) {
                printf("[%3d]  PRINT_STACK ", count_line);
                count_reg = 1;
                count_line++;
                while (count_reg != 0 && (getline(&line, &linesize, fp)) != -1) {

                    char *reg = strtok(line, " ;");
                    if (count_reg == 1) {
                        printf("%s \n", reg);
                        count_line++;
                        count_reg--;
                    }
                }
            } else if(!strcmp(p, "10")){
                printf("[%3d]  PUSH ", count_line);
                count_reg = 1;
                count_line++;
                while (count_reg != 0 && (getline(&line, &linesize, fp)) != -1){
                    char *reg = strtok(line, " ;");
                    if(count_reg == 1){
                        printf("R%s\n", reg);
                        count_line++;
                        count_reg--;
                    }
                }
            } else if (!strcmp(p, "11")){
                printf ("[%3d]  POP ", count_line);
                count_reg=1;
                count_line++;
                while (count_reg != 0 && (getline (&line, &linesize, fp)) != -1){
                    char *reg =strtok(line, " ;");
                    printf ("R%s \n", reg);
                    count_line++;
                    count_reg--;
                }
            } else if(!strcmp(p,"12")){
                printf("[%3d]  MOV ",count_line);
                count_reg = 2;
                count_line++;
                while (count_reg!=0 && (getline(&line, &linesize, fp)) != -1){
                    char *reg = strtok(line, " ;");
                    if(count_reg == 2)
                        printf("R%s ",reg);
                    else
                        printf("%s\n",reg);
                    count_line++;
                    count_reg--;
                }
            } else if(!strcmp(p,"20")){
                printf("[%3d]  CALL ",count_line);
                count_reg = 1;
                count_line++;
                while (count_reg!=0 && (getline(&line, &linesize, fp)) != -1){
                    char *reg = strtok(line, " ;");
                    if(count_reg == 1){
                        printf("%s\n",reg);
                        count_line++;
                        count_reg--;
                    }
                }
            } else if(!strcmp(p,"21")){
                printf("[%3d]  RET \n",count_line);
                count_line++;
            } else if(!strcmp(p,"22")){
                printf("[%3d]  JMP ",count_line);
                count_reg = 1;
                count_line++;
                while (count_reg!=0 && (getline(&line, &linesize, fp)) != -1){
                    char *reg = strtok(line, " ;");
                    if(count_reg == 1){
                        printf("%s\n",reg);
                        count_line++;
                        count_reg--;
                    }
                }
            } else if(!strcmp(p,"23")){
                printf("[%3d]  JZ ",count_line);
                count_reg = 1;
                count_line++;
                while (count_reg!=0 && (getline(&line, &linesize, fp)) != -1){
                    char *reg = strtok(line, " ;");
                    if(count_reg == 1){
                        printf("%s\n",reg);
                        count_line++;
                        count_reg--;
                    }
                }
            } else if(!strcmp(p,"24")){
                printf("[%3d]  JPOS ",count_line);
                count_reg = 1;
                count_line++;
                while (count_reg!=0 && (getline(&line, &linesize, fp)) != -1){
                    char *reg = strtok(line, " ;");
                    if(count_reg == 1){
                        printf("%s\n",reg);
                        count_line++;
                        count_reg--;
                    }
                }
            } else if(!strcmp(p,"25")){
                printf("[%3d]  JNEG ",count_line);
                count_reg = 1;
                count_line++;
                while (count_reg!=0 && (getline(&line, &linesize, fp)) != -1){
                    char *reg = strtok(line, " ;");
                    if(count_reg == 1){
                        printf("%s\n",reg);
                        count_line++;
                        count_reg--;
                    }
                }
            } else if(!strcmp(p,"30")){
                printf("[%3d]  ADD ",count_line);
                count_reg = 2;
                count_line++;
                while (count_reg!=0 && (getline(&line, &linesize, fp)) != -1){
                    char *reg = strtok(line, " ;");
                    if(count_reg == 2){
                        printf("R%s ",reg);
                        count_line++;
                        count_reg--;
                    } else if(count_reg == 1){
                        printf("R%s\n",reg);
                        count_line++;
                        count_reg--;
                    }
                }
            } else if(!strcmp(p,"31")){
                printf("[%3d]  SUB ",count_line);
                count_reg = 2;
                count_line++;
                while (count_reg!=0 && (getline(&line, &linesize, fp)) != -1){
                    char *reg = strtok(line, " ;");
                    if(count_reg == 2){
                        printf("R%s ",reg);
                        count_line++;
                        count_reg--;
                    } else if(count_reg == 1){
                        printf("R%s\n",reg);
                        count_line++;
                        count_reg--;
                    }
                }
            } else if(!strcmp(p,"32")){
                printf("[%3d]  MUL ",count_line);
                count_reg = 2;
                count_line++;
                while (count_reg!=0 && (getline(&line, &linesize, fp)) != -1){
                    char *reg = strtok(line, " ;");
                    if(count_reg == 2){
                        printf("R%s ",reg);
                        count_line++;
                        count_reg--;
                    } else if(count_reg == 1){
                        printf("R%s\n",reg);
                        count_line++;
                        count_reg--;
                    }
                }
            } else if(!strcmp(p,"33")){
                printf("[%3d]  DIV ",count_line);
                count_reg = 2;
                count_line++;
                while (count_reg!=0 && (getline(&line, &linesize, fp)) != -1){
                    char *reg = strtok(line, " ;");
                    if(count_reg == 2){
                        printf("R%s ",reg);
                        count_line++;
                        count_reg--;
                    } else if(count_reg == 1){
                        printf("R%s\n",reg);
                        count_line++;
                        count_reg--;
                    }
                }
            }
        }
        if (count_line<0)
            count_line++;
    }
    free(line);
     */
}