/**
* user:  VR436747
* fname: BRAGOI
* lname: VLADISLAV
* task:  Prob2_hanoi_equal_disks
* score: 20.0
* date:  2019-09-04 10:10:49.910408
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
llu num_mosse = 0;

void move(int n, int from, int to, int unused, void (*basicActionOnDisk) (int,char,char) ) {
  if(n <= 0) return;
  move(n-1, from, unused, to, basicActionOnDisk);
  (*basicActionOnDisk)(n, from, unused);
  move(n-1, unused, to, from, basicActionOnDisk);
}

void sposta_disco(int n, char from, char to) {
    printf("Muovi il disco %d dal piolo %c al piolo %c\n", n, from, to);
}

void conta_spostamentiDisco(int n, char from, char to) {
    num_mosse++;
}  

int main() {
  cin >> t >> N;
  for(int i = 1; i <= N; i++) {
    cin >> d[i];
  }
  if(t == 1)
    move(N, 'A', 'C', 'B', &sposta_disco);
  else {
    move(N, 'A', 'C', 'B', &conta_spostamentiDisco);
    printf("%llu", num_mosse);
  }  
  
  return 0;
}