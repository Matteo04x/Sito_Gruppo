/*Matteo Spiga 3INB

Programma Crittografia di Cesare 12-02-2019

La Crittografia di Cesare consiste nel sostituire ogni carattere 
con quello che si trova K posizioni dopo nella tabella ascii.
Scrivere un programma per codificare una stringa presa in input 
secondo la crittografia di Cesare preso in input il valore di K minore di 5.*/

int menu();
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	char str[51];//dichiaro la stringa str
	char str2[51];//dichiaro la stringa str2
	int k;//dichiaro la variabile k
	int k2;//dichiaro la variabile k2
	int i;//dichiaro la variabile i
	int l;//dichiaro la variabile l
	int scelta;//dichiaro la variabile scelta
	int flag;//dichiaro la variabile flag
	
    flag=0;//condizione iniziale del flag, non e' stato effettuato l'input dei dati

	do{

		scelta=menu();

		switch (scelta){

		    case 1:

		    	printf("\n****************************************************************************************\n");

                do{
                    printf("\nNumero Massimo di Caratteri 50\n");//output del messaggio
                 	printf("\nInserisci una Stringa : ");//output del messaggio
                  	scanf("%s",str);//input della stringa str
                }while(strlen(str)>50);//controllo della lunghezza della stringa str

                strcpy(str2,str);//copio il contenuto della stringa str nella stringa str2

                do{
                   	printf("\nInserisci di quante Posizioni Traslare le Lettere nella Stringa (0-5): ");//output del messaggio
                    scanf("%d",&k);//input di k
                }while((k<0) || (k>5));//controllo dell'input di k

                for(i=0;i<strlen(str);i++){//lettura stringa str
                    if((str[i]>=97) && (str[i]<=122)){//se il carattere e' compreso nell'intervallo tra 97 e 122 
                        //allora
	                    if(str[i]+k>122){//se il carattere di indice i della stringa str sommato a k e' maggiore di 122
	                	    //allora
	                 	    l=str[i]-96;//assegno alla variabile l la sottrazione tra il carattere di indice i della stringa str e il valore 96
		                  	k2=122-str[i];//assegno alla variabile k2 la sottrazione tra il valore 122 e il carattere di indice i della stringa str
		                    k2=k-k2;//assegno alla variabile k2 la sottrazione tra la variabile k e la variabile k2
		                    str[i]=str[i]-l+k2;//assegno al carattere di indice i della stringa str la sottrazione tra esso e la variabile l sommata con k2
		                }
		                else{//senno'
		                 	str[i]=str[i]+k;//assegno al carattere di indice i della stringa str la somma di esso con la variabile k
		                }
	                }
	                if((str[i]>=65) && (str[i]<=90)){//se il carattere e' compreso nell'intervallo tra 65 e 90 
		                //allora
		                if(str[i]+k>90){//se il carattere di indice i della stringa str sommato a k e' maggiore di 90
		                    //allora
		                    l=str[i]-64;//assegno alla variabile l la sottrazione tra il carattere di indice i della stringa str e il valore 64
	             	        k2=90-str[i];//assegno alla variabile k2 la sottrazione tra il valore 90 e il carattere di indice i della stringa str
	                     	k2=k-k2;//assegno alla variabile k2 la sottrazione tra la variabile k e la variabile k2
		                    str[i]=str[i]-l+k2;//assegno al carattere di indice i della stringa str la sottrazione tra esso e la variabile l sommata con k2
		                }
		              	else{//senno'
		              		str[i]=str[i]+k;//assegno al carattere di indice i della stringa str la somma di esso con la variabile k
	                	}
	                }
                }

                flag=1;//assegno alla variabile flag il valore 1

                printf("\n");//vado a capo

                printf("\n****************************************************************************************\n");
   			break;

            case 2:

				printf("\n****************************************************************************************\n");

				if(flag==1){//se flag e' uguale ad 1 
				    //allora
				    printf("\nLa Stringa prima della Traslazione di %d Posizioni era :%s",k,str2);//output del messaggio
				    printf("\n\nLa Stringa dopo la Traslazione di %d Posizioni e':%s",k,str);//output del messaggio
			    }
				else{//senno' stampo il messaggio
				printf("\nErrore: Stringa non Inserita.\n");//output del messaggio
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

	printf("\nCrittografia di Cesare\n\n");//output del messaggio
	printf("\n1- Inserisci Stringa.\n");//output del messaggio
	printf("\n2- Stampa Stringa.\n");//output del messaggio	
	printf("\n0- Fine Programma.\n");//output del messaggio

	do{
		printf("\nInserisci operazione (0-2): ");//output del messaggio
		scanf("%d",&sc);//input di sc
	}while((sc<0) || (sc>2));//controllo dell'input di sc

	return sc;	
}
