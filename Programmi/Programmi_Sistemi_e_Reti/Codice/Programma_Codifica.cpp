/*Matteo Spiga 3INB

Programma_Codifica

Scrivere un programma in linguaggio c dato un messaggio e una parola chiave di 4 caratteri scriva il corrispettivo messaggio crittografato attraverso la seguente modalita'.
*/

void codifica_frase(char codifica[]);//procedura prototipo per calcolare la codifica
int menu();//dichiarazione della funzione prototipo menu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	
	int scelta;//dichiaro la variabile scelta
	int i;//dichiaro la variabile i
	int i2;//dichiaro la variabile i2
	int flag;//dichiaro la variabile flag
	char codifica[5];//dichiaro la stringa codifica

    flag=0;//inizializzo la variabile flag assegnandogli il valore 0

	do{

		scelta=menu();//richiamo la funzione menu

		switch (scelta){

		    case 1:

		    	printf("\n****************************************************************************************\n");
		    	
				do{
		    		flag=0;//assegno alla variabile flag il valore 0
		    		
		    		printf("\nInserisci Lettere e Numeri,ma non Caratteri Uguali.\n");//output del messaggio
		    		do{
		    			printf("\nInserisci la Parola Chiave :");//output del messaggio
		    			scanf("%s",codifica);//input della stringa codifica
					}while(strlen(codifica)!=4);//controllo della lunghezza della stringa codifica
		    		
		    		for(i=0;i<=3;i++){
		    			if(((codifica[i]<48) || (codifica[i]>59)) && ((codifica[i]<65) || (codifica[i]>90)) && ((codifica[i]<97) || (codifica[i]>122))){
						//se il carattere di indice i della stringa codifica non e' un numero o una lettera
						    //allora
						    if(flag==0){//se il flag e' uguale a 0
						    	//allora
						    	printf("\nE' Stato Inserito un Carattere Diverso da una Lettera o un Numero.\n");//output del messaggio
							}
		    				flag=1;//assegno alla variabile flag il valore 1
						}
					}
					
					for(i=0;i<=3;i++){
						for(i2=0;i2<=3;i2++){
							if(i!=i2){//se la variabile i e' diversa dalla variabile i2
							    //allora
				 				if(codifica[i]==codifica[i2]){//se il carattere di indice i della stringa codifica e' uguale al carattere di indice i2 della stringa codifica
									//allora
									if(flag==0){//se il flag e' uguale a 0
						    	        //allora
						    	        printf("\nE' Stato Inserito piu' Volte lo Stesso Carattere.\n");//output del messaggio
							        }
									flag=1;//assegno alla variabile flag il valore 1
								}
							}
						}
					}
				}while(flag==1);//eseguo il ciclo do-while finche' flag e' uguale ad 1
		    	
                flag=1;//assegno alla variabile flag il valore 1
             
                printf("\n");//vado a capo

                printf("\n****************************************************************************************\n");
   			break;

            case 2:

				printf("\n****************************************************************************************\n");
				
				if(flag==1){
					codifica_frase(codifica);//calcolo la codifica della frase
				}
				else{
					printf("\nErrore: Non e' Stata Inserita Nessuna Parola Chiave.\n");//output del messaggio
				}

				printf("\n");//vado a capo

                printf("\n****************************************************************************************\n");
			break;
			

			
		}		
	}while(scelta!=0);//finche' scelta e' diversa da 0 eseguo il ciclo do-while
}

