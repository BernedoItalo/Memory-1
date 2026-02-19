#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

void stampaCoperta(char **visibile, int n) 
{
    cout << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << visibile[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() 
{
    srand(time(NULL));

     //////////////////////////// 1) dimensione casuale tra 4 e 7
    int n = 4 + rand() % 4;

     //////////////////////////// 2) creazione matrici
    char **mat = new char*[n];
    char **visibile = new char*[n];

    for(int i = 0; i < n; i++) {
        mat[i] = new char[n];
        visibile[i] = new char[n];
    }

    int tot = n * n;

     //////////////////////////// 3) se dispari inserire uno zero
    bool haZero = false;
    if(tot % 2 == 1) haZero = true;

     //////////////////////////// 4) preparazione vettore di coppie
    int coppie = tot / 2;
    char *v = new char[tot];

    int k = 0;

    if(haZero) {
        int posZero = rand() % tot;
        v[posZero] = '0';
        k = 0;
        for(int i = 0; i < tot; i++) {
            if(i == posZero) continue;
            char c = 'A' + (k / 2);
            v[i] = c;
            k++;
        }
    } else {
        for(int i = 0; i < tot; i++) {
            char c = 'A' + (i / 2);
            v[i] = c;
        }
    }

     //////////////////////////// 5) mescolamento
    for(int i = 0; i < tot; i++) {
        int r = rand() % tot;
        char temp = v[i];
        v[i] = v[r];
        v[r] = temp;
    }

     //////////////////////////// 6) riempimento matrice
    k = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            mat[i][j] = v[k++];

    //////////////////////////// 7) creazione della matrice visibile
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            visibile[i][j] = '*';

    int tentativi = 0;
    int scoperte = 0;

    cout << "Benvenuto nel gioco del Memory!" << endl;

     //////////////////////////// 8) ciclo di gioco
    while(scoperte < tot) 
	{

        stampaCoperta(visibile, n);

        int r1, c1, r2, c2;

        cout << "Inserisci riga prima tessera" << endl;
        cin >> r1;
        cout << "Inserisci colonna prima tessera" << endl;
        cin >> c1;
        cout<< "////////////////////////////////////"<<endl;
        cout << "Inserisci riga seconda tessera" << endl;
        cin >> r2;
        
        cout << "Inserisci colonna seconda tessera" << endl;
        cin >> c2;

        // controllo validità
        if(r1 < 0 || r1 >= n || c1 < 0 || c1 >= n ||
           r2 < 0 || r2 >= n || c2 < 0 || c2 >= n ||
           (r1 == r2 && c1 == c2)) {
            cout << "Coordinate non valide" << endl;
            continue;
            
        }

        tentativi++;

     
        
		char t1 = mat[r1][c1];
       
	    char t2 = mat[r2][c2];

        visibile[r1][c1] = t1;
        visibile[r2][c2] = t2;

        stampaCoperta(visibile, n);

        if(t1 == t2) 
		{
        	
            cout << "Coppia trovata" << endl;
            scoperte += 2;
        } else 
			{
        	
        	
            cout << "Non corrispondono, attesa 2 secondi..." << endl;
            this_thread::sleep_for(chrono::seconds(2));
            visibile[r1][c1] = '*';
            visibile[r2][c2] = '*';
      	  }
    }

    cout << "Hai finito  il gioco." << endl;
    cout << "Numero di tentativi effettuati: " << tentativi << endl;

    return 0;
}
