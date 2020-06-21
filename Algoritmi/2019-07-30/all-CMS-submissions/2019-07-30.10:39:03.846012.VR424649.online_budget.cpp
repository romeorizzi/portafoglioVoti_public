/**
* user:  VR424649
* fname: ERBISTI
* lname: ANDREA
* task:  online_budget
* score: 6.0
* date:  2019-07-30 10:39:03.846012
*/
#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
int N, B0, solution;
vector <int> X, B;

int calculate(int n){
    if(n == 1)
        //printf("ritorno : %d", B0+1);
        return B[0] + 1;
    int solution = 0;
    if(n>1){
        int partenza = X[n-2];
        int arrivo = B[n-1];
        //printf("Sommo da %d a %d: ", partenza, arrivo);
        for(int i = partenza; i<arrivo; i++){
            solution += i;
            //printf("%d + ", i);
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
