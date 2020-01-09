/*Matteo Spiga 3INB

Programma Rubrica

Vogliamo registrare i dati relativi ad una rubrica telefonica 
considerando che lo spazio disponibile e' di al massimo di 500 caratteri.
Il programma dovrà prevedere attraverso l'utilizzo di una funzione menu:

1- Inserisci i Contatti e le Informazioni che li riguardano.
2- Stampa Nome di un Determinato Contatto Inserendo il suo Numero di Telefono.
3- Stampa Numero di Telefono di un Contatto Inserendo il suo Nome.
4- Cancella un Contatto Inserendo il suo Nome.
5- Elenco Numeri Telefonici per una Determinata Citta' Inserita.
6- Elenco Numeri Telefonici dei Contatti con una Simpatia Minore o Uguale ad un numero preso in input.
0- Fine Programma.*/

struct rubrica{
	char nome[26],numero[15],indirizzo[21],citta[26],cap[6],provincia[3];
	int simpatia;
};

typedef struct rubrica telefono;

telefono inserimento(int n,telefono elenco[]);//dichiarazione della funzione prototipo inserimento
int numero_da_nome(char nome[26],int n,telefono elenco[]);//dichiarazione della funzione prototipo numero_da_nome
int nome_da_numero(char numero[15],int n,telefono elenco[]);//dichiarazione della funzione prototipo nome_da_numero
int cancellare_un_contatto(int n,telefono elenco[]);//dichiarazione della funzione prototipo cancellare_un_contatto
void telefoni_per_citta(int n,telefono elenco[]);//dichiarazione della procedura prototipo telefoni_per_citta
void telefoni_per_simpatia(int n,telefono elenco[]);//dichiarazione della procedura prototipo telefoni_per_simpatia
int menu();//dichiarazione della funzione prototipo menu
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	
	int scelta;//dichiaro la variabile scelta
	int flag;//dichiaro la variabile flag
	int n;//dichiaro la variabile n
	int i;//dichiaro la variabile i
	int k;//dichiaro la variabile k
	telefono elenco[500];//dichiaro l'array di struct elenco
	telefono ric;//dichiaro la struct ric
		
    flag=0;//condizione iniziale del flag, non e' stato effettuato l'input dei dati

	do{

		scelta=menu();

		switch (scelta){

		    case 1:

		    	printf("\n****************************************************************************************\n");

                n=0;//inizializzo la variabile n assegnandogli il valore 0
                
                k=1;//inizializzo la variabile k assegnandogli il valore 1
                
                do{
                    if(n!=0){//se la variabile n e' diversa da 0
                        //allora
                        do{
                    	    printf("\n\nVuoi Continuare ad Inserire i Contatti?\n");//output del messaggio
                    	    printf("\nInserisci 1 per un Si,0 per un No : ");//output del messaggio
                    	    scanf("%d",&k);//input di k
					    }while((k<0) || (k>1));//controllo dell'input di k 	    
				    }
				    
                    if(k==1){//se la variabile k e'uguale a 1
                	    //allora
                        printf("\n\nInserisci le Informazioni riguardanti il Contatto N.%d.\n\n",n+1);//output del messaggio
                
                        elenco[n]=inserimento(n,elenco);//richiamo la funzione inserimento
                        
                        n++;//incremento la variabile n di un'unita'
				    }
                }while((k==1) && (n<500));//eseguo il ciclo do-while finche' la variabile k e' uguale ad 1 e la variabile n e' minore di 500
                
                flag=1;//assegno alla variabile flag il valore 1
             
                printf("\n");//vado a capo

                printf("\n****************************************************************************************\n");
   			break;

            case 2:

				printf("\n****************************************************************************************\n");

				if(flag==1){//se flag e' uguale ad 1 
				    //allora
				    do{
	                    k=0;//inizializzo la variabile k assegnandogli il valore 0
		
                 		do{
                			printf("\nInserisci 14 Numeri.\n");//output del messaggio
               		        printf("\nInserisci il Numero di Telefono del Contatto di cui si vuole andare a conoscere il Nome : ");//output del messaggio
	                        scanf("%s",ric.numero);//input di ric.numero
	                    }while(strlen(ric.numero)!=14);//controllo della lunghezza di ric.numero
	    
                       	for(i=0;i<strlen(ric.numero);i++){//leggo tutti i caratteri della stringa ric.numero
	                        if((ric.numero[i]<48) || (ric.numero[i]>57)){//se il carattere di indice i della stringa ric.numero non e' un numero
	                            //allora
                 	    		k=1;//assegno alla variabile k il valore 1
                  			}
                 		}
                    }while((k!=0));//eseguo il ciclo do-while finche' la variabile k e' diversa da 0
				    
                    i=nome_da_numero(ric.numero,n,elenco);//richiamo la funzione nome_da_numero
                    
                    if(i!=-1){//se la variabile i e' diversa da -1
                        //allora
                    	printf("\n\nIl Nome del Contatto che ha come Numero %s e' : %s",ric.numero,elenco[i].nome);//output del messaggio
					}
					else{//senno'
						printf("\n\nNon e' Stato Trovato Nessun Contatto con il Numero %s.\n",ric.numero);//output del messaggio
					}    
			    }
				else{//senno' stampo il messaggio
				    printf("\nErrore: Nessun Contatto Inserito.\n");//output del messaggio
				}

				printf("\n");//vado a capo

                printf("\n****************************************************************************************\n");
			break;
			
			case 3:

				printf("\n****************************************************************************************\n");

				if(flag==1){//se flag e' uguale ad 1 
				    //allora				    
				    do{
         	            printf("\nInserisci Massimo 25 Caratteri.\n");//output del messaggio
                        printf("\nInserisci il Nome del Contatto di cui si vuole andare a conoscere il Numero : ");//output del messaggio
                        fflush(stdin);
                        gets(ric.nome);//input di ric.nome
                    }while((strlen(ric.nome)>25) || (strlen(ric.nome)<1));//controllo della lunghezza di ric.nome
                    
                    i=numero_da_nome(ric.nome,n,elenco);//richiamo la funzione numero_da_nome
                    
                    if(i!=-1){//se la variabile i e' diversa da -1
                        //allora
                    	printf("\n\nIl Numero del Contatto di Nome %s e' : %s",ric.nome,elenco[i].numero);//output del messaggio
					}
					else{//senno'
						printf("\n\nNon e' Stato Trovato Nessun Contatto con il Nome %s.\n",ric.nome);//output del messaggio
					}
			    }
				else{//senno' stampo il messaggio
				    printf("\nErrore: Nessun Contatto Inserito.\n");//output del messaggio
				}

				printf("\n");//vado a capo

                printf("\n****************************************************************************************\n");
			break;
			
			case 4:

				printf("\n****************************************************************************************\n");

				if(flag==1){//se flag e' uguale ad 1 
				    //allora
                
					i=cancellare_un_contatto(n,elenco);//richiamo la funzione cancellare_un_contatto
					
				    if(i==1){//se la variabile e' uguale ad 1
				        //allora
				  	    n--;//decremento la variabile n di un'unita'
				    }
				    
			    }
				else{//senno' stampo il messaggio
				    printf("\nErrore: Nessun Contatto Inserito.\n");//output del messaggio
				}

				printf("\n");//vado a capo

                printf("\n****************************************************************************************\n");
			break;
			
			case 5:

				printf("\n****************************************************************************************\n");

				if(flag==1){//se flag e' uguale ad 1 
				    //allora
                    telefoni_per_citta(n,elenco);//richiamo la procedura telefoni_per_citta
			    }
				else{//senno' stampo il messaggio
				    printf("\nErrore: Nessun Contatto Inserito.\n");//output del messaggio
				}

				printf("\n");//vado a capo

                printf("\n****************************************************************************************\n");
			break;
			
			case 6:

				printf("\n****************************************************************************************\n");

				if(flag==1){//se flag e' uguale ad 1 
				    //allora
	                telefoni_per_simpatia(n,elenco);//richiamo la procedura telefoni_per_simpatia
			    }
				else{//senno' stampo il messaggio
				    printf("\nErrore: Nessun Contatto Inserito.\n");//output del messaggio
				}

				printf("\n");//vado a capo

                printf("\n****************************************************************************************\n");
			break;
			
		}		
	}while(scelta!=0);//finche' scelta e' diversa da 0 eseguo il ciclo do-while
}

