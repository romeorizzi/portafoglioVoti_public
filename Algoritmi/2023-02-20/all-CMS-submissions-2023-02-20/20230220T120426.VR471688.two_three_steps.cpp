/**
* user:  VR471688
* fname: NICOLO
* lname: FRETTI
* task:  esame_two_three_steps
* score: 25.0
* date:  2023-02-20 12:04:26.938377
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

int max_ricordi(int index, int count){
  if (index >=N){
    return count;
  }
  int two = max_ricordi(index+2, count+GGG[index]);
  int tree = max_ricordi(index+3, count+GGG[index]);

  return max(two, tree);
}

int main() {
  assert( freopen("input.txt", "r", stdin) );
  assert( freopen("output.txt", "w", stdout) );

  scanf("%d", &N);
  for(int i = 0; i < N; i++)
     scanf("%d", &GGG[i]);

  printf("%d\n", max_ricordi(0,0)); // giusto quando tutti i ricordi sono scialbi tranne al più il secondo. 
  
  return 0;
}

