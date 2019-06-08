/*
 * File prodotto da Alessandro Mazzon e Davide Vio
 *
 * In questo file abbiamo inserito un main che svolge le operazioni preliminari, controlla che il file esista e manda alle relative funzioni
 * il necessario per eseguire o stampare.
 * Abbiamo utilizzato un header VM che contiene una struttura inizializzata ed allocata all'interno di questo file.
 * Il main ha 3 argomenti: il nome dell'eseguibile, l'istruzione richiesta, il nome del file macchina.
 */
#include "VM.h"

int main(int argc, char *argv[]) {

    FILE *fp;
    int *input_array = 0;
    char *input_name = NULL;
    char *instruction_name = NULL;
    unsigned int input_array_size = 0;
    instruction_name = argv[1];
    input_name = argv[2];

    /*
     * Controllo che il file esista, in caso contrario segnalo che il nome del file immesso è errato e non esiste.
     */

    if (!(fp = fopen(input_name, "r"))) {
        printf("File non trovato.\n");
        return 0;
    }

    /*
     * Controllo che quando eseguo il codice vengano usati i comandi corretti, in caso contrario segnalo l'errore.
     * Dopo aver controllato passo a alla funzione di stampa l'array contenente le istruzioni macchina in caso la funzione richiesta
     * fosse "stampa"
     *
     * Passo invece alla funzione di esecuzione l'array contenente le istruzioni macchina in caso la funzione richiesta fosse "esegui"
     * Se la richiesta fosse esegui, viene calcolata la dimensione dell'array che contiene le istruzioni e inizializzo lo stack e i registri
     * e pongo a zero gli indici ip e sp.
     */
    if (strcmp(instruction_name, "stampa") == 0) {

        input_array_size = input_to_array(fp, &input_array);
        print_assembly(input_array, input_array_size);
    } else if (strcmp(instruction_name, "esegui") == 0) {
        VM *virtual_stack;
        input_array_size = input_to_array(fp, &input_array);
        virtual_stack=(VM*)malloc (sizeof (struct virtual_machine));
        virtual_stack->sp=0;
        virtual_stack->ip=0; 
        execute (input_array, input_array_size, virtual_stack);
    } else {

        printf("Istruzione scorretta.\n");
    }


    /*
     * Libero la memoria allocata dinamicamente e rimuovo un errore del compilatore relativo ad argc
     */

    free(virtual_stack);
    free(input_array);
    (void) argc;
    return 0;
}