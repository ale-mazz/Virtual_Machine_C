/*
 * File prodotto da Davide Vio
 *
 * P1G95
 * Alessandro Mazzon - 877443
 * Davide Vio - 858687
 *
 * La funzione execute permette di eseguire il file *.cvm e di restiture il risultato.
 * L'array dato in input contiene le informazioni necessarie per eseguire il programma, ossia il numero dell' istruzione e nella maggior parte dei casi pure i registri
 * o i numeri da inserire nella struct virtual machine (stack o registri).
 * Lo stack, i registri e gli indici sp e ip vengono inizializzati nel main prima della chiamata a funzione execute.
 * Grazie ad un ciclo while e all'utilizzo dello switch sui valori dell' array in input, vengono eseguite le varie istruzioni.
 * Il programma segnale errori in casi di stack overflow sulla PUSH, ADD, SUB, MUL e DIV e di stack underflow nel caso della POP, RET, JZ, JPOS e JNEG.
 * Segnala inoltre gli errori in caso di overflow e underflow dei risultati delle quattro operazioni scritte sopra.
 */

#include "VM.h"

int execute(int const *input_array, unsigned int input_array_size, VM *mem) {
    unsigned int i=0;
    int a,b;
    while (mem->ip<input_array_size && input_array[mem->ip]!=0){
        switch (input_array[mem->ip]) {
            
            case 1:/*DISPLAY*/
                printf("%3d\n", mem->reg[input_array[mem->ip+1]]);
                mem->ip += 2;
                break;

            case 2:/*PRINT_STACK*/
                if (mem->sp==0)
                    printf ("STACK VUOTO\n");
                else {
                    i=mem->sp;
                    while (i>mem->sp-input_array[mem->ip+1]){
                        printf ("sp=%3d valore=%3d\n", i-1, mem->stack[i-1]);
                        i--;
                    }
                }
                mem->ip+=2;
                break;

            case 10:/*PUSH*/
                if (mem->sp<MEMSIZE){
                    mem->stack[mem->sp]=mem->reg [input_array[mem->ip+1]];
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
                    printf ("ERRORE POP STACK UNDERFLOW\n");
                    return 0;
                }
                break;

            case 12:/*MOV*/
                mem->reg[input_array[mem->ip+1]]=input_array[mem->ip+2];
                mem->ip += 3;
                break;

            case 20:/*CALL*/
                if (mem->sp<MEMSIZE){
                    mem->stack[mem->sp]=mem->ip+2;
                    mem->sp+=1;
                    mem->ip=input_array[mem->ip+1];
                }
                break;

            case 21:/*RET*/
                if (mem->sp>0){
                    mem->sp-=1;
                    mem->ip=mem->stack[mem->sp];
                }
                else{
                    printf ("ERRORE RET STACK UNDERFLOW\n");
                    return 0;
                }
                break;

            case 22:/*JMP*/
                mem->ip=input_array[mem->ip+1];  
                break;

            case 23:/*JZ*/
                if (mem->sp>0){
                    if (mem->stack [mem->sp-1]==0 && mem->sp>0){
                        mem->ip=input_array[mem->ip+1];
                    }
                    else
                        mem->ip += 2;
                    mem->sp-=1;
                }
                else{
                    printf ("ERRORE JZ STACK UNDERFLOW\n");
                    return 0;
                }
                break;

            case 24:/*JPOS*/
                if  (mem->sp>0){
                    if (mem->stack[mem->sp-1]>0 && mem->sp>0){
                        mem->ip=input_array[mem->ip+1];
                    }
                    else
                        mem->ip+=2;
                    mem->sp-=1;
                }
                else {
                    printf ("ERRORE JPOS STACK UNDERFLOW\n");
                    return 0;
                }
                break;

            case 25:/*JNEG*/
                if (mem->sp>0){
                    if (mem->stack[mem->sp-1]<0 && mem->sp>0){
                        mem->ip=input_array[mem->ip+1];
                    }
                    else
                        mem->ip+=2;
                    mem->sp-=1;
                }
                else{
                    printf ("ERRORE JNEG STACK UNDERFLOW\n");
                    return 0;
                }
                break;

            case 30:/*ADD*/
                if (mem->sp>=MEMSIZE){
                    printf ("ERRORE STACK OVERFLOW\n");
                    return 0;
                }
                a=mem->reg[input_array[mem->ip+1]];
                b=mem->reg[input_array[mem->ip+2]];
                if (a>=0){
                    if (mem->sp<MEMSIZE && INT_MAX-a>=b){
                        mem->stack[mem->sp]=a+b;
                        mem->sp+=1;
                        mem->ip += 3;
                    }
                    else{
                        printf ("ERRORE ADD OVERFLOW\n");
                        return 0;
                    }
                }
                else{
                    if (INT_MIN-a<=b){
                        mem->stack[mem->sp]=a+b;
                        mem->sp+=1;
                        mem->ip += 3;
                    }
                    else{
                        printf ("ERRORE ADD UNDERFLOW\n");
                        return 0;
                    }
                }
                
                break;

            case 31:/*SUB*/
                if (mem->sp>=MEMSIZE){
                    printf ("ERRORE STACK OVERFLOW\n");
                    return 0;
                }
                a=mem->reg[input_array[mem->ip+1]];
                b=mem->reg[input_array[mem->ip+2]];
                if (a>=0 && b<=0){
                    if (INT_MAX-a<=b){
                        mem->stack[mem->sp]=a-b;
                        mem->sp+=1;
                        mem->ip += 3;
                    }
                    else {
                        printf ("ERRORE SUB OVERFLOW\n");
                        return 0;
                    }
                }
                else {
                    if (a<=0 && b>=0){
                        if (INT_MIN-a>=b){
                            mem->stack[mem->sp]=a-b;
                            mem->sp+=1;
                            mem->ip += 3;
                        }
                        else {
                            printf ("ERRORE SUB UNDERFLOW\n");
                            return 0;
                        }
                    }
                    else {
                        mem->stack[mem->sp]=a-b;
                        mem->sp+=1;
                        mem->ip += 3;
                    }
                }
                break;

            case 32:/*MUL*/
                if (mem->sp>=MEMSIZE){
                    printf ("ERRORE STACK OVERFLOW\n");
                    return 0;
                }
                a=mem->reg[input_array[mem->ip+1]];
                b=mem->reg[input_array[mem->ip+2]];
                if (a==0 || b==0){
                    mem->stack[mem->sp]=0;
                    mem->sp+=1;
                    mem->ip += 3;
                }
                if (a>0 && b>0){
                    if (INT_MAX/a>=b){
                        mem->stack[mem->sp]=a*b;
                        mem->sp+=1;
                        mem->ip += 3;
                    }
                    else{
                        printf ("ERRORE MUL OVERFLOW\n");
                        return 0;
                    }
                }
                if (a<0 && b<0){
                    if (INT_MAX/a<=b){
                        mem->stack[mem->sp]=a*b;
                        mem->sp+=1;
                        mem->ip += 3;
                    }
                    else{
                        printf ("ERRORE MUL OVERFLOW\n");
                        return 0;
                    }
                }
                if (a>0 && b<0){
                    if (INT_MIN/a<=b){
                        mem->stack[mem->sp]=a*b;
                        mem->sp+=1;
                        mem->ip += 3;
                    }
                    else{
                        printf ("ERRORE SUB UNDERFLOW\n");
                        return 0;
                    }
                }
                if (a<0 && b>0){
                    if (INT_MIN/a>=b){
                        mem->stack[mem->sp]=a*b;
                        mem->sp+=1;
                        mem->ip += 3;
                    }
                    else{
                        printf ("ERRORE SUB UNDERFLOW\n");
                        return 0;
                    }
                }
                break;

            case 33:/*DIV*/
                if (mem->sp>=MEMSIZE){
                    printf ("ERRORE STACK OVERFLOW\n");
                    return 0;
                }
                a=mem->reg[input_array[mem->ip+1]];
                b=mem->reg[input_array[mem->ip+2]];
                if (b==0){
                    printf ("ERRORE DIVISIONE PER ZERO\n");
                    return 0;
                }
                mem->stack[mem->sp]=a/b;
                mem->sp+=1;
                mem->ip += 3;
                break;
        }
    }
    if ((input_array[mem->ip])==0){
        printf ("PROGRAMMA TERMINATO CORRETTAMENTE\n");
    }
    return 1;
}

