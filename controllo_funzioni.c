/**
 * @file controllo_funzioni.h
 * @author Andrea Catacchio [718760]
 * @date
 * @version 1.0
 * @brief Contiene funzione per il controllo di alcune funzioni locali.
*/
#include "controllo_funzioni.h"


int controllo_codice_cliente(const char * _cod_utente)
{
    if(_cod_utente == NULL)
        return 0;
    
   unsigned int lunghezza = 0,i;
    
    lunghezza = (unsigned int)strlen(_cod_utente);
    
    //Controllo lunghezza
    if(lunghezza > CARATTERI_TIPO_OPERAZIONE)
      return 0;
    if(lunghezza < LET_INIZIALI_COD_CLIENTE)
      return 0;
    //Controllo caratteri
    for(i = 0;i < lunghezza;i++)
    {
      if(isalpha(_cod_utente[i]) || isspace(_cod_utente[i]));
      else  return 0;
    }
    //controllo lunghezza
    for(i = 0; i < LET_INIZIALI_COD_CLIENTE;i++)
    {
        if(!isalpha(_cod_utente[i]))
            return 0;
    }
    for(i = LET_INIZIALI_COD_CLIENTE - 1 ;i < LET_INIZIALI_COD_CLIENTE + LET_INIZIALI_COD_CLIENTE ;i++)
    {
        if(!isdigit(_cod_utente[i]))
            return 0;
    }
    for(i = LET_INIZIALI_COD_CLIENTE + LET_INIZIALI_COD_CLIENTE - 1; i < CARATTERI_TIPO_OPERAZIONE;i++)
    {
        if(!isalpha(_cod_utente[i]))
            return 0;
    }
    return 1;
}
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
int confronto_date(const data *  d1, const data *  d2)
{
  if(d1 == NULL || d2 == NULL) //Errore
    return 0;

  //Confronta anno
  if(d1->anno < d2->anno) return 3;
  if(d1->anno > d2->anno) return 2;

  //Anno uguale ==> Confronta mese
  if(d1->mese < d2->mese) return 3;
  if(d1->mese > d2->mese) return 2;

  //Anno e mese uguali ==> Confronta giorno
  if(d1->giorno < d2->giorno) return 3;
  if(d1->giorno > d2->giorno) return 2;

  return 1; //Date uguali
}

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
int controllo_data( data *  _data)
{
  if(_data->mese > NUMERO_MESI || _data->mese < 1) return 0;

  if(_data->giorno > lista_giorni[(int)_data->mese -1] && !(_data->mese == MESE_FEBBRAIO && _data->giorno == 29  &&  isBisestile(_data->anno)))  return 0;
    
  if(_data->giorno < 1)  return 0;


  return 1;
}
/**
 *@brief funzione per il controllo del Saldo
 *@details viene effettuato un semplice if,che valutano se i il saldo è maggiore o minore alle costani rispettivamente Credito Massimo e Credito Minimo.
 *@param[in] _saldo il saldo di un utente
 * @return Valore di ritorno:
 *         - 1: Formato corretto.
 *         - 0: Valori non validi.
*/
int controllo_saldo(float _saldo)
{
    if(_saldo == 0)
        return 0;
    
    if(_saldo > CREDITO_MASSIMO || _saldo < CREDITO_MINIMO)
        return 0;
    
    return 1;
}
