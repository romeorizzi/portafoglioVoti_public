/**
* user:  VR436720
* fname: BERTI
* lname: MARCO
* task:  bin_heap_fill
* score: 25.0
* date:  2020-06-18 12:11:46.416208
*/
#include <stdio.h>
#include <algorithm>
#define MAX_N 1000000

int N, T;
int A[MAX_N];
int E[MAX_N];
int F[MAX_N];
int TEMP[MAX_N];

int somma_F = 0;

int verifica_E(){
    for (int i = 0; i < N; i++)
        if (E[i] == 1) {
            // Se non vale la heap property allora è sbagliato
            if (A[i] < A[(i - 1) / 2])
                return 0;
        }
    return 1;
}

int trova_F(){
    if (somma_F == 0)
        return 1;
    // Metto in tmp tutti gli elementi con F = 0
    int j = 0;
    for (int i = 0; i < N; i++)
        if (F[i] == 0)
            TEMP[j++] = A[i];
    std::sort(TEMP, TEMP + j);
    j = 0;
    for (int i = 0; i < N; i++)
        if (F[i] == 0)
            A[i] = TEMP[j++];
    return verifica_E();
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &T);
    for(int i = 0;  i < N; i++)
        scanf("%d", &A[i]);
    for(int i = 0;  i < N; i++)
        scanf("%d", &E[i]);
    for(int i = 0;  i < N; i++){
        scanf("%d", &F[i]);
        if (F[i] == 1)
            somma_F++;
    }

    int out = 0;
    if (T == 1)
        out = verifica_E();
    else
        out = trova_F();
    printf("%d\n", out);
    return 0;
}
