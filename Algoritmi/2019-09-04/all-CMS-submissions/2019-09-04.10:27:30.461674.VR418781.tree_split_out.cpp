/**
* user:  VR418781
* fname: BRENTEGANI
* lname: MATTEO
* task:  Prob1_tree_split_out
* score: 36.0
* date:  2019-09-04 10:27:30.461674
*/
#include <iostream>
using namespace std;

const int MAX_VAL = 1000000;

int kids[MAX_VAL];
int num_descendants[MAX_VAL];
int depth[MAX_VAL*2];

int posR, posW;

int node_index = 0;



void print_array1(int n) {
    for (int i= 0; i < n; i++)
        cout << " " << kids[i];

}


int remove_cod1(int root, int d) {
/*
    devo fare una funzione ricorsiva che partendo dalla radice scorre l'albero e somma al padre il numero dei nipoti
    e elimina i figli
*/
    root = node_index;

    if (d % 2 == 0) { //profondità pari teniamo il nodo
        if (kids[root] != 0) {
            int tmp = kids[root];
            //cout << "studio " << kids[root] << endl;
            for (int i=0; i < tmp; i++) {
                kids[root] += remove_cod1(node_index++, d+1);
            }
            
            kids[root] -= tmp;    
        }
    } else {
        //cout << "siamo in un livello dispari" << kids[root] << ">>>> " << root << "||" << node_index << endl;
        for (int i=0; i < kids[root]; i++) {
            remove_cod1(node_index++, d+1);
        }
        int tmp = kids[root];
        kids[root] = -1;
        return tmp;
    }    
    return 0;
}

int remove_cod2(int root, int d) {


    int somma = 0;

    if (d % 2 == 0) {
        //cout << "studio " << num_descendants[root] << endl;
        if (num_descendants[root] == 1) return 1;

        while (num_descendants[root] > 1) {
            num_descendants[root] -= num_descendants[++node_index];
            somma += remove_cod2(node_index, d+1);           
            //cout << "aggiorno somma " << root << " !! " << somma << endl;
        }
    
        num_descendants[root] = somma+1;
    } else {
        //cout << "siamo in un livello dispari " << num_descendants[root] << endl;
        if (num_descendants[root] == 1)  { num_descendants[root] = -1; return 0; }

        while (num_descendants[root] > 1) {
            
            num_descendants[root] -= num_descendants[++node_index];   
            //cout << "sottrazione " << num_descendants[root] << endl;
            somma += remove_cod2(node_index, d+1);           
        }

        num_descendants[root] = -1;
        //cout << somma << endl;
        return somma;
    }
    return 1;
}

void remove_cod3(int root, int n) {
    while (depth[root] > 0 && root < n) {
        if (depth[root] %2 == 0) {
            cout << depth[root] << "PARI DIVIDO " << depth[root]/2 << endl;
            cout << depth[root]/2 << " ";
        } else {
            cout << depth[root] << "DISPARI" << endl;
            depth[root] = -1;
        }
        remove_cod3(root+1, n);
    }
}


int main() {

    int cod, n=1;
    cin >> cod;
    if (cod == 1) { //ogni nodo detiene il numero di nodi figli detenuti
        cin >> kids[0];
        n += kids[0];
        for(int i = 1; i < n; i++) {
           cin >> kids[i];
            if (kids[i] > 0) n+=kids[i];        
        } 

        /*for (int i= 0; i < n; i++) {
                if (kids[i] != -1) 
                    cout << kids[i] << " ";
            }
        */
        cout << 1 << " ";
        if (remove_cod1(0,0) == 0) {
            for (int i= 0; i < n; i++) {
                if (kids[i] != -1) 
                    cout << kids[i] << " ";
            }
        }


    } else {
        if (cod == 2) { //ogni nodo detiene il numero di discendenti (conta anche se stesso come discendente)
            cin >> num_descendants[0];
            n = num_descendants[0];
            for(int i = 1; i < n; i++) {
                cin >> num_descendants[i];       
            }
           
            if (remove_cod2(0,0) == 1) {
                if (num_descendants[0] > 1) num_descendants[0]++;
                cout << 2<< " ";
                for (int i= 0; i < n; i++) {
                    if (num_descendants[i] != -1) 
                        cout << num_descendants[i] << " ";
                }
    
            }         
        
        } else {    //ogni nodo detiene il numero di archi per raggiungere la radice e parla due volte, in chiusura ed in apertura
            n=0;
            cin >> depth[n++];
            cin >> depth[n++];
            int tmp;
            
            while(depth[n-1] > 0) {
                cin >> tmp;
                if (tmp %2 == 0) { depth[n++] =tmp /2;}
                depth[n] = -1;
            }                   
            
            cout << 3<< " ";
            //remove_cod3(1, n);
            for (int i= 0; i < n; i++) {
                cout << depth[i] << " " ;        
            }

        }    
    }


    return 0;
}
