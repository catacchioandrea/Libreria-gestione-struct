/**
 * @file data.h
 * @author Andrea Catacchio [718760]
 * @date 
 * @version 1.0
 * @brief Contiene funzioni e tipi di dato per la gestione delle date.
*/
#ifndef DATA_H
#define DATA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define ANNO_MAX 2019 /**< Anno massimo per la generazione delle date */
#define ANNO_MIN 2000 /**< Anno minimo per la generazione delle date */
#define NUMERO_MESI 12 /**< Numero mesi in un anno */
#define LUNGHEZZA_DATA 10 /**< Lunghezza data in formato stringa */
#define MESE_FEBBRAIO 2 /**< Numero del mese di febbraio */
#define GIORNI_FEBBRAIO_BISESTILE 29 /**< Giorni di febbraio quando l'anno è bisestile */


//! @brief Array globale contenente il numero di giorni per ogni mese.
extern const unsigned short int lista_giorni[];

//! @brief Struttura dati per contenere una generica data.
typedef struct
{
  unsigned char giorno; /**< Contiene un valore di lista_giorni[] */
  unsigned char mese; /**< Contiene un valore in [1-12] */
  unsigned short anno; /**< Contiene un valore in [1960-2001] */
}data;
/**
 * @brief Funzione per il controllo della bisestilità.
 * @details Si ricorda che un anno è bisestile se è divisibile per 4.
 *          Se però è divisibile anche per 100, non è bisestile.
 *          Tuttavia è bisestile se è divisibile per 400.
 * @param[in] _anno Anno da analizzare.
 * @return Valore di ritorno:
 *         - 1: Anno bisestile.
 *         - 0: Anno non bisestile.
*/
int isBisestile(unsigned short _anno);

#endif // DATA_H
