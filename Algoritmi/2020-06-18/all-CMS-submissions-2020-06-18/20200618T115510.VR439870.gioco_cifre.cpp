/**
* user:  VR439870
* fname: SACCHETTO
* lname: LINDA
* task:  gioco_cifre
* score: 0.0
* date:  2020-06-18 11:55:10.833602
*/
#include <cassert>
#include <iostream>
using namespace std;

int N;

int main(){
    cin >> N;
    int num;
    int ris;
    num=N%10;
    if(num==0){//hai perso
    
        cout << 0;
    }
    else{
        cout << 1 << num;
    }  

}