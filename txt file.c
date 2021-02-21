/**
 * @file txt_file.c
 * @author Andrea Catacchio [718760]
 * @date
 * @version 1.0
 * @brief Contiene funzione per salvare le operazioni bancarie su un file di testo.
*/
#include "txt file.h"
/**
 * @brief Funzione per il salvataggio dell'archivio su file.
 * @details La funzione scrive su file l'archivio completo delle operazioni bancarie,
 *          sovrascrivendo il contenuto del vecchio file.
 * @param[in] ptr Puntatore al descrittore del file da scrivere.
 * @return Valore di ritorno:
 *         - 0: Errore: Archivio vuoto.
 *         - 1: File scritto correttamente.
 * @pre Archivio non vuoto.
 * @post File contenente il contenuto attuale dell'archivio.
 * @warning Il contenuto del file precedente alla scrittura andrà perso.
 *          Per evitare la perdita dei vecchi dati, si consiglia di eseguire
 *          un backup del file prima di ogni scrittura.
 * @warning Se l'archivio da scrivere non è stato correttamente inizializzato,
 *          il contenuto del file dopo la scrittura sarà indefinito.
*/
 int  text_file(FILE *ptr,Profilo * array[]) 
{
    if(ptr == NULL)
        return 0;
    
    int  result = 0;
    char  str[100];
    
    snprintf(str,100, " %s\t%s\t%s\t%s/%s|%s\n\n","codice cliente","tipo operazione","saldo","giorno","mese","anno");
    
    fwrite(str, sizeof(char), strlen(str), ptr);
    
    
    for(int i= 0;i < NUMERO_OPERAZIONI ;i++)
    {
        // la funzione memset compie una pulizia della stringa
        memset(str, 0, 100);
        snprintf(str,100," %s\t%s       %.2f\t %d/%d/%hu\n",array[i]->codice_cliente1,array[i]->tipo_operazione1,array[i]->ammontare_operazioni,array[i]->data_operazione1.giorno,array[i]->data_operazione1.mese,array[i]->data_operazione1.anno);
        
        
        result += fwrite(str, sizeof(char),strlen(str),ptr);
    
    }
    return result ;
}
