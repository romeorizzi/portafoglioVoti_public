/**
* user:  VR439238
* fname: BENINI
* lname: ANDREA
* task:  tree_transcode_disc
* score: 10.0
* date:  2019-07-30 11:50:39.627537
*/
#include <stdio.h>
#include <stdlib.h>

int N, i, j, dim, max=0;

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

        

        for(i=0; i<dim; i++) {
            printf("%d ", i+1);
        }
    } else if(N == 2) {
        int tmp;
        while(scanf("%d", &tmp)) {
            if(max<tmp) {
                max=tmp;
            }
        }

        printf("%d ", 1);
        for(i=max; i>0; i--) {
            printf("%d ", i);
        }
    }



    return 0;
}