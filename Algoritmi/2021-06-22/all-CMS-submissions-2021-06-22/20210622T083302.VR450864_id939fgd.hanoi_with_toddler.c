/**
* user:  VR450864_id939fgd
* fname: ANDREA
* lname: RANCAN
* task:  hanoi_with_toddler
* score: 30.0
* date:  2021-06-22 08:33:02.885887
*/
#include <stdio.h>
#include <assert.h>

const int BASE = 1000000;

char pole[10000];

int nMovesMod[10000];

int numMoves = 0;

void spostaDisco(int n, char from, char to) {
    assert(pole[n]==from);
    printf("Muovi il disco %d dal piolo %c al piolo %c\n", n, from, to);
    pole[n] = to;
}

void conta_spostamentiDisco(int n, char from, char to) {
    assert(pole[n]==from);
    numMoves = (numMoves + 1) % BASE;
    pole[n] = to;
}

char other_pole(char p1, char p2) {
    return 'A'+ (3 - (p1-'A') - (p2-'A') );
}

void makeTowerOnPole(int n, char target_pole, void (*basicActionOnDisk) (int,char,char) ) {
    if(n <= 0) return;
    if(pole[n] == target_pole)
        makeTowerOnPole(n-1, target_pole, basicActionOnDisk);
    else {
        char third_pole = other_pole(pole[n], target_pole);
        makeTowerOnPole(n-1, third_pole, basicActionOnDisk);
        (*basicActionOnDisk)(n, pole[n], target_pole);
        if(basicActionOnDisk==&spostaDisco)
            makeTowerOnPole(n-1, target_pole, basicActionOnDisk);
        else {
            assert(basicActionOnDisk==&conta_spostamentiDisco);
            numMoves = (numMoves + nMovesMod[n-1]) % BASE;
            for(int i = n-1; i >= 1; i--)
            pole[i] = target_pole;
        }
    }
}



int main(void){
    int N, tipo;
    int i;

    scanf("%i %i", &tipo, &N);


    long long int numero_mosse = 1;
    for(i = 1; i<=N; i++){
        do
           scanf("%c", &pole[i]);
        while( pole[i] < 'A' || pole[i] > 'C');
    }
    if(tipo == 0){
        for(int i = 1; i<= N; i++)
          nMovesMod[i] = ( (nMovesMod[i-1] + 1) % BASE + nMovesMod[i-1]) % BASE;
        makeTowerOnPole(N, 'A', &conta_spostamentiDisco);
        printf("%d\n", numMoves);
    }
    else{
         makeTowerOnPole(N, 'A', &spostaDisco);
    }


}
