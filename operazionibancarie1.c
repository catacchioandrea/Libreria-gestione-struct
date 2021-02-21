/**
 * @file operazionibancarie1.c
 * @author Andrea Catacchio [718760]
 * @date
 * @version 1.0
 * @brief Contiene funzioni e tipi di dato per la gestione delle operazioni bancarie.
*/
#include "operazionibancarie1.h"
/**@brief Funzione per generare il codice cliente.
 * @details Il codice utente generato è casuale Formato LLLNNNLL, dove L=Lettera e N=Numero.
 * @param[out] codice_cliente con  il nuovo codice.
 */
char * genera_cod_cliente(void)
{
    //eseguiamo il cast della malloc poiche' sappiamo che la malloc ritorna un puntatore a void
    char * codice_cliente = (char*)malloc(sizeof(char)* CARATTERI_CODICE_CLIENTE);
    //dichiarazione di variabili che verranno usate ripetute volte in questa funzione
    int offset = 0;
    int i;//variabile per ciclo for
    
    //ciclo for per inserire valori nella stringa
    for (i = offset; i < LET_INIZIALI_COD_CLIENTE; i++)
    {
        codice_cliente[i] = (rand() % NUMERI_LETTERE_ALFABETO) + ASCII_A ;
    }
    
    //diamo un nuovo valore all'offset
    offset += LET_INIZIALI_COD_CLIENTE;
    
    //ciclo for per inserire valori nella stringa
    for (i = offset ; i < offset + LET_INIZIALI_COD_CLIENTE; i++)
    {
        codice_cliente[i] = (rand() % DIECI) + ASCII_0 ;    }
    
    //diamo un nuovo valore all'offset
    offset += LET_INIZIALI_COD_CLIENTE;
    
    //ciclo for per inserire valori nella stringa
    for (i = offset ; i < offset + LET_INIZIALI_COD_CLIENTE - 1 ; i++)
    {
        codice_cliente[i] = (rand() % NUMERI_LETTERE_ALFABETO) + ASCII_A ;
    }
    

    codice_cliente[i] = '\0';
    
    return codice_cliente;
}
/**
 * @brief funzione per la generazione di un array di struct contenente il codice dei clienti
 * @param[in] _mini_profilo è un array di struct (Mini_Profilo).
 * @pre Il parametro in input deve avere una zona di memoria allocata.
 * @return Valore di ritorno:
 *         - 0: Operazioni bancarie  non allocate
 *         - 1: Stampa completata
 */
int genera_array_cod_cliente(Mini_Profilo ** _mini_profilo)
{
    if(_mini_profilo == NULL)
        return 0;
    
    int i = 0;
        
    for(i = 0; i < NUMERO_CLIENTI ;i++)
    {
//  Alloca un blocco di dimensioni byte di memoria, restituendo un puntatore all'inizio del blocco.
        Mini_Profilo * heap = malloc(sizeof(Mini_Profilo));

//  Usiamo la strncpy per inserire il valore del seconto elemento nel primo elemento
        strncpy(heap->codice_cliente2,genera_cod_cliente(),CARATTERI_CODICE_CLIENTE);
//  Il contatore saldo, ovvero un campo della nostra struct lo poniamo = 0;
        heap->saldo = 0;
// Assegnamo il valore di heap ovvero la nostra variabile struct ai vari posti dell'array coni il  ciclo for
        _mini_profilo[i] = heap;
    }
    return 1;
}
/**
 * @brief Funzione per generare il tipo di operazione bancaria
 * @details scelta casualem di due possibilità [prelievo/deposito]
 */
