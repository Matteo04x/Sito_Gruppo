/*Matteo Spiga 3INB

Programma Visitatori
Gestire i dati dei visitatori dell'Istituto "G.M.Montani" nelle giornate del tombolone.I dati da gestire sono:
-Nome,Cognome,Citta',Provincia,E-mail,Classe frequentata (0-14),Codice.
Eseguire le seguenti funzioni tramite un menu di scelta:
-Inserimento dei dati (richiamando la funzione volta a volta)
-Stampa con selezione (per citta',provincia,classe frequentata)
-Eliminazione visitatore (per codice numerico)
-Modifica dato (per codice numerico)
-Termina Programma

Nell'inserimento della mail vanno imposte le seguenti condizioni:
-Deve essere presente una chiocciola(la chiocciola non dovra' essere inserita in posizione [0]);
-Dopo la chiocciola, deve essere presente solo un punto (tra la chiocciola e il punto ci va almeno un carattere);
-Dopo il punto, devono essere presenti almeno due caratteri;*/

struct visitatore{
	char nome[26],cognome[26],citta[26],provincia[3],email[26];
	int codice,classe;
	//char descrizione[31];//Scuola Aperta,Settimana dell'Informatica,Visita Guidata,Tombolone,Altro..
	//codice che viene incrementato automaticamente quando inserisco un visitatore
};

typedef struct visitatore visitatore;

visitatore inserimento(int n,visitatore elenco[]);//dichiarazione della funzione prototipo inserimento

int controllo_nome(char nome[],char cognome[],int n,visitatore elenco[]);//dichiarazione della funzione prototipo controllo_nome
int controllo_email(char email[],int n,visitatore elenco[]);//dichiarazione della funzione prototipo controllo_email
int controllo_codice(int codice,int n,visitatore elenco[]);//dichiarazione della funzione prototipo controllo_codice

void visitatori_per_citta(int n,visitatore elenco[]);//dichiarazione della procedura prototipo visitatori_per_citta
void visitatori_per_provincia(int n,visitatore elenco[]);//dichiarazione della procedura prototipo visitatori_per_provincia
void visitatori_per_classe(int n,visitatore elenco[]);//dichiarazione della procedura prototipo visitatori_per_classe

int cancellare_un_visitatore(int n,visitatore elenco[]);//dichiarazione della funzione prototipo cancellare_un_visitatore

void modifica(int n,visitatore elenco[]);//dichiarazione della procedura prototipo modifica

int menu();//dichiarazione della funzione prototipo menu
int menu_();//dichiarazione della funzione prototipo menu_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	
	int scelta;//dichiaro la variabile scelta
	int flag;//dichiaro la variabile flag
	int n;//dichiaro la variabile n
	int i;//dichiaro la variabile i
	visitatore elenco[500];//dichiaro l'array di struct elenco

	n=0;//inizializzo la variabile n assegnandogli il valore 0	
	
    flag=0;//condizione iniziale del flag, non e' stato effettuato l'input dei dati

	do{

		scelta=menu();

		switch (scelta){

		    case 1:

		    	printf("\n****************************************************************************************\n");

                    if(n<500){//se la variabile n e' minore di 500
                	    //allora
                        printf("\n\nInserisci le Informazioni riguardanti il Visitatore N.%d.\n\n",n+1);//output del messaggio
                
                        elenco[n]=inserimento(n,elenco);//richiamo la funzione inserimento
                        
                        n++;//incremento la variabile n di un'unita'
				    }
                
                flag=1;//assegno alla variabile flag il valore 1
             
                printf("\n");//vado a capo

                printf("\n****************************************************************************************\n");
   			break;

            case 2:

				printf("\n****************************************************************************************\n");

				if(flag==1){//se flag e' uguale ad 1 
				    //allora
				    printf("\nInserisci 1 per Visualizzare i Visitatori di una Determinata Citta'.\n");//output del messaggio
					printf("\nInserisci 2 per Visualizzare i Visitatori di una Determinata Provincia.\n");//output del messaggio
					printf("\nInserisci 3 per Visualizzare i Visitatori di una Determinata Classe.\n");//output del messaggio
					
					do{
						printf("\nInserisci scelta (1-3) : ");//output del messaggio
						scanf("%d",&i);//input di i
					}while((i<1) || (i>3));//controllo dell'input di i
					
					if(i==1){//se la variabile i e' uguale al valore 1
					    //allora
						visitatori_per_citta(n,elenco);//richiamo la procedura visitatori_per_citta
					}
					else{//senno'
						if(i==2){//se la variabile i e' uguale al valore 2
						    //allora
							visitatori_per_provincia(n,elenco);//richiamo la procedura visitatori_per_provincia
						}
						else{//senno'
							visitatori_per_classe(n,elenco);//richiamo la procedura visitatori_per_classe
						}
					}
			    }
				else{//senno' stampo il messaggio
				    printf("\nErrore: Nessun Visitatore Inserito.\n");//output del messaggio
				}

				printf("\n");//vado a capo

                printf("\n****************************************************************************************\n");
			break;
			
			case 3:

				printf("\n****************************************************************************************\n");

				if(flag==1){//se flag e' uguale ad 1 
				    //allora
                
					i=cancellare_un_visitatore(n,elenco);//richiamo la funzione cancellare_un_visitatore
					
				    if(i==1){//se la variabile e' uguale ad 1
				        //allora
				  	    n--;//decremento la variabile n di un'unita'
				    }
				    
			    }
				else{//senno' stampo il messaggio
				    printf("\nErrore: Nessun Visitatore Inserito.\n");//output del messaggio
				}

				printf("\n");//vado a capo

                printf("\n****************************************************************************************\n");
			break;
			
			case 4:

				printf("\n****************************************************************************************\n");

				if(flag==1){//se flag e' uguale ad 1 
				    //allora  		
                    modifica(n,elenco);//richiamo la procedura modifica
			    }
				else{//senno' stampo il messaggio
				    printf("\nErrore: Nessun Visitatore Inserito.\n");//output del messaggio
				}

				printf("\n");//vado a capo

                printf("\n****************************************************************************************\n");
			break;	
		}		
	}while(scelta!=0);//finche' scelta e' diversa da 0 eseguo il ciclo do-while
}

