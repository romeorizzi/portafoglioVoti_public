/**
* user:  VR439254_id142nxb
* fname: ANDREA
* lname: TOAIARI
* task:  gioco_parentesi
* score: 4.0
* date:  2020-09-18 12:54:32.348167
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int MAXN = 1000000;
const int MAXM = 1000000;
int N;

int main(){
    cin >> N;
    string p;   
    cin >> p;
    if((N/2)%2==0){
        cout << 1 << endl;
        cout << 0 << " " << N-1;
    }
    else
        cout << 0 << endl;
}