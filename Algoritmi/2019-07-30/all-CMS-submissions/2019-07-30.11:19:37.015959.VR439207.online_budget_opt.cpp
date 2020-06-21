/**
* user:  VR439207
* fname: TROTTI
* lname: FRANCESCO
* task:  online_budget_opt
* score: 50.0
* date:  2019-07-30 11:19:37.015959
*/
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <iostream>
using namespace std;

long int n, B0, t;
long int x[100000], q[100000];
long int j[100000];
long int b[100000];
int main(void){
    int i;
    cin >> n >>B0>>t;
    for (i =0; i<n; i++){
        cin>>x[i];
    }
    for (i =0; i<n; i++){
        cin>>q[i];
    }
    j[n-1] = n-1;
    for(int i=n-2;i>=0; i--){
        if(q[i]<q[i+1]){
            q[i]=q[i+1];
            j[i] = j[i+1];
        }
    }
    long int guadagno = 0;
    long int buget = B0;

    for(int i =0; i<n; i++){
        guadagno+=buget*q[i];
        b[j[i]]+=buget;
        buget=x[i];
    }
    if(t == 1){
        cout << guadagno;
    }else if(t==2){
        for(i=0; i<n;i++){
            cout<< b[i] << " ";
        }
    }
}