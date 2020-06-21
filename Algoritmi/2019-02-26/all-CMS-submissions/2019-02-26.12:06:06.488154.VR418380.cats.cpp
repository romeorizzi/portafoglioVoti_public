/**
* user:  VR418380
* fname: CRUCIANI
* lname: FEDERICA
* task:  cats
* score: 0.0
* date:  2019-02-26 12:06:06.488154
*/
/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <stdio.h>
#include <assert.h>
#include <math.h>
// constraints
#define MAXN 1000

// input data
int Nm, Nf, i;
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

    // insert your code here
    for(int i = 0; i<Nm; i++)
    {
        printf("%d",M[i]);

    }
    
    for(int i = 0; i<Nf; i++)
    {
        printf("%d",F[i]);

    }
    
    
    int max = 0; 
    int val = M[0];
    for(int i = 0; i<Nf; i++)
    {
        int sum = 0;
        int sub = 0;
        int k = i;
        for(int j = 0; j<Nm; j++)
        {
            sum += F[k];
            sub += val;
            //printf("sono il F[K] all'iterazione %d: %d\n", j,F[k]);
            //printf("sono il SUM all'iterazione %d: %d\n", j,sum);
            //printf("sono il sub all'iterazione %d: %d\n", j,sub);
            if(fabs(sum-sub) > max)
            {
                max = fabs(sum-sub);
                
            //    printf("sono il max all'iterazione %d: %d\n", j,max);
            }
            k++;
        }
    }
    
    printf("%d\n", max); // change 42 with actual answer
    return 0;
}
