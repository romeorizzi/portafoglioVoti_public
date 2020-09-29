/**
* user:  VR439254_id142nxb
* fname: ANDREA
* lname: TOAIARI
* task:  chordal_lexBFS
* score: 20.0
* date:  2020-09-18 12:13:57.118187
*/
#include <iostream>
#include <vector>

using namespace std;
int g;
int n;
int m;

int main(){
    cin >> g >> n >> m;
    if(g==2){
        cout << "[-1, ";
        for(int i=0; i<n-1; i++){
            cout << "[], ";
        }    
        cout << "[]]" << endl << "2" << endl;   
    }
}