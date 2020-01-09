/*Matteo Spiga 3INB

Programma_Pacchetti_28-02-2019

I dati preparati dalla precedente esercitazione vanno inseriti in un frame cosi strutturato:

-----------------------------------------------------
        |Header|<<dati>>|Checksum|
-----------------------------------------------------

Piu' precisamente:
1-L'Header di un byte contiene la lunghezza del campo dati.
2-I dati sono gli stessi calcolati nella precedente esercitazione:
'A' per le stringhe,'N' per i numeri in formato Big Endian,
'L' per i numeri in formato Little Endian.
3-Il trailer conterra' il checksum del solo campo dati, 
calcolato come XOR dei singoli byte contenuti in tale campo.
*/

int menu();//dichiarazione funzione prototipo menu
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){

    int scelta;//dichiaro la variabile scelta
	char str[24];//dichiaro la stringa str
	int  v[4];//dichiaro il vettore v
	int numero;//dichiaro la variabile numero
	int i;//dichiaro la variabile i
	int work;//dichiaro la variabile work
	int lunghezza;//dichiaro la variabile lunghezza

	do{

		scelta=menu();
		
		switch (scelta){

			case 1:

                printf("\n****************************************************************************************\n");

	            do{
		            printf("\nInserisci un Numero (0-32767): ");//output del messaggio
		            scanf("%d",&numero);//input di numero
	            }while((numero<0) || (numero>32767));//controllo dell'input di numero

                v[0]=3;//assegno al vettore v di indice 0 il valore 3
                
                v[1]=78;//assegno al vettore v di indice 1 il valore 78

                v[2]=numero/256;//assegno al vettore v di indice 2 la divisione tra numero e il valore 256
                
                v[3]=numero%256;//assegno al vettore v di indice 3 il resto della divisione tra numero e il valore 256
                
                v[4]=v[1]^v[2]^v[3];//effettuo la XOR dei singoli byte
                
                printf("\nIl Pacchetto in Formato Big Endian e' :");//output del messaggio
                
                for(i=0;i<5;i++){//lettura vettore v
                	if((i==1) || (i==4)){//se la variabile i e' uguale ad 1 o e' uguale a 4
                		//allora
                		printf("|");//stampo il carattere '|'
					}
					printf(" %xh ",v[i]);//ouput in esadecimale del vettore v di indice i
				}

	            printf("\n");//vado a capo

                printf("\n****************************************************************************************\n");

            break;

		    case 2:
		    	 
                printf("\n****************************************************************************************\n");

	            do{
		            printf("\nInserisci un Numero (0-32767): ");//output del messaggio
		            scanf("%d",&numero);//input di numero
	            }while((numero<0) || (numero>32767));//controllo dell'input di numero

                v[0]=3;//assegno al vettore v di indice 0 il valore 3
                
                v[1]=76;//assegno al vettore v di indice 1 il valore 76

                v[2]=numero%256;//assegno al vettore v di indice 2 il resto della divisione tra numero e il valore 256
                
                v[3]=numero/256;//assegno al vettore v di indice 3 la divisione tra numero e il valore 256
                
                v[4]=v[1]^v[2]^v[3];//effettuo la XOR dei singoli byte
                
                printf("\nIl Pacchetto in Formato Little Endian e' :");//output del messaggio
                
                for(i=0;i<5;i++){//lettura vettore v
                	if((i==1) || (i==4)){//se la variabile i e' uguale ad 1 o e' uguale a 4
                		//allora
                		printf("|");//stampo il carattere '|'
					}
					printf(" %xh ",v[i]);//ouput in esadecimale del vettore v di indice i
				}

	            printf("\n");//vado a capo

                printf("\n****************************************************************************************\n");

   			break;

   			case 3:

				printf("\n****************************************************************************************\n");

                
				do{
					printf("\nNumero Massimo di Caratteri 20\n");//output del messaggio
		            printf("\nInserisci una Stringa : ");//output del messaggio
		            scanf("%s",str);//input della stringa str
	            }while(strlen(str)>20);//controllo della lunghezza della stringa str

                lunghezza=strlen(str);//assegno alla variabile lunghezza la lunghezza della stringa

	            for(i=lunghezza-1;i>=0;i--){
		            str[i+2]=str[i];//sposto i caratteri all'interno della stringa di due posizioni
	            }
	            
	            str[1]='A';//assegno alla posizione di indice 1 della stringa str il carattere A
	            
	            str[0]=lunghezza+1;//assegno alla posizione di indice 0 della stringa il valore corrispondente alla somma di lunghezza e 1
	            
	            work=str[1];//assegno alla variabile work il carattere di indice 1 della stringa str
	            
	            for(i=2;i<lunghezza+2;i++){
	                work=work^str[i];//effettuo la XOR dei singoli byte
				}

	            str[lunghezza+2]=work;//assegno alla posizione di indice uguale alla somma di lunghezza e 2 la variabile work
	            
	            str[lunghezza+3]='\0';//assegno alla posizione di indice uguale alla somma di lunghezza e 3 il carattere '\0'

                printf("\nIl Pacchetto e' : ");//output del messaggio
                	                            

                for(i=0;i<lunghezza+3;i++){//lettura stringa str
                	if((i==lunghezza+2) || (i==1)){//se la variabile i e' uguale alla somma di lunghezza e 2
                		//allora
                		printf("|");//stampo il carattere '|'
					}
					printf(" %xh ",str[i]);//ouput in esadecimale del carattere di indice i della stringa str
				}

				printf("\n");//vado a capo
				
                printf("\n****************************************************************************************\n");
                
            break;
		}		
	}while(scelta!=0);//finche' scelta e' diversa da 0 eseguo il ciclo do-while
}

int menu()
{
	int sc;//dichiaro la variabile sc

	printf("\nProgramma Pacchetti.\n\n");//output del messaggio
	printf("\n1- Pacchetto in Formato Big Endian.\n");//output del messaggio
	printf("\n2- Pacchetto in Formato Little Endian.\n");//output del messaggio
	printf("\n3- Pacchetto Stringa.\n");//output del messaggio	
	printf("\n0- Fine Programma.\n");//output del messaggio

	do{
		printf("\nInserisci operazione (0-3): ");//output del messaggio
		scanf("%d",&sc);//input di sc
	}while((sc<0) || (sc>3));//controllo dell'input di sc

	return sc;//restituisco la variabile sc
}
