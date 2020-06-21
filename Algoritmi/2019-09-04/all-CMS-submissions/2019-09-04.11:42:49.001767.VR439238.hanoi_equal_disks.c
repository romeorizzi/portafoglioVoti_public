/**
* user:  VR439238
* fname: BENINI
* lname: ANDREA
* task:  Prob2_hanoi_equal_disks
* score: 20.0
* date:  2019-09-04 11:42:49.001767
*/
/**
 *  Andrea Benini VR439238
 *  04/09/2019
 *
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//const int DEBUG = 0;
//const int DEBUG = 1;
#define MAXN 100000

int t, N;
int d[MAXN+1];
int doppi[MAXN+1];


void sposta_disco(int n, char piolo_from, char piolo_to) {
  printf("sposta il disco %d dal piolo %c al piolo %c\n", n, piolo_from, piolo_to);
}

long long unsigned int calcolo_mosse(int dischi) {
    if(dischi == 1) {
        return 1;
    } else {
        return calcolo_mosse(dischi-1)+calcolo_mosse(dischi-1)+1;
    }
}

long long unsigned int potenza(int valore, int esponente) {
    if(esponente == 0) {
        return 1;
    }else if(esponente == 1) {
        return valore;
    }else {
        return valore*potenza(valore, esponente-1);
    }
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

  scanf("%d%d", &t, &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &d[i]);
  }
  long long unsigned int num_mosse = 1;
  int duplicates = 0, counter = 0;


    for(int i=2; i<=N; i++) {
        counter++;
        if(d[i] == d[i-1]) {
            doppi[duplicates] = counter;
            duplicates++;
            counter--;
        }
    }

    
    num_mosse = calcolo_mosse(N-duplicates);

    for(int i=0; i<duplicates; i++) {
        num_mosse = num_mosse + potenza(2, doppi[i]-1);
    }
    


  if(t==0)
    printf("%llu\n", num_mosse);
  else
    sposta_disco(1, 'A', 'B');
        
  return 0;
}

