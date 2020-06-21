/**
* user:  VR424867
* fname: CONSOLARO
* lname: GIANPIETRO
* task:  cats
* score: 0.0
* date:  2019-02-26 12:04:07.685850
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
vector<int> differenza;

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

    
    for(int i=0;i<Nm;i++){
        for(int j=0;j<Nf;j++){
            if(M[i]-F[j]>0)
                differenza.push_back(M[i]-F[j]);
            else
                differenza.push_back(F[i]-M[j]);
        }
    }

    int minore;
    if(Nm<Nf)
        minore=Nm;
    else
        minore=Nf;

    sort(differenza.begin(),differenza.end());
    int risultato=0;
    for(int c=1;c<minore;c++){
        int max=0;
        for(int i=0;i<c;i++){
            max+=differenza[i];
        }
        if(max>risultato)
            risultato=max;
    }

    printf("%d\n", risultato); // change 42 with actual answer
    return 0;
}
