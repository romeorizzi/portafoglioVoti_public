/**
* user:  VR464574_id364gis
* fname: LETIZIA
* lname: QUERCI
* task:  hanoi_with_toddler
* score: 30.0
* date:  2021-06-22 10:06:59.438160
*/
#include <iostream>
#include <fstream>
using namespace std;

int conta=0;
int bimbo=0;
bool todler=false;

void mossa(int n, char prima, char temp, char fine, fstream &outFile){

    if(n==1)
    {
        if(todler){
            if(bimbo%2==0) {
                cout << "daddy muove il disco " << n << " dal piolo " << prima << " al piolo " << fine << endl;
                bimbo++;
            }
            else{
                cout << "toddler muove il disco " << n << " dal piolo " << prima << " al piolo " << fine << endl;
                bimbo++;
            }
        }
        else
            conta++;

        return;
    }
    mossa(n-1, prima, fine, temp, outFile);

    if (todler){
        if(bimbo%2==0){
            cout << "daddy il disco " << n << " da " << prima << " a " << fine << endl;
         bimbo++;
        }
        else {
         cout << "toddler muove il disco " << n << " dal piolo " << prima << " al piolo " << fine << endl;
         bimbo++;
        }
    }
    else
        conta++;
    mossa(n-1, temp, prima, fine, outFile);
}


int main(){

    int n, t;
    string posizioni;
    fstream outFile;
    outFile.open("output.txt");

    //cout << "Inserire il tipo di operazione (0 per conta, 1 per le mosse): ";
    cin >> t;
   // cout << "Inserire ilmero di dischi: " ;
    cin >> n;
    //cout << "Inserire posizione finale dei dischi: ";
    for(int i=0;i<n;i++){
        cin >> posizioni[i];
    }
   /* for(int i=0;i<n;i++){
        cout << posizioni[i];

    }*/

    if(t==0){
        mossa(n,'A','C','B', outFile);
        cout << conta;
    }
    else{
        if(t==1){
            todler= true;
            mossa(n,'A','C', posizioni[0], outFile);
        }
    }
    outFile.close();
    return 0;
}