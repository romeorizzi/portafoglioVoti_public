/**
* user:  VR424616_id163zjd
* fname: ALESSANDRA
* lname: CASTIGLIONI
* task:  risparmio
* score: 23.0
* date:  2020-07-14 09:46:13.964016
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

static FILE *file;
static long long int N;
static long long int M;
static int op;
static int stanza;
static int i1, i2;
static vector<int> luci;
static vector<int> op2;


void stampa();


/*void stampa(long long int numero){
    for (int i=0; i<N; i++){
        fprintf(file, "%d\n", array[i]);
    }
    exit(0);
}*/

int main(){

  bool accese=false;
  int count;

#ifdef EVAL
  file = fopen("input.txt", "r");
#else
  file = stdin;
#endif

  assert(fscanf(file, "%lld %lld", &N, &M)==2);
  
  //resize a N il vettore luci
  luci.resize(N);
  op2.resize(M);
  int c=0;

  //inizializzazione a spente (0) di tutte le luci
  for (int i=0; i<N; i++){
    luci[i]=0;
  }
    
  //itero per scoprire le azioni da svolgere e le svolgo
  for (int j=0; j<M; j++){
      assert(fscanf(file, "%d", &op)==1);

      switch (op)
      {
      case 1:
        //leggo la stanza in cui cambiare la luce
        assert(fscanf(file, "%d", &stanza)==1);
        //accendo/spengo la luce
        if (luci[stanza]==0) luci[stanza]=1;
        else if(luci[stanza]==1) luci[stanza]=0;
        
        /* prova stampa
        for (int i=0; i<N; i++){
            cout << luci[i] << endl;
        }*/

        break;

      case 2:
        //leggo che intervallo controllare
        count=0;
        accese=false;
        assert(fscanf(file, "%d %d", &i1, &i2)==2);
        //itero sulle stanze nell'intervallo dato
        for(int i=i1; i<=i2; i++){
            //se non avevo iniziato un intervallo e trovo una luce accesa, ho un nuovo intervallo
            if(!accese && luci[i]==1){
                count+=1;
                accese=true;
            }
            //se ero già in un intervallo acceso e trovo una luce spenta, finisco l'intervallo
            else if(accese && luci[i]==0){
                accese=false;
            }
        }
        /* prova stampa
        cout << i1 << i2 << count << endl;*/

        op2[c] = count;
        c+=1;
    
        break;

      default:
        break;
      }
  }

  fclose(file);

#ifdef EVAL
  file = fopen("output.txt", "w");
#else
  file = stdout;
#endif

  //stampa risultato;
  op2.resize(c);
  for(int i=0; i<c; i++){
    fprintf(file, "%d\n", op2[i]);
  }

  fclose(file);
}