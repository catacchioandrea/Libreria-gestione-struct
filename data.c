/**
 * @file data.c
 * @author Andrea Catacchio [718760]
 * @date 17/11/2020
 * @version 1.0
 * @brief Contiene funzioni e tipi di dato per la gestione delle date.
*/

#include "data.h"

//! Array globale contenente il numero di giorni per ogni mese
const unsigned short int lista_giorni[] =
    {31,28,31,30,31,30,31,31,30,31,30,31};
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
int isBisestile(unsigned short _anno)
{
  if((_anno % 400) == 0)
    return 1; //Anno bisestile

  if((_anno % 4) == 0)
  {
    if((_anno % 100) == 0)
      return 0; //Anno non bisestile
    else
      return 1; //Anno bisestile
  }

  return 0; //Anno non bisestile
}
