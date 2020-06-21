/**
* user:  VR434403
* fname: CROSARA
* lname: MARCO
* task:  online_budget
* score: 0.0
* date:  2019-07-30 11:00:51.886772
*/
/**
 *  Template per soluzione in c per il problema online_budget
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <assert.h>
#include <stdio.h>

#define MAX_N 500
#define MAX_VAL 10

int n, B0, x[MAX_N];

void print_array(int *v, int len) {
  for(int i = 0; i < len; i++)
      printf("%d ", v[i]);
  printf("\n");
}

long int fun(int val, int level){
  if(level == 0){
    return 1;
  }

  long int result = 0;
  for(int i = 1; i <= val; i++){
    result += fun(i + x[n - level], level-1);
  }

  return result;
}

int main() {
    scanf("%d %d", &n, &B0);
    for(int i = 0; i < n; i++)
       scanf("%d", &x[i]);
    //print_array(x, n);

    long int value = fun(B0 + 1, n); // n = tempo

    printf("%ld\n", risp);
    return 0;
}