visitatore inserimento(int n,visitatore elenco[]){
	
	visitatore scheda;//dichiaro la struct scheda
	char classe[3];//dichiaro la stringa classe
	int ris;//dichiaro la variabile ris
	int i;//dichiaro la variabile i
	
	do{
	    do{
            printf("\nInserisci Massimo 25 Caratteri.\n");//output del messaggio
            printf("\nInserire il Nome del Visitatore : ");//output del messaggio
            fflush(stdin);
            gets(scheda.nome);//input di scheda.nome
        }while((strlen(scheda.nome)>25) || (strlen(scheda.nome)<1));//controllo della lunghezza di scheda.nome
        
	    do{
         	printf("\n\nInserisci Massimo 25 Caratteri.\n");//output del messaggio
            printf("\nInserire il Cognome del Visitatore : ");//output del messaggio
            fflush(stdin);
            gets(scheda.cognome);//input di scheda.cognome
        }while((strlen(scheda.cognome)>25) || (strlen(scheda.cognome)<1));//controllo della lunghezza di scheda.cognome
	
        ris=controllo_nome(scheda.nome,scheda.cognome,n,elenco);//richiamo la funzione controllo_nome

        if(ris!=-1){//se la variabile ris e' diversa da -1
            //allora
            printf("\n\nIl Nome e Cognome Inseriti Sono gia' Stati Associati ad un altro Visitatore.\n");//output del messaggio
        }
    }while(ris!=-1);//esegui il ciclo do-while finche' la variabile ris e' diversa da -1

    do{
    	
	    ris=0;//inizializzo la variabile ris assegnandogli il valore 0
	    
        do{
		    printf("\n\nInserisci 2 Caratteri.\n");//output del messaggio
         	printf("\nInserire la Provincia del Visitatore %s %s : ",scheda.nome,scheda.cognome);//output del messaggio
		    scanf("%s",scheda.provincia);//input di scheda.provincia
        }while(strlen(scheda.provincia)!=2);//controllo della lunghezza di scheda.provincia
        
        for(i=0;i<strlen(scheda.provincia);i++){//leggo tutti i caratteri della stringa scheda.provincia
	    	if(((scheda.provincia[i]<97) || (scheda.provincia[i]>122)) && ((scheda.provincia[i]<65) || (scheda.provincia[i]>90))){
			//se il carattere di indice i della stringa scheda.provincia non e' una lettera
			    //allora
	    		ris=1;//assegno alla variabile ris il valore 1
			}
		}
    }while(ris!=0);//eseguo il ciclo do-while finche' la variabile ris e' diversa da 0

    do{
    	
	    ris=0;//inizializzo la variabile ris assegnandogli il valore 0
	    
        do{
		    printf("\n\nInserisci Massimo 25 Caratteri.\n");//output del messaggio
		    printf("\nInserire la Citta' del Visitatore %s %s : ",scheda.nome,scheda.cognome);//output del messaggio
		    fflush(stdin);
		    gets(scheda.citta);//input di scheda.citta
	    }while((strlen(scheda.citta)>25) || (strlen(scheda.citta)<1));//controllo della lunghezza di scheda.citta
        
        for(i=0;i<strlen(scheda.citta);i++){//leggo tutti i caratteri della stringa scheda.citta
	    	if(((scheda.citta[i]<97) || (scheda.citta[i]>122)) && ((scheda.citta[i]<65) || (scheda.citta[i]>90)) && (scheda.citta[i]!=32) && (scheda.citta[i]!=39)){
	    		//se il carattere di indice i della stringa scheda.citta non e' una lettera,spazio,apostrofo
	            //allora
	    		ris=1;//assegno alla variabile ris il valore 1
			}
		}
    }while(ris!=0);//eseguo il ciclo do-while finche' la variabile ris e' diversa da 0
    
    do{
    	
	    ris=0;//inizializzo la variabile ris assegnandogli il valore 0
	    
        do{
		    printf("\n\nInserisci 2 Cifre.\n");//output del messaggio
		    printf("\nInserire la Classe (00-14) del Visitatore %s %s : ",scheda.nome,scheda.cognome);//output del messaggio
		    fflush(stdin);
		    gets(classe);//input della stringa classe
	    }while(strlen(classe)!=2);//controllo della lunghezza della stringa classe
        
        
        for(i=0;i<strlen(classe);i++){//leggo i caratteri della stringa classe
	        if((classe[i]<48) || (classe[i]>57)){
				//se il carattere di indice i della stringa classe non e' un numero
	            //allora
	            ris=1;//assegno alla variabile ris il valore 1
            }
        }
        i=classe[1]-48+((classe[0]-48)*10);//calcolo della classe
    }while((ris!=0) || (i>14));//eseguo il ciclo do-while finche' la variabile ris e' diversa da 0 o la variabile i e' maggiore di 14
    
    scheda.classe=i;//assegno alla variabile scheda.classe la classe del visitatore
    
    do{
    	do{
    		printf("\n\nInserisci Massimo 25 Caratteri.\n");//output del messaggio
		    printf("\nInserire l' Email del Visitatore %s %s : ",scheda.nome,scheda.cognome);//output del messaggio
		    fflush(stdin);
		    gets(scheda.email);//input di scheda.email
		}while((strlen(scheda.email)>25) || (strlen(scheda.email)<1));//controllo della lunghezza di scheda.email
    	
    	ris=controllo_email(scheda.email,n,elenco);//richiamo la funzione controllo_email
    	
	}while(ris==0);//eseguo il ciclo do-while finche' la variabile ris e' uguale a 0
	
    do{
	    do{
		    printf("\n\nInserisci il Codice del Visitatore %s %s (1-1000) : ",scheda.nome,scheda.cognome);//output del messaggio
		    scanf("%d",&scheda.codice);//input di scheda.codice
	    }while((scheda.codice<1) || (scheda.codice>1000));//controllo dell'input di scheda.codice
	    
	    ris=controllo_codice(scheda.codice,n,elenco);//richiamo la funzione controllo_codice 
	    
		if(ris!=-1){//se la variabile ris e' diversa da -1
            //allora
            printf("\nIl Codice Inserito E' gia' Stato Associato ad un altro Visitatore.\n");//output del messaggio
        }
    }while(ris!=-1);//eseguo il ciclo do-while finche' la variabile ris e' diversa da -1
    
	return scheda;//restituisco la struct scheda
}

