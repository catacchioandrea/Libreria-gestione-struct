/**
 * @file menu.h
 * @author Andrea Catacchio [718760]
 * @date
 * @version 1.0
 * @brief Contiene funzione per salvare le operazioni bancarie su un file di testo.
*/
#ifndef menu_h
#define menu_h

#include "operazionibancarie1.h"
/**
 * @brief Funzione per la stampa del menu.
 * @details La funzione si occupa di stampare un menu a scelta e di ricevere in
 *          input l'indice relativo alla funzionalità alla quale si vuole accedere.
 * @param[out] Stampa del menu.
 * @return Valore di ritorno:
 *         - [1-5]: Comando inserito correttamnte.
 *         -    -1: Ristampa la linea dei comandi.
*/
int menu(void);

#endif /* menu_h */
