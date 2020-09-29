/**
* user:  VR452297_id439bgm
* fname: ZENO
* lname: MONTOLLI
* task:  align_one_string
* score: 0.0
* date:  2020-07-14 11:52:36.517013
*/
#include <cassert>
#include <cstdio>
#include <iostream>

#define MAXN 131072
#define MAXM 200000
#define MAXP 1000
using namespace std;

int N,M,P;
int cost[MAXP];
string stringa1, stringa2;
int prec[MAXN*2];
int succ[MAXN*2];
int X[MAXN*2];


int best(int n){
    if(n<P){
        return cost[n];
    }else{
        if(n%2==0){
            return best(n/2);
        }else{
            return best((n-1)/2)+ best((n-1/2+1));
        }

    }
}
int prova( int i, int j){   
    int min=100000;
    bool find;
    int nuovo;
    while(j<stringa1.length()){
        if(stringa2[i]==stringa1[j]){
            find=true;
            if(i==stringa2.length()-1){
                nuovo=best(j-i)+best(stringa1.length()-j);
            }else{
                nuovo=prova(i+1,j+1);
                if(nuovo!=-1){
                    nuovo+=best(j-i);
                }
            }
            if(nuovo<min){
                min=nuovo;
            }
        }
        j++;
    }
    if(find==false){
        return -1;
    }
    return min;
}

void best_cost(){// trovo i costi migliori singolarmente
    int mini,pos;
    for(int i=2;i<P;i++){
        mini=cost[i];
        pos=1;
        int j=i;
        while(pos<=j){
            if(mini>cost[j-1]+cost[pos]){
                mini=cost[j-1]+cost[pos];
            }
            pos++;
            j--;
        }
        cost[i]=mini;
    }
}

int main() {
    cin >> N >> M >> P;

    cin >> stringa1;
    cin >> stringa2;
    for(int i=0;i<P;i++){
        cin >> cost[i];
    }
    best_cost();
    cout << prova(0,0) << endl;

    return 0;
}

