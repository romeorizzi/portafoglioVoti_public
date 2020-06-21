/**
* user:  VR440462
* fname: GOBBI
* lname: FRANCESCO
* task:  is_shuffle_of
* score: 0.0
* date:  2019-06-25 11:40:11.238295
*/

#include <iostream>
#include <fstream>
using namespace std;


ifstream input("input1.txt");
ofstream output("output.txt");

int X[1000];
int Y[1000];

int XY[1000];
int s[2000]; //per la soluzione


int main(){
    
int m,n,t;
input >> m >> n >> t;
for(int i=0; i<m; i++) {

    input >> X[i];
    }

for(int i=0; i<n; i++) {
    input >> Y[i];
    }

//contatori per le soluzioni locali
int countm = 0;
int countn = 0;

//variabile per la correttezza del controllo sulle carte mescolate
bool correct = true;

//faccio lo shuffle
for(int i=0; i<m+n; i++) {//guardo tutte le m+n carte prese!
    int val;
    input >> val; //prendo un valore dal file
    if(countm < m && val == X[countm]){
        s[i]= 0;
        countm++;      
     }
    else if(countn<n && val==Y[countn]) {
        s[i]=0;
        countn++;
    }
    else correct = false; //quindi ho soluzione falsa
   }//end for

    output<<correct<<endl;

if(t==1 && correct) {
    for(int i=0; i<n+m; i++) {
    output<<s[i]<<" "; 
    }
output<<endl;
}//fine if


}//fine main
