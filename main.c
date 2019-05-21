#include <stdio.h>
#include "VM.h"
/*#include "execute.c"*/

int main() {

    /*
     * In questo main dobbiamo poter eseguire due operazioni:
     * print : Stampa il file di input come una serie di comandi
     * execute : Esegue i comandi riportarti all'interno del file input
     */

    FILE *fp;
    if (!(fp = fopen ("Fattoriale_prova.txt","r"))){
        printf  ("FILE NOT FOUND\n");
        return 0;
    }
    print_input(fp);
    fclose (fp);
    return 0;
}