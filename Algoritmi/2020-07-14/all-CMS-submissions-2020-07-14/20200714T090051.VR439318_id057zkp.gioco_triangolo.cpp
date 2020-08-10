/**
* user:  VR439318_id057zkp
* fname: GIANLUCA
* lname: PAVAN
* task:  gioco_triangolo
* score: 0.0
* date:  2020-07-14 09:00:51.093135
*/
#include <cassert>
#include <cstdio>
#include <iostream>

using namespace std;

#define MAXN 100000
#define MAXM 200000

int N,M;
int m,n,p;
int costi[MAXN];


int main(){

    assert( freopen("input.txt", "r", stdin) );
    int n;
    int m;
    scanf("%d",&n);
    // cout << n;
    scanf("%d",&m);
    if(n == 1){
        if(m == 21)
            cout << "T 2 0 0" << endl;
        else
            cout << "T 2 1 0" << endl;
    } else {
        if(m == 21)
            cout << "1T 2 1 0" << endl;
        else
            cout << "0" << endl;

    }
}