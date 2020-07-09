/**
* user:  VR424289
* fname: BRUNONE
* lname: STEFANO
* task:  gioco_cifre
* score: 20.0
* date:  2020-06-18 12:02:39.278884
*/
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

static FILE *file;

int main(){
    
    int n;
    //int cifre[10000000]:



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
   
    fprintf(file, "1 %lld", r);

    return 0;
}