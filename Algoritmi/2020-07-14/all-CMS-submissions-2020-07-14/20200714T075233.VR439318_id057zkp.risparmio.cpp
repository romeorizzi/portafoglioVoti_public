/**
* user:  VR439318_id057zkp
* fname: GIANLUCA
* lname: PAVAN
* task:  risparmio
* score: 23.0
* date:  2020-07-14 07:52:33.101245
*/
#include <cassert>
#include <cstdio>
#include <iostream>

using namespace std;

#define MAXN 100000
#define MAXM 200000

int N,M;
int luci[MAXN];

int f2(int min, int max){
    for(int i = min; i<=max; i++){

    }

}




int main(){

    assert( freopen("input.txt", "r", stdin) );
    
    scanf("%d%d",&N,&M);

    for(int i=0; i<M; i++){
        int op = 0;
        scanf("%d",&op);
        if(op == 1){
            int scambio;
            scanf("%d",&scambio);
            luci[scambio] = 1-luci[scambio];
        }
        else
        {
            int min, max;
            scanf("%d%d",&min,&max);
            int counter = 0;
            int primo_acceso = 0;
            for(int i = min; i<=max; i++){
                if(luci[i]==1&&primo_acceso==0){
                    counter++;
                    primo_acceso = 1;
                }
                else if(luci[i]==0)
                {
                    primo_acceso = 0;
                }
            }
            cout << counter << endl;
        }
    }
    




}