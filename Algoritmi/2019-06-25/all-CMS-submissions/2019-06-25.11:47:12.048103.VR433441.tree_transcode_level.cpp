/**
* user:  VR433441
* fname: ANCONA
* lname: GIACOMO
* task:  tree_transcode_level
* score: 50.0
* date:  2019-06-25 11:47:12.048103
*/
#include<stdio.h>

int ttl1(FILE*,FILE*, int);

void ttl2(FILE*, FILE*);

int main()
{
    FILE* in;
    FILE* out;
    int tipo;

    in= fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    
    fscanf(in, "%d", &tipo);

    if(tipo = 1)
    {
        fprintf(out, "2 ");
        ttl1(in, out, 0);
    }

    else
    {
        fprintf(out, "1 ");
        ttl2(in, out);
    }
    fclose(in);
    fclose(out);

    return 0;
}

int ttl1(FILE* in,FILE* out, int lvl)
{
    int node;
    int sub;

    if(feof(in))
        return 0;

    fprintf(out, "%d ", lvl);

    fscanf(in, "%d", &node);

    sub = node-1;

    while(sub>0)
        sub = sub - ttl1(in, out, lvl+1);

    fprintf(out, "%d ", lvl);

    return node;
    
}

void ttl2(FILE* in, FILE* out)
{
    return;
}