void codifica_frase(char codifica[]){
	
	char frase[25];//dichiaro la stringa frase
	char matrice[6][5];//dichiaro l'array di stringhe matrice
	char quattro[4][7];//dichiaro l'array di stringhe quattro
	char swap[7];//dichiaro la stringa swap
	int i,i2,k,n,f;//dichiaro le variabili
	
	do{
		printf("\n\nNumero Massimo di Caratteri Inseribili 20.\n");//output del messaggio
	    printf("\nInserisci la Frase che Vuoi Andare a Codificare : ");//output del messaggio
	    fflush(stdin);
		gets(frase);//input della stringa frase
	}while((strlen(frase)<1) || (strlen(frase)>20));//controllo della lunghezza della stringa frase
	
	strcpy(matrice[0],codifica);//copio la stringa codifica nella riga 0 dell'array di stringhe matrice
	
	i=0;//inizializzo la variabile i assegnandogli il valore 0
    
	i2=0;//inizializzo la variabile i2 assegnandogli il valore 0
    
	k=1;//inizializzo la variabile k assegnandogli il valore 1
			
    do{//divido la stringa frase in sottostringhe di 4 caratteri ognuna e le salvo nell'array di stringhe matrice
    	matrice[k][i2]=frase[i];//assegno al carattere di indice i2 della stringa k dell'array di stringhe matrice il carattere di indice i della stringa frase
    	
    	i2++;//incremento i2
    	if(i2==4){//se i2 e' uguale a 4
    	    //allora
    		i2=0;//azzero i2
    		k++;//incremento k
		}
    	i++;//incremento i
	}while(i<strlen(frase));//eseguo il ciclo do-while finche' i e' minore della lunghezza della stringa frase
	
	f=0;//inizializzo la variabile f assegnandogli il valore 0
	
	if(i2!=0){//se la variabile i2 e' diversa da 0
	    //allora
		for(i=i2;i<=3;i++){
			matrice[k][i]='*';//assegno al carattere di indice i della stringa k dell'array di matrice il carattere '*'
			f++;//incremento f
		}
	}
		
	for(i2=0;i2<=3;i2++){//salvo nell'array di stringhe quattro le colonne dell'array di stringhe matrice 
		for(i=0;i<=k;i++){
			fflush(stdin);//pulisco il buffer
		    quattro[i2][i]=matrice[i][i2];//assegno al carattere di indice i della stringa i2 dell'array quattro il carattere di indice i della stringa i2 dell'array matrice
	    }
	}
	
    for(i=1;i<=3;i++){//colloco i fine stringa alla fine delle stringhe
    	quattro[i][strlen(quattro[0])]='\0';
	}
    
	i2=0;//inizializzo la variabile i2 assegnandogli il valore 0
	
	do{//ordino attraverso il bubble-sort le stringhe dell'array quattro secondo la tabella ascii
		n=0;//inizializzo la variabile n assegnandogli il valore 0
		for(i=0;i<3-i2;i++){
			if(quattro[i][0]>quattro[i+1][0]){//se il carattere di indice 0 della stringa di indice i dell'array quattro e' maggiore del carattere di indice 0 della stringa i+1 dell'array quattro
				//allora
				strcpy(swap,quattro[i]);//copio la stringa di indice i dell'array quattro nella stringa swap
				strcpy(quattro[i],quattro[i+1]);//copio la stringa di indice i+1 dell'array quattro nella stringa di indice i dell'array quattro
				strcpy(quattro[i+1],swap);//copio la stringa swap nella stringa di indice i+1 dell'array quattro
				n++;//incremento n
			}
		}
		i2++;//incremento i2
	}while(n!=0);//eseguo il ciclo do-while finche n e' diversa da 0
	
	n=strlen(frase)+f;//calcolo la lunghezza della stringa frase
	
	i2=0;//inizializzo la variabile i2 assegnandogli il valore 0
	
	for(i=0;i<=3;i++){//unisco le stringhe dell'array quattro in unica stringa chiamata frase 
		for(k=1;k<strlen(quattro[i]);k++){
			frase[i2]=quattro[i][k];
			i2++;
		}
	}
	
	frase[n]='\0';//colloco il fine stringa alla fine della stringa
	
	printf("\nLa Frase Codificata Attraverso la Parola Chiave e' : %s",frase);//output del messaggio
	

}

int menu()
{
	int sc;//dichiaro la variabile sc

	printf("\nProgramma Codifica\n\n");//output del messaggio
	printf("\n1- Inserisci la Parola Chiave.\n");//output del messaggio
	printf("\n2- Inserisci una Frase e Visualizza la Codifica\n");//output del messaggio
	printf("\n0- Fine Programma.\n");//output del messaggio

	do{
		printf("\nInserisci operazione (0-2): ");//output del messaggio
		scanf("%d",&sc);//input di sc
	}while((sc<0) || (sc>2));//controllo dell'input di sc

	return sc;//restituisco la variabile sc
}