telefono inserimento(int n,telefono elenco[]){
	
	telefono scheda;//dichiaro la struct scheda
	int ris;//dichiaro la variabile ris
	int i;//dichiaro la variabile i
	int k;//dichiaro la variabile k
	
	do{
	    do{
         	printf("\nInserisci Massimo 25 Caratteri.\n");//output del messaggio
            printf("\nInserire il Nome del Contatto : ");//output del messaggio
            fflush(stdin);
            gets(scheda.nome);//input di scheda.nome
        }while((strlen(scheda.nome)>25) || (strlen(scheda.nome)<1));//controllo della lunghezza di scheda.nome
	
        ris=numero_da_nome(scheda.nome,n,elenco);//richiamo la funzione numero_da_nome

        if(ris!=-1){//se la variabile ris e' diversa da 1
            //allora
            printf("\nIl Nome Inserito e' gia' stato associato ad un altro Contatto.\n");//output del messaggio
        }
    }while(ris!=-1);//esegui il ciclo do-while finche' la variabile ris e' diversa da 1
    
	do{
		ris=0;//inizializzo la variabile ris assegnandogli il valore 0
		
		do{
			printf("\nInserisci 14 Numeri.\n");//output del messaggio
		    printf("\nInserisci il Numero di Telefono del Contatto %s :",scheda.nome);//output del messaggio
		    scanf("%s",scheda.numero);//input di scheda.numero
	    }while(strlen(scheda.numero)!=14);//controllo della lunghezza di scheda.numero
	    
	    for(i=0;i<strlen(scheda.numero);i++){//leggo tutti i caratteri della stringa scheda.numero
	    	if((scheda.numero[i]<48) || (scheda.numero[i]>57)){//se il carattere di indice i della stringa scheda.numero non e' un numero
	    	    //allora
	    		ris=1;//assegno alla variabile ris il valore 1
			}
		}
		
		if(ris==0){//se la variabile ris e' uguale a 0
		    //allora
			k=nome_da_numero(scheda.numero,n,elenco);//richiamo la funzione nome_da_numero
		}

		if(k!=-1){//se la variabile k e' diversa da -1
		    //allora
            printf("\nIl Numero Inserito e' gia' stato associato ad un altro Contatto.\n");//output del messaggio
        } 
	}while((ris!=0) || (k!=-1));//eseguo il ciclo do-while finche' la variabile ris e' diversa da 0 o la variabile k e' diversa da -1

    do{
    	
	    ris=0;//inizializzo la variabile ris assegnandogli il valore 0
	    
        do{
		    printf("\nInserisci 2 Caratteri.\n");//output del messaggio
         	printf("\nInserire la Provincia del Contatto %s : ",scheda.nome);//output del messaggio
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
		    printf("\nInserisci Massimo 25 Caratteri.\n");//output del messaggio
		    printf("\nInserire la Citta' del Contatto %s : ",scheda.nome);//output del messaggio
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
		    printf("\nInserisci 5 Numeri.\n");//output del messaggio
		    printf("\nInserire il Cap della Citta' %s : ",scheda.citta);//output del messaggio
		    scanf("%s",scheda.cap);//input di scheda.cap
	    }while(strlen(scheda.cap)!=5);//controllo della lunghezza di scheda.cap
	    
	    for(i=0;i<strlen(scheda.cap);i++){//leggo tutti i caratteri della stringa scheda.cap
	    	if((scheda.cap[i]<48) || (scheda.cap[i]>57)){//se il carattere di indice i della stringa scheda.cap non e' un numero
	    	    //allora
	    		ris=1;//assegno alla variabile ris il valore 1
			}
		}
	}while(ris!=0);//eseguo il ciclo do-while finche' la variabile ris e' diversa da 0
	
	do{
		printf("\nInserisci Massimo 20 Caratteri.\n");//output del messaggio
		printf("\nInserire l' Indirizzo del Contatto %s : ",scheda.nome);//output del messaggio
		fflush(stdin);
		gets(scheda.indirizzo);//input di scheda.indirizzo
	}while((strlen(scheda.indirizzo)>20) || (strlen(scheda.indirizzo)<1));//controllo della lunghezza di scheda.indirizzo
	
	do{
		printf("\nInserisci la Simpatia del Contatto %s (1-10) : ",scheda.nome);//output del messaggio
		scanf("%d",&scheda.simpatia);//input di scheda.simpatia
	}while((scheda.simpatia<1) || (scheda.simpatia>10));//controllo dell'input di scheda.simpatia

	return scheda;//restituisco la struct scheda
}

