/**
* user:  VR450788
* fname: CRIVELLARO
* lname: LUCA
* task:  bin_heap_fill
* score: 25.0
* date:  2020-06-18 11:18:31.251161
*/
#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

unsigned long long int n;
unsigned long long int t;
vector<long long int> x;
vector<long long int> e;
vector<long long int> f;

int possible(){

    int possible = 0;
    for(int i = 1; i < n; i++){
        if(e[i] == 1){
            int figlio = x[i];
            int padre = x[(i-1)/2];

            if(figlio < padre && f[i] == 0 && f[(i-1)/2] == 0){
                possible = 1;
                break;
            }
        }
    }
    
    return possible;

}


int isValid(){

    int valid = 1;
    
    for(int i = 1; i < n; i++){
        if(e[i] == 1){
            if(x[i] < x[(i-1)/2]){
                valid = 0;
                break;
            }
        }
    }
    
    return valid;


}

int main(){

    
    #ifdef EVAL
        assert(freopen("input.txt","r",stdin)>0);
        assert(freopen("output.txt","w",stdout)>0);
    #endif
    
    cin >> n >> t;

    x.resize(n);
    e.resize(n);
    f.resize(n);

    for(int i = 0; i < n; i++){
        cin >> x[i];
    }

    for(int i = 0; i < n; i++){
        cin >> e[i];
    }

    for(int i = 0; i < n; i++){
        cin >> f[i];
    }


    if(t == 1)          
        cout << isValid() << endl;
    else
        cout << possible() << endl;
    return 0;
}