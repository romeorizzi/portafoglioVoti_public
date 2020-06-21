/**
* user:  VR436823
* fname: TESTOLIN
* lname: LEONARDO
* task:  tree_transcode_disc
* score: 0.0
* date:  2019-07-30 11:05:24.523159
*/
/**
 *  Template per soluzione in c per il problema tree_transcode_disc
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define MAX_N 1000000

int n, seq[MAX_N], input_type;
int i = 0;

void print_array(int *v, int len) {
  for(int i = 0; i < len; i++)
      printf("%d ", v[i]);
  printf("\n");
}

void parse_array(int *v, int *len, char *str)
{
    char *num = strtok(str," ");
    do
    {
        v[(*len)++] = strtol(num,NULL,10);
    }
    while((num = strtok(NULL, " "))!= NULL);
}

void from1to2(int *v1,int root, int len, FILE *out)
{
    if(len>0)
    {
        for(i = root+1; i<root+len; i+=v1[i])
        {
            from1to2(v1,i,v1[i],out);
        }
        fprintf(out,"%d",v1[root]);
    }
}

int main() {
    char str[MAX_N];
    input = fopen("input.txt","r");
    output = fopen("output.txt","w");

    fscanf(input,"%d",&input_type);

    fgets(str,MAX_N,input);
    parse_array(seq,&n,str);

    fprintf(output,"2 ");
    from1to2(seq,0,n-1,output);








   /* scanf("%d", &input_type);

    // leggere la sequenza che codifica l'albero in formato input_type

    // ottenere la codifica nell'altro formato
    
    printf("%d\n", 3-input_type);

    // scrivere la nuova codifica dell'albero*/

    return 0;
}

