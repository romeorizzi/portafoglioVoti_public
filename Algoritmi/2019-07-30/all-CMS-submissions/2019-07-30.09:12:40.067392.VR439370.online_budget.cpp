/**
* user:  VR439370
* fname: FERRO
* lname: GIACOMO
* task:  online_budget
* score: 0.0
* date:  2019-07-30 09:12:40.067392
*/
/**
 *  Template per soluzione in c++ per il problema online_budget
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <limits.h>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <queue>


using namespace std;


#define MAXB 501
#define MAXX 51

int *num;
int calcolo[MAXX][MAXB];
int n;


int trova(int,int);


int main(){

    int b0;
    scanf("%d %d", &n, &b0);
    num=new int[n];
    for(int i = 0; i < n; i++)
       scanf("%d", &num[i]);
    //print_array(x, n);

    int risp=trova(0,b0);
    printf("%d",risp);
    return 0;
}



int trova(int p,int bi){
    
    if(calcolo[p][bi]!=0){
        return calcolo[p][bi];
    }

    
    
    for(int i=0; i<=bi; i++){
    
        if(calcolo[p][i]!=0){
            continue;    
        }
    
        calcolo[p][i]=(calcolo[p][i-1] + trova(p+1,i+num[p]))%1000000007;
    
    }
    
    return calcolo[p][bi];
}