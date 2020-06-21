/**
* user:  VR433441
* fname: ANCONA
* lname: GIACOMO
* task:  biancaneve
* score: 0.0
* date:  2019-06-25 08:35:52.889015
*/
#include <stdio.h>

void scambio(int*, int, int);

int vicini(int*, int, int, int);


void main()
{
    int n, m;
    int * fila;
    int i, j;
    int in1, in2;
    int richiesta;

    scanf("%d %d", &n, &m);

    fila = malloc(sizeof("int")*n);
    for(i = 0; i<n; i++)
        scanf("%d", &fila[i]);

    for(i=0; i<m; i++)
    {
        scanf("%d %d %d", &richiesta, &in1, &in2);

        if(richiesta == 1)
            scambio(fila, in1-1, in2-1);
        else if(vicini(fila, n, in1,in2))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return;
}


void scambio(int* fila, int p1, int p2)
{
    int tmp;

    tmp = fila[p1];
    fila[p1] = fila[p2];
    fila[p2] = tmp;

    return;

}

int vicini(int* fila, int dimFila, int h1, int h2)
{
    int i;
    int mancano = h2-h1+1;
    short start = 0;

    for(i=0; i<dimFila; i++)
    {
        if(start)
        {
            if(!(fila[i]>=h1 && fila[i]<=h2))
            {
                if(mancano)
                    return 0;
                else
                    return 1;
            }
    
            mancano--;
        }
        else if(fila[i]>=h1 && fila[i]<=h2)
        {
            start=1;
            mancano--;
        }
    }    

    return 1;
}
