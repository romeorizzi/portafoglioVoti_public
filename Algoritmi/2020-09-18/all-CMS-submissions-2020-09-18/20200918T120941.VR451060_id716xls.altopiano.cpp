/**
* user:  VR451060_id716xls
* fname: NICHOLAS
* lname: CARON
* task:  altopiano
* score: 0.0
* date:  2020-09-18 12:09:41.566810
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>



using namespace std;



const int minimissimo = numeric_limits<int>::min();



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
        int h = i<N?viaggio[i]:minimissimo;
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
        return minimissimo;

    if (l >= a && r <= b)
        return tree[id-1];

    int mid = (l + r) / 2;

    return std::max(
        get_max(tree, 2 * id, l, mid, a, b),
        get_max(tree, 2 * id + 1, mid, r, a, b)
    );
}




void update(vector<int>& tree, int id, int l, int r, int z, int c) {
    if(r <= z || l > z)
        return;

    if(r > l+1) {
        int mid = (l + r) / 2;

        update(tree, 2 * id, l, mid, z, c);
        update(tree, 2 * id + 1, mid, r, z, c);

        tree[id-1] = std::max(
            tree[2 * id-1],
            tree[2 * id]
        );
    }
    else {
        tree[id-1] = c;
    }
}








int main() {
    int N, M;
    cin >> N >> M;
    vector<int> viaggio(N);
    for(int i=0; i<N; ++i) {
        cin >> viaggio[i];
    }
    vector<int> plateau(N, minimissimo);
    for(int i=1; i<N-1;++i) {
        if(viaggio[i-1]==viaggio[i] && viaggio[i]==viaggio[i+1]) {
            plateau[i] = viaggio[i];
        }
    }
    vector<int> tree = build_tree(plateau, N);


    int operator, z, c;
    for(int i=0; i<M; ++i) {
        cin >> operator >> z >> c;
        if(operator == 1) {
            viaggio[z]+=c;
            if(z-2>=0) {
                if(viaggio[z-2]==viaggio[z-1] && viaggio[z-1]==viaggio[z]) {
                    update(tree, 1, 0, msb(N), z-1, viaggio[z-1]);
                }
                else {
                    update(tree, 1, 0, msb(N), z-1, minimissimo);
                }
            }
            if(z-1>=0 && z+1<N) {
                if(viaggio[z-1]==viaggio[z] && viaggio[z]==viaggio[z+1]) {
                    update(tree, 1, 0, msb(N), z, viaggio[z]);
                }
                else {
                    update(tree, 1, 0, msb(N), z, minimissimo);
                }
            }
            if(z+2<N) {
                if(viaggio[z]==viaggio[z+1] && viaggio[z+1]==viaggio[z+2]) {
                    update(tree, 1, 0, msb(N), z+1, viaggio[z+1]);
                }
                else {
                    update(tree, 1, 0, msb(N), z+1, minimissimo);
                }
            }
        }
        else {
            if(viaggio[z] == viaggio[z+1]) z++;
            if(viaggio[c] == viaggio[c-1]) c--;
            int maximum = get_max(tree, 1, 0, msb(N), z, c+1);
            if(maximum == minimissimo)
                cout << "NESSUN_PLATEAU" << endl;
            else

                cout << maximum << endl;
        }
    }
    return 0;
}
