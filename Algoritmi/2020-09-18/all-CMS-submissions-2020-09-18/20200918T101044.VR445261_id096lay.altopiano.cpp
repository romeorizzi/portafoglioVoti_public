/**
* user:  VR445261_id096lay
* fname: NICOLA
* lname: SCARABELLO
* task:  altopiano
* score: 25.0
* date:  2020-09-18 10:10:44.572788
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

const int MINIMUM = numeric_limits<int>::min();

int msb(int N) {
    int bit=-1;
    int n = N;
    while(n!=0) {
        n/=2; bit++;
    }
    if(N ^ (1<<bit) != 0) bit++;
    n = 1<<bit;
    return n;
}

vector<int> build_tree(vector<int>& percorso, int N) {
    vector<int> tree;
    queue<int> q;
    int n = msb(N);
    for(int i=n-1; i>=0; --i){
        int h = i<N?percorso[i]:MINIMUM;
        q.push(h);
        tree.push_back(h);
    }
    while(q.size()!=1) {
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

int get_max(vector<int>& tree, int id, int l, int r, int a, int b) {
    if (r <= a || l >= b)
        return MINIMUM;

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
    int N, M;
    cin >> N >> M;
    vector<int> percorso(N);
    for(int i=0; i<N; ++i) {
        cin >> percorso[i];
    }
    vector<int> altipiani(N, MINIMUM);
    for(int i=1; i<N-1;++i) {
        if(percorso[i-1]==percorso[i] && percorso[i]==percorso[i+1]) {
            altipiani[i] = percorso[i];
        }
    }
    vector<int> tree = build_tree(altipiani, N);


    int op, x, y;
    for(int i=0; i<M; ++i) {
        cin >> op >> x >> y;
        if(op == 1) {
            percorso[x]+=y;
            if(x-2>=0) {
                if(percorso[x-2]==percorso[x-1] && percorso[x-1]==percorso[x]) {
                    update(tree, 1, 0, msb(N), x-1, percorso[x-1]);
                }
                else {
                    update(tree, 1, 0, msb(N), x-1, MINIMUM);
                }
            }
            if(x-1>=0 && x+1<N) {
                if(percorso[x-1]==percorso[x] && percorso[x]==percorso[x+1]) {
                    update(tree, 1, 0, msb(N), x, percorso[x]);
                }
                else {
                    update(tree, 1, 0, msb(N), x, MINIMUM);
                }
            }
            if(x+2<N) {
                if(percorso[x]==percorso[x+1] && percorso[x+1]==percorso[x+2]) {
                    update(tree, 1, 0, msb(N), x+1, percorso[x+1]);
                }
                else {
                    update(tree, 1, 0, msb(N), x+1, MINIMUM);
                }
            }
        }
        else {
            if(percorso[x] == percorso[x+1]) x++;
            if(percorso[y] == percorso[y-1]) y--;
            int maximum = get_max(tree, 1, 0, msb(N), x, y+1);
            if(maximum == MINIMUM)
                cout << "NESSUN_ALTIPIANO" << endl;
            else

                cout << maximum << endl;
        }
    }
    return 0;
}