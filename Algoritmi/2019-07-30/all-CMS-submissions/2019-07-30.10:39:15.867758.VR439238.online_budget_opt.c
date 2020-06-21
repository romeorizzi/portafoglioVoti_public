/**
* user:  VR439238
* fname: BENINI
* lname: ANDREA
* task:  online_budget_opt
* score: 10.0
* date:  2019-07-30 10:39:15.867758
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXVAL 1000000007

int N, B0, T, i, max=0, min=11, maxq=0, pos;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d %d", &N, &B0, &T);
    int X[N];
    int Q[N];
    for(i=0; i<N; i++) {
        scanf("%d", &X[i]);
        min = (X[i]<min)?X[i]:min;
        max = (X[i]>max)?X[i]:max;
    }
    for(i=0; i<N; i++) {
        scanf("%d", &Q[i]);
        maxq = (Q[i]>maxq)?Q[i]:maxq;
        if(Q[i]>maxq) {
            maxq = Q[i];
            pos = i;
        }
    }

    if(T==1 && N==1) {
        printf("%d", B0*Q[0]);
    } else if(T==2 && N==1) {
        printf("%d", B0);
    }

    if(max==0 && min==0) {
        if(T==1)
            printf("%d", maxq*B0);
        if(T==2) {
            for(i=0; i<N; i++) {
                if(i==pos) {
                    printf("%d ", maxq);
                } else {
                    printf("%d ", 0);
                }
            }
        }
    }

    

    return 0;
}