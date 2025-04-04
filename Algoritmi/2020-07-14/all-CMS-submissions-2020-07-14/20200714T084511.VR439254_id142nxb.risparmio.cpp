/**
* user:  VR439254_id142nxb
* fname: ANDREA
* lname: TOAIARI
* task:  risparmio
* score: 0.0
* date:  2020-07-14 08:45:11.540606
*/
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

#define MAXN 100000
#define MAXM 200000

int N, M;
int luci[ MAXN ];
int action;
int a1, a2;
int inter;
int r;

int main(){
    // freopen("input.txt", "r", stdin);
    cin >> N >> M;
    
    for (int i=0; i<N; i++)
        luci[i] = 0;

    for (int i=0; i<M; i++){
        cin >> action;
        if (action == 1){
            cin >> a1;
            luci[a1] = 1 - luci[a1];
        }
        else{
            cin >> a1 >> a2;
            inter = 0;
            r = 0;
            for (int j=a1; j<a2; j++){
                // cout << luci[j] << " " << luci[j+1] << endl;
                // if(luci[j] == 1 && luci[j+1] == 0){
                //     inter++;
                // }
                // else if (luci[j+1] == 1 && j == a2-1){
                //     inter++;
                // }
                if (luci[j] != 0){
                    inter++;
                    if (inter > r)
                    {
                        r = inter;
                    }  
                }
                else
                {
                    inter = 0;
                }
                
            }
            cout << r << endl;
        }
    }
    return 0; 

}