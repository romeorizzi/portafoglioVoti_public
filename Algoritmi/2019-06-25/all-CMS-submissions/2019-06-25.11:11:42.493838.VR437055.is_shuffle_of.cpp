/**
* user:  VR437055
* fname: CONTRO
* lname: FILIPPO
* task:  is_shuffle_of
* score: 17.0
* date:  2019-06-25 11:11:42.493838
*/
#include <stdio.h>
#include <algorithm>
#include <assert.h>

#define MAXN 10010

int N, M, T;
int deck1[MAXN];
int deck2[MAXN];
int deck_shuffle[MAXN*2];
int B[MAXN*2];
FILE *fin, *fout;

int main(){
    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");

    assert(3 == fscanf(fin, "%d %d %d", &M, &N, &T));

    for(int i = 0; i<M; i++){
        assert(1 == fscanf(fin, "%d", &deck1[i]));
    }

    for(int i = 0; i<N; i++){
        assert(1 == fscanf(fin, "%d", &deck2[i]));
    }

    for(int i = 0; i<M+N; i++){
        assert(1 == fscanf(fin, "%d", &deck_shuffle[i]));
    }


    int m=0, n=0;
    int choices[M+N][3];
    int last_choice = 0;

    for (int i=0; i<N+M; i++){
        // se ho una sola scelta
        if (deck1[m] != deck2[n]){
            if (m < M && deck_shuffle[i] == deck1[m]){
                m++;
                B[i] = 0;
            }
            else if (n < N && deck_shuffle[i] == deck2[n]){
                n++;
                B[i] = 1;
            }
            else {
                printf("Assurdo\n");
                // non avevo una scelta precedente
                if (last_choice == 0){
                    fprintf(fout, "0\n");
                    return 0;
                }
                // altrimenti loopback
                last_choice--;
                i = choices[last_choice][0];
                m = choices[last_choice][1];
                n = choices[last_choice][2];
                // scelgo da 2 stavolta
                n++;
                printf("\tLoopback: i=%d, m=%d, n=%d\n", i,m,n);
            }
        } else {
            // Sono uguali, vedo se posso scegliere
            // new choice, choose from 1 if possible
            if (m < M && deck_shuffle[i] == deck1[m]){
                choices[last_choice][0] = i;
                choices[last_choice][1] = m;
                choices[last_choice][2] = n;
                last_choice++;
                m++;
                B[i] = 0;
            } else if (n < N && deck_shuffle[i] == deck2[n]){
                m++;
                B[i] = 1;
            } else {
                printf("Assurdo\n");
                // non avevo una scelta precedente
                if (last_choice == 0){
                    fprintf(fout, "0\n");
                    return 0;
                }
                // altrimenti loopback
                last_choice--;
                i = choices[last_choice][0];
                m = choices[last_choice][1];
                n = choices[last_choice][2];
                // scelgo da 2 stavolta
                n++;
                printf("\tLoopback: i=%d, m=%d, n=%d\n", i,m,n);
            }
        }
    }

    fprintf(fout, "1\n");
    if (T == 1){
        fprintf(fout, "%d", B[0]);
        for(int i=1; i<M+N; i++)
            fprintf(fout, " %d", B[i]);
    }

    return 0;
}