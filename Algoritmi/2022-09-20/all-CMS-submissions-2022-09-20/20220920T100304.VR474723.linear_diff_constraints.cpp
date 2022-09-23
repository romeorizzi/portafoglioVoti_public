/**
* user:  VR474723
* fname: MARCELLO
* lname: DE VINCENZI
* task:  esame_linear_diff_constraints
* score: 0.0
* date:  2022-09-20 10:03:04.188376
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long costruisci(int N, int M, vector<long long>& H, vector<int>& A,
vector<int>& B, vector<int>& C);

bool check(int N,int M, vector <int> &A, vector <int>& B,vector<int>& C, vector<int>& altezze);

long max(long,long);

int main(){
    int n, m;
    cin >> n >> m;
    vector<long long> h(n);
    vector<int> a(m), b(m), c(m);

    for(size_t i = 0; i < n; i++) {
        cin >> h[i];
    }
    for(size_t j = 0; j < m; j++) {
        cin >> a[j] >> b[j] >> c[j];
    }
    cout << costruisci(n, m, h, a, b, c) << endl;
    return 0;
}

long long costruisci(int N, int M, vector<long long>& H, vector<int>& A, vector<int>& B, vector<int>& C){

vector <int> altezze(N);
for(size_t i = 0; i < N; i++) {
        altezze[i]=1;
    }
    //Penso faccia un giro in più
long result=0;
long somma=0;
int i=0;
while(altezze[0]<=H[0]){
    
    if(check(N,M,A,B,C,altezze)){
        somma=0;
        for(int i=0;i<N;i++)
            somma+=altezze[i];
    result=max(result,somma);
    }
    //Aumento le altezze
    altezze[N-1]+=1;

    //Controllo come sono messo
    for(int i=1;i<N;i++ ){
        if(altezze[i]>H[i]){
            altezze[i]=0;
            altezze[i-1]=altezze[i-1]+1;
        }
    }
}

return result;
}

bool check(int N,int M, vector <int> &A, vector <int>& B,vector<int>& C, vector<int>& altezze){
    for(int i=0;i<M;i++){
        if(altezze[B[i]]<=(altezze[A[i]] + C[i]));
        else
            return false;
    }
    return true;

}

long max(long a,long b){
    if(a>b)
        return a;
    else
        return b;
}