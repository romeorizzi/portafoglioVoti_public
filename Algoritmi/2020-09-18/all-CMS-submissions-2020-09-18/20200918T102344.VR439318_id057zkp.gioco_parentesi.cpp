/**
* user:  VR439318_id057zkp
* fname: GIANLUCA
* lname: PAVAN
* task:  gioco_parentesi
* score: 4.0
* date:  2020-09-18 10:23:44.236149
*/
#include <assert.h>
#include <stdio.h>
#include <vector>
#include <list>
#include <iterator>
#include <iostream>
#include <fstream>
using namespace std;
const int MAXN = 1000000;
const int MAXM = 1000000;
int N;

int main(){

    cin >> N;
    if((N/2)%2 == 0){
        cout << 1 << endl;
        cout << 0 << " " << N-1;
    }
    else
    {
        cout << 0 << endl;
    }
    


}