int controllo_nome(char nome[],char cognome[],int n,visitatore elenco[]){
	
	int i;//dichiaro la variabile i
	
	for(i=0;i<n;i++){//leggo tutti i visitatori
		if((strcmp(nome,elenco[i].nome)==0) && (strcmp(cognome,elenco[i].cognome)==0)){
		//se la stringa nome e' uguale al nome di un visitatore inserito e se la stringa cognome e' uguale al cognome di un visitatore inserito
		    //allora
			return i;//restituisco la variabile i
		}
	}

	return -1;//restituisco il valore -1
}

int controllo_email(char email[],int n,visitatore elenco[]){
	
	int i;//dichiaro la variabile i
	int i2;//dichiaro la variabile i2
	int k;//dichiaro la variabile k
	
	i2=0;//inizializzo la variabile i2 assegnandogli il valore 0
	
	for(i=0;i<strlen(email);i++){//leggo i caratteri della stringa email
	    if(((email[i]<97) || (email[i]>122)) && ((email[i]<65) || (email[i]>90)) && ((email[i]<48) || (email[i]>57)) && (email[i]!=46)){
			//se il carattere di indice i della stringa email non e' una lettera o un numero
	        //allora
			if(email[i]==64){//se il carattere di indice i della stringa email e' una chiocciola
				//allora
				i2++;//incremento la variabile i2 di un'unita'
			}
			else{//senno'
				printf("\n\nNon Sono Ammissibili Caratteri Diversi da Lettere,Numeri,Chiocciola e Punti.\n");//output del messaggio
				return 0;//restituisco il valore 0
			}		
		}
    }
    
    
    for(i=0;i<n;i++){//leggo tutti i visitatori
		if(strcmp(email,elenco[i].email)==0){
		//se la stringa email e' uguale all'email di un contatto inserito
		    //allora
		    printf("\n\nL'Email E' gia' Stata Associata al Visitatore %s %s.\n",elenco[i].nome,elenco[i].cognome);//output del messaggio
			return 0;//restituisco il valore 0
		}
	}

	if((email[0]==64) || (i2!=1)){
	    //se il carattere di indice 0 della stringa email e' una chiocciola o sono presenti piu' di una o nessuna chiocciola all'interno dell'email
	    //allora
	    if(i2!=1){
	    	printf("\n\nSono State Inserite Due o piu' o Nessuna Chiocciola.\n");//output del messaggio
		}
		else{
			printf("\n\nE' Stato Inserito come Carattere Iniziale una Chiocciola.\n");//output del messaggio
		}
		return 0;//restituisco il valore 0
	}
	
	i=1;//inizializzo la variabile i assegnandogli il valore 1

    do{
    	if(email[i]==64){//se il carattere di indice i della stringa email e' una chiocciola
    	    //allora
    		if(email[i+1]==46){//se il carattere di indice i+1 della stringa email e' un punto
    		    //allora
    		    printf("\n\nE' Stato Inserito un Punto subito Dopo la Chiocciola.\n");//output del messaggio
    			return 0;//restituisco il valore 0
			}
    		for(i2=i+2;i2<strlen(email);i2++){
    			if(email[i2]==46){//se il carattere di indice i2 della stringa email e' un punto
    			    //allora
    				if(strlen(email)<i2+3){//se la lunghezza della stringa email e' minore della variabile i2 sommata a 3
    				    //allora
    				    printf("\n\nNon Sono Stati Inseriti Due Caratteri dopo il Punto.\n");//output del messaggio
    					return 0;//restituisco il valore 0
					}else{
						for(k=i2+1;k<strlen(email);k++){
							if(email[k]==46){//se il carattere di indice k della stringa email e' un punto
								//allora
								printf("\n\nE' Stato Inserito piu' di un Punto dopo la Chiocciola.\n");//output del messaggio
								return 0;//restituisco il valore 0
							}
						}
					}
				}
			}
		}
    	i++;//incremento la variabile i di un'unita'
	}while((i<strlen(email)) && (email[i-1]!=64));
	//eseguo il ciclo do-while finche' la variabile i e' minore della lunghezza della stringa email e il carattere di indice i-1 della stringa email e' diverso da 64
	
	return 1;//restituisco il valore 1
}

