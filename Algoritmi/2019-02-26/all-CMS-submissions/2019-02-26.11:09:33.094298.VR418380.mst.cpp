/**
* user:  VR418380
* fname: CRUCIANI
* lname: FEDERICA
* task:  mst
* score: 0.0
* date:  2019-02-26 11:09:33.094298
*/
/* funzione che ritorna l'mst*/
/*
bool compare_arco(const arco& a, const arco& b)
{
    return (a.peso, b.peso);
}
*/
int find(int v, int[] rep)
{
    if(rep[v] == v)
    {
        return v;
    }
    else
    {
        return rep[v] = find(rep[v], rep);
    }
}

int mst(int N, int M, int A[], int B[], int P[], int C[], int D[])
{
    struct arco
    {
        int nodo1;
        int nodo2;
        int peso;
    };
    
    int rep[N+1];
    arco archi[M];
    arco albero[N-1];

    for(int i = 0; i<M;i++)
    {
        archi[i].nodo1 = A[i];
        archi[i].nodo2 = B[i];
        archi[i].peso = P[i]; 
    }

    sort(archi, archi+M, compare_arco);
    // ordina gli archi per peso crescente
    
    for(int i = 0; i< N; i++)
    {
        rep[i] = i;
    }

    int opt_val = 0; 
    int opt_card = 0;

    for(int j = 0; j < M; j++)
    {
        int repA = find(archi[j].nodo1,rep);
        int repB = find(archi[j].nodo2, rep);
        if(repA!=repB)
        {
            albero[opt_card++] = archi[j];
            opt_val += archi[j].peso;
            rep[repA] = repB;
        }
    }
    return opt_val;
}
