/**
* user:  VR439264
* fname: CREMA
* lname: EMANUELE
* task:  Prob2_hanoi_equal_disks
* score: 80.0
* date:  2019-09-04 09:22:44.120576
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

llu num_mosse = 0; 

void sposta_disco(int n, char piolo_from, char piolo_to) {
  printf("sposta il disco %d dal piolo %c al piolo %c\n", n, piolo_from, piolo_to);
}

int all_equals(int n) {
  for(int i=1;i<n;i++) { 
    if(d[i] != d[i+1]) { 
      return 0; 
    } 
  } 
  return 1; 
}

void count_movs(int n, char from, char to, char aux) {
  if(n==1) { 
    num_mosse++;
    return; 
  } 

  if(all_equals(n)) {
    for(int i=1;i<=n;i++) {  
      num_mosse++; 
    } 
    return; 
  }
  
  int i = n; 
  int ct = 1; 
  while(d[i] == d[i-1] && i>1) {
    i--; 
    ct++;   
  }  
  count_movs(n-ct, from, aux, to);   
    
  for(int j=n-ct+1;j<=n;j++) {    
    num_mosse++;
  }

  count_movs(n-ct, aux, to, from); 
  
}

void hanoi_recursive(int n, char from, char to, char aux) {
  if(n==1) {
    sposta_disco(n, from, to); 
    return; 
  } 

  if(all_equals(n)) {
    for(int i=1;i<=n;i++) {  
      sposta_disco(i, from, to); 
    } 
    return; 
  }
  
  int i = n; 
  int ct = 1; 
  while(d[i] == d[i-1] && i>1) {
    i--; 
    ct++;   
  }  
  hanoi_recursive(n-ct, from, aux, to);   
    
  for(int j=n-ct+1;j<=n;j++) {  
    sposta_disco(j, from, to);   
  }

  hanoi_recursive(n-ct, aux, to, from); 
  
}

int main() { 
  scanf("%d%d", &t, &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &d[i]);
  } 
  
  if(t==0) { 
    count_movs(N,'A','B','C'); 
    printf("%llu\n", num_mosse); 
  }
  else
    hanoi_recursive(N, 'A','B','C');
        
  return 0;
}

