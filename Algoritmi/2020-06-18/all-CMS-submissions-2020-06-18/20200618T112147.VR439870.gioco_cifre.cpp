/**
* user:  VR439870
* fname: SACCHETTO
* lname: LINDA
* task:  gioco_cifre
* score: 0.0
* date:  2020-06-18 11:21:47.727231
*/
#include <cassert>
#include <iostream>
using namespace std;

int N;

int main(){
    cin >> N;
    int n=N;
    int num;
    int flag == 1;
    while(n!=0 && flag==1){
        num=N%10;
        if(num!=0){
            if(N-num==0){
                flag=0;
                ris = 0;
            }
            else{
                flag=0;
                ris=1;
            }


        }
        n=n/10;
    }

    cout << ris << num;
    
    


}