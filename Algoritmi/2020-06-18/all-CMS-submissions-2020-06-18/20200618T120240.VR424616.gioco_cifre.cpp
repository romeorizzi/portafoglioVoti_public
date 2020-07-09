/**
* user:  VR424616
* fname: CASTIGLIONI
* lname: ALESSANDRA
* task:  gioco_cifre
* score: 0.0
* date:  2020-06-18 12:02:40.269370
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static FILE *file;
static long long int numero;

int main() {

#ifdef EVAL
  file = fopen("input.txt", "r");
#else
  file = stdin;
#endif

  assert( fscanf(file, "%lld", &numero) == 1);
  fclose(file);

#ifdef EVAL
  file = fopen("output.txt", "w");
#else
  file = stdout;
#endif
  long long int mod=numero%10;
  
  if(mod!=0){
      fprintf(file, "1 %lld", mod);
  }
  else{
      fprintf(file, "0", );
  }

  fclose(file);
  return 0;
}