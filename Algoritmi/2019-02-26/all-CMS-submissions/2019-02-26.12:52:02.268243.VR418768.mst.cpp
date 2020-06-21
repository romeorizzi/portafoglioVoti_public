/**
* user:  VR418768
* fname: GRIGOLINI
* lname: FEDERICO
* task:  mst
* score: 20.0
* date:  2019-02-26 12:52:02.268243
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unistd.h>
//minimum spannin tree.


#define maxN 10000
#define maxWeight 10000

using namespace std;

int i,l;
int Sum;

bool matrice[maxN][maxN];
bool visited[maxN];
vector<pair<int,int>> result;
pair<int,int> aux;

vector<pair<int,pair<int,int>>> archi;


bool trova(int k, int target){

    for(auto a : result){
        if(a.first==k){
            if(a.second==target)
                return true;
            if(trova(a.second,target))
                return true;
        }

    }
    return false;
}

bool trova2(int k, int target){

    for(auto a : result){
        if(a.second==k){
            if(a.first==target)
                return true;
            if(trova(a.first,target))
                return true;
        }
    }
    return false;
}




int mst(int N, int M, int A[], int B[], int P[], int C[], int D[]){

    for(i=0; i<M; ++i){
        archi.push_back(make_pair(P[i],make_pair(min(A[i],B[i]),max(A[i],B[i]) )));
    }
    sort(archi.begin(),archi.end());
    for(auto u : archi){
        aux=u.second;
        if( !trova(aux.first,aux.second) && !trova2(aux.second,aux.first) ){
            result.push_back(aux);
            C[l]=aux.first;
            D[l]=aux.second;
            Sum+=u.first;
            l++;
            //cout << aux.first << "  " << aux.second << endl;
        }

    }

    return Sum;

}

/*
int mst(int N, int M, int A[], int B[], int P[], int C[], int D[]){
    vector<pair<int,int>> grafo[N];
    for(i=0; i<M; ++i){
        aux.first=B[i];
        aux.second=P[i];
        grafo[A[i]].push_back(aux);
        aux.first=A[i];
        grafo[B[i]].push_back(aux);
    }
    for(i=0; i<N; ++i){
        for(auto c: grafo[i])
            cout<< i << " | " << c.first << " | " << c.second << endl;
    }
    cout << endl << endl;
    for(i=0; i<N; ++i){
        if(!grafo[i].empty() && result.size()!=N-1){

            bool avanza=false;
            minimo=maxWeight;
            for(auto u : grafo[i]){
                if(u.second<minimo && (!matrice[u.first][i])){
                    minimo=u.second;
                    Node=u.first;
                    avanza=true;
                }
            }

            if(avanza){
                Sum+=minimo;
                aux.first=i;
                aux.second=Node;
                result.insert(aux);
                visited[i]=true;
                visited[Node]=true;
                matrice[i][Node]=true;
                matrice[Node][i]=true;
            }

        }
        
    }
    i=0;
    for(auto u: result){
        D[i]=u.second;
        C[i]=u.first;
        cout<< C[i] << " " << D[i] << endl;
        ++i;
    }
    cout << "===============================" << Sum<<endl;
    return Sum;
}

*/
/*
int main(){
    vector<int> v={1,2,3,4};
    vector<int> p[2];
    p[0]=v;
    v.pop_back();
    v.push_back(8);
    p[1]=v;
    for(int i=0; i<2; i++){
        for(auto a: p[i]){
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}*/