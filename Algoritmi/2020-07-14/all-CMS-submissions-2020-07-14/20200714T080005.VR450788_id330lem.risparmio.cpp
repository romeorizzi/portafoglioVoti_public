/**
* user:  VR450788_id330lem
* fname: LUCA
* lname: CRIVELLARO
* task:  risparmio
* score: 100.0
* date:  2020-07-14 08:00:05.805633
*/
#include<iostream>
#include<cstdio>

using namespace std;
const int MAXN = 100000;
int N, M;
int arr[MAXN];

struct node{
    int num_intervalli;
    int first;
    int last;
};

node seg[4*MAXN+1];

node combine(node n1, node n2){

    node res;
    res.num_intervalli = n1.num_intervalli + n2.num_intervalli;
    if(n1.last == 1 && n2.first == 1)
        res.num_intervalli -= 1;
    res.first = n1.first;
    res.last = n2.last;
    return res;

}


void build(int v, int tl, int tr){

    if(tl == tr){
        if(arr[tl] == 0){
            seg[v].num_intervalli = 0;
            seg[v].first = 0;
            seg[v].last = 0;
        }
        else{
            seg[v].num_intervalli = 1;
            seg[v].first = 1;
            seg[v].last = 1;
        }
    }

    else{
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2 + 1, tm+1, tr);
        seg[v] = combine(seg[v*2], seg[v*2+1]);
    }
}

node sum(int v, int tl, int tr, int l, int r){
    
    if(l > r){
        node res;
        res.num_intervalli = 0;
        res.last = 0;
        res.first = 0;
        return res;
    }
    if(l == tl && r == tr)
        return seg[v];
    int tm = (tl + tr) / 2;
    return combine(sum(v*2, tl, tm, l, min(r, tm)),
                sum(v*2+1, tm+1, tr, max(l, tm+1),r));
}


void update(int v, int tl, int tr, int pos, int new_val){
    if(tl == tr){
        if(new_val == 1){
            seg[v].num_intervalli = 1;
            seg[v].first = 1;
            seg[v].last = 1;
        }
        else{
            seg[v].num_intervalli = 0;
            seg[v].first = 0;
            seg[v].last = 0;
        }
    }
    else{
        int tm = (tl + tr) / 2;
        if(pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        seg[v] = combine(seg[v*2], seg[v*2+1]);

        
    }
}


int main(){


    #ifdef EVAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> N >> M;
    

    build(1, 0, N-1);
    
    int type;
    int i, j;
    while(M--){
        cin >> type;
        if(type == 1){
            cin >> i;
            int new_val = 1 - arr[i];
            arr[i] = new_val;
            update(1, 0, N-1, i, new_val);

        }
        else{
            //query
            cin >> i >> j;
            node res = sum(1,0, N-1, i, j);
            cout << res.num_intervalli << endl;            
        }
        /*
        ///stampa
        for(int i = 0; i < N; i++){
            cout << arr[i] << " ";
        }
        cout << endl;

        for(int i = 1; i < 4*N+1; i++){
            cout << seg[i].num_intervalli << " ";
        }
        cout << endl;
        ///
        */
    }


}