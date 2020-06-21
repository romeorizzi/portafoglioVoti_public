/**
* user:  VR439238
* fname: BENINI
* lname: ANDREA
* task:  Prob1_tree_split_out
* score: 30.0
* date:  2019-09-04 09:29:49.990749
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

#define MAX_N 1000000

int n = 0, counter = 0, input_type;
char str[MAX_N];
int in_tree[MAX_N], out_tree[MAX_N];

void parse_array(int *v, int *len, char *str){
    char *num=strtok(str," ");
    do{
        //v[(*len)++]=strtol(num,NULL,10);
        v[(*len)++]=atoi(num);
    }while((num=strtok(NULL, " "))!=NULL);
}

int main() {
  // leggere l'input_type:
  //scanf("%d",&input_type);

  // leggo il resto della riga come stringa
  //FILE *input=fopen("input.txt", "r");
  //FILE *input=fopen("input.txt", "r");
  //fgets(input_type,1,input);
  //int int_type = atoi(input_type);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  //fgets(str,MAX_N,input); // se da file, impostare la variabile <input> al file desiderato. Preferiamo utilizzare fgets invece di gets per ragioni di stabilità e generalità.

  scanf("%d", &input_type);

  for(long i=0; i<MAX_N; i++) {
    scanf("%d", &in_tree[i]);
    n = (in_tree[i] == 0)?n+1:n;
    if(n == 3) {
      n = i;
      i = MAX_N;
    }
  }
  
  // ottengo la sequenza che codifica l'albero in input (in formato input_type):
  //parse_array(in_tree,&n,str);
  int pari = 0, tmp[MAX_N], counter = 0, c = 0;

  for(int i=0; i<n && input_type == 1; i++) {
   
    if(i==0) {
      out_tree[c] = (in_tree[i] == 0)?out_tree[c]:in_tree[i]/2;
      tmp[counter] = in_tree[i];
      c++;
      counter++;
    }else{
      tmp[counter-1]--;
      //printf("-%d ", counter);
      if(counter%2 == 0) {
        //printf("%d-", in_tree[i]/2);
        out_tree[c] = in_tree[i]/2;
        c++;
      }
      if(tmp[counter-1] == 0) 
        counter--;
      if(in_tree[i] != 0) {
        
        tmp[counter] = in_tree[i];
        counter++;
      }
    }

  }
  counter=c;

  for(int i=0; i<n && input_type == 3; i++)
    if(in_tree[i]%2 == 0) {
      out_tree[counter] = in_tree[i]/2;
      counter++;
    }

  // in questo template di soluzione mi limito a ricopiare l'input in output (non sarà mai la soluzione corretta tranne che per alberi di un solo nodo):
  printf("%d ", input_type);

  for(int i=0; i<counter; i++)
    printf("%d ", out_tree[i]);
  printf("\n");
  
  return 0;
}

