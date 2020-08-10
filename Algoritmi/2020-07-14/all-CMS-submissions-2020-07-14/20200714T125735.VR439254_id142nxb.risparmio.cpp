/**
* user:  VR439254_id142nxb
* fname: ANDREA
* lname: TOAIARI
* task:  risparmio
* score: 5.0
* date:  2020-07-14 12:57:35.087088
*/
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

#define MAXN 100000
#define MAXM 200000


struct node {
    int sx;
    int dx;
    int inter;
};

node segtree[ 4 * MAXN +1 ];

int N, M;
int action;
int a1, a2;

node combine(node l, node r) {
    node res;
    res.sx = l.sx;
    res.dx = r.dx;
    if (l.dx == r.sx)
        res.inter = l.inter;
    else
        res.inter = l.inter + r.inter ;
    return res;
}

void build(int n, int l, int r){
    if(l == r){
        segtree[n].sx = 0;
        segtree[n].dx = 0;
        segtree[n].inter = 0;
    }
    else
    {
        build(2*n, l, (l+r)/2);
        build(2*n+1, (l+r)/2 +1, r);
        segtree[n] = combine(segtree[n*2], segtree[n*2+1]);
    }
}

void update(int n, int l, int r, int pos){
    if (l == r){
        segtree[n].dx = 1 - segtree[n].dx;
        segtree[n].sx = 1 - segtree[n].sx;
        segtree[n].inter = 1 - segtree[n].inter;
    }
    else{
        int tm = (l+r)/2;
        if(pos <= tm)
            update(n*2, l, tm, pos);
        else
            update(n*2+1, tm+1, r, pos);
        segtree[n] = combine(segtree[n*2], segtree[n*2+1]);
    }
}

node intervals(int n, int tl, int tr, int l, int r){
    node fakenode = {0,0,0};
    if (l > r)
        return fakenode;
    if (l == tl && r == tr)
        return segtree[n];
    int tm = (tl + tr)/2;
    return combine(intervals(n*2, tl, tm, l, min(r,tm)), intervals(n*2+1, tm+1, tr, max(l, tm+1), r));    
}

void print_tree()
{
    for (int i=1; i<4*N; i++){
        cout << "-" << segtree[i].sx << ", " << segtree[i].dx << ", " << segtree[i].inter << endl;
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N >> M;
    node resp;
    
    build(1, 0, N-1);
    for (int i=0; i<M; i++){
        cin >> action;
        if (action == 1){
            cin >> a1;
            update(1, 0, N-1, a1);
            // cout << "update" << endl;
        }
        else{
            cin >> a1 >> a2;
            // cout << a1 << " " << a2 << endl;
            resp = intervals(1, 0, N-1, a1, a2);
            cout << resp.inter << endl;
        }
    }

    return 0; 

}