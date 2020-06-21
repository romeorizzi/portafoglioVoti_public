/**
* user:  VR437055
* fname: CONTRO
* lname: FILIPPO
* task:  tree_transcode
* score: 0.0
* date:  2019-06-25 09:58:28.085794
*/
#include <stdio.h>
#include <algorithm>

#define MAXN 1000010

int N;
int ARR[MAXN];

void read_tree_1(int root, int depth){
    //printf("Ho %d figli e sono a profondita' %d\n", root, depth);
    int child, i=1;
    printf(" %d", depth);
    while(i < root){
        scanf("%d", &child);
        i+=child;
        //printf("\tIo sono %d, figlio %d, ne ho contati %d\n", root, child, i);
        if (child == 1){
            printf(" %d %d", depth+1, depth+1);
        } else {
            read_tree_1(child, depth+1);
        }
    }
    printf(" %d", depth);
}

void convert_tree(int min, int max, int depth){
    // printf("Guardo il sottoalbero da %d a %d e cerco le occorrenze di %d\n", min, max, depth);
    // for(int i=min; i<max; i++)
    //     printf("%d ", ARR[i]);
    // printf("\n");


    if (min >= max){
        //printf(" 1");
        return;
    }


    int inizio_sottoalbero = min;
    for (int i = min+1; i < max; i++){
        // printf("\tVedo ARR[%d]=%d\n", i, ARR[i]);
        if (ARR[i] == depth){
            // calcolo la differenza di indici e la stampo
            printf(" %d", (i - inizio_sottoalbero + 1)/2);
            //chiamata ricorsiva
            convert_tree(inizio_sottoalbero+1, i, depth+1);
            inizio_sottoalbero = i+1;
            i++;
        }
    }
}


int main(){
    int codifica;

    scanf("%d", &codifica);

    if (codifica == 1){
        // TRASFORMO IN CODIFICA 2
        int root;
        scanf("%d", &root);
        printf("%d", 2);

        read_tree_1(root, 0);

    } else {
        // TRASFORMO IN CODIFICA 1
        printf("%d", 1);
        int node = 1;
        int max_depth = 0;
        scanf("%d", &ARR[0]);
        int i=1;
        while (node != 0){
            scanf("%d", &node);
            ARR[i] = node;
            i++;
            if (node > max_depth)
                max_depth = node;
        }
        N = i;

        //primo numero è la lunghezza dell'albero
        //printf(" %d", N/2);
        convert_tree(0, N, 0);
    }

    return 0;
}