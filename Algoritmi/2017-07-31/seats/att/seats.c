#include <stdio.h>
#include <assert.h>

#define MAXQ 100000

int experiment(int N, int Q, char T[], int K[]) {
    // insert your code here
    return 42;
}

char T[MAXQ];
int K[MAXQ];

int main() {
    FILE *fr, *fw;
    int N, Q, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &N, &Q));
    for(i=0; i<Q; i++) {
        assert(1 == fscanf(fr, " %c", &T[i]));
        assert(1 == fscanf(fr, " %d", &K[i]));
    }

    fprintf(fw, "%d\n", experiment(N, Q, T, K));
    fclose(fr);
    fclose(fw);
    return 0;
}
