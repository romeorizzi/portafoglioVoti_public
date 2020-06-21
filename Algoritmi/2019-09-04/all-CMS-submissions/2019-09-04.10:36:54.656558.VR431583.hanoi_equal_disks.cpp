/**
* user:  VR431583
* fname: ALBANESE
* lname: MIRKO
* task:  Prob2_hanoi_equal_disks
* score: 20.0
* date:  2019-09-04 10:36:54.656558
*/
/**
 * Un template per la tua soluzione di hanoi_equal_disks
 * Romeo Rizzi, 2019-08-28
 *
 */

#include <cassert>
#include <cstdio>

const int DEBUG = 0;
//const int DEBUG = 1;
const int MAXN = 100000;

int t, N;
int d[MAXN+1];

typedef long long unsigned int llu;

void sposta_disco(int n, char piolo_from, char piolo_to) {
  printf("sposta il disco %d dal piolo %c al piolo %c\n", n, piolo_from, piolo_to);
}

int AllEqual (int N, int d[MAXN+1]) {
  for (int i = 1; i < MAXN+1; i++)
  {
    if (d[i] != d[i+1])
      return 1;
  }
  return 0;
} 

int ParEqual (int N, int d[MAXN+1]) {

  int count = 0, num_d_disk = 0;

  for (int i = 1; i < MAXN; i++)
  {
    if (d[i] == d[i+1])
      count++;
    else
      num_d_disk++;
      
  }
  return num_d_disk;
}

llu Nmosse(int N, int d[MAXN+1]) {

  int resEqual, num_disk;
  llu mosse = 1;

  if (N == 1)
    return 1;
  else
  {
    //if ((resEqual = AllEqual(N, d) == 0))
    //  return N;
    //else
    //{
      //Chiamo ParEqual, mi ritorna il numero effettivo di dischi
      num_disk = ParEqual(N, d);
      for (int k = 2; k <= num_disk; k++)
      {
        mosse += (mosse + 1);
      }
      if (N != num_disk)
        mosse += (1 + (N - num_disk));
    //}
  }
  return mosse;  
}

int algoMosse (int N, int d[MAXN+1]) {

}

int main() {
  scanf("%d%d", &t, &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &d[i]);
  }
  llu num_mosse;
  if(t==0)
  {
    num_mosse = Nmosse(N, d);
    printf("%llu\n", num_mosse);
  }
  else
    //sposta_disco(1, 'A', 'B');
        
  return 0;
}

