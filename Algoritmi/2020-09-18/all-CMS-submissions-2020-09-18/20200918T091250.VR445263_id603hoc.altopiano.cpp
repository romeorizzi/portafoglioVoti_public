/**
* user:  VR445263_id603hoc
* fname: MARCO
* lname: PEGORARO
* task:  altopiano
* score: 26.0
* date:  2020-09-18 09:12:50.742111
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

struct node { //num_max,val_dx,lunghezza_dx, val_sx,lunghezza_sx
	int n,dx,l_dx,sx,l_sx;
};

void init_segTree(int a[], int v, int tl, int tr, node t[]){
  if (tl == tr) {
      // salvo valore
        t[v].dx = a[tl];
        t[v].l_dx =1;
        t[v].sx =  a[tl];
        t[v].l_sx =1;
        t[v].n = -INF;
  } else {
    int tm = (tl + tr) / 2;
    init_segTree(a,v+1, tl, tm, t);
    init_segTree(a,v+2*(tm-tl+1), tm+1, tr, t);

    t[v].n = max(t[v+1].n,t[v+2*(tm-tl+1)].n);
    t[v].sx = t[v+1].sx;
    t[v].l_sx = t[v+1].l_sx;
    t[v].dx = t[v+2*(tm-tl+1)].dx;
    t[v].l_dx = t[v+2*(tm-tl+1)].l_dx;

    if(t[v+1].dx == t[v+2*(tm-tl+1)].sx){ // intervalli contigui
        if(t[v+1].l_dx + t[v+2*(tm-tl+1)].l_sx >= 3){ // metto nuovo massimo
            t[v].n = max(t[v].n,t[v+1].dx);
        }
        // confini sono lo stesso intervallo
        if(tm + t[v+2*(tm-tl+1)].l_sx == tr){ // aggiorno confine dx
            t[v].l_dx= t[v+1].l_dx + t[v+2*(tm-tl+1)].l_sx;
        }
        if(tl -1 + t[v+1].l_sx == tm){// aggiorno confine sx
            t[v].l_sx= t[v+1].l_dx + t[v+2*(tm-tl+1)].l_sx;
        }
    }
  }
}

void update(int v, int tl, int tr, int pos, int new_val, node t[]) {
    if (tl == tr) {
        t[v].dx = new_val;
        t[v].l_dx =1;
        t[v].sx = new_val;
        t[v].l_sx =1;
        t[v].n = -INF;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v+1, tl, tm, pos, new_val,t);
        else
            update(v+2*(tm-tl+1), tm+1, tr, pos, new_val,t);

        t[v].n = max(t[v+1].n,t[v+2*(tm-tl+1)].n);
        t[v].sx = t[v+1].sx;
        t[v].l_sx = t[v+1].l_sx;
        t[v].dx = t[v+2*(tm-tl+1)].dx;
        t[v].l_dx = t[v+2*(tm-tl+1)].l_dx;

        if(t[v+1].dx == t[v+2*(tm-tl+1)].sx){ // intervalli contigui
            if(t[v+1].l_dx + t[v+2*(tm-tl+1)].l_sx >= 3){ // metto nuovo massimo
                t[v].n = max(t[v].n,t[v+1].dx);
            }
            // confini sono lo stesso intervallo
            if(tm + t[v+2*(tm-tl+1)].l_sx == tr){ // aggiorno confine dx
                t[v].l_dx= t[v+1].l_dx + t[v+2*(tm-tl+1)].l_sx;
            }
            if(tl -1 + t[v+1].l_sx == tm){// aggiorno confine sx
                t[v].l_sx= t[v+1].l_dx + t[v+2*(tm-tl+1)].l_sx;
            }
        }
    }
}

node query(int v, int tl, int tr, int l, int r, node t[]) {
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    if(l> min(r, tm))
        return query(v+2*(tm-tl+1), tm+1, tr, max(l, tm+1), r, t); // sottoalbero dx
    else if(max(l, tm+1)> r)
        return query(v+1, tl, tm, l, min(r, tm), t); // sottoalbero sx

    node n1=query(v+1, tl, tm, l, min(r, tm), t); // sottoalbero sx
    node n2= query(v+2*(tm-tl+1), tm+1, tr, max(l, tm+1), r, t); // sottoalbero dx
    
    node nt;
    nt.n = max(n1.n,n2.n);
    nt.sx = n1.sx;
    nt.l_sx = n1.l_sx;
    nt.dx = n2.dx;
    nt.l_dx = n2.l_dx;

    if(n1.dx == n2.sx){ // intervalli contigui
        if(n1.l_dx + n2.l_sx >= 3){ // metto nuovo massimo
            nt.n = max(nt.n,n1.dx);
        }
        // confini sono lo stesso intervallo
        if(tm + n2.l_sx == tr){ // aggiorno confine dx
            nt.l_dx= n1.l_dx + n2.l_sx;
        }
        if(tl -1 + n1.l_sx == tm){// aggiorno confine sx
            nt.l_sx= n1.l_dx + n2.l_sx;
        }
    }
    return nt;
}

int main() {
  int N,Q;
  scanf("%d%d",&N,&Q);

  int u,v,w;
  int vals[N];
  for(int i=0; i<N; i++){
    scanf("%d", &v);
    vals[i] = v;
  }

  // costruzione del segment_tree
  node segtree[2*N];
  init_segTree(vals,0,0,N-1, segtree);

  // query - update
  node nt;
  while(Q--){
      scanf("%d",&u);
      if(u==1){ //update 
        scanf("%d%d",&v,&w); 
        vals[v]=w;
        update(0,0,N-1,v,w,segtree);
      }else{ // query
        scanf("%d%d",&v,&w); // limiti
        if(v<0) v=0;
        if(w>N-1) w=N-1;
        nt = query(0,0,N-1,v,w,segtree);
        if(nt.n == -INF)
            printf("NESSUN_ALTOPIANO\n");
        else
            printf("%d\n",nt.n);
      }
  }
  
  return 0;
}
