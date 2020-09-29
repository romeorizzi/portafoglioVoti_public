/**
* user:  VR424289_id308myt
* fname: STEFANO
* lname: BRUNONE
* task:  risparmio
* score: 23.0
* date:  2020-07-14 12:18:54.930512
*/

#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

static FILE *file;

int main(){

  int count;
  int op;
  bool on=false;

  int p;
  int i1, i2;

  long long int n,m;

#ifdef EVAL
  file = fopen("input.txt", "r");
#else
  file = stdin;
#endif

  fscanf(file, "%lld %lld", &n, &m);


  vector<int> l(n,0);
  vector<int> res(m);
  int resc=0;


  for (int j=0; j<m; j++){
      fscanf(file, "%d", &op);

        if(op==1){
        fscanf(file, "%d", &p);

        if (l[p]==1) 
          l[p]=0;
        else 
          if(l[p]==0) 
            l[p]=1;
        }
        else{

          count=0;
          on=false;

          fscanf(file, "%d %d", &i1, &i2);

          for(int i=i1; i<=i2; i++){
              if(!on && l[i]==1){
                  on=true;
                  count+=1;
              }
              else if(on && l[i]==0){
                  on=false;
              }
          }
          res[resc] = count;
          resc+=1;
       
        }
      }
  

  fclose(file);

#ifdef EVAL
  file = fopen("output.txt", "w");
#else
  file = stdout;
#endif

  for(int i=0; i<resc; i++){
    fprintf(file, "%d\n", res[i]);
  }

  fclose(file);
}