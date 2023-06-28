/**
* user:  VR463656
* fname: GIOVANNI
* lname: DANIELI
* task:  esame_two_three_steps_stdio
* score: 80.0
* date:  2023-02-20 13:22:16.243517
*/

#include <cassert>
#include <cstdio>
#include <array>

#define MAXN 1000000

int N;
int GGG[MAXN]; // GGG[i] = valore del ricordo i-esimo.
std::array<int, MAXN> MEMORY = {0};

int corridoio(int pos){
	if(pos > N){
    return 0;
  }
  if (MEMORY[pos] != 0){
    return MEMORY[pos];
  }
  int dueStep = 0; 
  int treStep = 0;
  dueStep = GGG[pos] + corridoio(pos + 2);
  treStep = GGG[pos] + corridoio(pos + 3);
  if (dueStep > treStep){
    MEMORY[pos] = dueStep;
    return dueStep;
  }
  MEMORY[pos] = treStep;
  return treStep;
}

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; i++)
     scanf("%d", &GGG[i]);
     
  

  printf("%d\n", corridoio(0)); // giusto quando tutti i ricordi sono scialbi tranne al più il secondo. 
  
  return 0;
}

