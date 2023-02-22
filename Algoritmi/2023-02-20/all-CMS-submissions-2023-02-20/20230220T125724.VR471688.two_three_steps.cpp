/**
* user:  VR471688
* fname: NICOLO
* lname: FRETTI
* task:  esame_two_three_steps
* score: 100.0
* date:  2023-02-20 12:57:24.190549
*/
/**
 *  Soluzione farlocca di two_three_steps (illustra come curare input ed output)
 *
 *  Autore: Romeo Rizzi, 2018-06-14
 *
 */

#include <cassert>
#include <cstdio>

#define MAXN 1000000

int N;
int GGG[MAXN]; // GGG[i] = valore del ricordo i-esimo.

int max(int a, int b){
  if(a>b){
    return a;
  }
  return b;
}


int main() {
  assert( freopen("input.txt", "r", stdin) );
  assert( freopen("output.txt", "w", stdout) );

  scanf("%d", &N);
  int memo[N];
  for(int i = 0; i < N; i++){
     scanf("%d", &GGG[i]);
     memo[i] = 0;
  }
  memo[N-1] = GGG[N-1];
  memo[N-2] = GGG[N-2];
  memo[N-3] = GGG[N-3] + memo[N-1];
  
  for(int i=N-4; i >=0; i--){
    memo[i]=GGG[i]+max(memo[i+2], memo[i+3]);
  }


  printf("%d\n", memo[0]); // giusto quando tutti i ricordi sono scialbi tranne al più il secondo. 
  
  return 0;
}

