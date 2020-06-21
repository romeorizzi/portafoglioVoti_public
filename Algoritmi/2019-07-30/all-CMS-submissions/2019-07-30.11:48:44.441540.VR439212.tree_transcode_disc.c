/**
* user:  VR439212
* fname: IERVASI
* lname: MATTEO
* task:  tree_transcode_disc
* score: 0.0
* date:  2019-07-30 11:48:44.441540
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000000

int n=0, seq[MAX_N], input_type;
FILE *input;
FILE *output;

void print_array(int *v, int len) {
  for(int i = 0; i < len; i++)
      printf("%d ", v[i]);
  printf("\n");
}

void parse_array(int *v, int *len, char *str){
    char *num=strtok(str," ");
    do{
        v[++(*len)]=strtol(num,NULL,10);
    }while((num=strtok(NULL, " "))!=NULL);
}

void from1to2(int *v1, int root, int len, FILE *out){
    if(len>0){
        for(int i=root+1;i<root+len;i+=v1[i])
            from1to2(v1,i,v1[i],out);
        fprintf(out, "%d ",v1[root]);
    }
}

void from2to1(int *v1, int root, int len, FILE *out){
    
}

int main() {
    char str[MAX_N];
    input=fopen("input.txt", "r");
    output=fopen("output.txt", "w");
    
    fscanf(input, "%d", &input_type);
    
    // leggo l'array e ignoro la sua codifica
    fgets(str,MAX_N,input);
    parse_array(seq,&n,str);

    // ottenere la codifica nell'altro formato
    if(input_type){
        fprintf(output,"2 ");
        from1to2(seq,0,n-1,output);
    }else{
        fprintf(output,"1 ");
        from2to1(seq,0,n-1,output);
    }
    
    //printf("%d\n", 3-input_type);

    // scrivere la nuova codifica dell'albero

    return 0;
}

