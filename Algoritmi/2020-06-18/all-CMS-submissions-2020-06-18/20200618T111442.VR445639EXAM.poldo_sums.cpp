/**
* user:  VR445639EXAM
* fname: RUSSO
* lname: ROSA
* task:  poldo_sums
* score: 0.0
* date:  2020-06-18 11:14:42.749057
*/
#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
using namespace std;
typedef unsigned long long int ll;

vector<int> panino;
vector<int> gym;
int N;

int main(){
    #ifdef EVAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int p, g;

    cin >> N;
    assert(N > 0);
    assert(N <= 100000);

    for (int i=0; i<N; i++){
        cin >> p;
        assert(panino[i] >= 0);
        assert(panino[i] <= 10000);
        panino.push_back(p);
//        cout << panino[i];

        cin >> g;
        assert(gym[i] >= -1000);
        assert(gym[i] <= 1000);
        gym.push_back(g);
//        cout << gym[i];
    }

    vector<int> s;
    vector<int> seq;
    int j = 0;
    int k = 1;
    int sum = 0;
    int t = 0; // indice di seq
    
    for (int i=0; i<N; i++){
        for (int k = 1; k<N; k++){
            s[j] = k-1;
            j += 1;
            s[j] = k;
            if( s[j-1] < s[j]-1 ){
                sum += gym[s[j-1]];
                if (panino[k] < panino[k-1] + sum )
                    break;
                else{
                    seq[t] = s[j-1];
                    //cout << seq[t];
                    t += 1;
                    seq[t] = s[j];
                    seq[t];
                }
            }
        }
    }
    int taglia = sizeof(seq);

    cout << taglia << endl;
    for (int i=0; i<taglia; i++)
        cout << seq[i];

    return 0;
}
