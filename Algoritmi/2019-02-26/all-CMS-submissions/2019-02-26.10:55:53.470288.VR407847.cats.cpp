/**
* user:  VR407847
* fname: ZANDONA
* lname: CHIARA
* task:  cats
* score: 0.0
* date:  2019-02-26 10:55:53.470288
*/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#define maxN 1000

using namespace std;
long long int Nf;
long long int Nm;
int f;
int m;
int femmine[maxN];
int maschi[maxN];
int sub;
int submax;
int matrice[maxN][maxN];
int massimopriga[maxN];
int massimo;
int r;
int c;
int st;


int somma(int a, int b, int max){
    
    cout << "a: " << a << " b: " << b << " ";
    if(a==r-1 || b==c-1){
        max += matrice[a][b];
        cout << "massimo: " << max << "\n";
        return max;
    }
    else{

        
            max+=matrice[a][b];
            cout << max << " ";
            max = somma(a+1,b+1, max);
            cout <<"max: " << max << "\n";
        
        /*if(a==c-3){
            max+=matrice[a][b];
            cout << max << " ";
            max = somma(a+2,b+2, max);
            cout <<"max: " << max << "\n";

        }
         if(a==c-4){
            max+=matrice[a][b];
            cout << max << " ";
            max = somma(a+3,b+3, max);
            cout <<"max: " << max << "\n";

        }*/
        
        
        

        return max;
            
        
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ifstream in;
    in.open("input.txt");
    in >> Nf;
    //cout << "numero femmine Nf" << "\n";
    in >> Nm;
    //cout << "numero maschi" < Nm << "\n";
    for(int i=0;i<Nf; i++){
        in >> femmine[i];
        //cout << femmine[icout << "a: " << a << "" ";
    }
    cout << "\n";
    for(int i=0;i<Nm; i++){
        in >> maschi[i];
        //cout << maschi[i] << " ";
    }
    //cout << "\n";

    if(Nm>Nf){
        r = Nf;
        c = Nm;
        //cout << r << c << "\n";
    }
    else{
        c = Nf;
        r = Nm;
        //cout << r << c << "\n";
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            //cout << "femmine: " << femmine[i] << "\n";
            //cout << "maschi: " << maschi[j]<< "\n"; 
            matrice[i][j]= abs(femmine[i]-maschi[j]);
            //cout << matrice[i][j] << " ";
        }
        //cout << "\n";
    }
    submax = min(Nf, Nm);
    //cout << submax << "\n";

    for(int i=0; i< r; i++){
        massimopriga[i] = matrice[i][0];
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(matrice[i][j]>massimopriga[i]){
                massimopriga[i]=matrice[i][j];
                //cout << massimo[i] << " ";
            }

        }
        //cout << "\n";
    }
    
    //cout << massimopriga[0] << " " << massimopriga[1] << " " << massimopriga[2] << "\n";
    
    massimo = massimopriga[0];
    for(int i=1; i<r; i++){
        if(massimopriga[i]>massimo){
            massimo = massimopriga[i];
        }
    }
    //cout << "massimo: " << massimo << "\n";
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            //cout << "i: " << i << " j: " << j << "\n";
            st = somma(i,j,0);
            
            if(st>massimo){
                massimo = somma(i,j,0);
            }
        }
    }
    
    ofstream out;
    out.open("output.txt");
    out << massimo;
    //cout << massimo;
         
}