int controllo_codice(int codice,int n,visitatore elenco[]){
	
	int i;//dichiaro la variabile i
	
	for(i=0;i<n;i++){//leggo tutti i visitatori
		if(codice==elenco[i].codice){//se la variabile codice e' gia' stata associata ad un altro visitatore
		    //allora
			return i;//restituisco la variabile i
		}
	}

	return -1;//restituisco il valore -1	
}

void visitatori_per_citta(int n,visitatore elenco[]){
	
	int i;//dichiaro la variabile i
	int k;//dichiaro la variabile k
	char citta[26];//dichiaro la stringa citta
	
	do{
    	
	    k=0;//inizializzo la variabile k assegnandogli il valore 0
	    
        do{
		    printf("\n\nInserisci Massimo 25 Caratteri.\n");//output del messaggio
		    printf("\nInserire la Citta' di cui si vogliono andare a vedere tutti i Visitatori : ");//output del messaggio
		    fflush(stdin);
		    gets(citta);//input di citta
	    }while((strlen(citta)>25) || (strlen(citta)<1));//controllo della lunghezza di citta
        
        for(i=0;i<strlen(citta);i++){//leggo i caratteri della stringa citta
	        if(((citta[i]<97) || (citta[i]>122)) && ((citta[i]<65) || (citta[i]>90)) && (citta[i]!=32) && (citta[i]!=39)){
				//se il carattere di indice i della stringa citta non e' una lettera,spazio,apostrofo
	            //allora
	            k=1;//assegno alla variabile k il valore 1
            }
        }
    }while(k!=0);//eseguo il ciclo do-while finche' la variabile k e' diversa da 0
	
	k=0;//inizializzo la variabile k assegnandogli il valore 0
	
	for(i=0;i<n;i++){//leggo tutti i visitatori
		if(strcmp(citta,elenco[i].citta)==0){//se la stringa citta e' uguale alla citta di un visitatore inserito
		    //allora
		    if(k==0){//se la variabile k e' uguale al valore 0
	            //allora
                printf("\n\nI Visitatori della Citta' %s sono : ",citta);//output del messaggio
	        }
		    printf(" %s %s ",elenco[i].nome,elenco[i].cognome);//output del messaggio
			k=1;//assegno alla variabile k il valore 1
		}
	}

	if(k==0){//se la variabile k e' uguale al valore 0
	    //allora
        printf("\n\nNon e' Stato Trovato alcun Visitatore per la Citta' %s.\n",citta);//output del messaggio
	}
}

