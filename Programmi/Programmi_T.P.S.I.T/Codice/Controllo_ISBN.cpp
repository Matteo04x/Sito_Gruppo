/*Matteo Spiga 3INB

Calcolo o controllo del Carattere di controllo Codice_ISBN*/
int codice_isbn(char str[14]);
int menu();
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main ()
{
	char str[14];//dichiaro la stringa str
	int flag;//dichiaro la variabile flag
	int i;//dichiaro la variabile i
	int somma;//dichiaro la variabile somma
	int scelta;//dichiaro la variabile confronto
	int work;//dichiaro la variabile work
	char confronto;//dichiaro la variabile confronto
	
	do{
		
	    scelta=menu();
	    
	    switch(scelta){
	    	
	    	case 1:
	    		
	    		printf("\n**************************************************************\n");
	    		
	            do{
	
	                do{
		                printf("\nNumero di Caratteri da Inserire 12\n");//output del messaggio
		                printf("\nInserisci un Codice ISBN : ");//output del messaggio
		                fflush(stdin);
		                scanf("%s",str);//input della stringa str
	                }while(strlen(str)!=12);//controllo della lunghezza della stringa str

                    flag=0;//inizializzo flag assegnandogli il valore 0
    
                    for(i=0;i<strlen(str);i++){//lettura della stringa str
			            if((str[i]<48) || (str[i]>57)){//se il carattere non e' un numero
			                //allora
    			            flag=1;//assegno alla variabile flag il valore 1
			            }
	                }     
                }while(flag==1);//eseguo il ciclo do-while finche' la variabile flag e' uguale ad 1
                
                str[13]=codice_isbn(str);//richiamo la funzione codice_isbn
       	        
       	        if(str[13]==':'){
       	        	str[13]='0';
				}
       	        
                str[14]='\0';//assegno a str[14] il carattere '\0'

                printf("\n\nIl Codice ISBN con il Carattere di Controllo e' : %s%c\n",str,str[13]);//output del messaggio
    
                printf("\nIl Carattere di Controllo e' : %c\n",str[13]);//output del messaggio
            	
				printf("\n**************************************************************\n");
            break;
            
            case 2:
            	
            	printf("\n**************************************************************\n");
            	
            	do{
	
	                do{
                 		printf("\n\nNumero di Caratteri da Inserire 13\n");//output del messaggio
               		    printf("\nInserisci un Codice ISBN : ");//output del messaggio
               		    fflush(stdin);
               		    scanf("%s",str);//input della stringa str
                 	}while(strlen(str)!=13);//controllo della lunghezza della stringa str

                    flag=0;//inizializzo flag assegnandogli il valore 0
    
                    for(i=0;i<strlen(str);i++){//lettura stringa str
			            if((str[i]<48) || (str[i]>57)){//se il carattere non e' un numero
			                //allora
    			            flag=1;//assegno alla variabile flag il valore 1
			            }
	                }
	                
                }while(flag==1);//eseguo il ciclo do-while finche' la variabile flag e' uguale ad 1
                
                work=str[12];//assegno alla variabile work il carattere di indice 12 della stringa str
                
                if(work==':'){
       	        	work='0';
				}
                
                str[12]='\0';//assegno al carattere di indice 12 della stringa str il carattere '\0'
                
                confronto=codice_isbn(str);//richiamo la funzione codice_isbn
                
                if(confronto==':'){
       	        	confronto='0';
				}
                
                if(confronto==work){//se la variabile confronto e' uguale alla variabile work
                	//allora
                	printf("\n\nIl Carattere di Controllo Inserito e' Esatto.\n");//output del messaggio
				}
				else{//senno'
					printf("\n\nIl Carattere di Controllo Inserito e' Errato.\n");//output del messaggio
					printf("\nIl Carattere di Controllo Esatto e' : %c\n",confronto);//output del messaggio
				}
				
				printf("\n**************************************************************\n");
				
			break;	
	    }
    }while(scelta!=0);
}       

int codice_isbn(char str[14])
{
    int somma;//dichiaro la variabile somma
    int i;//dichiaro la variabile i
    
	somma=0;//inizializzo somma assegnandogli il valore 0
	
	for(i=0;i<strlen(str);i++){//lettura della stringa str
		if((i+1)%2==1){//se i e' pari
		    //allora
		   somma=somma+str[i]-48;//assegno a somma la somma tra essa stessa e la sottrazione del carattere di indice i della stringa str e il valore 48 
	    }
		else{//senno'
            somma=somma+(str[i]-48)*3;//assegno a somma la somma tra essa stessa e la moltiplicazione tra il valore 3 e la sottrazione del carattere di indice i della stringa str e il valore 48 
	    }
	}

    somma=somma%10;//assegno a somma il resto della divisione tra somma e il valore 10

    if(somma!=10){//se la variabile somma e' diversa da 10
        //allora
    	somma=58-somma;//assegno a somma la sottrazione tra il valore 58 e la variabile somma
	}
	else{//senno'
		somma=48;//assegno a somma il valore 48
	}

	return somma;//restituisco la variabile somma
}

int menu()
{
	int sc;//dichiaro la variabile sc

	printf("\nCodice ISBN\n\n");//output del messaggio
	printf("\n1- Calcolo del Bit di Controllo del Codice ISBN.\n");//output del messaggio
	printf("\n2- Verifica che il Bit di Controllo Inserito sia Esatto.\n");//output del messaggio	
	printf("\n0- Fine Programma.\n");//output del messaggio

	do{
		printf("\nInserisci operazione (0-2): ");//output del messaggio
		scanf("%d",&sc);//input di sc
	}while((sc<0) || (sc>2));//controllo dell'input di sc

	return sc;//restituisco la variabile sc
}
