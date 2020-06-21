/**
* user:  VR424649
* fname: ERBISTI
* lname: ANDREA
* task:  online_budget
* score: 25.0
* date:  2019-07-30 11:03:23.062445
*/
#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
int N, B0, solution;
vector <int> X, B;

int calculate(int n){

    if(n == 1)
        return B[0] + 1;
    if(n == 2 and B[0] ==0)
        return B[1] + 1;
    if(n== 2 and B[1] == 0)
        return 2*B[0] +1;
    int solution = 0;
    if(n>1){
        int partenza = X[n-2];
        int retro = B[n-1]-X[n-2];

        int arrivo = B[n-1];
        //printf("Retro: %d  Partenza %d Arrivo %d", retro,partenza,arrivo);
        //printf("Sommo da %d a %d: ", partenza, arrivo);
        for(int i = partenza; i<=arrivo; i++){
            
            solution += i;
            if(retro>0)
                retro --;
        }
        //printf("\n");
        return solution + calculate(n-1);
   }
   return 0;
}

int main(){
#ifdef EVAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    scanf("%d", &N);
    B.resize(N);
    scanf("%d", &B[0]);
    X.resize(N);

    for(int i=0; i<N; i++){
        scanf("%d", &X[i]);
    }

    for(int i=1; i<N; i++){
        B[i] = B[i-1]+X[i-1];
    }
    int S = calculate(N);
    printf("%d", S);
    return 0;
}
