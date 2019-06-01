#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "VM.h"

int execute (int *input_array, int input_array_size, VM *mem){
    while (mem->ip<input_array_size && input_array[mem->ip]!=0){
        switch (input_array[i]) {
            case 1:/*DISPLAY*/
                printf("%3d", mem->reg[input_array[mem->ip+1]]);
                mem->ip += 1;
                break;

            case 2:/*non capisco cosa debba fare print_stack,*/
                printf("[%3d]  PRINT_STACK %d\n", i, input_array[i + 1]);
                i += 1;
                break;

            case 10:/*PUSH*/
                if (mem->sp<MEMSIZE){
                    mem->stack[mem->sp]=input_array[mem->ip+1];
                    mem->sp+=1;
                    mem->ip += 1;
                }
                else{
                    printf("ERRORE PUSH:OVERFLOW CAUSA STACK PIENO");
                    return 0;
                }
                break;

            case 11:/*POP*/
                if (mem->sp>0){
                    mem->sp-=1;
                    mem->reg[sp]=input_array[mem->ip+1];
                    mem->ip += 1;
                }
                else{
                    printf ("ERRORE POP: UNDERFLOW CAUSA STACK VUOTO");
                    return 0;
                }
                break;

            case 12:/*MOV*/
                mem->reg[mem->ip+1]=input_array[mem->ip+2];
                mem->ip += 2;
                break;

            case 20:/*CALL*/
                mem->stack[sp]=input_array[mem->ip+2];
                mem->sp+=1;
                mem->ip=input_array[mem->ip+1];
                break;

            case 21:/*RET*/
                mem->sp-=1;
                mem->ip=mem->stack[mem->sp];
                return mem->ip;
                break;

            case 22:/*JMP*/
                mem->ip=input_array[mem->ip+1];
                mem->ip += 1;  
                break;

            case 23:/*JZ*/
                if (mem->stack [mem->sp-1]!=0 && mem->sp>0){
                    mem->sp-1;
                    mem->ip=input_array[mem->ip+1];
                }
                else
                    mem->ip += 2;
                break;

            case 24:/*JPOS*/
                if (mem->stack[mem->sp-1]>0 && mem->sp>0){
                    mem->sp-1;
                    mem->ip=input_array[mem->ip+1];
                }
                else
                    mem->ip+=2;
                break;

            case 25:/*JNEG*/
                if (mem->stack[mem->sp-1]>0 && mem->sp>0){
                    mem->sp-1;
                    mm->ip=input_array[mem->ip+1];
                }
                else
                    mem->ip+=2;
                break;

            case 30:/*ADD*/
                if (mem->sp<MEMSIZE){
                    mem->stack[sp]=mem->reg[mem->ip+1]+mem->reg[mem->ip+2];
                    mem->sp+=1;
                    mem->ip += 2;
                }
                else{
                    printf ("ERRORE ADD OVERFLOW");
                    return 0;
                }
                break;

            case 31:/*SUB*/
                if (mem->sp<MEMSIZE){
                    mem->stack[sp]=mem->reg[mem->ip+1]-mem->reg[mem->ip+2];
                    mem->sp+=1;
                    mem->ip += 2;
                }
                else {
                    printf ("ERRORE SUB OVERFLOW");
                    return 0;
                }
                break;

            case 32:/*MUL*/
                if (mem->sp<MEMSIZE){
                    mem->stack[sp]=mem->reg[mem->ip+1]*mem->reg[mem->ip+2];
                    mem->sp+=1;
                    mem->ip += 2;
                }
                else{
                    printf ("ERRORE MUL OVERFLOW");
                    return 0;
                }
                break;

            case 33:/*DIV*/
                if (mem->sp<MEMSIZE){
                    mem->stack[sp]=mem->reg[mem->ip+1]/mem->reg[mem->ip+2];
                    mem->sp+=1;
                    mem->ip += 2;
                }
                else {
                    printf("ERRORE DIV OVERFLOW");
                    return 0;
                }
                break;
        }
    }
    if (input_array[mem->ip]=0){
        printf ("HALT, IL PROGRAMMA TERMINA QUA");
        return 0;
    }

}

