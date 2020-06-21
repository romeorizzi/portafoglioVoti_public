/**
* user:  VR436747
* fname: BRAGOI
* lname: VLADISLAV
* task:  Prob2_hanoi_equal_disks
* score: 0.0
* date:  2019-09-04 09:03:50.433314
*/
/**
 * Un template per la tua soluzione di hanoi_equal_disks
 * Romeo Rizzi, 2019-08-28
 *
 */

#include <cassert>
#include <cstdio>
#include <iostream>

using namespace std;
const int DEBUG = 0;
//const int DEBUG = 1;
const int MAXN = 100000;

int t, N;
int d[MAXN+1];

typedef long long unsigned int llu;
llu num_mosse = 1;

void sposta_disco(int n, int piolo_from, int piolo_to) {
  char from = piolo_from == 1? 'A': piolo_from == 2? 'B': 'C';
  char to = piolo_to == 1? 'A': piolo_to == 2? 'B': 'C';
  printf("sposta il disco %d dal piolo %c al piolo %c\n", n, from, to);
}

void conta_spostamentiDisco(int n, int from, int to) {
  num_mosse++;
} 

void spostaTorre(int n, int from, int to, int aux, int requires_extra_move[], void (*basicActionOnDisk) (int,int,int) ) {
  if(n <= 0) return;
  if( requires_extra_move[n] ) {
    spostaTorre(n-1,  from, to, aux,  requires_extra_move, basicActionOnDisk);
    (*basicActionOnDisk)(n, from, aux);
    spostaTorre(n-1,  to, from, aux, requires_extra_move, basicActionOnDisk);
    (*basicActionOnDisk)(n, aux, to);
    spostaTorre(n-1,  from, to, aux,  requires_extra_move, basicActionOnDisk);
    requires_extra_move[n] = 0;
  }
  else {
    spostaTorre(n-1,  from, aux, to,  requires_extra_move, basicActionOnDisk);
    (*basicActionOnDisk)(n, from, to);
    spostaTorre(n-1,  aux, to, from,  requires_extra_move, basicActionOnDisk);
  }  
}  

int main() {
  cin >> t >> N;
  for(int i = 1; i <= N; i++) {
    cin >> d[i];
  }

  int requires_extra_move_to_fix_parity[MAXN +1];
    if( d[N] == 2 )
      requires_extra_move_to_fix_parity[N] = 0;
    else
      requires_extra_move_to_fix_parity[N] = 1 - d[N];
    
    for(int i = N-1; i >= 1; i--) {
      if( d[i] == 2 )
        requires_extra_move_to_fix_parity[i] = 0;
      else
        requires_extra_move_to_fix_parity[i] = (d[i] + requires_extra_move_to_fix_parity[i+1]) %2;
    }   
    int copy2_requires_extra_move_to_fix_parity[MAXN +1]; // just a second copy for second use (it gets spoiled with use)
    for(int i = 1; i <= N; i++) {
       copy2_requires_extra_move_to_fix_parity[i] = requires_extra_move_to_fix_parity[i];
    }   

    if (t == 0) {
      spostaTorre(N, 1,3,2, requires_extra_move_to_fix_parity, &conta_spostamentiDisco);
      printf("%llu\n", num_mosse );
    } else {
      spostaTorre(N, 1,3,2, copy2_requires_extra_move_to_fix_parity, &sposta_disco);
    }
  
  return 0;
}