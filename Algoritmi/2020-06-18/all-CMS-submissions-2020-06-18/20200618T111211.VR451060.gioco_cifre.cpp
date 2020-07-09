/**
* user:  VR451060
* fname: CARON
* lname: NICHOLAS
* task:  gioco_cifre
* score: 100.0
* date:  2020-06-18 11:12:11.248271
*/
#include <iostream>

using namespace std;

void whaToDo(int N){
    int initialNumber=N;
    while (N > 0)
    {
        int digit = N%10;
        N /= 10;

        if((initialNumber-digit)%10==0){
            cout<<digit;
            return;
        }
    }   
}

int main(){
    int N;
    cin>>N;

    if(N%10==0){
        cout<<0;
    }
    else{
        cout<<1<<" ";
        whaToDo(N);
    }
}
