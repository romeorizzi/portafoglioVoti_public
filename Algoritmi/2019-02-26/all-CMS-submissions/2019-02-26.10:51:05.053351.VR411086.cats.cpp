/**
* user:  VR411086
* fname: ZANOTTI
* lname: MATTIA
* task:  cats
* score: 0.0
* date:  2019-02-26 10:51:05.053351
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
int Nm, Nf, i, j;
int M[MAXN], F[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &Nm, &Nf));
    for(i=0; i<Nm; i++)
        assert(1 == scanf("%d", &M[i]));
    for(i=0; i<Nf; i++)
        assert(1 == scanf("%d", &F[i]));

    int diff[Nm][Nf];

    for(i = 0 ; i < Nm ; i++)
        for(j = 0 ; j < Nf ; j++)
            diff[i][j] = abs(M[i] - F[j]);

    int result = 0;
    int tmp_result = 0;
    if(Nm = Nf){
        for(i = Nm - 1 ;  i >= 0 ; i--){
            j = 0;

            do{
                tmp_result += diff[i][j];
                j++;
            }while(j < Nf && i + 1 < Nm);

            if(tmp_result > result){
                result = tmp_result;
                tmp_result = 0;
            }
        }
    }
    
    printf("%d\n", result); // change 42 with actual answer
    return 0;
}
