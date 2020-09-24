/**
* user:  VR451060_id716xls
* fname: NICHOLAS
* lname: CARON
* task:  altopiano
* score: 100.0
* date:  2020-09-18 12:32:03.568739
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>


using namespace std;


const int MINIMISSIMO = numeric_limits<int>::min();


int msb(int N) {
    int chip=-1;
    int n = N;
    while(n!=0) {
        n/=2; chip++;
    }
    if(N ^ (1<<chip) != 0) chip++;
    n = 1<<chip;
    return n;
}



vector<int> build_tree(vector<int>& viaggio, int N) {
    vector<int> tree;
    queue<int> q;
    int n = msb(N);
    for(int i=n-1; i>=0; --i){
        int h = i<N?viaggio[i]:MINIMISSIMO;
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
        return MINIMISSIMO;

    if (l >= a && r <= b)
        return tree[id-1];

    int medio = (l + r) / 2;

    return std::max(
        get_max(tree, 2 * id, l, medio, a, b),
        get_max(tree, 2 * id + 1, medio, r, a, b)
    );
}

void update(vector<int>& tree, int id, int l, int r, int z, int v) {
    if(r <= z || l > z)
        return;

    if(r > l+1) {
        int medio = (l + r) / 2;

        update(tree, 2 * id, l, medio, z, v);
        update(tree, 2 * id + 1, medio, r, z, v);

        tree[id-1] = std::max(
            tree[2 * id-1],
            tree[2 * id]
        );
    }
    else {
        tree[id-1] = v;
    }
}




int main() {
    int N, M;
    cin >> N >> M;
    vector<int> viaggio(N);
    for(int i=0; i<N; ++i) {
        cin >> viaggio[i];
    }
    vector<int> plateau(N, MINIMISSIMO);
    for(int i=1; i<N-1;++i) {
        if(viaggio[i-1]==viaggio[i] && viaggio[i]==viaggio[i+1]) {
            plateau[i] = viaggio[i];
        }
    }
    vector<int> tree = build_tree(plateau, N);


    int op, z, v;
    for(int i=0; i<M; ++i) {
        cin >> op >> z >> v;
        if(op == 1) {
            viaggio[z]+=v;
            if(z-2>=0) {
                if(viaggio[z-2]==viaggio[z-1] && viaggio[z-1]==viaggio[z]) {
                    update(tree, 1, 0, msb(N), z-1, viaggio[z-1]);
                }
                else {
                    update(tree, 1, 0, msb(N), z-1, MINIMISSIMO);
                }
            }
            if(z-1>=0 && z+1<N) {
                if(viaggio[z-1]==viaggio[z] && viaggio[z]==viaggio[z+1]) {
                    update(tree, 1, 0, msb(N), z, viaggio[z]);
                }
                else {
                    update(tree, 1, 0, msb(N), z, MINIMISSIMO);
                }
            }
            if(z+2<N) {
                if(viaggio[z]==viaggio[z+1] && viaggio[z+1]==viaggio[z+2]) {
                    update(tree, 1, 0, msb(N), z+1, viaggio[z+1]);
                }
                else {
                    update(tree, 1, 0, msb(N), z+1, MINIMISSIMO);
                }
            }
        }
        else {
            if(viaggio[z] == viaggio[z+1]) z++;
            if(viaggio[v] == viaggio[v-1]) v--;
            int maximum = get_max(tree, 1, 0, msb(N), z, v+1);
            if(maximum == MINIMISSIMO)
                cout << "NESSUN_ALTOPIANO" << endl;
            else

                cout << maximum << endl;
        }
    }
    return 0;
}
