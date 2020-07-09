/**
* user:  VR424616
* fname: CASTIGLIONI
* lname: ALESSANDRA
* task:  gioco_cifre
* score: 20.0
* date:  2020-06-18 11:57:35.418221
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

  fprintf(file, "1 %lld", mod);

  fclose(file);
  return 0;
}