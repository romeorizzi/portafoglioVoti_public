/**
* user:  VR439620
* fname: MOLINARI
* lname: DAVIDE
* task:  Prob2_hanoi_equal_disks
* score: 40.0
* date:  2019-09-04 10:27:35.790143
*/
/**
 * Un template per la tua soluzione di hanoi_equal_disks
 * Romeo Rizzi, 2019-08-28
 *
 */

#include <cassert>
#include <cstdio>
#include <cmath>

const int DEBUG = 0;
//const int DEBUG = 1;
const int MAXN = 100000;

int t, N;
int d[MAXN+1];
int sol[MAXN+1];

typedef long long unsigned int llu;

void sposta_disco(int n, char piolo_from, char piolo_to) {
  printf("sposta il disco %d dal piolo %c al piolo %c\n", n, piolo_from, piolo_to);
}

void RisolviRic(int n, char from, char to, char appoggio)
{
    assert(n >= 0);
    if(n == 0) return;
    assert(n>=1);
    RisolviRic(n-1,from,appoggio,to);
    sposta_disco(n,from,to);
    RisolviRic(n-1,appoggio,to,from);
}

int ContaMosse(int diversi)
{
    llu sum = 0;
    for(int i =1; i<=diversi;i++)
        sum += sol[i]*pow(2,diversi-i);
    return sum;
}

int main() {
  scanf("%d%d", &t, &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &d[i]);
  }
  llu num_mosse = 1;
  int check=1,occ=1,diversi=0;
  for(int i = 1;i <= N; i++)
  {
    for(int j = i+1;j <= N; j++)
      {
        if(d[i] == d[j])
        {
            check = 0;
            occ++;
        }
      }
    if (check == 1)
    {
        diversi++;
        sol[i] = 1;
    }
    else sol[i] = occ;
    occ = 1;
    check = 1;
  }
  if(t==0)
    printf("%llu\n", num_mosse = ContaMosse(diversi));
  else
  {
    RisolviRic(N,'A','B','C');
  }
        
  return 0;
}

