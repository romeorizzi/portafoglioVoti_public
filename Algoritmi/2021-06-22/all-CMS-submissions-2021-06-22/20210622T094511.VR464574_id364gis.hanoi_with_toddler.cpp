/**
* user:  VR464574_id364gis
* fname: LETIZIA
* lname: QUERCI
* task:  hanoi_with_toddler
* score: 0.0
* date:  2021-06-22 09:45:11.226831
*/
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>

using namespace std;
ofstream fcout("output.txt");

void torre(int n, char inizio, char supporto, char fine){
    if(n==1){
        fcout << "dady muove il disco " << n << " dal piolo " << inizio << " al piolo " << fine << endl;
        return;
    }

    torre(n-1, inizio, fine, supporto);
    fcout << "todler muove il disco " << n << " dal piolo " << inizio << " al piolo " << fine << endl;
}

int main(){

    int t;
    cin >> t;
    int n;
    cin << n;

    torre (n, 'A', 'C', 'B');

    return 0;
}