void visitatori_per_provincia(int n,visitatore elenco[]){
	
	int i;//dichiaro la variabile i
	int k;//dichiaro la variabile k
	char provincia[3];//dichiaro la stringa provincia
	
	do{
    	
	    k=0;//inizializzo la variabile k assegnandogli il valore 0
	    
        do{
		    printf("\n\nInserisci 2 Caratteri.\n");//output del messaggio
		    printf("\nInserire la Provincia di cui si vogliono andare a vedere tutti i Visitatori : ");//output del messaggio
		    fflush(stdin);
		    gets(provincia);//input di provincia
	    }while(strlen(provincia)!=2);//controllo della lunghezza di provincia
        
        for(i=0;i<strlen(provincia);i++){//leggo i caratteri della stringa provincia
	        if(((provincia[i]<97) || (provincia[i]>122)) && ((provincia[i]<65) || (provincia[i]>90))){
				//se il carattere di indice i della stringa provincia non e' una lettera
	            //allora
	            k=1;//assegno alla variabile k il valore 1
            }
        }
    }while(k!=0);//eseguo il ciclo do-while finche' la variabile k e' diversa da 0
	
	k=0;//inizializzo la variabile k assegnandogli il valore 0
	
	for(i=0;i<n;i++){//leggo tutti i visitatori
		if(strcmp(provincia,elenco[i].provincia)==0){//se la stringa provincia e' uguale alla provincia di un visitatore inserito
		    //allora
		    if(k==0){//se la variabile k e' uguale al valore 0
	            //allora
                printf("\n\nI Visitatori della Provincia %s sono : ",provincia);//output del messaggio
	        }
		    printf(" %s %s ",elenco[i].nome,elenco[i].cognome);//output del messaggio
			k=1;//assegno alla variabile k il valore 1
		}
	}

	if(k==0){//se la variabile k e' uguale al valore 0
	    //allora
        printf("\n\nNon e' Stato Trovato alcun Visitatore per la Provincia %s.\n",provincia);//output del messaggio
	}
}

