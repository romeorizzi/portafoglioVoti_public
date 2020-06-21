/**
* user:  VR424867
* fname: CONSOLARO
* lname: GIANPIETRO
* task:  cats
* score: 0.0
* date:  2019-02-26 12:45:03.545614
*/
/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <vector>
// constraints
#define MAXN 1000
using namespace std;
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
    int k=0;
    // insert your code here

    vector<int> differenza;
        for(int j=0;j<Nf;j++){
            if(M[0]-F[j]>0)
                differenza.push_back(M[i]-F[j]);
            else
                differenza.push_back(F[j]-M[0]);
        }
    int minore;
    if(Nm<Nf)
        minore=Nm;
    else
        minore=Nf;

    sort(differenza.begin(),differenza.end());
    int risultato=0;

    for(int i=Nf-1;i>=Nf-minore;i--)
        risultato+=differenza[i];

    printf("%d\n", risultato); // change 42 with actual answer
    return 0;
}
