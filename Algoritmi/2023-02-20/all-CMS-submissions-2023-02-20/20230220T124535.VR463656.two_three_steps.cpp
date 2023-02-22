/**
* user:  VR463656
* fname: GIOVANNI
* lname: DANIELI
* task:  esame_two_three_steps
* score: 25.0
* date:  2023-02-20 12:45:35.374198
*/

#include <cassert>
#include <cstdio>

#define MAXN 1000000

int N;
int GGG[MAXN]; // GGG[i] = valore del ricordo i-esimo.
int MEMORY[MAXN];

int corridoio(int pos){
	if(pos > N){
    return 0;
  }
  int dueStep = 0; 
  int treStep = 0;
  dueStep = GGG[pos] + corridoio(pos + 2);
  treStep = GGG[pos] + corridoio(pos + 3);
  if (dueStep > treStep){
    return dueStep;
  }
  return treStep;
}

int main() {
  assert( freopen("input.txt", "r", stdin) );
  assert( freopen("output.txt", "w", stdout) );

  scanf("%d", &N);
  for(int i = 0; i < N; i++)
     scanf("%d", &GGG[i]);
     
  

  printf("%d\n", corridoio(0)); // giusto quando tutti i ricordi sono scialbi tranne al più il secondo. 
  
  return 0;
}

