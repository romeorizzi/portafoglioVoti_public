/**
* user:  VR439318
* fname: PAVAN
* lname: GIANLUCA
* task:  Prob3_pacman_best
* score: 0.0
* date:  2019-09-04 08:41:28.110264
*/
/* template per pacman, problema per esame Algorimi 2018-09-26
   Romeo 2018-09-25
*/

#include <cassert>
#include <cstdio>

const int BASE = 1000000;
const int MAXBLUE = 5;
const int MAXM = 1000;
const int MAXN = 1000;

char mappa[MAXM+1][MAXN+1];

int M, N;

int main() {
#ifdef EVAL
    assert( freopen("input3.txt", "r", stdin) );
    assert( freopen("output3.txt", "w", stdout) );
#endif
    int x = 0;
    int p = 0;
    int f = 0;
    scanf("%d%d", &M, &N);
	
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            do { 
                scanf("%c", &mappa[i][j]);
            } while(mappa[i][j] != '#' && mappa[i][j] != '+' && mappa[i][j] != '*' && ( mappa[i][j] < '1' || mappa[i][j] > '5')  );

    // // stampa 
    // for (int i = 1; i <= M; i++){
    //     for (int j = 1; j <= N; j++)
    //         printf("%c",mappa[i][j]);
    //     printf("\n");
    // }
    // int val[M][N];
    // for (int i = 1; i <= M; i++)
    //     for (int j = 1; j <= N; j++)
    //         val[i][j]=0;
    // val[M][N] = 1;
    // // vado su
    // if(M-1 != 0)
    //     if(mappa[M-1][N] != '#')
    //         val[M-1][N] = 1;
    // // vado a sx 
    // if(N-1 != 0)
    //     if(mappa[M][N-1] != '#')
    //         val[M][N-1] = 1;

    // // // stampa val
    // // for (int i = 1; i <= M; i++){
    // //     for (int j = 1; j <= N; j++)
    // //         printf("%i",val[i][j]);
    // //     printf("\n");
    // // }


    // for (int i = M; i != 0; i--)
    //     for (int j = N; j != 0; j--){
    //         if(val[i][j]==1){
    //             // vado su
    //             if(i-1 != 0)
    //                 if(mappa[i-1][j] != '#')
    //                     val[i-1][j] = 1;
    //             // vado a sx 
    //             if(j-1 != 0)
    //                 if(mappa[i][j-1] != '#')
    //                     val[i][j-1] = 1;
    //         }
    //     }
    // stampa val
    // for (int i = 1; i <= M; i++){
    //     for (int j = 1; j <= N; j++)
    //         printf("%i",val[i][j]);
    //     printf("\n");
    // }

    // if(val[1][1] != 0)
    //     x = 1;

        

    // int risp = 0;
    printf("%d %d %d",x,f,p);
    return 0;
}