/**
* user:  VR439870
* fname: SACCHETTO
* lname: LINDA
* task:  gioco_cifre
* score: 0.0
* date:  2020-06-18 11:45:07.184112
*/
#include <cassert>
#include <iostream>
using namespace std;

int N;

int main(){
    cin >> N;
    int n=N;
    int num;
    int flag = 1;
    int ris;
    while(n!=0 && flag==1){
        num=N%10;
        printf("num %i", num);
        if(num==0){//hai perso
            flag=0;
        }
        if(num!=0){
            if((N-num)%10==0){//meglio sceglierne un altro perchè ti porta a perdere
                flag=0;
                ris=1;
            }
        }
        n=n/10;
    }

    cout << ris << num;
    
    


}