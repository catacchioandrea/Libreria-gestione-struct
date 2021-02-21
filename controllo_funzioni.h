/**
 * @file controllo_funzioni.h
 * @author Andrea Catacchio [718760]
 * @date
 * @version 1.0
 * @brief Contiene funzione per il controllo di alcune funzioni locali.
*/
#ifndef controllo_funzioni_h
#define controllo_funzioni_h

#include "txt file.h"

int controllo_codice_cliente(const char * _cod_utente);
/**
 * @brief Funzione per il controllo della correttezza della data.
 * @details Vengono effettuati controlli di singoli valori di giorno,
 *          mese e anno. Viene controllato che il giorno sia compatibile
 *          con il mese e che tutti i campi rientrino nei range prefissati.
 * @param[in] _data Data da controllare.
 * @return Valore di ritorno:
 *         - 1: Formato corretto.
 *         - 0: Valori non validi.
*/
int controllo_data( data *  _data);
/**
 * @brief Funzione per il confronto di due date.
 * @pre Entrambi i parametri devono avere un'area di memoria associata, in quanto
 *      nella funzione non vi sono allocazioni dinamiche della memoria.
 * @param[in] d1 Prima data da confrontare.
 * @param[in] d2 Seconda data da confrontare.
 * @return Valore di ritorno:
 *         - 0: Errore: Parametri in input non allocati.
 *         - 1: data1 = data2
 *         - 2: data1 > data2
 *         - 3: data1 < data2
*/
int confronto_date(const data * const d1, const data * const d2);
/**
 *@brief funzione per il controllo del Saldo
 *@details viene effettuato un semplice if,che valutano se i il saldo è maggiore o minore alle costani rispettivamente Credito Massimo e Credito Minimo.
 *@param[in] _saldo il saldo di un utente
 * @return Valore di ritorno:
 *         - 1: Formato corretto.
 *         - 0: Valori non validi.
*/
int controllo_saldo(float _saldo);
#endif /* controllo_funzioni_h */