int numero_da_nome(char nome[26],int n,telefono elenco[]){
	
	int i;//dichiaro la variabile i
	
	for(i=0;i<n;i++){//leggo tutti i contatti
		if(strcmp(nome,elenco[i].nome)==0){//se la stringa nome e' uguale al nome di un contatto inserito
		    //allora
			return i;//restituisco la variabile i
		}
	}

    i=-1;//assegno alla variabile i il valore -1

	return i;//restituisco la variabile i
}

int nome_da_numero(char numero[15],int n,telefono elenco[]){
	
	int i;//dichiaro la variabile i
	
	for(i=0;i<n;i++){//leggo tutti i contatti
		if(strcmp(numero,elenco[i].numero)==0){//se la stringa numero e' uguale al numero di un contatto inserito
		    //allora
			return i;//restituisco la variabile i
		}
	}

    i=-1;//assegno alla variabile i il valore -1

	return i;//restituisco la variabile i
}

int cancellare_un_contatto(int n,telefono elenco[]){
	
	int i;//dichiaro la variabile i
	int k;//dichiaro la variabile k
	char nome[26];//dichiaro la variabile nome
	int flag;//dichiaro la variabile flag
	
	do{
        printf("\nInserisci Massimo 25 Caratteri.\n");//output del messaggio
        printf("\nInserisci il Nome del Contatto che si vuole andare a Cancellare: ");//output del messaggio
        fflush(stdin);
        gets(nome);//input di nome
    }while((strlen(nome)>25) || (strlen(nome)<1));//controllo della lunghezza di nome
	
	flag=0;//inizializzo la variabile flag assegnandogli il valore 0
	
	i=0;//inizializzo la variabile i assegnandogli il valore 0
	
    do{
		if(strcmp(nome,elenco[i].nome)==0){//se la stringa nome e' uguale al nome di un contatto inserito
		    //allora
	        printf("\n\nIl Contatto %s e' Stato Cancellato.\n",nome);//output del messaggio
			for(k=i;k<n;k++){
	            elenco[k]=elenco[k+1];//shift di una struct nell'array di struct
		    }
		    flag=1;//assegno alla variabile flag il valore 1
	    }
	    i++;//incremento la variabile i di un'unita'
    }while((i<n) && (flag==0));//eseguo un ciclo do-while finche' la variabile i e' minore di n e la stringa nome e' diversa dalla stringa nome della struct elenco di indice i 
    
    if(flag==0){//se la variabile flag e' uguale a 0
        //allora
    	printf("\n\nNon e' Possibile Cancellare il Contatto %s poiche' non Esiste.\n",nome);//output del messaggio
	}
    return flag;//restituisco la variabile flag
}