char * genera_operazione(void)
{
//    viene creato un array contenente due stringhe
    char * tipo_operazione[] = {"prelievo","deposito"};
    
    int indice ;
//    funzione che genera un numero casuale nel range [0,1] e passa il valore alla variabile indice
    indice = (rand () % 2);

    return tipo_operazione[indice];
}
/**
 * @brief Funzione per generare un'operazione bancaria in modo casuale.
 * @details Vengono utilizzate funzioni locali per la generazione casuale
 *          dei singoli campi dell'operazione bancaria .
 * @pre vengono passate due valori di due struct  una contenete i codici utenti e una le date
 * @return Valore di ritorno:
 *         - NULL: Allocazione dinamica non riuscita.
 *         - STRUCT: Completa.
*/
Profilo * genera_op_bancaria(Mini_Profilo * t,data * max)
{
    Profilo * profilo1 = malloc(sizeof(Profilo));
    
    if(profilo1 == NULL)
    //Impossibile allocare dinamicamente
    return NULL;
    
//    genera codice utente
//  usiamo la strncpy per inserire il valore del seconto elemento nel primo elemento
    strncpy(profilo1->codice_cliente1,t->codice_cliente2,CARATTERI_CODICE_CLIENTE);
//    genera tipo operazione
//  usiamo la strncpy per inserire il valore del seconto elemento nel primo elemento
    strncpy(profilo1->tipo_operazione1,genera_operazione(), CARATTERI_TIPO_OPERAZIONE);
//    genera data operazione
    profilo1->data_operazione1.giorno = (*max).giorno ;
    profilo1->data_operazione1.mese = (*max).mese ;
    profilo1->data_operazione1.anno = (*max).anno ;
//    genera saldo operazione
    profilo1->ammontare_operazioni = rand() % (CREDITO_MASSIMO - CREDITO_MINIMO + 1 )+ CREDITO_MINIMO;
    profilo1->ammontare_operazioni += (float)(rand() % 99)/100.0;
    
    
    return profilo1;
}
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
int genera_array_date(data ** arraydate)
{
    
 if(arraydate == NULL)
     return 0;
    
    int i ;
    
    time_t a = 0;
    
    a = rand();
    
    struct tm * data_ora =  localtime(&a);
    
    for(i = 0;i < NUMERO_OPERAZIONI;i++)
    {
        data * data1 = malloc(sizeof(data1)*NUMERO_OPERAZIONI);
        
        a += 86400 * (rand() % 10);
        
        data_ora = localtime(&a);
        
        data1->giorno = data_ora->tm_mday;
        
        data1->mese = (data_ora->tm_mon + 1 ) ;
        
        data1->anno = (data_ora->tm_year + 1900);
        
        
        arraydate[i] = data1;

    }
    return 1;
}
/**
 * @brief Funzione per la creazione di un archivio di operazioni bancarie.
 * @param[in] Array  di struct Data,Profilo e Info.
 * @return Valore di ritorno:
 *         - 0: Operazioni bancarie  non allocate
 *         - 1: Stampa completata
 * @warning Non verrà garantito il corretto funzionamento nel caso di valori
 *          non validi dei campi. Si consigli di effettuare un controllo
 *          della correttezza dei campi prima della stampa.
*/
int archivio_operazioni_bancarie(data ** arraydate,Profilo ** array_struct,Mini_Profilo ** t)
{
    Profilo * profilo_principale = NULL;
    
    int i = 0;
    int flag = 0;
    
    for(i = 0;i < NUMERO_OPERAZIONI ;i++)
    {
        profilo_principale = genera_op_bancaria(t[rand() % NUMERO_CLIENTI],arraydate[i]);
        
        array_struct[i] = profilo_principale;
        if((stampa_op_bancarie(profilo_principale)) > 0)
           // free(profilo_principale)SBAGLIATISSIMO PERCHè LIBERO MEMOMORIA DOVE IN REALTà NON STA PIù.
        puts("");
        flag = 1;
    }
    
    return flag;
}
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
int stampa_op_bancarie(Profilo * profilo)
{
    if(profilo == NULL)
      return 0;
    
    printf("|Codice cliente : %s\n",profilo->codice_cliente1);
    printf("|Tipo di operazione :%s\n",profilo->tipo_operazione1);
    printf("|Data operazione : %d/%d/%d\n",profilo->data_operazione1.giorno,profilo->data_operazione1.mese,profilo->data_operazione1.anno);
    printf("|Ammontare credito cliente:%.2f\n",profilo->ammontare_operazioni);
    
    return 1;
    
}
/**
 * @brief Funzione per determinare il cliente con il saldo maggiore.
 * @pre Il parametro in input deve avere una zona di memoria allocata.
 * @param[in] _mini_profilo array di struct(Mini_Profilo)
 * @return Valore di ritorno:
 *         - 0: Saldo maggiore non trovato
 *         - 1: Saldo maggiore trovato
 */
