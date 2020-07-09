/**
* user:  VR424289
* fname: BRUNONE
* lname: STEFANO
* task:  bin_heap_fill
* score: 0.0
* date:  2020-06-18 13:01:30.693542
*/
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

static FILE *file;

int main(){
    
    int n;
    int val;
    int a[n];
    int c[n];
    int b[n];
    #ifdef EVAL
    file = fopen("input.txt", "r");
	#else
  	file = stdin;
	#endif
int o;
    fscanf(file, "%d", &n);
    fscanf(file, "%d", &o);

     for(int i=0;i<n;i++)
    {
        
        fscanf(file, "%d", &val);
        a[i]=val;
        

    }
    for(int i=0;i<n;i++)
    {
        fscanf(file, "%d", &val);
        b[i]=val;

    }
    for(int i=0;i<n;i++)
    {
        fscanf(file, "%d", &val);
        c[i]=val;

    }

    #ifdef EVAL
    file = fopen("output.txt", "w");
	#else
    file = stdout;
	#endif
   bool res=true;

    for(int i=0;i<n;i++){
        if(a[i]<=b[i] || b[i]<=c[i])
            res=false;
    }




    
    if (res)
    fprintf(file, "1");
    else
    fprintf(file, "0");

    return 0;
}