/**
* user:  VR439238
* fname: BENINI
* lname: ANDREA
* task:  tree_transcode_disc
* score: 10.0
* date:  2019-07-30 11:40:43.539811
*/
#include <stdio.h>
#include <stdlib.h>

int N, i, j, dim;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N);
    if(N == 1) {
        scanf("%d", &dim);
        int tree[dim];
        int tmp[dim];
        tree[0] = dim;
        for(i=1; i<dim; i++) {
            scanf("%d", &tree[i]);
        }

        printf("%d ", 2);

        long long counter = 0;
        j = 0;
        for(i=0; i<dim; i++) {
            if(tree[i] == 1) {
                //counter++;
                //printf("1 ");
                /*while(tmp[j]<=counter && j>=0) {
                    print("%d ", tmp[j]);
                    j--;
                }*/
            }
        }

        for(i=0; i<dim; i++) {
            printf("%d ", i+1);
        }
    }



    return 0;
}