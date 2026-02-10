#include <iostream>
#include<time.h>
#include<cstdlib>
#include<iomanip>
using namespace std;


/*Realizzare il gioco del Memory con le seguenti funzionalità:


Fase preparatoria

il programma genera casualmente la dimensione della matrice quadrata scegliendo un numero tra 4 e 7;
in caso di matrice con numero di elementi dispari inserire lo zero in una posizione casuale;
il programma inserisce nella matrice le coppie di caratteri in modo casuale;
il programma visualizza una matrice di asterischi (tessere coperte);
Gioco
l'utente inserisce le coordinate di due tessere;
il programma scopre le due tessere,  se sono uguali le lascia scoperte, se sono diverse le ricopre dopo 2 secondi;
il gioco finisce quando vengono scoperte tutte le tessere;
a fine gioco il programma segnala il numero di tentativi effettuati dal giocatore;
Effettuare almeno un commit  per ogni funzionalità elencata. */





int main() 
{


  char a; 
  int  i=0; 
    srand(time(NULL));
    i=(rand()%4+4);
    cout<<i<<endl;    //spazzi grandezza tabella
    
    
    
    if(i%2==0)
    {
  		 for(int l=0;l<i;l++)
     		{ cout<<endl;
        		 for (int j=0; j < i; j++)    
        		 {  
         		    a=(rand()%26+65);
             
	    		     if(j%2!=0)  
            		 cout <<setw(1)<< "" << a << "|";
           		  else
            		 cout <<setw(1)<< "|" << a << "";
       		  }
    		 }
     
    }
    else
   {
    	for(int l=0;l<i;l++)           //valore all'ultima riga e lo stesso che i
     		{ cout<<endl;
        		 for (int j=0; j < i; j++)    
        		 {  
         		    a=(rand()%26+65);
                      
                      
	    		     if(j%2!=0)  
            		 cout <<setw(1) << ""<< a << "|";
           		  else
            		 cout << setw(1)  <<"|"<< a << "";
            		 
            	     
       		     }
       		     
    		 }
     
    	
	}
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
