/**
* user:  VR445263_id603hoc
* fname: MARCO
* lname: PEGORARO
* task:  risparmio
* score: 100.0
* date:  2020-07-14 08:17:14.081138
*/
// soluzione per il problema risparmio
#include <iostream>     
#include <algorithm>
#include <cassert>
#include <cstdio>

#define MAXN 100000
#define MAXM 200000
#define INF 100000000

using namespace std;

struct node { //numero intervalli, indice minimo inizio intervallo, indice massimo fine intervallo
	int n,min,max;
};

// void init_segTree(bool a[], int v, int tl, int tr, node t[]){
//   if (tl == tr) {
//       if(a[tl]){
//         t[v].max = tl;
//         t[v].min = tl;
//         t[v].n = 1;
//       }
//       else{ // non ho luci accese quindi ho 0 intervalli
//         t[v].max = -1;
//         t[v].min = -1;
//         t[v].n = 0;
//       }
//   } else {
//       int tm = (tl + tr) / 2;
//       init_segTree(a, v+1, tl, tm, t);
//       init_segTree(a, v+2*(tm-tl+1), tm+1, tr, t);
//       if(t[v+1].n == 0 && t[v+2*(tm-tl+1)].n==0){ // ho 0 intervalli in entrambi
//         t[v].max = -1;
//         t[v].min = -1;
//         t[v].n = 0;
//       } else if(t[v+1].n == 0){ // ho 0 intervalli solo nel primo
//         t[v].max = t[v+2*(tm-tl+1)].max;
//         t[v].min = t[v+2*(tm-tl+1)].min;
//         t[v].n = t[v+2*(tm-tl+1)].n;
//       }else if(t[v+2*(tm-tl+1)].n == 0){ // ho 0 intervalli solo nel secondo
//         t[v].max = t[v+1].max;
//         t[v].min = t[v+1].min;
//         t[v].n = t[v+1].n;
//       }else{ // entrambi hanno intervalli
//         t[v].max = t[v+2*(tm-tl+1)].max;
//         t[v].min = t[v+1].min;
//         t[v].n = t[v+1].n + t[v+2*(tm-tl+1)].n;
//         if(t[v+1].max + 1 == t[v+2*(tm-tl+1)].min) // ho itervalli consecutivi
//             t[v].n = t[v].n - 1 ;
//       }
//   }
// }

void init_segTree( int v, int tl, int tr, node t[]){
  if (tl == tr) {
      // non ho luci accese quindi ho 0 intervalli
        t[v].max = -1;
        t[v].min = -1;
        t[v].n = 0;
  } else {
    int tm = (tl + tr) / 2;
    init_segTree(v+1, tl, tm, t);
    init_segTree(v+2*(tm-tl+1), tm+1, tr, t);
    // ho 0 intervalli inizialmente
    t[v].max = -1;
    t[v].min = -1;
    t[v].n = 0;
  }
}

void update(int v, int tl, int tr, int pos, node t[]) {
    if (tl == tr) {
        t[v].n = 1 - t[v].n; //inverto luce

        if(t[v].n == 1){ // ho luce con 1 intervallo
            t[v].max = tl;
            t[v].min = tl;
        }
        // else{ // non ho luci accese quindi ho 0 intervalli
        //     t[v].max = -1;
        //     t[v].min = -1;
        //     t[v].n = 0;
        // }
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) // ramo sinistro
            update(v+1, tl, tm, pos, t);
        else // ramo destro
            update(v+2*(tm-tl+1), tm+1, tr, pos, t);
        // aggiusto valori nodo
        if(t[v+1].n == 0 && t[v+2*(tm-tl+1)].n==0){ // ho 0 intervalli in entrambi
            t[v].max = -1;
            t[v].min = -1;
            t[v].n = 0;
        } else if(t[v+1].n == 0){ // ho 0 intervalli solo nel primo
            t[v].max = t[v+2*(tm-tl+1)].max;
            t[v].min = t[v+2*(tm-tl+1)].min;
            t[v].n = t[v+2*(tm-tl+1)].n;
        }else if(t[v+2*(tm-tl+1)].n == 0){ // ho 0 intervalli solo nel secondo
            t[v].max = t[v+1].max;
            t[v].min = t[v+1].min;
            t[v].n = t[v+1].n;
        }else{ // entrambi hanno intervalli
            t[v].max = t[v+2*(tm-tl+1)].max;
            t[v].min = t[v+1].min;
            t[v].n = t[v+1].n + t[v+2*(tm-tl+1)].n;
            if(t[v+1].max + 1 == t[v+2*(tm-tl+1)].min) // ho itervalli consecutivi
                t[v].n = t[v].n - 1 ;
        }
    }
}

node query(int v, int tl, int tr, int l, int r, node t[]) {
    if (l > r) {
        return node{.n=0, .min=-1, .max=-1};
    }
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    node nsx=query(v+1, tl, tm, l, min(r, tm), t); // sottoalbero sx
    node ndx= query(v+2*(tm-tl+1), tm+1, tr, max(l, tm+1), r, t); // sottoalbero dx
    
    // aggiusto valori nodo
    if(nsx.n == 0 && ndx.n==0){ // ho 0 intervalli in entrambi
        return node{.n=0, .min=-1, .max=-1};
    } else if(nsx.n == 0){ // ho 0 intervalli solo nel primo
        return ndx;
    }else if(ndx.n == 0){ // ho 0 intervalli solo nel secondo
        return nsx;
    }else{ // entrambi hanno intervalli
        if(nsx.max + 1 == ndx.min) // ho itervalli consecutivi
            return node{.n=nsx.n+ndx.n-1, .min=nsx.min, .max=ndx.max}; 
        else 
            return node{.n=nsx.n+ndx.n, .min=nsx.min, .max=ndx.max}; 
    }    
  
}

int main() {
  int N,Q;
  scanf("%d%d",&N,&Q);

//   bool luci[N];
  int u,v,w;
  // inizializzo a tutto spento
//   for(int i=0; i<N; i++){
//     luci[i] = false;
//   }

  // costruzioe del segment_tree
  node segtree[2*N];
  init_segTree(0,0,N-1, segtree);

  // query - update
  node nt;
  while(Q--){
      scanf("%d",&u);
      if(u==1){ //update 
        scanf("%d",&v); // indice interruttore
        // luci[v] = ! luci[v];
        update(0,0,N-1,v,segtree);
      }else{ // query
        scanf("%d%d",&v,&w); // limiti
        if(v<0) v=0;
        if(w>N-1) w=N-1;
        nt = query(0,0,N-1,v,w,segtree);
        printf("%d\n",nt.n);
      }
  }
  
  return 0;
}
