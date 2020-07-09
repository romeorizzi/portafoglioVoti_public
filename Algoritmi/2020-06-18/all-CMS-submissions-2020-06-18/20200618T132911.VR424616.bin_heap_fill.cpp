/**
* user:  VR424616
* fname: CASTIGLIONI
* lname: ALESSANDRA
* task:  bin_heap_fill
* score: 1.0
* date:  2020-06-18 13:29:11.876855
*/
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

static FILE *file;
static int n;
static int val;

int main(){
    
    #ifdef EVAL
    file = fopen("input.txt", "r");
	#else
  	file = stdin;
	#endif
int o;
    fscanf(file, "%i", &n);
    fscanf(file, "%i", &o);

    int a[n];
    int c[n];
    int b[n];

     for(int i=0;i<n;i++)
    {
        
        fscanf(file, "%i", &val);
        a[i]=val;
        

    }
    for(int i=0;i<n;i++)
    {
        fscanf(file, "%i", &val);
        b[i]=val;

    }
    for(int i=0;i<n;i++)
    {
        fscanf(file, "%i", &val);
        c[i]=val;
    }

    #ifdef EVAL
    file = fopen("output.txt", "w");
	#else
    file = stdout;
	#endif
   bool res=true;

    for(int i=0;i<n;i++){
        if((a[i]<=b[i] || b[i]<=c[i]) && (b[i]!=0 && c[i]!=0 && c[i]!=0)  )
           res=false;
        
        
           
    }




    
    if (res)
    fprintf(file, "1");
    else
    fprintf(file, "0");

    return 0;
}