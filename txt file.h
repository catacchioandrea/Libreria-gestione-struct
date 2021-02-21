/**
 * @file txt_file.h
 * @author Andrea Catacchio [718760]
 * @date
 * @version 1.0
 * @brief Contiene funzione per salvare le operazioni bancarie su un file di testo.
*/
#ifndef txt_file_h
#define txt_file_h

#include "menu.h"
/**
 * @brief Funzione per il salvataggio dell'archivio su file.
 * @details La funzione scrive su file l'archivio completo delle operazioni bancarie,
 *          sovrascrivendo il contenuto del vecchio file.
 * @param[in] ptr Puntatore al descrittore del file da scrivere e un array di struct Profilo.
 * @return Valore di ritorno:
 *         - 0: Errore: Archivio vuoto.
 *         - 1: File scritto correttamente.
 * @pre il file deve essere già stato aperto
 * @post File contenente il contenuto attuale dell'archivio.
 * @warning Il contenuto del file precedente alla scrittura andrà perso.
 *          Per evitare la perdita dei vecchi dati, si consiglia di eseguire
 *          un backup del file prima di ogni scrittura.
 * @warning Se l'archivio da scrivere non è stato correttamente inizializzato,
 *          il contenuto del file dopo la scrittura sarà indefinito.
*/
 int  text_file(FILE *ptr,Profilo * array[]);

#endif /* txt_file_h */
