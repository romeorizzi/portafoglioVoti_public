/**
* user:  VR451060_id716xls
* fname: NICHOLAS
* lname: CARON
* task:  altopiano
* score: 25.0
* date:  2020-09-18 12:16:19.036829
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

vector<int> build_tree(vector<int>& viaggio, int N) {
    vector<int> tree;
    queue<int> q;
    int n = msb(N);
    for(int i=n-1; i>=0; --i){
        int h = i<N?viaggio[i]:MINIMUM;
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

    int mezzo = (l + r) / 2;

    return std::max(
        get_max(tree, 2 * id, l, mezzo, a, b),
        get_max(tree, 2 * id + 1, mezzo, r, a, b)
    );
}

void update(vector<int>& tree, int id, int l, int r, int x, int y) {
    if(r <= x || l > x)
        return;

    if(r > l+1) {
        int mezzo = (l + r) / 2;

        update(tree, 2 * id, l, mezzo, x, y);
        update(tree, 2 * id + 1, mezzo, r, x, y);

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
    vector<int> viaggio(N);
    for(int i=0; i<N; ++i) {
        cin >> viaggio[i];
    }
    vector<int> plateau(N, MINIMUM);
    for(int i=1; i<N-1;++i) {
        if(viaggio[i-1]==viaggio[i] && viaggio[i]==viaggio[i+1]) {
            plateau[i] = viaggio[i];
        }
    }
    vector<int> tree = build_tree(plateau, N);


    int op, x, y;
    for(int i=0; i<M; ++i) {
        cin >> op >> x >> y;
        if(op == 1) {
            viaggio[x]+=y;
            if(x-2>=0) {
                if(viaggio[x-2]==viaggio[x-1] && viaggio[x-1]==viaggio[x]) {
                    update(tree, 1, 0, msb(N), x-1, viaggio[x-1]);
                }
                else {
                    update(tree, 1, 0, msb(N), x-1, MINIMUM);
                }
            }
            if(x-1>=0 && x+1<N) {
                if(viaggio[x-1]==viaggio[x] && viaggio[x]==viaggio[x+1]) {
                    update(tree, 1, 0, msb(N), x, viaggio[x]);
                }
                else {
                    update(tree, 1, 0, msb(N), x, MINIMUM);
                }
            }
            if(x+2<N) {
                if(viaggio[x]==viaggio[x+1] && viaggio[x+1]==viaggio[x+2]) {
                    update(tree, 1, 0, msb(N), x+1, viaggio[x+1]);
                }
                else {
                    update(tree, 1, 0, msb(N), x+1, MINIMUM);
                }
            }
        }
        else {
            if(viaggio[x] == viaggio[x+1]) x++;
            if(viaggio[y] == viaggio[y-1]) y--;
            int maximum = get_max(tree, 1, 0, msb(N), x, y+1);
            if(maximum == MINIMUM)
                cout << "NESSUN_PLATEAU" << endl;
            else

                cout << maximum << endl;
        }
    }
    return 0;
}