void visitatori_per_classe(int n,visitatore elenco[]){
	
	int i;//dichiaro la variabile i
	int k;//dichiaro la variabile k
	char classe[3];//dichiaro la stringa classe
	int classe_;//dichiaro la variabile classe_
	
	do{
    	
	    k=0;//inizializzo la variabile k assegnandogli il valore 0
	    
        do{
		    printf("\n\nInserisci 2 Cifre.\n");//output del messaggio
		    printf("\nInserire la Classe (00-14) di cui si vogliono andare a vedere i Visitatori : ");//output del messaggio
		    fflush(stdin);
		    gets(classe);//input di classe
	    }while(strlen(classe)!=2);//controllo della lunghezza di classe
        
        for(i=0;i<strlen(classe);i++){//leggo i caratteri della stringa classe
	        if((classe[i]<48) || (classe[i]>57)){
				//se il carattere di indice i della stringa classe non e' un numero
	            //allora
	            k=1;//assegno alla variabile k il valore 1
            }
        }
        i=classe[1]-48+((classe[0]-48)*10);//calcolo della classe
    }while((k!=0) || (i>14));//eseguo il ciclo do-while finche' la variabile k e' diversa da 0 o la variabile i e' maggiore di 14
    
    classe_=i;//assegno alla variabile classe_ la classe della quale voglio visualizzare i visitatori
	
	k=0;//inizializzo la variabile k assegnandogli il valore 0
	
	for(i=0;i<n;i++){//leggo tutti i visitatori
		if(classe_==elenco[i].classe){//se la varibile classe_ e' uguale alla classe di un visitatore inserito
		    //allora
		    if(k==0){//se la variabile k e' uguale al valore 0
	            //allora
                printf("\n\nI Visitatori della Classe %d sono : ",classe_);//output del messaggio
	        }
	        printf(" %s %s ",elenco[i].nome,elenco[i].cognome);//output del messaggio
			k=1;//assegno alla variabile k il valore 1
		}
	}

	if(k==0){//se la variabile k e' uguale al valore 0
	    //allora
        printf("\n\nNon e' Stato Trovato alcun Visitatore per la Classe %d.\n",classe_);//output del messaggio
	}
}

int cancellare_un_visitatore(int n,visitatore elenco[]){
	
	int i;//dichiaro la variabile i
	int k;//dichiaro la variabile k
	int codice;//dichiaro la variabile codice
	int flag;//dichiaro la variabile flag
	
	do{
		printf("\nInserisci il Codice del Visitatore che si Vuole Andare a Cancellare (1-1000) : ");//output del messaggio
		scanf("%d",&codice);//input di codice
	}while((codice<1) || (codice>1000));//controllo dell'input di codice
	
	flag=0;//inizializzo la variabile flag assegnandogli il valore 0
	
	i=0;//inizializzo la variabile i assegnandogli il valore 0
	
    do{
		if(codice==elenco[i].codice){//se la variabile codice e' uguale al codice di un contatto inserito
		    //allora
	        printf("\n\nIl Visitatore %s %s e' Stato Cancellato.\n",elenco[i].nome,elenco[i].cognome);//output del messaggio
			for(k=i;k<n;k++){
	            elenco[k]=elenco[k+1];//shift di una struct nell'array di struct
		    }
		    flag=1;//assegno alla variabile flag il valore 1
	    }
	    i++;//incremento la variabile i di un'unita'
    }while((i<n) && (flag==0));//eseguo un ciclo do-while finche' la variabile i e' minore di n e la variabile codice e' diversa da codice della struct elenco di indice i 
    
    if(flag==0){//se la variabile flag e' uguale a 0
        //allora
    	printf("\n\nNon e' Possibile Cancellare il Visitatore dall'Elenco poiche' non Esiste.\n");//output del messaggio
	}
    return flag;//restituisco la variabile flag
}

