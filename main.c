#include <stdio.h>
#include "print.c"
#include "execute.c"

int main() {

    /*
     * In questo main dobbiamo poter eseguire due operazioni:
     * print : Stampa il file di input come una serie di comandi
     * execute : Esegue i comandi riportarti all'interno del file input
     */
    FILE *fp;
    fp = fopen ("Fattoriale_prova.txt","r");
    print_input(fp);
    return 0;
}