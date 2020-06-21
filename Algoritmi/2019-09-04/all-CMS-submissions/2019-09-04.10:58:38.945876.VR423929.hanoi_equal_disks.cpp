/**
* user:  VR423929
* fname: BRAGAGLIO
* lname: MORENO
* task:  Prob2_hanoi_equal_disks
* score: 0.0
* date:  2019-09-04 10:58:38.945876
*/
#include <cassert>
#include <cstdio>

const int BASE = 100000;
const int MAXN = 100000;

int N,T;
char pole[MAXN+1];
int nMovesMod[MAXN];
int numMoves=0;

void spostaDisco(int n, char from, char to){
    assert(pole[n]==from);
    printf("sposta il disco %d dal piolo %c al piolo %c\n", n, from, to);
    pole[n]=to;
}

void conta_spostamentiDisco(int n, char from, char to){
    assert(pole[n]==from);
    numMoves = (numMoves+1)%BASE;
    pole[n]=to;
}

char other_pole(char p1, char p2){
    return 'A'+(3-(p1-'A')-(p2-'A'));
}

void makeTowerOnPole(int n, char target_pole, void(*basicActionOnDisk)(int,char,char)){
    if(n<=0) return;
    if(pole[n]==target_pole)
        makeTowerOnPole(n-1, target_pole, basicActionOnDisk);
    else{
        char third_pole=other_pole(pole[n], target_pole);
        makeTowerOnPole(n-1,third_pole,basicActionOnDisk);
        (*basicActionOnDisk)(n,pole[n], target_pole);
        if(basicActionOnDisk==&spostaDisco)
            makeTowerOnPole(n-1, target_pole, basicActionOnDisk);
        else{
            assert(basicActionOnDisk==&conta_spostamentiDisco);
            numMoves=(numMoves + nMovesMod[n-1]) %BASE;
            for(int i=n-1; i>=1; i--)
                pole[i] = target_pole;
        }
    }
}




int main(){
    #ifdef EVAL
        assert( freopen("input.txt", "r", stdin));
        assert( freopen("output.txt", "w", stdout));
    #endif
        scanf("%d%d", &T, &N);
        for(int i=1; i<=N; i++){
            do{
                scanf("%c", &pole[i]);
            }while( pole[i] <= 'A' || pole[i] > 'C');
        }
        
        if(N<=10)
        //if(T!=0)
            makeTowerOnPole(N, 'A', &spostaDisco);
        else{
            for(int i=1; i<=N; i++)
                nMovesMod[i] = ((nMovesMod[i-1] + 1) % BASE + nMovesMod[i-1]) %BASE;
            makeTowerOnPole(N, 'A', &conta_spostamentiDisco);
            printf("%d", numMoves);
        }
        printf("\n");

        return 0;
}