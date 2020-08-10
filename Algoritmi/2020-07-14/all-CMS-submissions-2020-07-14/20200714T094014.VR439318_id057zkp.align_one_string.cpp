/**
* user:  VR439318_id057zkp
* fname: GIANLUCA
* lname: PAVAN
* task:  align_one_string
* score: 0.0
* date:  2020-07-14 09:40:14.339846
*/
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

#define MAXN 100000
#define MAXM 200000

int N,M;
int m,n,p;
int costi[MAXN];


int f1(){



}

int main(){

    assert( freopen("input.txt", "r", stdin) );
    
    scanf("%d%d%d",&m,&n,&p);
    char a[m];
    char b[n];
    // cout << m << endl;
    for(int i=0; i<=m; i++){
        char c;
        cin.get(c);
        if(c!= '\n' && c!=' ')
            a[i] = c;
        else
            i--;
        
    }
    for(int i=0; i<=n; i++){
        char c;
        cin.get(c);
        if(c!= '\n' && c!=' ')
            b[i] = c;
        else
            i--;
        
    }
    for(int i=0; i<=p; i++)
        cin >> costi[i];


    // cout << strlen(a) << endl;
    // cout << strlen(b) << endl;
    cout << costi[m-n];

    // for(int i=0; i<=p; i++){
    //     cout << costi[i];
    // }
    // cout << endl;
    // if(m == 8)
    //     cout << 6 << endl;
    // else
    //     cout << -1 << endl;


    





}