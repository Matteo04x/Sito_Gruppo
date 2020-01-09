/*Matteo Spiga 3INB

Programma Indirizzo MAC 28-03-2019

Dato un Indirizzo MAC dire se e' di broadcast,single o di gruppo.*/

void indirizzo(char str[]);//dichiaro la procedura prototipo indirizzo
int menu();//dichiarazione funzione prototipo menu
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){

    int scelta;//dichiaro la variabile scelta
    int flag;//dichiaro la variabile flag
	int i;//dichiaro la variabile i
	char str[18];//dichiaro la stringa str
	
    flag=0;//stato iniziale del flag, non e' stato effettuato l'input dei dati

	do{

		scelta=menu();
		
		switch (scelta){

			case 1:

                printf("\n****************************************************************************************\n");
                
				printf("\nIndirizzo Mac nel Formato **-**-**-**-**-** .\n");//output del messaggio
				
                printf("\nEsempio : 02-60-8C-E9-8B-01 .\n");//output del messaggio
                   
                do{
                    do{
                    	printf("\n\nInserisci un Indirizzo Mac : ");//output del messaggio
                    	scanf("%s",str);//input della stringa str
					}while(strlen(str)!=17);//controllo della lunghezza della stringa str
						
					flag=0;//assegno alla variabile flag il valore 0

					for(i=0;i<strlen(str);i++){//leggo la stringa str
						if((i==2) || (i==5) || (i==8) || (i==11) || (i==14)){//se la variabile i e' uguale al valore 2,5,8,11,14
						    //allora
							if(str[i]!='-'){//se il carattere di indice i della stringa str e' diverso da '-'
							    //allora
								flag=1;//assegno alla variabile flag il valore 1
							}
						}
						else{//senno'
							if(((str[i]<48) || (str[i]>57)) && ((str[i]<65) || (str[i]>70))){//se il carattere di indice i della stringa str non e' compreso tra 0-9 o tra A-F
							    //allora
								flag=1;//assegno alla variabile flag il valore 1
							}
						}	
					}	
				}while(flag==1);//eseguo il ciclo do-while finche' la variabile flag e' uguale ad 1
				    
				flag=1;//assegno alla variabile flag il valore 1
                   	            
	            printf("\n");//vado a capo

                printf("\n****************************************************************************************\n");
            break;

		    case 2:
		    	 
                printf("\n****************************************************************************************\n");
                
                if(flag==1){//se la variabile flag e' uguale ad 1

                   indirizzo(str);//richiamo la procedura indirizzo
				}
				else{
					printf("\nErrore : Nessun Indirizzo Mac Inserito.\n");//output del messaggio  
				}

	            printf("\n");//vado a capo

                printf("\n****************************************************************************************\n");
   			break;
		}		
	}while(scelta!=0);//finche' scelta e' diversa da 0 eseguo il ciclo do-while
}

void indirizzo(char str[]){
	
	int i;//dichiaro la variabile i
	int decimale;//dichiaro la variabile decimale
	char compara[18]="FF-FF-FF-FF-FF-FF";//dichiaro la stringa compara
	
	decimale=0;//inizializzo la variabile decimale assegnandogli 0
	
    for(i=0;i<2;i++){
        if((str[i]>=48) && (str[i]<=57)){//se il carattere di indice i della stringa str e' un numero
            //allora
			decimale=(decimale*16)+str[i]-48;//calcolo il decimale
		}
		else{//senno'
			decimale=(decimale*16)+str[i]-55;//calcolo il decimale
		}
	}
               
    if(strcmp(str,compara)==0){//se la stringa str e la stringa compara sono uguali
    	//allora
        printf("\nL'Indirizzo MAC e' Broadcast.\n");//output del messaggio
	}
	else{//senno'
		if(decimale%2==0){//se la variabile decimale e' pari
			//allora
			printf("\nL'Indirizzo MAC e' Unicast.\n");//output del messaggio
		}
		else{//senno'
			if(decimale%2!=0){//se la variabile decimale e' dispari
			    //allora
				printf("\nL'Indirizzo MAC e' Multicast.\n");//output del messaggio
			}
		}
	}
}

int menu()
{
	int sc;//dichiaro la variabile sc

	printf("\nProgramma Indirizzo MAC.\n\n");//output del messaggio
	printf("\n1- Inserisci un Indirizzo MAC.\n");//output del messaggio
	printf("\n2- Stampa il Tipo dell'Indirizzo MAC inserito.\n");//output del messaggio
	printf("\n0- Fine Programma.\n");//output del messaggio

	do{
		printf("\nInserisci operazione (0-2): ");//output del messaggio
		scanf("%d",&sc);//input di sc
	}while((sc<0) || (sc>2));//controllo dell'input di sc

	return sc;//restituisco la variabile sc
}
