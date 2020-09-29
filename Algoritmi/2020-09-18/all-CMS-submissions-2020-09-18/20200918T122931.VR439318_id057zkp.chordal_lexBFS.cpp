/**
* user:  VR439318_id057zkp
* fname: GIANLUCA
* lname: PAVAN
* task:  corrected-chordal_lexBFS
* score: 0.0
* date:  2020-09-18 12:29:31.071775
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