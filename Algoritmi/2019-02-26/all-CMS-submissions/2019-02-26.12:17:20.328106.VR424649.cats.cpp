/**
* user:  VR424649
* fname: ERBISTI
* lname: ANDREA
* task:  cats
* score: 0.0
* date:  2019-02-26 12:17:20.328106
*/
/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 1000

// input data
int Nm, Nf;
int M[MAXN], F[MAXN];
int diff[MAXN][MAXN];
int used_M[MAXN];
int used_F[MAXN];

int sum_diff_F(int i){
    int m, max = 0;

    for(int j=i; j<Nm; j++){
	    if(used_M[j] == 0 && used_F[i] == 0){ 
          used_M[j] = 1;
          used_F[i] = 1;
          if(i == Nf-1){
	        if(max < diff[j][i]){
	            max= diff[j][i];
            }
          }
          else{ 
            //printf("Sono dentro per%d %d\n", i, j);
            int parz = diff[j][i] + sum_diff_F(i+1);
            if(parz > max){
                max = parz;
            }

	      }
          used_M[j] = 0;
          used_F[i] = 0;
        }
	}

    return max;
}

int sum_diff(int i){
    int f, max = 0;

        
    for(int j=i; j<Nf; j++){
	    if(used_M[i] == 0 && used_F[j] == 0){ 
          used_M[i] = 1;
          used_F[j] = 1;
          if(i == Nm-1){
            //printf("Sono dentro per%d %d\n", i, j);
            if(max < diff[i][j])
                max = diff[i][j];
            }
          else{ 
            //printf("Sono dentro per%d %d\n", i, j);
            int parz = diff[i][j] + sum_diff(i+1);
            //if(i==0)
                //printf("Max[%d] = %d\n", j, parz);
            if(parz > max){
                max = parz;
            }

	      }
          used_M[i] = 0;
          used_F[j] = 0;
        }

    }

    return max;
}
int main() {
//  uncomment the following lines if you want to read/write from files
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &Nm, &Nf));
    for(int i=0; i<Nm; i++)
        assert(1 == scanf("%d", &M[i]));
    for(int i=0; i<Nf; i++)
        assert(1 == scanf("%d", &F[i]));


    for(int i=0; i<Nm; i++){
      for(int j=0; j<Nf; j++){
	    if(M[i]>=F[j])
	      diff[i][j] = M[i]- F[j];
        else
	      diff[i][j] = F[j]- M[i];
      }
      //printf("\n");
    }
    int somma = 0;
    int parz = 0;
    if(Nm<=Nf){

	  somma =  sum_diff(0);

    }
   if(Nm>Nf){

	    somma = sum_diff_F(0);
    }



    printf("%d\n", somma);
    return 0;
}
