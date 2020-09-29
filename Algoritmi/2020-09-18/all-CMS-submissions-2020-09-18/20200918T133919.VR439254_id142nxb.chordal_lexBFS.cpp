/**
* user:  VR439254_id142nxb
* fname: ANDREA
* lname: TOAIARI
* task:  corrected-chordal_lexBFS
* score: 40.0
* date:  2020-09-18 13:39:19.224033
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;
int g;
int n;
int m;

int a,b;


int main(){
    cin >> g >> n >> m;
    if(g==2){
        // cout << "[-1, ";
        // for(int i=0; i<n-1; i++){
        //     cout << "[], ";
        // }    
        // cout << "[]]" << endl << "2" << endl;   
        cout << "2" << endl;
    }
    if(g==3){
        int max = 0;
        int v[n+1]{};
        for(int i=1; i<=n; i++){
            v[i] = 1;
        }
        for (int i=0; i<m; i++){
            cin >> a >> b;
            if(a>b)
                v[b]++;
            if(b>a)
                v[a]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if(v[i]>max)
                max = v[i];
        }
        cout << max << endl;   
    }
    if(g==4){
        set<int> clique;
        int mat[m][2];
        int max = 0;
        int max_index = -1;
        int v[n+1]{};
        for(int i=1; i<=n; i++){
            v[i] = 1;
        }
        for (int i=0; i<m; i++){
            cin >> a >> b;
            mat[i][1] = a;
            mat[i][2] = b;
            if(a>b)
                v[b]++;
            if(b>a)
                v[a]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if(v[i]>max){
                max = v[i];
                max_index = i;
            }
        }
        cout << max << endl;
        clique.insert(max_index);
        for(int i=0; i<m; i++){
            if(mat[i][1] == max_index)
                clique.insert(mat[i][2]);
            if(mat[i][2] == max_index)
                clique.insert(mat[i][1]);
        }
        for(int i: clique){
            cout << i << " ";
        }
        cout <<endl;
    }
}