void modifica(int n,visitatore elenco[]){
	
	int codice;//dichiaro la variabile codice
	int i;//dichiaro la variabile i
	int ris;//dichiaro la variabile ris
	int k;//dichiaro la variabile k
	int scelta;//dichiaro la variabile scelta
	char classe[3];//dichiaro la stringa classe
	visitatore ric;//dichiaro la struct ric
	visitatore scheda;//dichiaro la struct scheda
	
	do{
		printf("\nInserisci il Codice del Visitatore che si Vuole Andare a Modificare (1-1000) : ");//output del messaggio
		scanf("%d",&codice);//input di codice
	}while((codice<1) || (codice>1000));//controllo dell'input di codice
	
	k=controllo_codice(codice,n,elenco);//richiamo la funzione controllo_codice
	
	if(k!=-1){//se la variabile k e' diversa da -1
	    //allora
        do{
        	scelta=menu_();
        	
        	switch(scelta){
        		case 1:
        			
        			 do{
                        printf("\nInserisci Massimo 25 Caratteri.\n");//output del messaggio
                        printf("\n\nModifica il Nome del Visitatore di Codice %d : ",elenco[k].codice);//output del messaggio
                        fflush(stdin);
                        gets(elenco[k].nome);//input di elenco[k].nome
                    }while((strlen(elenco[k].nome)>25) || (strlen(elenco[k].nome)<1));//controllo della lunghezza di elenco[k].nome
        		break;
				
				case 2:

        			do{
         	            printf("\n\nInserisci Massimo 25 Caratteri.\n");//output del messaggio
         	            printf("\n\nModifica il Cognome del Visitatore di Codice %d : ",elenco[k].codice);//output del messaggio
                        fflush(stdin);
                        gets(elenco[k].cognome);//input di elenco[k].cognome
                    }while((strlen(elenco[k].cognome)>25) || (strlen(elenco[k].cognome)<1));//controllo della lunghezza di elenco[k].cognome
        		break;
				
				case 3:
        			
        			do{
	                    ris=0;//inizializzo la variabile ris assegnandogli il valore 0
	    
                        do{
	                    	printf("\n\nInserisci 2 Caratteri.\n");//output del messaggio
                           	printf("\n\nModifica la Provincia del Visitatore di Codice %d : ",elenco[k].codice);//output del messaggio
	                  	    scanf("%s",elenco[k].provincia);//input di elenco[k].provincia
                        }while(strlen(elenco[k].provincia)!=2);//controllo della lunghezza di elenco[k].provincia
        
                        for(i=0;i<strlen(elenco[k].provincia);i++){//leggo tutti i caratteri della stringa elenco[k].provincia
	                        if(((elenco[k].provincia[i]<97) || (elenco[k].provincia[i]>122)) && ((elenco[k].provincia[i]<65) || (elenco[k].provincia[i]>90))){
	                 		//se il carattere di indice i della stringa elenco[k].provincia non e' una lettera
	                 		    //allora
	                            ris=1;//assegno alla variabile ris il valore 1
	                        }
	                    }
                    }while(ris!=0);//eseguo il ciclo do-while finche' la variabile ris e' diversa da 0
        		break;
        		
        		case 4:
        			
        			do{
	                    ris=0;//inizializzo la variabile ris assegnandogli il valore 0
	    
                        do{
	                    	printf("\n\nInserisci Massimo 25 Caratteri.\n");//output del messaggio
	                   	    printf("\n\nModifica la Citta' del Visitatore di Codice %d : ",elenco[k].codice);//output del messaggio
	                 	    fflush(stdin);
	                 	    gets(elenco[k].citta);//input di elenco[k].citta
	                      }while((strlen(elenco[k].citta)>25) || (strlen(elenco[k].citta)<1));//controllo della lunghezza di elenco[k].citta
        
                         for(i=0;i<strlen(elenco[k].citta);i++){//leggo tutti i caratteri della stringa elenco[k].citta
	                    	if(((elenco[k].citta[i]<97) || (elenco[k].citta[i]>122)) && ((elenco[k].citta[i]<65) || (elenco[k].citta[i]>90)) && (elenco[k].citta[i]!=32) && (elenco[k].citta[i]!=39)){
	                        //se il carattere di indice i della stringa elenco[k].citta non e' una lettera,spazio,apostrofo
	                            //allora
	               		        ris=1;//assegno alla variabile ris il valore 1
	            		    }
	                    }
                    }while(ris!=0);//eseguo il ciclo do-while finche' la variabile ris e' diversa da 0
        		break;
        		
        		case 5:
        			strcpy(elenco[k].email,"email");
        			do{
                        do{
    	                 	printf("\n\nInserisci Massimo 25 Caratteri.\n");//output del messaggio
	                        printf("\n\nModifica l' Email del Visitatore di Codice %d : ",elenco[k].codice);//output del messaggio
	                    	fflush(stdin);
	                        gets(ric.email);//input di ric.email
	                 	}while((strlen(ric.email)>25) || (strlen(ric.email)<1));//controllo della lunghezza di ric.email
                    	
                        ris=controllo_email(ric.email,n,elenco);//richiamo la funzione controllo_email
    	
                    }while(ris==0);//eseguo il ciclo do-while finche' la variabile ris e' uguale a 0
                    strcpy(elenco[k].email,ric.email);
        			
        		break;
        		
        		case 6:
        			
	                do{
	                    ris=0;//inizializzo la variabile ris assegnandogli il valore 0
	    
                        do{
	                        printf("\n\nInserisci 2 Cifre.\n");//output del messaggio
	                      	printf("\n\nModifica la Classe del Visitatore di Codice %d : ",elenco[k].codice);//output del messaggio
	                        fflush(stdin);
	                    	gets(classe);//input della stringa classe
	                    }while(strlen(classe)!=2);//controllo della lunghezza della stringa classe

                        for(i=0;i<strlen(classe);i++){//leggo i caratteri della stringa classe
	                        if((classe[i]<48) || (classe[i]>57)){
	                    	//se il carattere di indice i della stringa classe non e' un numero
	                            //allora
	                            ris=1;//assegno alla variabile ris il valore 1
                            }
                        }
                        i=classe[1]-48+((classe[0]-48)*10);//calcolo della classe
                    }while((ris!=0) || (i>14));//eseguo il ciclo do-while finche' la variabile ris e' diversa da 0 o la variabile i e' maggiore di 14
                    
                    elenco[k].classe=i;//assegno alla variabile elenco[k].classe la variabile i
        		break;
        		
        		case 7:
        			elenco[k].codice=-1;
        			
        			do{
	                    do{
		                    printf("\n\nModifica il Codice del Visitatore (1-1000): ");//output del messaggio
		                    scanf("%d",&ric.codice);//input di ric.codice
	                    }while((ric.codice<1) || (ric.codice>1000));//controllo dell'input di ric.codice
	    
	                    ris=controllo_codice(ric.codice,n,elenco);//richiamo la funzione controllo_codice 
	    
		                if(ris!=-1){//se la variabile ris e' diversa da -1
                            //allora
                            printf("\nIl Codice Inserito E' gia' Stato Associato ad un altro Visitatore.\n");//output del messaggio
                        }
                    }while(ris!=-1);//eseguo il ciclo do-while finche' la variabile ris e' diversa da -1
                    elenco[k].codice=ric.codice;
        		break;
        		
        		case 8:
        			printf("\n\nModifica le Informazioni riguardanti il Visitatore %s %s.\n\n",elenco[k].nome,elenco[k].cognome);//output del messaggio
		            elenco[k]=scheda;//assegno ad elenco di indice i la struct scheda
		            elenco[k]=inserimento(n,elenco);//richiamo la funzione inserimento
        		break;
			}
		}while(scelta!=0);//finche' scelta e' diversa da 0 eseguo il ciclo do-while
	}
	else{
		printf("\n\nNon e' Stato Trovato Nessun Visitatore con il Codice %d.",codice);//output del messaggio
	}
}

