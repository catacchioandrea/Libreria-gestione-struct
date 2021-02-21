
#include "testing.h"
#include "controllo_funzioni.h"
int main() {
    
  
    //variabili che conterranno valori di ritorno rispettivamente delle funzioni:saldo_maggiore(),saldo_negativo() e test()
    int saldo1,saldo2,test1;
    //variabili per contenere rispettivamente i valori di ritorno dekle funzioni archivio_operazioni_bancarie(),incrementa_saldo()
    int archivio1,incrementa;
//Inizializza il generatore pseudo-casuale
    srand((unsigned int)time(NULL));
    
int result_txt_operation = 0;//variabile che conterrà il valore di ritorno della funzione text_file().
    
int scelta = 0;//variabile che conterrà il valore di ritorno della funzione menu().
    
    //dichiaro array di struct principale
    Profilo * struct_array_profili[NUMERO_OPERAZIONI];
    //array di struct secondaria
   Mini_Profilo * array_codice_cliente[NUMERO_CLIENTI];
    //funzione per la generazione di un array di codici clienti,i codici clienti generati dipendono dalla costante NUMERO_CLIENTI
    genera_array_cod_cliente(array_codice_cliente);
    //dichiaro l'array di struct data
    data * struct_array_date[NUMERO_OPERAZIONI];
    
    genera_array_date(struct_array_date);
    
    FILE * fd;//Descrittore del file per il backup
    
   // fopen restituisce un valore che ritorna nel descrittore del file se il valore del file è uguale a NULL ripete l'operazione
    if((fd = fopen("OperazioniBancarie.txt","w")) == NULL)
      fd = fopen("OperazioniBancarie.txt","w");
    
    
    //ripetizione del menu fino all'inserimento del valore sentinella ovvero 6
    while(( scelta = menu() )  != 6)
    {
        switch (scelta) {
                
            case 1://crea archivio
                
                    if((archivio1 = archivio_operazioni_bancarie(struct_array_date, struct_array_profili,array_codice_cliente))== 1)
                    
                    if((incrementa = incrementa_saldo(array_codice_cliente, struct_array_profili))== 1)
                    break;
                
            case 2://Salvataggio su file
                
                    if( (result_txt_operation = text_file(fd, struct_array_profili)) > 0)
                       {
                           puts("\n\nIl file di testo e' stato creato correttamente.\n\n");
                       }
                
                    break;
                
            case 3://saldo maggiore
                
                    if ((saldo1 = saldo_maggiore(array_codice_cliente))== 1)
                
                    break;
                
            case 4://saldo negativo
                
                    if((saldo2 = saldo_negativo(array_codice_cliente))== 1)
                
                    break;
                
            case 5:
                
                    if ((test1 = test())== 1)
                
                   puts("testing eseguito correttamente");
               
                    break;
                
            default:
                
                    puts("\n\nInserire numero corretto\n\n");
                
                    break;
        }
    }
    
    //eseguo il free per liberare memoria 
    for(int i = 0; i < NUMERO_CLIENTI; i++)
    {
        free(array_codice_cliente[i]);
    }
    
}
