/**
* user:  VR439620
* fname: MOLINARI
* lname: DAVIDE
* task:  Prob2_hanoi_equal_disks
* score: 60.0
* date:  2019-09-04 11:18:09.716857
*/
/**
 * Un template per la tua soluzione di hanoi_equal_disks
 * Romeo Rizzi, 2019-08-28
 *
 */

#include <cassert>
#include <cstdio>
#include <cmath>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

const int DEBUG = 0;
//const int DEBUG = 1;
const int MAXN = 100000;

int t, N;
vector<int> d;
vector<int> card;

typedef long long unsigned int llu;

void sposta_disco(int n, char piolo_from, char piolo_to) {
  printf("sposta il disco %d dal piolo %c al piolo %c\n", n, piolo_from, piolo_to);
}

void RisolviRic(int n, char from, char to, char appoggio)
{
    //assert(n >= 0);
    if(n == 0) return;
    //assert(n>=1);
    RisolviRic(n-1,from,appoggio,to);
    sposta_disco(n,from,to);
    RisolviRic(n-1,appoggio,to,from);
}

int ContaMosse()
{
    llu sum = 0;
    for(int i =1; i<=d.size();i++)
        sum += card[i-1]*pow(2,d.size()-i);
    return sum;
}

int main() {
  scanf("%d%d", &t, &N);
  int temp;
  for(int i = 0; i < N; i++) {
    scanf("%d", &temp);
    if(d.size() == 0 || d[d.size()-1] != temp)
    {
        d.push_back(temp);
        card.push_back(0);
    }
    card[d.size()-1] = card[d.size()-1] +1;
  }
  //llu num_mosse = 1;
  if(t==0)
    printf("%llu\n", ContaMosse());
  else
  {
    RisolviRic(N,'A','B','C');
  }
        
  return 0;
}

