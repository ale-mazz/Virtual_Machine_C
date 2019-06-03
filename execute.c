#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "VM.h"
/*Il programma fattoriale funziona fino a n=12, poichè l' int non è abbastanza*/
int execute (unsigned int *input_array, unsigned int input_array_size, VM *mem){
    unsigned int i=0;
    while (mem->ip<input_array_size && input_array[mem->ip]!=0){
        switch (input_array[mem->ip]) {
            
            case 1:/*DISPLAY*/
                printf("%3d\n", mem->reg[input_array[mem->ip+1]]);
                mem->ip += 2;
                break;

            case 2:/*PRINT_STACK*/
                i=mem->sp-1;
                while (i>=mem->sp-input_array[mem->ip+1]){
                    printf ("%3d %3d", i, mem->stack[i]);
                    i--;
                }
                break;

            case 10:/*PUSH*/
                if (mem->sp<MEMSIZE){
                    mem->stack[mem->sp]=input_array[mem->ip+1];
                    mem->sp+=1;
                    mem->ip += 2;
                }
                else{
                    printf("ERRORE PUSH:OVERFLOW CAUSA STACK PIENO\n");
                    return 0;
                }
                break;

            case 11:/*POP*/
                if (mem->sp>0){
                    mem->sp-=1;
                    mem->reg[input_array[mem->ip+1]]= mem->stack[mem->sp];
                    mem->ip += 2;
                }
                else{
                    printf ("ERRORE POP: UNDERFLOW CAUSA STACK VUOTO\n");
                    return 0;
                }
                break;

            case 12:/*MOV*/
                mem->reg[input_array[mem->ip+1]]=input_array[mem->ip+2];
                mem->ip += 3;
                break;

            case 20:/*CALL*/
                mem->stack[mem->sp]=mem->ip+2;
                mem->sp+=1;
                mem->ip=input_array[mem->ip+1];
                break;

            case 21:/*RET*/
                if (mem->sp>0){
                    mem->sp-=1;
                    mem->ip=mem->stack[mem->sp];
                }
                else{
                    printf ("ERRORE RET, STACK VUOTO\n");
                    return 0;
                }
                break;

            case 22:/*JMP*/
                mem->ip=input_array[mem->ip+1];  
                break;

            case 23:/*JZ*/
                if (mem->stack [mem->sp-1]==0 && mem->sp>0){
                    mem->ip=input_array[mem->ip+1];
                }
                else
                    mem->ip += 2;
                mem->sp-=1;
                break;

            case 24:/*JPOS*/
                if (mem->stack[mem->sp-1]>0 && mem->sp>0){
                    mem->ip=input_array[mem->ip+1];
                }
                else
                    mem->ip+=2;
                mem->sp-=1;
                break;

            case 25:/*JNEG*/
                if (mem->stack[mem->sp-1]<0 && mem->sp>0){
                    mem->ip=input_array[mem->ip+1];
                }
                else
                    mem->ip+=2;
                mem->sp-=1;
                break;

            case 30:/*ADD*/
                if (mem->sp<MEMSIZE){
                    mem->stack[mem->sp]=mem->reg[input_array[mem->ip+1]]+mem->reg[input_array[mem->ip+2]];
                    mem->sp+=1;
                    mem->ip += 3;
                }
                else{
                    printf ("ERRORE ADD OVERFLOW\n");
                    return 0;
                }
                break;

            case 31:/*SUB*/
                if (mem->sp<MEMSIZE){
                    mem->stack[mem->sp]=mem->reg[input_array[mem->ip+1]]-mem->reg[input_array[mem->ip+2]];
                    mem->sp+=1;
                    mem->ip += 3;
                }
                else {
                    printf ("ERRORE SUB OVERFLOW\n");
                    return 0;
                }
                break;

            case 32:/*MUL*/
                if (mem->sp<MEMSIZE){
                    mem->stack[mem->sp]=mem->reg[input_array[mem->ip+1]]*mem->reg[input_array[mem->ip+2]];
                    mem->sp+=1;
                    mem->ip += 3;
                }
                else{
                    printf ("ERRORE MUL OVERFLOW\n");
                    return 0;
                }
                break;

            case 33:/*DIV*/
                if (mem->sp<MEMSIZE){
                    mem->stack[mem->sp]=mem->reg[input_array[mem->ip+1]]/mem->reg[input_array[mem->ip+2]];
                    mem->sp+=1;
                    mem->ip += 3;
                }
                else {
                    printf("ERRORE DIV OVERFLOW\n");
                    return 0;
                }
                break;
        }
    }
    if ((input_array[mem->ip])==0){
        printf ("HALT, IL PROGRAMMA TERMINA QUA\n");
    }
    return 1;
}

