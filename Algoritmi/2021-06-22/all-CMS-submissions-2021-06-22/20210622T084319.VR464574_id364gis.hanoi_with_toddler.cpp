/**
* user:  VR464574_id364gis
* fname: LETIZIA
* lname: QUERCI
* task:  hanoi_with_toddler
* score: 0.0
* date:  2021-06-22 08:43:19.120578
*/
#include <iostream>
#include <fstream>
using namespace std;

int conta=0;

void mossa(int n, char prima, char temp, char fine, fstream &outFile){

    if(n==1)
    {
        //outFile << "AAMuovi il disco " << n << " da " << prima << " a " << fine << endl;
        cout << "Muovi il disco " << n << " da " << prima << " a " << fine << endl;
        conta++;
        return;
    }

    mossa(n-1, prima, fine, temp, outFile);
    //outFile << "Muovi il disco " << n << " da " << prima << " a " << fine << endl;
    cout << "Muovi il disco " << n << " da " << prima << " a " << fine << endl;
    conta++;
    mossa(n-1, temp, prima, fine,outFile);


}

//main program
int main(){

    int n, t;

    fstream inFile;
    inFile.open("input.txt");
    fstream outFile;
    outFile.open("output.txt");

    inFile >> t >> n ;
    //cout << "ho letto: " << n << endl;

    //char piolo;
    //bool uguali=true;
    if(t==0){
        /*for(int i=0; i<n; i++){
            inFile >> piolo;
        }*/

        mossa(n,'A','C','B',outFile);

    }


    outFile << conta;

    inFile.close();
    outFile.close();
    return 0;
}