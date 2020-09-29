/**
* user:  VR452297_id439bgm
* fname: ZENO
* lname: MONTOLLI
* task:  risparmio
* score: 100.0
* date:  2020-07-14 08:23:43.323823
*/
#include <cassert>
#include <cstdio>
#include <iostream>

#define MAXN 131072
#define MAXM 200000

using namespace std;
int N,M;
int pot;

int prec[MAXN*2];
int succ[MAXN*2];
int X[MAXN*2];


void init(){
    pot=1;
    while(pot<N){
        pot=pot*2;
    }
    for(int i=1;i<pot*2;i++){
        prec[i]=0;
        succ[i]=0;
        X[i]=0;
    }
}

void change(int A){
    A=A+pot;
    if(X[A]==0){
        X[A]=1;
        prec[A]=1;
        succ[A]=1;
    }else{
        X[A]=0;
        prec[A]=0;
        succ[A]=0;
    }
    do{
        if(A%2==1){
            A=(A-1)/2;
        }else{
            A=A/2;
        }
        if((succ[A*2]==0)||(prec[A*2+1]==0)){
            X[A]=X[A*2]+X[A*2+1];
            prec[A]=prec[A*2];
            succ[A]=succ[A*2+1];
        }else{
            X[A]=X[A*2]+X[A*2+1]-1;
            prec[A]=prec[A*2];
            succ[A]=succ[A*2+1];
        }
    }while(A>1);
}

int query(int A, int B){
        int pb=0,sa=0,xa=0,xb=0;
		A += pot;
		B += pot;

		while(A<B){
            if(A%2==1){
                if((prec[A]==0)||(sa==0)){
                    xa=xa+X[A];
                    sa=succ[A];
                }else{
                    xa=xa+X[A]-1;
                    sa=succ[A];
                }
                A++;
            }
            if(B%2==0){
                if((succ[B]==0)||(pb==0)){
                    xb=xb+X[B];
                    pb=prec[B];
                }else{
                    xb=xb+X[B]-1;
                    pb=prec[B];
                }
                B--;
            }
            A=A/2;
            B=(B-1)/2;
        
        }
        if(A==B){
            if((prec[A]==0)||(sa==0)){
                xa=xa+X[A];
                sa=succ[A];
            }else{
                xa=xa+X[A]-1;
                sa=succ[A];
            }
            if((sa==0)||(pb==0)){
                    return xb+xa;
                }else{
                    return xb+xa-1;
                }  
        }
        if((sa==0)||(pb==0)){
                return xb+xa;
            }else{
                return xb+xa-1;
            }
}



int main() {
    int q, A, B;
    cin >> N >> M;
    init();
    
    for(int i=0;i<M;i++){
        cin >> q;
        if(q==1){
            cin >> A;
            change(A);
        }else{
            cin >> A;
            cin >> B;
            cout << query(A,B) << endl;
        }
    }

    return 0;
}

