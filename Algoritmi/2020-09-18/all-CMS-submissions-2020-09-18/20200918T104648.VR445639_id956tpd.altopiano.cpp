/**
* user:  VR445639_id956tpd
* fname: ROSA
* lname: RUSSO
* task:  altopiano
* score: 100.0
* date:  2020-09-18 10:46:48.468484
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
#include <cassert>

using namespace std;

const int MIN = numeric_limits<int>::min();

int msbit(int N){ // most significant bit
    int bit = -1;
    int n = N;

    while(n != 0){
        n /= 2;
        bit++;
    }

    if(N^(1<<bit) != 0)
        bit++;

    n = 1<<bit;

    return n;
}

vector<int> build_tree(vector<int>& path, int N) {
    vector<int> tree;
    queue<int> q;
    int n = msbit(N);

    for(int i = n-1; i >= 0; --i){
        int h;
        if (i < N){
            h = path[i];
        }else{
            h = MIN;
        }

        q.push(h);
        tree.push_back(h);
    }

    while(q.size() != 1){
        int l = q.front();
        q.pop();

        int r = q.front();
        q.pop();

        int h = max(l, r);
        q.push(h);
        tree.push_back(h);
    }

    reverse(tree.begin(), tree.end());
    return tree;
}

int get_max(vector<int>& tree, int id, int l, int r, int a, int b) { // a e b estremi della camminata di Poldo
    if (r <= a || l >= b)
        return MIN;

    if (l >= a && r <= b)
        return tree[id-1];

    int mid = (l + r) / 2;

    return std::max(
        get_max(tree, 2 * id, l, mid, a, b),
        get_max(tree, 2 * id + 1, mid, r, a, b)
    );
}

void update(vector<int>& tree, int id, int l, int r, int x, int y) {
    if(r <= x || l > x)
        return;

    if(r > l+1) {
        int mid = (l + r) / 2;

        update(tree, 2 * id, l, mid, x, y);
        update(tree, 2 * id + 1, mid, r, x, y);

        tree[id-1] = std::max(
            tree[2 * id-1],
            tree[2 * id]
        );
    }
    else {
        tree[id-1] = y;
    }
}

int main() {
    int N, M; //N numero di altezze iniziali del percorso, M numero di operazioni da eseguire
    cin >> N >> M;

    vector<int> path(N);
    for(int i=0; i<N; ++i) {
        cin >> path[i];
    }

    vector<int> altipiani(N, MIN);

    for(int i=1; i<N-1;++i) {
        if(path[i-1]==path[i] && path[i]==path[i+1]) {
            altipiani[i] = path[i];
        }
    }

    vector<int> tree = build_tree(altipiani, N);


    int op, x, y; // operazione richiesta
    for(int i=0; i<M; ++i){
        cin >> op >> x >> y;
        assert(x >= 0);
        assert(x <= N-1);

        if(op == 1){ // variazione dell'altitudine di indice x e y metri
            path[x]+=y;
            if(x-2 >= 0){
                if(path[x-2]==path[x-1] && path[x-1]==path[x]) {
                    update(tree, 1, 0, msbit(N), x-1, path[x-1]);
                }
                else{
                    update(tree, 1, 0, msbit(N), x-1, MIN);
                }
            }
            if(x-1 >= 0 && x+1 < N){
                if(path[x-1]==path[x] && path[x]==path[x+1]) {
                    update(tree, 1, 0, msbit(N), x, path[x]);
                }
                else{
                    update(tree, 1, 0, msbit(N), x, MIN);
                }
            }
            if(x+2 < N){
                if(path[x]==path[x+1] && path[x+1]==path[x+2]) {
                    update(tree, 1, 0, msbit(N), x+1, path[x+1]);
                }
                else{
                    update(tree, 1, 0, msbit(N), x+1, MIN);
                }
            }
        }
        if (op == 2){ // se op == 2, x e y rappresentano l'inizio e la fine della camminata di Poldo (estremi inclusi)
            if(path[x] == path[x+1])
                x++;
            if(path[y] == path[y-1])
                y--;
            int maximum = get_max(tree, 1, 0, msbit(N), x, y+1); //altezza apiano più alto presente nel cammino

            if(maximum == MIN)
                cout << "NESSUN_ALTOPIANO" << endl;
            else
                cout << maximum << endl;
        }
    }
    return 0;
}