int menu()
{
	int sc;//dichiaro la variabile sc

	printf("\nProgramma Visitatori\n\n");//output del messaggio
	printf("\n1- Inserisci un Visitatore e le Informazioni che lo riguardano.\n");//output del messaggio
	printf("\n2- Elenco delle Informazioni dei Visitatori per una Determinata Citta',Provincia o Classe Inserita.\n");//output del messaggio
	printf("\n3- Cancella un Visitatore Inserendo il suo Codice.\n");//output del messaggio
	printf("\n4- Modifica le Informazioni riguardanti un Visitatore Precedentemente Inserito.\n");//output del messaggio
	printf("\n0- Fine Programma.\n");//output del messaggio

	do{
		printf("\nInserisci operazione (0-4): ");//output del messaggio
		scanf("%d",&sc);//input di sc
	}while((sc<0) || (sc>4));//controllo dell'input di sc

	return sc;//restituisco la variabile sc
}

int menu_()
{
	int sc;//dichiaro la variabile sc
    printf("\n****************************************************************************************\n");
    
	printf("\nQuale Campo Dati vuoi andare a Modificare del Visitatore?\n");//output del messaggio
	printf("\n1- Per Andare a Modificare il Campo Relativo al Nome.\n");//output del messaggio
	printf("\n2- Per Andare a Modificare il Campo Relativo al Cognome.\n");//output del messaggio
	printf("\n3- Per Andare a Modificare il Campo Relativo alla Provincia.\n");//output del messaggio
	printf("\n4- Per Andare a Modificare il Campo Relativo alla Citta'.\n");//output del messaggio
	printf("\n5- Per Andare a Modificare il Campo Relativo all' Email.\n");//output del messaggio
	printf("\n6- Per Andare a Modificare il Campo Relativo alla Classe.\n");//output del messaggio
	printf("\n7- Per Andare a Modificare il Campo Relativo al Codice.\n");//output del messaggio
	printf("\n8- Per Andare a Reinserire Tutti i Campi Relativi ai Dati.\n");//output del messaggio
	printf("\n0- Torna al Menu' Principale.\n");//output del messaggio

	do{
		printf("\nInserisci operazione (0-8): ");//output del messaggio
		scanf("%d",&sc);//input di sc
	}while((sc<0) || (sc>8));//controllo dell'input di sc
	
    printf("\n****************************************************************************************\n");
    
	return sc;//restituisco la variabile sc
}
