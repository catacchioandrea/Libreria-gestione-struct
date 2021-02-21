/**
 * @file testing.c
 * @author Andrea Catacchio [718760]
 * @date
 * @version 1.0
 * @brief Contiene funzione per il testing.
*/
#include "testing.h"
#include "controllo_funzioni.h"
#include <assert.h>

/**
 * @brief Procedura di testing per le funzioni della libreria @b studente.h.
 * @warning La procedura causa l'arresto dell'esecuzione del programma
 *          nel caso in cui le asserzioni non siano tutte verificate.
*/ 
int test(void)
{
    int flag = 0;
    //creazione data1
     data * data1 = malloc(sizeof(data));
    data1->anno = (unsigned short)2019;
    data1->mese = 11;
    data1->giorno = 12;
    //creazione data2
    data * data2 = malloc(sizeof(data));
    data2->anno = (unsigned short)2070;
    data2->mese = 11;
    data2->giorno = 4;
    
    data * data3 = malloc(sizeof(data));
    data3->anno = (unsigned short)2033;
    data3->mese = 2;
    data3->giorno = 29;
    
    data * data4 = malloc(sizeof(data));
    data4->anno = (unsigned short)2020;
    data4->mese = 1;
    data4->giorno = 32;
    
    
    assert(controllo_saldo(17.89) == 0);/**numero troppo piccolo*/
    assert(controllo_saldo(1002.0) == 1);/**numero corretto*/
    assert(controllo_saldo(75000.3) == 0);/**numero troppo grande*/
    assert(controllo_saldo(74999.9) == 1);/**numero corretto*/
 
    
   assert(controllo_data(data1)==  1);/**data accettata*/
   assert(controllo_data(data3)== 0);/***anno non bisestile*/
   assert(controllo_data(data4)== 0);/**giorni non validi*/
    
    
   assert(confronto_date(data1,data2)== 3);/**data1 < data2*/
   assert(confronto_date(data2,data1)== 2);/**data 2 > data1*/
   assert(confronto_date(data1,data1)== 1);/**le due date sono uguali*/

    flag = 1;
    
    return flag;
}
    

