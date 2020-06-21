/**
* user:  VR418380
* fname: CRUCIANI
* lname: FEDERICA
* task:  cats
* score: 0.0
* date:  2019-02-26 11:24:48.356101
*/
/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 1000

// input data
int Nm, Nf, i;
int M[MAXN], F[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &Nm, &Nf));
    for(i=0; i<Nm; i++)
        assert(1 == scanf("%d", &M[i]));
    for(i=0; i<Nf; i++)
        assert(1 == scanf("%d", &F[i]));

    // insert your code here

    int max = 0; 
    int val = M[0];
    for(int i = 0; i<Nf; i++)
    {
        for(int j = 0; j<Nm; j++)
        {
            int sum;
            sum += F[i+1];
            int sub = val * (j+1);
            if(sum-sub > max)
            {
                max = sum-sub;
            }
        }
    }
    
    printf("%d\n", max); // change 42 with actual answer
    return 0;
}
