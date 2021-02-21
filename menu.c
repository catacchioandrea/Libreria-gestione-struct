/**
 * @file menu.c
 * @author Andrea Catacchio [718760]
 * @date
 * @version 1.0
 * @brief Contiene funzione per salvare le operazioni bancarie su un file di testo.
*/
#include "menu.h"
/**
 * @brief Funzione per la stampa del menu.
 * @details La funzione si occupa di stampare un menu a scelta e di ricevere in
 *          input l'indice relativo alla funzionalità alla quale si vuole accedere.
 * @param[out] Stampa del menu.
 * @return Valore di ritorno:
 *         - [1-5]: Comando inserito correttamnte.
 *         -    -1: Ristampa la linea dei comandi.
*/
int menu (void)
{
    int choice = 0;
    puts("*************************************************************************");
    puts("Benvenuto, questo e' un programma che genera random 100 operazioni bancarie");
    puts("premere 1 per generare 100 operazioni bancarie ");
    puts("premere 2 per salvare le operazioni bancarie su un file di testo");
    puts("premere 3 per sapere chi e' l'utente con il saldo piu' alto");
    puts("premere 4 per sapere chi e' l'utente con il saldo negativo");
    puts("premere 5 per eseguire il test.");
    puts("premere 6 per terminare il programma ");
    puts("*************************************************************************");

    scanf("%d",&choice);
    
    return choice;
}
