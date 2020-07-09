/**
* user:  VR449169
* fname: MONTRESOR
* lname: STEFANO
* task:  gioco_cifre
* score: 100.0
* date:  2020-06-18 10:50:37.002760
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){

    int n;
    cin >> n;
    
    if(n%10!=0){
        cout << 1 << " " << n%10;
    }
    else{
        cout << 0 << endl;
    }
}