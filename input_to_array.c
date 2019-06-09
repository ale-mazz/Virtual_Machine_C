/*
 * File prodotto da Alessandro Mazzon
 *
 * P1G95
 * Alessandro Mazzon - 877443
 * Davide Vio - 858687
 *
 * In questo file è stata creata una funzione che, partendo dal file fp crea un array "input_array" allocato dinamicamente contenente
 * tutti numeri interi che corrispondono alle istruzioni e ai registri/numeri contenuti nel file macchina,
 * il tipo di ritorno della funzione è int poichè ritornerà la dimensione dell'array appena creato.
 * Anche se il file macchina è corretto per ipotesi, abbiamo deciso di usare unsigned solo per il valore relativo
 * alla dimensione dell'array.
 */

#include "VM.h"

int input_to_array(FILE *fp, int **input_array) {

    char *line;
    int first = 0;
    unsigned int array_size = 0;
    int i = 0;
    size_t linesize = 1;


    line = (char *) malloc(sizeof(char) * linesize);

    /*
     * Mi salvo la dimensione dell'array passandomi il numero all'interno della prima riga del file, in questo modo
     * lo salvo e sono pronto a scorrere il file per riempirmi l'array.
     */
    while ((first == 0 && getline(&line, &linesize, fp)) > 0) { /* Viene utilizzato un intero first per avere la certezza che venga preso sempre
 *                                                                 e solo il primo numero valido trovato nel file.*/
        char *p = strtok(line, " ;");
        if (p[0] >= '0' && p[0] <= '9') {
            array_size = atoi(line);
            first = 1;
        }
    }
    *input_array = realloc(*input_array, array_size * sizeof(int));
    while ((getline(&line, &linesize, fp)) != -1) {
        /*
         * Prendo solo il contenuto della linea fino al carattere ";".
         */
        char *p = strtok(line, " ;");

        /*
         * Tramite questo if controllo che nella prossima linea ci sia inanzitutto un numero
         * che potrà essere sia positivo che negativo, in caso affermativo lo inserisco nell'array tramite atoi.
         */
        if ((p[0] >= '0' && p[0] <= '9') || p[0] == '-') {
            (*input_array)[i] = atoi(p);
            i++;
        }
    }

    free(line);
    return array_size;
}

