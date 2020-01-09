/*Matteo Spiga 3INB

Calcolo del Carattere di controllo Codice_Fiscale*/
int codice_fiscale(char str[16]);
int menu();
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main ()
{
	char str[16];//dichiaro la stringa str
	int flag;//dichiaro la variabile flag
	int i;//dichiaro la variabile i
	int somma;//dichiaro la variabile somma
	int scelta;
	char confronto;
	
	do{
		
	    scelta=menu();
	    
	    switch(scelta){
	    	
	    	case 1:
	    		
	    		printf("\n**************************************************************\n");
	    		
	            do{
	
	                do{
                 		printf("\n\nNumero di Caratteri da Inserire 15.\n");//output del messaggio
               		    printf("\nInserisci il Codice Fiscale : ");//output del messaggio
               		    scanf("%s",str);//input della stringa str
                 	}while(strlen(str)!=15);//controllo della lunghezza della stringa str

                    flag=0;//inizializzo flag assegnandogli il valore 0
    
                    for(i=0;i<15;i++){
                  	    if((i!=6) && (i!=7) && (i!=9) && (i!=10) && (i!=12) && (i!=13) && (i!=14)){//se il carattere e' diverso da un numero
                    	    //allora
                 		    if((str[i]<65) || (str[i]>90)){//se il carattere non e' compreso tra 65 e 90
                  			    //allora
		                 		flag=1;//assegno alla variabile flag il valore 1
	               		    }
	                 	}
	                    else{//senno'
		               	    if((str[i]<48) || (str[i]>57)){//se il carattere non e' compreso tra 48 e 57
		                	    //allora
    	               		    flag=1;//assegno alla variabile flag il valore 1
	           		        }
	                    }
	                }
	                
                }while(flag==1);//eseguo il ciclo do-while finche' la variabile flag e' uguale ad 1
                
                str[15]=codice_fiscale(str);
       	
                str[16]='\0';//assegno a str[16] il carattere '\0'

                printf("\n\nIl Codice Fiscale con il Carattere di Controllo e' : %s\n",str);//output del messaggio
    
                printf("\nIl Carattere di Controllo e' : %c\n",str[15]);//output del messaggio
                
            	printf("\n**************************************************************\n");
            break;
            
            case 2:
            	
            	printf("\n**************************************************************\n");
            	
            	do{
	
	                do{
                 		printf("\n\nNumero di Caratteri da Inserire 16.\n");//output del messaggio
               		    printf("\nInserisci il Codice Fiscale : ");//output del messaggio
               		    scanf("%s",str);//input della stringa str
                 	}while(strlen(str)!=16);//controllo della lunghezza della stringa str

                    flag=0;//inizializzo flag assegnandogli il valore 0
    
                    for(i=0;i<16;i++){
                  	    if((i!=6) && (i!=7) && (i!=9) && (i!=10) && (i!=12) && (i!=13) && (i!=14)){//se il carattere e' diverso da un numero
                    	    //allora
                 		    if((str[i]<65) || (str[i]>90)){//se il carattere non e' compreso tra 65 e 90
                  			    //allora
		                 		flag=1;//assegno alla variabile flag il valore 1
	               		    }
	                 	}
	                    else{//senno'
		               	    if((str[i]<48) || (str[i]>57)){//se il carattere non e' compreso tra 48 e 57
		                	    //allora
    	               		    flag=1;//assegno alla variabile flag il valore 1
	           		        }
	                    }
	                }
                }while(flag==1);//eseguo il ciclo do-while finche' la variabile flag e' uguale ad 1
                
                confronto=codice_fiscale(str);
                
                if(confronto==str[15]){
                	//allora
                	printf("\n\nIl Carattere di Controllo Inserito e' Esatto.\n");
				}
				else{//senno'
					printf("\n\nIl Carattere di Controllo Inserito e' Errato.\n");
					printf("\nIl Carattere di Controllo Esatto e' : %c\n",confronto);
				}
                
				printf("\n**************************************************************\n");
			break;	
	    }
    }while(scelta!=0);
}       

