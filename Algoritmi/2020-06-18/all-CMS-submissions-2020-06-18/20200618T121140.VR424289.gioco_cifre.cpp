/**
* user:  VR424289
* fname: BRUNONE
* lname: STEFANO
* task:  gioco_cifre
* score: 100.0
* date:  2020-06-18 12:11:40.427608
*/
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

static FILE *file;

int main(){
    
    int n;
    #ifdef EVAL
    file = fopen("input.txt", "r");
	#else
  	file = stdin;
	#endif

    fscanf(file, "%d", &n);

    long long int r=n%10;

    #ifdef EVAL
    file = fopen("output.txt", "w");
	#else
    file = stdout;
	#endif

     if(r==0){
      
      fprintf(file, "0");
    }
    else{
        fprintf(file, "1 %lld", r);
    }


    
   
    //fprintf(file, "1 %lld", r);

    return 0;
}