int saldo_maggiore(Mini_Profilo ** _mini_profilo)
{
    if(_mini_profilo == NULL)
        return 0;
   
    Mini_Profilo * cliente_saldo_max = _mini_profilo[0];
    
    int i;//variabile contatore
    
    
    for(i = 1;i < NUMERO_CLIENTI ;i++)
    {
        
            if(_mini_profilo[i]->saldo > cliente_saldo_max->saldo)
            {
                cliente_saldo_max = _mini_profilo[i];
            }
    }
    puts("*************************************************************************");
    printf("\nIl cliente con il seguente codice %s ha il saldo piu' alto : %.2f\n",cliente_saldo_max->codice_cliente2,cliente_saldo_max->saldo);
    puts("\n*************************************************************************\n");

    return 1;
}
/**
 * @brief Funzione per determinare i clienti con il saldo negativo.
 * @pre Il parametro in input deve avere una zona di memoria allocata.
 * @param[in] _mini_profilo array di struct(Mini_Profilo)
 * @return Valore di ritorno:
 *         - 0: Saldo negativo non trovato
 *         - 1: Saldo negativo trovato
 */
int saldo_negativo (Mini_Profilo ** _mini_profilo)
{
    if(_mini_profilo == NULL)
        return 0;
    
    int i ;
    
    for(i = 0;i < NUMERO_CLIENTI;i++)
    {
            if(_mini_profilo[i]->saldo < 0)
            {
                puts("*************************************************************************");
                printf("\nIl cliente con il seguente codice %s ha il saldo negativo.\n",_mini_profilo[i]->codice_cliente2);
            }
    }
    return 1;
}
/**
 *@brief Funzione per l'incremento del saldo cliente.
 * @param[in] _mini_profili  è un array di struct (Mini_Profilo) e archivio è un array di struct (Profilo)i
 * @pre  I parametro in input devono avere una zona di memoria allocata.
 * @return Valore di ritorno:
 *         - 0:  I saldi dei clienti non  sono stati incrementati
 *         - 1:  I saldi dei clienti sono stati incrementati
 */
int incrementa_saldo(Mini_Profilo ** _mini_profili,Profilo ** archivio)
{
    if(_mini_profili == NULL || archivio == NULL)
        return 0;
//    dichiarazione variabili contatori per i cicli for
    int i = 0,j = 0;
//   ciclo for annidato per ricercare degli elementi specifici nei vari array di struct
    for(j = 0;j < NUMERO_CLIENTI ;j++)
    {
        for(i = 0;i < NUMERO_OPERAZIONI ;i++)
               {
//             funzione che paragona il primo argomento al secondo
                   if(strncmp(archivio[i]->codice_cliente1,_mini_profili[j]->codice_cliente2,CARATTERI_CODICE_CLIENTE)==0)
                   {
//             funzione che paragona il primo argomento al secondo
                       if(strcmp(archivio[i]->tipo_operazione1,"prelievo")==0)
                       {
                           _mini_profili[j]->saldo += (archivio[i]->ammontare_operazioni) * (-1);
                       }
                       else
                       {
                           _mini_profili[j]->saldo += archivio[i]->ammontare_operazioni;
                       }
                       
                   }
               }
    }
    return 1;
}
