/**
* user:  VR439254_id142nxb
* fname: ANDREA
* lname: TOAIARI
* task:  altopiano
* score: 25.0
* date:  2020-09-18 11:57:56.984747
*/
#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100000
#define MAX_M 100000

int N, M;
int n[MAX_N];
int m[MAX_M];
int a1, a2;

void search(int a1, int a2) {
    int vmax = -1000000;
    bool find = false;

    for(int i = a1; i <= a2-2; i++) {
        if (n[i] == n[i+1]){
            if (n[i+1] == n[i+2]){
                find = true;
                if(n[i] > vmax)
                    vmax = n[i];
            }
        }
    }

    if(!find)
        cout << "NESSUN_ALTOPIANO" << endl;
    else
        cout << vmax << endl;
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++)
       cin >> n[i];

    for(int i = 0; i < M; i++) {
        int action = 0;
        cin >> action;
        if (action == 1) {
            cin >> a1 >> a2;
            n[a1] += a2;
        } else {
            cin >> a1 >> a2;
            search(a1, a2);
        }
    }

    return 0;
}