int codice_fiscale(char str[16])
{
    int somma;//dichiaro la variabile somma
    int i;
    somma=0;//inizializzo somma assegnandogli il valore 0
	
	for(i=0;i<15;i++){//lettura della stringa str
		if((i+1)%2==0){//se i e' pari
		    //allora
		    if((i!=6) && (i!=7) && (i!=9) && (i!=10) && (i!=12) && (i!=13) && (i!=14)){//se il carattere e' diverso da un numero
		        //allora
                somma=somma+str[i]-65;//assegno a somma la somma tra essa e il carattere di indice i della stringa str meno il valore 65
		    }
		    else{//senno'
                somma=somma+str[i]-48;//assegno a somma la somma tra essa e il carattere di indice i della stringa str meno il valore 48
	        }
	    }
		else{//senno'
            
			switch(str[i]){
                	case 'A'://se il carattere di indice i della stringa str e' uguale ad 'A'
                		somma=somma+1;//assegno alla variabile somma la somma tra essa e il valore 1
                	break;
                	
                	case 'B'://se il carattere di indice i della stringa str e' uguale ad 'B'
                		
                	break;
                	
                	case 'C'://se il carattere di indice i della stringa str e' uguale ad 'C'
                		somma=somma+5;//assegno alla variabile somma la somma tra essa e il valore 5
                	break;
                	
                	case 'D'://se il carattere di indice i della stringa str e' uguale ad 'D'
                		somma=somma+7;//assegno alla variabile somma la somma tra essa e il valore 7
                	break;
                	
                	case 'E'://se il carattere di indice i della stringa str e' uguale ad 'E'
                		somma=somma+9;//assegno alla variabile somma la somma tra essa e il valore 9
                	break;
                	
                	case 'F'://se il carattere di indice i della stringa str e' uguale ad 'F'
                		somma=somma+13;//assegno alla variabile somma la somma tra essa e il valore 13
                	break;
                	
                	case 'G'://se il carattere di indice i della stringa str e' uguale ad 'G'
                		somma=somma+15;//assegno alla variabile somma la somma tra essa e il valore 15
                	break;
                	
                	case 'H'://se il carattere di indice i della stringa str e' uguale ad 'H'
                		somma=somma+17;//assegno alla variabile somma la somma tra essa e il valore 17
                	break;
                	
                	case 'I'://se il carattere di indice i della stringa str e' uguale ad 'I'
                		somma=somma+19;//assegno alla variabile somma la somma tra essa e il valore 19
                	break;
                	
                	case 'J'://se il carattere di indice i della stringa str e' uguale ad 'J'
                		somma=somma+21;//assegno alla variabile somma la somma tra essa e il valore 21
                	break;
                	
                	case 'K'://se il carattere di indice i della stringa str e' uguale ad 'K'
                		somma=somma+2;//assegno alla variabile somma la somma tra essa e il valore 2
                	break;
                	
                	case 'L'://se il carattere di indice i della stringa str e' uguale ad 'L'
                		somma=somma+4;//assegno alla variabile somma la somma tra essa e il valore 4
                	break;
                	
                	case 'M'://se il carattere di indice i della stringa str e' uguale ad 'M'
                		somma=somma+18;//assegno alla variabile somma la somma tra essa e il valore 18
                	break;
                	
                	case 'N'://se il carattere di indice i della stringa str e' uguale ad 'N'
                		somma=somma+20;//assegno alla variabile somma la somma tra essa e il valore 20
                	break;
                	
                	case 'O'://se il carattere di indice i della stringa str e' uguale ad 'O'
                		somma=somma+11;//assegno alla variabile somma la somma tra essa e il valore 11
                	break;
                	
                	case 'P'://se il carattere di indice i della stringa str e' uguale ad 'P'
                		somma=somma+3;//assegno alla variabile somma la somma tra essa e il valore 3
                	break;
                	
                	case 'Q'://se il carattere di indice i della stringa str e' uguale ad 'Q'
                		somma=somma+6;//assegno alla variabile somma la somma tra essa e il valore 6
                	break;
                	
                	case 'R'://se il carattere di indice i della stringa str e' uguale ad 'R'
                		somma=somma+8;//assegno alla variabile somma la somma tra essa e il valore 8
                	break;
                	
                	case 'S'://se il carattere di indice i della stringa str e' uguale ad 'S'
                		somma=somma+12;//assegno alla variabile somma la somma tra essa e il valore 12
                	break;
                	
                	case 'T'://se il carattere di indice i della stringa str e' uguale ad 'T'
                		somma=somma+14;//assegno alla variabile somma la somma tra essa e il valore 14
                	break;
                	
                	case 'U'://se il carattere di indice i della stringa str e' uguale ad 'U'
                		somma=somma+16;//assegno alla variabile somma la somma tra essa e il valore 16
                	break;
                	
                	case 'V'://se il carattere di indice i della stringa str e' uguale ad 'V'
                		somma=somma+10;//assegno alla variabile somma la somma tra essa e il valore 10
                	break;
                	
                	case 'W'://se il carattere di indice i della stringa str e' uguale ad 'W'
                		somma=somma+22;//assegno alla variabile somma la somma tra essa e il valore 22
                	break;
                	
                	case 'X'://se il carattere di indice i della stringa str e' uguale ad 'X'
                		somma=somma+25;//assegno alla variabile somma la somma tra essa e il valore 25
                	break;
                	
                	case 'Y'://se il carattere di indice i della stringa str e' uguale ad 'Y'
                		somma=somma+24;//assegno alla variabile somma la somma tra essa e il valore 24
                	break;
                	
                	case 'Z'://se il carattere di indice i della stringa str e' uguale ad 'Z'
                		somma=somma+23;//assegno alla variabile somma la somma tra essa e il valore 23
                	break;
                	
                	case '0'://se il carattere di indice i della stringa str e' uguale ad '0'
                		somma=somma+1;//assegno alla variabile somma la somma tra essa e il valore 1
                	break;

		    	    case '1'://se il carattere di indice i della stringa str e' uguale ad '1'
                	
                	break;
                	
                	case '2'://se il carattere di indice i della stringa str e' uguale ad '2'
                		somma=somma+5;//assegno alla variabile somma la somma tra essa e il valore 5
                	break;
                	
                	case '3'://se il carattere di indice i della stringa str e' uguale ad '3'
                		somma=somma+7;//assegno alla variabile somma la somma tra essa e il valore 7
                	break;
                	
                	case '4'://se il carattere di indice i della stringa str e' uguale ad '4'
                		somma=somma+9;//assegno alla variabile somma la somma tra essa e il valore 9
                	break;
                	
                	case '5'://se il carattere di indice i della stringa str e' uguale ad '5'
                		somma=somma+13;//assegno alla variabile somma la somma tra essa e il valore 13
                	break;
                	
                	case '6'://se il carattere di indice i della stringa str e' uguale ad '6'
                		somma=somma+15;//assegno alla variabile somma la somma tra essa e il valore 15
                	break;
                	
                	case '7'://se il carattere di indice i della stringa str e' uguale ad '7'
                		somma=somma+17;//assegno alla variabile somma la somma tra essa e il valore 17
                	break;
                	
                	case '8'://se il carattere di indice i della stringa str e' uguale ad '8'
                		somma=somma+19;//assegno alla variabile somma la somma tra essa e il valore 19
                	break;
                	
                	case '9'://se il carattere di indice i della stringa str e' uguale ad '9'
                		somma=somma+21;//assegno alla variabile somma la somma tra essa e il valore 21
                	break;
	        }
		}	
	} 
	somma=(somma%26)+65;//assegno a str[15] la somma tra il valore 65 e il resto della divisione tra somma e 26
	
	return somma;
}

int menu()
{
	int sc;//dichiaro la variabile sc

	printf("\nCodice Fiscale\n\n");//output del messaggio
	printf("\n1- Calcolo del Bit di Controllo del Codice Fiscale.\n");//output del messaggio
	printf("\n2- Verifica che il Bit di Controllo Inserito sia Esatto.\n");//output del messaggio	
	printf("\n0- Fine Programma.\n");//output del messaggio

	do{
		printf("\nInserisci operazione (0-2): ");//output del messaggio
		scanf("%d",&sc);//input di sc
	}while((sc<0) || (sc>2));//controllo dell'input di sc

	return sc;	
}
