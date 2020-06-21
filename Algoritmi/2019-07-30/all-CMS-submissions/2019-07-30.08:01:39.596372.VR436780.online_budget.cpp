/**
* user:  VR436780
* fname: CAUCCHIOLO
* lname: ANDREA
* task:  online_budget
* score: 100.0
* date:  2019-07-30 08:01:39.596372
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <cstdlib>
#include <cstdio>
#include <queue>

#define MAXB 705
#define MAXX 55
using namespace std;

int * x;
int partial[MAXX][MAXB];
int n;

int ric(int pos, int bi){
    //cout << "testing pos: " << pos << ", bi: " << bi << endl;
    if (partial[pos][bi] != 0) return partial[pos][bi];
    if (pos == n-1) return bi+1;
    for (int i = 0; i<=bi;i++){
        if (partial[pos][i] != 0) continue;
        partial[pos][i] = (partial[pos][i-1]+ric(pos+1, i+x[pos]))%1000000007;
    }
    return partial[pos][bi];

}

int main()
{
    int b0;
    scanf("%i %i", &n, &b0);
    x = new int[n];
    for (int i = 0; i<n;i++){
        scanf("%i", &x[i]);
    }
    //partial[n-1][0] = 1;
    /*for(int i = 0; i<n;i++){
        for (int j = 0; j<10;j++){
            cout << partial[i][j] << " ";
        }
        cout << endl;
    }*/


    int res = ric(0, b0);
/*
    for(int i = 0; i<n;i++){
        for (int j = 0; j<10;j++){
            cout << partial[i][j] << " ";
        }
        cout << endl;
    }
*/
    printf("%i", res);
    return 0;
}
