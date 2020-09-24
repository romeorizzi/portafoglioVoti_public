/**
* user:  VR424616_id163zjd
* fname: ALESSANDRA
* lname: CASTIGLIONI
* task:  gioco_parentesi
* score: 0.0
* date:  2020-09-18 12:04:21.411737
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<assert.h>

using namespace std;

static FILE *file;
const long long int MAXN = 1000000;

static long long int N;
static char parentesi[MAXN];

int main() {

    #ifdef EVAL
    file = fopen("input.txt", "r");
    #else
    file = stdin;
    #endif

    assert(fscanf(file, "%lld", &N)==1);
    for (int i=0; i<N; i++){
        assert(fscanf(file, "%c", &parentesi[i])==1);
    }
    
    /*cin >> N;

    for (int i = 0; i < N; ++i) {
		cin >> parentesi[i];
    }*/

    fclose(file);
    #ifdef EVAL
    file = fopen("output.txt", "w");
    #else
    file = stdout;
    #endif

    int seq[N];
    long long int x=0;

    for (int i = 0; i < N; i++){
        if (parentesi[i] == '('){
            x=x+1;
            seq[i]=x;
        }
        else if(parentesi[i]== ')'){
            seq[i]=x;
            x=x-1;
        }
    }

    int max = 0;
    for (int i = 0; i<N; i++){
        if(seq[i]>max){
            max=seq[i];
        }
    }

    int numeri[max] = {0};

    for (int i=0; i<N; i++){
        for (int j=0;j<max; j++){
            if (seq[i]==j+1){
                numeri[j]+=1;
            }
        }
    }
    
    if (numeri[0]/2==1){
        /*cout << 1 << endl;
        cout << 0 << N << endl;*/
        fprintf(file, "1\n0 %lld\n", N-1);
    }

    
    fclose(file);
    return 0;
}