void telefoni_per_citta(int n,telefono elenco[]){
	
	int i;//dichiaro la variabile i
	int k;//dichiaro la variabile k
	char citta[26];//dichiaro la stringa citta
	int v[500];//dichiaro il vettore v
	
	do{
    	
	    k=0;//inizializzo la variabile k assegnandogli il valore 0
	    
        do{
		    printf("\nInserisci Massimo 25 Caratteri.\n");//output del messaggio
		    printf("\nInserire la Citta' di cui si vogliono andare a vedere tutti i Numeri Telefonici : ");//output del messaggio
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
	
	for(i=0;i<n;i++){//leggo tutti i contatti
		if(strcmp(citta,elenco[i].citta)==0){//se la stringa citta e' uguale alla citta di un contatto inserito
		    //allora
		    v[k]=i;//assegno al vettore v di indice k la variabile i
			k++;//incremento k di un'unita'
		}
	}

	if(k==0){//se la variabile k e' uguale al valore 0
	    //allora
        printf("\n\nNon e' Stato Trovato alcun Numero Telefonico per la Citta' %s.\n",citta);//output del messaggio
	}
	else{//senno'
		printf("\n\nI Numeri Telefonici della Citta' %s sono : ",citta);//output del messaggio
		for(i=0;i<k;i++){
			printf(" %s ",elenco[v[i]].numero);//output dei numeri telefonici dei contatti che vivono in una determinata citta'
		}
	}
}

void telefoni_per_simpatia(int n,telefono elenco[]){
	
	int i;//dichiaro la variabile i
	int k;//dichiaro la variabile k
	int simpatia;//dichiaro la variabile simpatia
	int v[500];//dichiaro il vettore v
	
	do{
		printf("\nInserisci la Simpatia Minore Uguale per cui andro' a Stampare i Numeri Telefonici dei Contatti  (1-10) : ");//output del messaggio
		scanf("%d",&simpatia);//input di simpatia
	}while((simpatia<1) || (simpatia>10));//controllo dell'input di simpatia
	
	k=0;//inizializzo la variabile k assegnandogli il valore 0
	
	for(i=0;i<n;i++){//leggo tutti i contatti
		if(elenco[i].simpatia<=simpatia){//se la variabile simpatia della struct elenco di indice i e' minore o uguale alla variabile simpatia
			//allora
		    v[k]=i;//assegno al vettore v di indice k la variabile i
			k++;//incremento k di un'unita'	
		}
	}
	
    if(k==0){//se la variabile k e' uguale al valore 0
        //allora
        printf("\n\nNon e' Stato Trovato alcun Numero Telefonico per Simpatia Minore o Uguale a %d.\n",simpatia);//output del messaggio
	}
	else{//senno'
		printf("\n\nI Numeri Telefonici dei Contatti con una Simpatia Minore Uguale ad %d sono : ",simpatia);//output del messaggio
		for(i=0;i<k;i++){
		    printf(" %s ",elenco[v[i]].numero);//output dei numeri telefonici dei contatti che hanno una simpatia minore o uguale ad una simpatia presa in input
		}
	}
}

int menu()
{
	int sc;//dichiaro la variabile sc

	printf("\nProgramma Rubrica\n\n");//output del messaggio
	printf("\n1- Inserisci i Contatti e le Informazioni che li riguardano.\n");//output del messaggio
	printf("\n2- Stampa Nome di un Determinato Contatto Inserendo il suo Numero di Telefono.\n");//output del messaggio
	printf("\n3- Stampa Numero di Telefono di un Contatto Inserendo il suo Nome.\n");//output del messaggio
	printf("\n4- Cancella un Contatto Inserendo il suo Nome.\n");//output del messaggio
	printf("\n5- Elenco Numeri Telefonici per una Determinata Citta' Inserita.\n");//output del messaggio
	printf("\n6- Elenco Numeri Telefonici dei Contatti con una Simpatia Minore o Uguale ad un numero preso in input.\n");//output del messaggio
	printf("\n0- Fine Programma.\n");//output del messaggio

	do{
		printf("\nInserisci operazione (0-6): ");//output del messaggio
		scanf("%d",&sc);//input di sc
	}while((sc<0) || (sc>6));//controllo dell'input di sc

	return sc;//restituisco la variabile sc
}
