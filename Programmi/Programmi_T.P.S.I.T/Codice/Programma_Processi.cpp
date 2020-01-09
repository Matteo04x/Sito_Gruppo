/*Matteo Spiga 3INB

Programma FCFS,SJF,Priorita',Round Robin*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int menu();

void fcfs();
int menu_();

void sjf();
int menu__();

void priorita();
int bubble_sort(int v[][2],int n);
int menu___();

void round_robin();
float rr(int v[],int n,int tempo,int _scelta);
int menu____();


int main()
{
	int scelta;//dichiaro la variabile scelta
	
	do{

		scelta=menu();

		switch (scelta){

		    case 1:

		    	printf("\n****************************************************************************************\n");

                    fcfs();
                
                printf("\n");//vado a capo

                printf("\n****************************************************************************************\n");
   			break;

            case 2:

				printf("\n****************************************************************************************\n");

			    	sjf();

				printf("\n");//vado a capo

                printf("\n****************************************************************************************\n");
			break;
			
			case 3:

				printf("\n****************************************************************************************\n");

			    	priorita();
				
				printf("\n");//vado a capo

                printf("\n****************************************************************************************\n");
			break;
			
			case 4:

				printf("\n****************************************************************************************\n");

                    round_robin();
				
				printf("\n");//vado a capo

                printf("\n****************************************************************************************\n");
			break;
		}		
	}while(scelta!=0);//finche' scelta e' diversa da 0 eseguo il ciclo do-while
}

int menu()
{
	int sc;//dichiaro la variabile sc

	printf("\nProgramma Processi\n\n");//output del messaggio
	printf("\n1- Programma FCFS.\n");//output del messaggio
	printf("\n2- Programma SJF.\n");//output del messaggio
	printf("\n3- Programma Priorita'.\n");//output del messaggio
	printf("\n4- Programma Round Robin.\n");//output del messaggio
	printf("\n0- Fine Programma.\n");//output del messaggio

	do{
		printf("\nInserisci operazione (0-4): ");//output del messaggio
		scanf("%d",&sc);//input di sc
	}while((sc<0) || (sc>4));//controllo dell'input di sc

	return sc;//restituisco la variabile sc
}



void fcfs(){
	
	int scelta;//dichiaro la variabile scelta
    int v[25];//dichiaro il vettore v
    int i;//dichiaro la variabile i
    int i2;//dichiaro la variabile i2
    int somma;//dichiaro la variabile somma
    int n;//dichiaro la variabile n
    float media;//dichiaro la variabile media
    int flag;//dichiaro la variabile flag

    flag=0;//inizializzo la variabile flag assegnandogli il valore 0
	
	do{
		
	    scelta=menu_();
	    
	    switch(scelta){
	    	
	    	case 1:
	    		
	    		printf("\n****************************************************************************************\n");
	    		
	            do{
    	            printf("\nInserisci il Numero di Processi (1-25) : ");//output del messaggio
                    scanf("%d",&n);//input di n
                }while((n<1) || (n>25));//controllo dell'input di n

                for(i=0;i<n;i++){//lettura vettore v
                    do{
                    	printf("\nInserisci la Durata del Processo N.%d : ",i+1);//output del messaggio
                   		scanf("%d",&v[i]);//input del vettore v di indice i
                	}while(v[i]<0);//controllo dell'input del vettore v di indice i
                }
                
                flag=1;//assegno alla variabile flag il valore 1
                
	            printf("\n");//vado a capo
			    
			    printf("\n****************************************************************************************\n");
            break;
            
            case 2:
	    		
	    		printf("\n****************************************************************************************\n");
	    		
	            if(flag==1){//se flag e' uguale ad 1
	            	//allora
	            	somma=v[0];//assegno a somma il vettore v di indice 0
	
               	    for(i=1;i<n-1;i++){
               		    i2=i+1;//assegno alla variabile i2 la variabile i incrementata di 1
                	    do{
	               	        somma=somma+v[i2-1];//assegno a somma la somma tra essa stessa e il vettore v di indice i2-1
	               	        i2--;//decremento la variabile i2 di un'unita'
              	        }while(i2!=0);
	                }
	
                    media=1.0*somma/n;//calcolo della media
                
                    printf("\n\nIl Tempo Medio di Attesa per ogni Processo e' di : %.2f.\n",media);//output del messaggio
				}
				else{
					printf("\nErrore : Non e' Stata Inserita Nessuna Sequenza di Processi.\n");//output del messaggio
				}
                
	            printf("\n");//vado a capo
			    
			    printf("\n****************************************************************************************\n");
            break;
            
            case 3:
	    		
	    		printf("\n****************************************************************************************\n");
	    		
	            if(flag==1){//se flag e' uguale ad 1
	            	//allora
	            	somma=v[0];//assegno a somma il vettore v di indice 0
	
               	    for(i=1;i<n-1;i++){
               		    i2=i+1;//assegno alla variabile i2 la variabile i incrementata di 1
                	    do{
	               	        somma=somma+v[i2-1];//assegno a somma la somma tra essa stessa e il vettore v di indice i2-1
	               	        i2--;//decremento la variabile i2 di un'unita'
              	        }while(i2!=0);
	                }
	                
	                for(i=0;i<n;i++){//leggot tutta la sequenza di 
	                	somma+=v[i];//assegno a somma la somma tra essa stessa e il vettore v di indice i
					}
	                
                    media=1.0*somma/n;//calcolo della media
                
                    printf("\n\nIl Tempo Medio di Completamento per ogni Processo e' di : %.2f.\n",media);//output del messaggio
				}
				else{
					printf("\nErrore : Non e' Stata Inserita Nessuna Sequenza di Processi.\n");//output del messaggio
				}
                
	            printf("\n");//vado a capo
			    
			    printf("\n****************************************************************************************\n");
            break;
	    }
    }while(scelta!=0);
}       


int menu_()
{
	int sc;//dichiaro la variabile sc

	printf("\nProgramma FCFS\n");//output del messaggio
	printf("\n1- Inserisci la Sequenza di Processi.\n");//output del messaggio
	printf("\n2- Stampa Tempo Medio di Attesa.\n");//output del messaggio
	printf("\n3- Stampa Tempo Medio di Completamento.\n");//output del messaggio
	printf("\n0- Torna al Menu' Principale.\n");//output del messaggio

	do{
		printf("\nInserisci operazione (0-3): ");//output del messaggio
		scanf("%d",&sc);//input di sc
	}while((sc<0) || (sc>3));//controllo dell'input di sc

	return sc;	
}



void sjf(){
	
	int scelta;//dichiaro la variabile scelta
    int v[25];//dichiaro il vettore v
    int i;//dichiaro la variabile i
    int i2;//dichiaro la variabile i2
    int somma;//dichiaro la variabile somma
    int n;//dichiaro la variabile n
    float media;//dichiaro la variabile media
    int swap;//dichiaro la variabile swap
    int scambi;//dichiaro la variabile scambi
    int flag;

    flag=0;//inizializzo la variabile flag assegnandogli il valore 0
	
	do{
		
	    scelta=menu__();
	    
	    switch(scelta){
	    	
	    	case 1:
	    		
	    		printf("\n****************************************************************************************\n");
	    		
	            do{
    	            printf("\nInserisci il Numero di Processi (1-25) : ");//output del messaggio
                    scanf("%d",&n);//input di n
                }while((n<1) || (n>25));//controllo dell'input di n

                for(i=0;i<n;i++){//lettura vettore v
                    do{
                    	printf("\nInserisci la Durata del Processo N.%d : ",i+1);//output del messaggio
                   		scanf("%d",&v[i]);//input del vettore v di indice i
                	}while(v[i]<0);//controllo dell'input del vettore v di indice i
                }
                
                flag=1;//assegno alla variabile flag il valore 1
                
	            printf("\n");//vado a capo
			    
			    printf("\n****************************************************************************************\n");
            break;
            
            case 2:
	    		
	    		printf("\n****************************************************************************************\n");
	    		
	            if(flag==1){//se flag e' uguale ad 1
	            	//allora
	            	i2=0;//inizializzo i2 assegnandogli il valore 0
	            
	                do{//algoritmo bubble-sort
	                    scambi=0;
	                    for(i=0;i<n-1-i2;i++){
	                        if(v[i]>v[i+1]){
	                           	swap=v[i];
	                            v[i]=v[i+1];
	                           	v[i+1]=swap;
	                           	scambi++;
			                }
		             	}
			            i2++;
		            }while(scambi!=0);
	
                    somma=v[0];//assegno a somma il vettore v di indice 0
	
                    for(i=1;i<n-1;i++){
                        i2=i+1;//assegno alla variabile i2 la variabile i incrementata di 1
                        do{
	                        somma=somma+v[i2-1];//assegno a somma la somma tra essa stessa e il vettore v di indice i2-1
	                        i2--;//decremento la variabile i2 di un'unita'
              	        }while(i2!=0);
	                }
	
                    media=1.0*somma/n;//calcolo della media
                
                    printf("\n\nIl Tempo Medio di Attesa per ogni Processo e' di : %.2f.\n",media);//output del messaggio
				}
				else{
					printf("\nErrore : Non e' Stata Inserita Nessuna Sequenza di Processi.\n");//output del messaggio
				}
                
	            printf("\n");//vado a capo
			    
			    printf("\n****************************************************************************************\n");
            break;
            
            case 3:
	    		
	    		printf("\n****************************************************************************************\n");
	    		
	            if(flag==1){//se flag e' uguale ad 1
	            	//allora
	            	i2=0;//inizializzo i2 assegnandogli il valore 0
	            
	                do{//algoritmo bubble-sort
	            	    scambi=0;
	                    for(i=0;i<n-1-i2;i++){
	                        if(v[i]>v[i+1]){
	                           	swap=v[i];
	                           	v[i]=v[i+1];
	                           	v[i+1]=swap;
	                            scambi++;
		                 	}
		                }
		                i2++;
		            }while(scambi!=0);
	
                    somma=v[0];//assegno a somma il vettore v di indice 0
	
                    for(i=1;i<n-1;i++){
                        i2=i+1;//assegno alla variabile i2 la variabile i incrementata di 1
                        do{
	                        somma=somma+v[i2-1];//assegno a somma la somma tra essa stessa e il vettore v di indice i2-1
	                        i2--;//decremento la variabile i2 di un'unita'
              	        }while(i2!=0);
	                }
                
	                for(i=0;i<n;i++){//leggot tutta la sequenza di 
	                	somma+=v[i];//assegno a somma la somma tra essa stessa e il vettore v di indice i
					}
	                
                    media=1.0*somma/n;//calcolo della media
                
                    printf("\n\nIl Tempo Medio di Completamento per ogni Processo e' di : %.2f.\n",media);//output del messaggio
				}
				else{
					printf("\nErrore : Non e' Stata Inserita Nessuna Sequenza di Processi.\n");//output del messaggio
				}
                
	            printf("\n");//vado a capo
			    
			    printf("\n****************************************************************************************\n");
            break;
	    }
    }while(scelta!=0);
}       

int menu__()
{
	int sc;//dichiaro la variabile sc

	printf("\nProgramma SJF\n");//output del messaggio
	printf("\n1- Inserisci la Sequenza di Processi.\n");//output del messaggio
	printf("\n2- Stampa Tempo Medio di Attesa.\n");//output del messaggio
	printf("\n3- Stampa Tempo Medio di Completamento.\n");//output del messaggio
    printf("\n0- Torna al Menu' Principale.\n");//output del messaggio

	do{
		printf("\nInserisci operazione (0-3): ");//output del messaggio
		scanf("%d",&sc);//input di sc
	}while((sc<0) || (sc>3));//controllo dell'input di sc

	return sc;	
}



void priorita(){
	
	int scelta;//dichiaro la variabile scelta
    int v[25][2];//dichiaro il vettore v
    int i;//dichiaro la variabile i
    int somma;//dichiaro la variabile somma
    int n;//dichiaro la variabile n
    float media;//dichiaro la variabile media
    int flag;//dichiaro la variabile flag

    flag=0;//inizializzo la variabile flag assegnandogli il valore 0
	
	do{
		
	    scelta=menu___();
	    
	    switch(scelta){
	    	
	    	case 1:
	    		
	    		printf("\n****************************************************************************************\n");
	    		
	            do{
    	            printf("\nInserisci il Numero di Processi (1-25) : ");//output del messaggio
                    scanf("%d",&n);//input di n
                }while((n<1) || (n>25));//controllo dell'input di n

                for(i=0;i<n;i++){//lettura matrice v
                    do{
                    	printf("\nInserisci la Durata del Processo N.%d : ",i+1);//output del messaggio
                   		scanf("%d",&v[i][0]);//input della matrive v di riga i colonna 0
                	}while(v[i][0]<0);//controllo dell'input della matrice v di riga i colonna 0
                	    
                	do{
                    	printf("\nInserisci la Priorita' del Processo N.%d (1-5) : ",i+1);//output del messaggio
                   		scanf("%d",&v[i][1]);//input della matrice v di riga i colonna 1
                	}while((v[i][1]<0) || (v[i][1]>5));//controllo dell'input della matrice v di riga i colonna 1
				}
                
                flag=1;//assegno alla variabile flag il valore 1
                
	            printf("\n");//vado a capo
			    
			    printf("\n****************************************************************************************\n");
            break;
            
            case 2:
	    		
	    		printf("\n****************************************************************************************\n");
	    		
	            if(flag==1){//se flag e' uguale ad 1
	            	//allora
	            	somma=bubble_sort(v,n);
	
                    media=1.0*somma/n;//calcolo della media
                
                    printf("\n\nIl Tempo Medio di Attesa per ogni Processo e' di : %.2f.\n",media);//output del messaggio
				}
				else{
					printf("\nErrore : Non e' Stata Inserita Nessuna Sequenza di Processi.\n");//output del messaggio
				}
                
	            printf("\n");//vado a capo
			    
			    printf("\n****************************************************************************************\n");
            break;
            
            case 3:
	    		
	    		printf("\n****************************************************************************************\n");
	    		
	            if(flag==1){//se flag e' uguale ad 1
	            	//allora
	            	
	            	somma=bubble_sort(v,n);
	                
	                for(i=0;i<n;i++){//leggo tutta la sequenza di 
	                	somma+=v[i][0];//assegno a somma la somma tra essa stessa e il vettore v di indice i
					}
	                
                    media=1.0*somma/n;//calcolo della media
                
                    printf("\n\nIl Tempo Medio di Completamento per ogni Processo e' di : %.2f.\n",media);//output del messaggio
				}
				else{
					printf("\nErrore : Non e' Stata Inserita Nessuna Sequenza di Processi.\n");//output del messaggio
				}
                
	            printf("\n");//vado a capo
			    
			    printf("\n****************************************************************************************\n");
            break;
	    }
    }while(scelta!=0);
}       

int bubble_sort(int v[][2],int n){
	
    int i;//dichiaro la variabile i
    int i2;//dichiaro la variabile i2
    int somma;//dichiaro la variabile somma
    int swap;//dichiaro la variabile swap
    int scambi;//dichiaro la variabile scambi

	i2=0;//inizializzo i2 assegnandogli il valore 0
	            
	do{//algoritmo bubble-sort
	    scambi=0;
	    for(i=0;i<n-1-i2;i++){
	        if(v[i][1]<v[i+1][1]){
	            swap=v[i][1];
	            v[i][1]=v[i+1][1];
	            v[i+1][1]=swap;

	            swap=v[i][0];
	            v[i][0]=v[i+1][0];
	            v[i+1][0]=swap;
	            scambi++;
				}
			}
		i2++;
	}while(scambi!=0);

    somma=v[0][0];//assegno a somma il vettore v di indice 0
	
    for(i=1;i<n-1;i++){
        i2=i+1;//assegno alla variabile i2 la variabile i incrementata di 1
        do{
	        somma=somma+v[i2-1][0];//assegno a somma la somma tra essa stessa e il vettore v di indice i2-1
	        i2--;//decremento la variabile i2 di un'unita'
        }while(i2!=0);
	}
	return somma;
}


int menu___()
{
	int sc;//dichiaro la variabile sc

	printf("\nProgramma Priorita'\n");//output del messaggio
	printf("\n1- Inserisci la Sequenza di Processi.\n");//output del messaggio
	printf("\n2- Stampa Tempo Medio di Attesa.\n");//output del messaggio
	printf("\n3- Stampa Tempo Medio di Completamento.\n");//output del messaggio
	printf("\n0- Torna al Menu' Principale.\n");//output del messaggio

	do{
		printf("\nInserisci operazione (0-3): ");//output del messaggio
		scanf("%d",&sc);//input di sc
	}while((sc<0) || (sc>3));//controllo dell'input di sc

	return sc;	
}


void round_robin(){
	
	int scelta;//dichiaro la variabile scelta
	int flag;//dichiaro la variabile flag
    int v[25];//dichiaro la matrice v
    int i;//dichiaro la variabile i
    int n;//dichiaro la variabile n
    float media;//dichiaro la variabile media
    int tempo;//dichiaro la variabile tempo
    int _scelta;

    flag=0;//inizializzo la variabile flag assegnandogli il valore 0
	
	do{
		
	    scelta=menu____();
	    
	    switch(scelta){
	    	
	    	case 1:
	    		
	    		printf("\n****************************************************************************************\n");
	    		
				do{
	    			printf("\nInserisci la Quantita' di Tempo che andro' a dedicare ad ogni processo (>1) : ");
	    			scanf("%d",&tempo);
				}while(tempo<1);
				
	            do{
    	            printf("\nInserisci il Numero di Processi (1-25) : ");//output del messaggio
                    scanf("%d",&n);//input di n
                }while((n<1) || (n>25));//controllo dell'input di n

                for(i=0;i<n;i++){//lettura matrice v
                    do{
                    	printf("\nInserisci la Durata del Processo N.%d : ",i+1);//output del messaggio
                   		scanf("%d",&v[i]);//input della matrive v di riga i colonna 0
                	}while(v[i]<0);//controllo dell'input della matrice v di riga i colonna 0
				}
                
                flag=1;//assegno alla variabile flag il valore 1
                
	            printf("\n");//vado a capo
			    
			    printf("\n****************************************************************************************\n");
            break;
            
            case 2:
	    		
	    		printf("\n****************************************************************************************\n");
	    		
	            if(flag==1){//se flag e' uguale ad 1
	            	//allora
	            	_scelta=2;
	            	media=rr(v,n,tempo,_scelta);
                
                    printf("\n\nIl Tempo Medio di Attesa per ogni Processo e' di : %.2f.\n",media);//output del messaggio
				}
				else{
					printf("\nErrore : Non e' Stata Inserita Nessuna Sequenza di Processi.\n");//output del messaggio
				}
                
	            printf("\n");//vado a capo
			    
			    printf("\n****************************************************************************************\n");
            break;
            
            case 3:
	    		
	    		printf("\n****************************************************************************************\n");
	    		
	            if(flag==1){//se flag e' uguale ad 1
	            	//allora
	            	_scelta=3;
	                media=rr(v,n,tempo,_scelta);

                    printf("\n\nIl Tempo Medio di Completamento per ogni Processo e' di : %.2f.\n",media);//output del messaggio
				}
				else{
					printf("\nErrore : Non e' Stata Inserita Nessuna Sequenza di Processi.\n");//output del messaggio
				}
                
	            printf("\n");//vado a capo
			    
			    printf("\n****************************************************************************************\n");
            break;
	    }
    }while(scelta!=0);
}       

float rr(int v[],int n,int tempo,int _scelta){

    int i;//dichiaro la variabile i
    int i2;//dichiaro la variabile i2
    int n2;//dichiaro la variabile n2
    int k;//dichiaro la variabile k
    int k2;//dichiaro la variabile k2
    int flag;//dichiaro la variabile flag
    int somma;//dichiaro la variabile somma
    float media;//dichiaro la variabile media
    int v2[200][3];//dichiaro la matrice v2
    
    for(i=0;i<n;i++){
    	v2[i][0]=v[i];
	}

	i2=0;//inizializzo la variabile i2 assegnandogli il valore 0

	do{
	    flag=0;//inizializzo la variabile flag assegnandogli il valore 0
	    i=0;//inizializzo la variabile i assegnandogli il valore 0
		do{	
	        if((v2[i][0]-tempo>0) && (v2[i][0]!=0)){
	        	//allora
	            v2[i2][1]=tempo;//assegno alla posizione di riga i2 e colonna 1 della matrice v2 la variabile tempo
	            v2[i2][2]=i;//assegno alla posizione di riga i2 e colonna 2 della matrice v2 la variabile i
	            v2[i][0]-=tempo;//assegno alla posizione di riga i e colonna 0 della matrice v2 la sottrazione tra la posizione della matrice e la variabile tempo
			}
			else{//senno'
				v2[i2][1]=v2[i][0];//assegno alla posizione di riga i2 e colonna 1 della matrice v2 la posizione di riga i e colonna 0 della matrice v2
				v2[i][0]=0;//assegno alla posizione di riga i e colonna 0 della matrice v2 il valore 0
				v2[i2][2]=i;//assegno alla posizione di riga i2 e colonna 2 della matrice v2 la variabile i
			}
			i++;//incremento la variabile i di un'unita'
			i2++;//incremento la variabile i2 di un'unita'
		}while(i<n);//eseguo il ciclo do-while finche' la variabile i e' minore di n
					    
		for(i=0;i<n;i++){
			if(v2[i][0]!=0){//se la posizione di riga i e colonna 0 della matrice v2 e' diversa dal valore 0
				//allora
				flag=1;//assegno alla variabile flag il valore 1
			}
		}
	}while(flag==1);//eseguo il ciclo do-while finche' la variabile flag e' uguale ad 1

    n2=i2;//assegno ad n2 la variabile i2

    somma=0;//assegno alla variabile somma il valore 0

	for(k=0;k<n;k++){
	    for(i=0;i<n2;i++){
		    if((v2[i][2]==k) && (v2[i][1]!=0)){
		        k2=i;
			}
        }
        
        for(i=0;i<k2;i++){
            if((v2[i][2]!=k) && (v2[i][1]!=0)){
                somma+=v2[i][1];
			}
		}
	}

	if(_scelta==3){
		for(i=0;i<n;i++){//leggo tutta la sequenza
	        somma+=v[i];//assegno a somma la somma tra essa stessa e il vettore v di indice i
	    }
	}

    media=1.0*somma/n;//calcolo della media
    
    return media;
}

int menu____()
{
	int sc;//dichiaro la variabile sc

	printf("\nProgramma Round Robin\n");//output del messaggio
	printf("\n1- Inserisci la Sequenza di Processi.\n");//output del messaggio
	printf("\n2- Stampa Tempo Medio di Attesa.\n");//output del messaggio
	printf("\n3- Stampa Tempo Medio di Completamento.\n");//output del messaggio
	printf("\n0- Torna al Menu' Principale.\n");//output del messaggio

	do{
		printf("\nInserisci operazione (0-3): ");//output del messaggio
		scanf("%d",&sc);//input di sc
	}while((sc<0) || (sc>3));//controllo dell'input di sc

	return sc;	
}
