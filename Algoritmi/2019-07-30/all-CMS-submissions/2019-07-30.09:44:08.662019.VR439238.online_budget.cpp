/**
* user:  VR439238
* fname: BENINI
* lname: ANDREA
* task:  online_budget
* score: 10.0
* date:  2019-07-30 09:44:08.662019
*/
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAXVAL 1000000007

int N, B0, i;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d", &N, &B0);
    int X[N];
    for(i=0; i<N; i++) {
        scanf("%d", &X[i]);
    }

    long long counter = 1;
    int prev;

    for(i=0; i<N; i++) {
        counter = (counter*(B0+1))%MAXVAL;
        /*
        if(i==0) {
            counter = (B0+1)%MAXVAL;
        } else {
            for(j=0; j<B0; j++) {
                counter += 
            }
        }*/
        prev = B0;
        B0 += X[i];
    }

    printf("%lld", counter);

    return 0;
}