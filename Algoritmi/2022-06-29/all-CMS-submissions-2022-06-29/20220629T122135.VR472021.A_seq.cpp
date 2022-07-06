/**
* user:  VR472021
* fname: ANNA
* lname: DALLA VECCHIA
* task:  A_seq
* score: 0.0
* date:  2022-06-29 12:21:35.785987
*/
#include <stdio.h>
#include using namespace std;

int G, N;
int* s;

int max_n = 0, max_c=0;

void prox(int i_prec, int index, int cont_p, bool asc){
    if(index==N){
        if(cont_p > max_n){
            max_n = cont_p;
            max_c = 1;
        } else if (cont_p == max_n){
            max_c++;
        }
        return;
    }
    if(asc && s[index] > s[i_prec]){
        prox(index, index+1, cont_p+1, true);
        prox(index, index+1, cont_p+1, false);
    }
    if(!asc && s[i_prec] > s[index]){
        prox(index, index+1, cont_p+1, false);
    }
    prox(i_prec, index+1, cont_p, asc);
}


int main() {
    cin >> G;
    cin >> N;
    s = new int[N];


    for(int i=0; i<(N-max_n+1); i++){
        prox(i, i, 1, true);
        prox(i, i, 1, false);
    }

    if(G == 1)
        cout << max_n;

    return 0;
}