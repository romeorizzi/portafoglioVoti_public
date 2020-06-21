/**
* user:  VR436747
* fname: BRAGOI
* lname: VLADISLAV
* task:  Prob2_hanoi_equal_disks
* score: 20.0
* date:  2019-09-04 11:02:57.809412
*/
/**
 * Un template per la tua soluzione di hanoi_equal_disks
 * Romeo Rizzi, 2019-08-28
 *
 */

#include <cassert>
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;
const int DEBUG = 0;
//const int DEBUG = 1;
const int MAXN = 100000;

int t, N;
int d[MAXN+1];
int k[MAXN+1];

typedef long long unsigned int llu;
llu num_mosse = 1;

llu count(int not_equals, int k[]) {
  llu sum = 0;

  for (int i = 1; i <= not_equals; i++) 
    sum += k[i]*pow(2,not_equals-i);

  return sum;
}

void sposta_disco(int n, char from, char to) {
    printf("Muovi il disco %d dal piolo %c al piolo %c\n", n, from, to);
}

void move(int n, int from, int to, int tmp) {
  if(n == 0) return;
  if (n >= 1) {
    move(n-1, from, tmp, to);
    sposta_disco(n, from, to);
    move(n-1, tmp, to, from);
  }
}

int main() {
  cin >> t >> N;
  for(int i = 1; i <= N; i++) {
    cin >> d[i];
  }

  int not_equal = 0, check = 1, occ=1;

  for (int i = 1; i <= N; i++) {
    for (int j = i+1; j <= N; j++) {
      if (d[i] == d[j]) {
        check = 0;
        occ++;
      }
    }

    if (check == 1) {
      not_equal++;
      k[i] = 1;
    }

    if (check == 0) k[i] = occ;
  
    occ = 1;
    check = 1;
  }
  if(t == 1)
    move(N, 'A', 'C', 'B');
  else {
    printf("%llu", count(not_equal, k));
  }  
  
  return 0;
}