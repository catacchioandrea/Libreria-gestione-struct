/**
 * @file operazionibancarie1.h
 * @author Andrea Catacchio [718760]
 * @date
 * @version 1.0
 * @brief Contiene funzioni e tipi di dato per la gestione delle operazioni bancarie.
*/
#ifndef operazionibancarie1_h
#define operazionibancarie1_h

#define CARATTERI_CODICE_CLIENTE 9//!Caratteri per  il campo  codice_cliente1
#define CARATTERI_TIPO_OPERAZIONE 14//!Caratteri per  il campo tipo_operazione1
#define LET_INIZIALI_COD_CLIENTE 3//!
#define LET_FINALI_COD_CLIENTE 2//!

#define NUMERI_LETTERE_ALFABETO 21
#define ASCII_A  65//! Codice ASCII carattere 'A'
#define ASCII_0 48//! Codice ASCII carattere '0'
#define DIECI 10//! Numero 10

#define CREDITO_MASSIMO 75000
#define CREDITO_MINIMO  1000

#define NUMERO_OPERAZIONI 100
#define NUMERO_CLIENTI 20


#include "data.h"

//! @brief Struttura dati per contenere una generica operazione bancaria.
struct profilo
{
    char codice_cliente1[CARATTERI_CODICE_CLIENTE];/**<Codice cliente */
    char tipo_operazione1[CARATTERI_TIPO_OPERAZIONE];/**<Tipo operazione[prelievo/deposito]*/
    data data_operazione1;/**Data dell'operazione bancaria */
    float ammontare_operazioni;/**Saldo del cliente*/
    
};
//typedef usato per rinominare il nome di una struct
typedef struct profilo Profilo;
//! @brief Struttura dati per contenere dei requisiti specifici di una certa operazione bancaria.
struct mini_profilo
{
    char codice_cliente2[CARATTERI_CODICE_CLIENTE];
    float  saldo;
};
//typedef usato per rinominare il nome di una struct
typedef struct mini_profilo Mini_Profilo;
/**@brief Funzione per generare il codice cliente.
 * @details Il codice utente generato è casuale Formato LLLNNNLL, dove L=Lettera e N=Numero.
 * @param[out] codice_cliente con  il nuovo codice.
 */
char * genera_cod_cliente(void);
/**
 * @brief Funzione per generare il tipo di operazione bancaria
 * @details scelta casualem di due possibilità [prelievo/deposito]
 */
char * genera_operazione(void);
/**
 * @brief Funzione per generare un'operazione bancaria in modo casuale.
 * @details Vengono utilizzate funzioni locali per la generazione casuale
 *          dei singoli campi dell'operazione bancaria .
 * @pre vengono passate due valori di due struct  una contenete i codici utenti e una le date
 * @return Valore di ritorno:
 *         - NULL: Allocazione dinamica non riuscita.
 *         - STRUCT: Completa.
*/
Profilo * genera_op_bancaria(Mini_Profilo * t,data * max);
/**
 *@brief Funzione per la generazione di date consecutive in un array di struct(data).
 *@param[in] arraydate Struct array date.
 *@return Valore di ritorno:
 *         - 0: date non allocate
 *         - 1: data allocata
 @warning Non verrà garantito il corretto funzionamento nel caso di valori
      non validi dei campi. Si consigli di effettuare un controllo
       della correttezza dei campi prima della stampa.
 */
int genera_array_date(data ** arraydate);
/**
 * @brief Funzione per la creazione di un archivio di operazioni bancarie.
 * @param[in]  Array di struct Data,Profilo e Info.
 * @return Valore di ritorno:
 *         - 0: Operazioni bancarie  non allocate
 *         - 1: Stampa completata
 * @warning Non verrà garantito il corretto funzionamento nel caso di valori
 *          non validi dei campi. Si consigli di effettuare un controllo
 *          della correttezza dei campi prima della stampa.
*/
int archivio_operazioni_bancarie(data ** arraydate,Profilo ** array_struct,Mini_Profilo ** t);
/**
 * @brief Funzione per stampare un'operazione bancaria nello strandard output.
 * @param[in] profilo Puntatore all'operazione bancaria da stampare.
 * @return Valore di ritorno:
 *         - 0: Operazioni bancarie  non allocate
 *         - 1: Stampa completata
 * @warning Non verrà garantito il corretto funzionamento nel caso di valori
 *          non validi dei campi. Si consigli di effettuare un controllo
 *          della correttezza dei campi prima della stampa.
*/
int stampa_op_bancarie(Profilo * profilo);
/**
 * @brief funzione per la generazione di un array di struct contenente il codice dei clienti
 * @param[in] _mini_profilo è un array di struct (Mini_Profilo).
 * @pre Il parametro in input deve avere una zona di memoria allocata.
 * @return Valore di ritorno:
 *         - 0: Array codice cliente non generato
 *         - 1: Array codice cliente generato
 */
int genera_array_cod_cliente(Mini_Profilo ** _mini_profilo);
/**
 *@brief Funzione per l'incremento del saldo cliente.
 * @param[in] _mini_profili  è un array di struct (Mini_Profilo) e archivio è un array di struct (Profilo)i
 * @pre  I parametro in input devono avere una zona di memoria allocata.
 * @return Valore di ritorno:
 *         - 0:  I saldi dei clienti non  sono stati incrementati
 *         - 1:  I saldi dei clienti sono stati incrementati
 */
int incrementa_saldo(Mini_Profilo ** _mini_profili,Profilo ** archivio);
/**
 * @brief Funzione per determinare il cliente con il saldo maggiore.
 * @pre Il parametro in input deve avere una zona di memoria allocata.
 * @param[in] _mini_profilo array di struct(Mini_Profilo)
 * @return Valore di ritorno:
 *         - 0: Saldo maggiore non trovato
 *         - 1: Saldo maggiore trovato
 */
int saldo_maggiore(Mini_Profilo ** _mini_profilo);
/**
 * @brief Funzione per determinare i clienti con il saldo negativo.
 * @pre Il parametro in input deve avere una zona di memoria allocata.
 * @param[in] _mini_profilo array di struct(Mini_Profilo)
 * @return Valore di ritorno:
 *         - 0: Saldo negativo non trovato
 *         - 1: Saldo negativo trovato
 */
int saldo_negativo (Mini_Profilo ** _mini_profilo);


#endif /* operazionibancarie1_h */
