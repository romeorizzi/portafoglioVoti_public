/**
* user:  VR439212
* fname: IERVASI
* lname: MATTEO
* task:  Prob1_tree_split_out
* score: 0.0
* date:  2019-09-04 11:24:14.586351
*/
/**
 *  Template per soluzione in c per il problema tree_split_out
 *
 *  Romeo Rizzi, per l'appello di algoritmi 2019-09-04
 *
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000000

int n = 0, input_type, index=1;
char str[MAX_N];
int in_tree[MAX_N], out_tree[MAX_N];

void parse_array(int *v, int *len, char *str){
    char *num=strtok(str," ");
    do{
        //v[(*len)++]=strtol(num,NULL,10);
        v[(*len)++]=atoi(num);
    }while((num=strtok(NULL, " "))!=NULL);
}

void dfs1(int *in, int *out, int *start, int len, int level){
  //printf("%d %d\n",in[*start],level);
  //if(level%2==0)
    //out_tree[index++]=in[*start];
    //out_tree[index++]=level;
    //printf("%d %d - ",in[*start],level);
    printf("Node %d (length %d) at level %d has %d sons\n",in[*start],len,level,in[*start]);
  for(int i=*start;i<*start+len;i++){
    if(in[i]>0){
      ++(*start);
      printf("Starting new DFS on new root %d\n",in[i]);
      dfs1(in, out, start, in[i],level+1);
    }
  }
}

void dfs2(int *in, int *out, int *start, int len, int level){

}

void dfs3(int *in, int *out, int *len){
  out[0]=3;
  for(int i=0;i<*len;i++){
    if(in[i]%2==0)
      out[index++]=in[i]/2;
  }
  *len=index;
}

int main() {
  // leggere l'input_type:
  //scanf("%d",&input_type);

  // leggo il resto della riga come stringa
  FILE *input=fopen("input3.txt", "r");
  //FILE *input=stdin;
  fgets(str,MAX_N,input); // se da file, impostare la variabile <input> al file desiderato. Preferiamo utilizzare fgets invece di gets per ragioni di stabilità e generalità.

  // ottengo la sequenza che codifica l'albero in input (in formato input_type):
  parse_array(in_tree,&n,str);

  int start=1;

  input_type=in_tree[0];
  printf("%d ", input_type);
  if(input_type==1)
    dfs1(in_tree, out_tree,&start,1,0);
  else if(input_type==2)
    dfs2(in_tree, out_tree,&start,1,0);
  else if(input_type==3)
    dfs3(in_tree, out_tree,&n);
  else
    printf("ERRORE");
  

  for(int i=1; i<n; i++)
    printf("%d ", out_tree[i]);
  printf("\n");
  
  return 0;
}

