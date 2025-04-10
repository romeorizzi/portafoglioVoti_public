/**
* user:  VR436823
* fname: TESTOLIN
* lname: LEONARDO
* task:  online_budget
* score: 0.0
* date:  2019-07-30 11:29:03.875634
*/
/**
 *  Template per soluzione in c per il problema online_budget
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 500
#define MAX_VAL 10

int n, B0, x[MAX_N];
int j = 1;
long int decremento = 0;
int i = 0;


void print_array(int *v, int len) 
{
  for(i = 0; i < len; i++)
      printf("%d ", v[i]);
  printf("\n");
}

int main() 
{
    freopen("input1.txt","r",stdin);
    freopen("output.txt","w",stdout);


    assert(2 == scanf("%d %d",&n,&B0));
    for (i = 0; i<n; i++)
        assert(1 == scanf(" %d",&x[i]));
    
    
    
    /*scanf("%d %d", &n,&B0);
    for(i = 0; i < n; i++)
       scanf("%d", &x[i]);
    print_array(x, n);*/


    long int risp = 42;


    while (B0 >= 0)
    {
        if(B0 == 0 && n == 1) //niente soldi
        {
            decremento++;
            break;
        }
        /*if(B0 > 0 && n == 1) //niente soldi
        {
            while(j)
            {
                B0 -= decremento;
                if(B0 > 0)
                    decremento++;
                else
                {
                    decremento--;
                    break;
                }
            }
        }*/
    }
    
    printf("%ld\n", decremento);
    return 0;
}

