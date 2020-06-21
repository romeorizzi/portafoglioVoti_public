/**
* user:  VR411086
* fname: ZANOTTI
* lname: MATTIA
* task:  cats
* score: 0.0
* date:  2019-02-26 10:28:58.103946
*/
/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 1000

// input data
int Nm, Nf, i;
int M[MAXN], F[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
    freopen("input0.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &Nm, &Nf));
    for(i=0; i<Nm; i++)
        assert(1 == scanf("%d", &M[i]));
    for(i=0; i<Nf; i++)
        assert(1 == scanf("%d", &F[i]));



    int result = 0;
    if(Nm = Nf)
        for(i = 0 ; i < Nm ; i++)
            result += abs(M[i] - F[i]);

    
    printf("%d\n", result); // change 42 with actual answer
    return 0;
}
