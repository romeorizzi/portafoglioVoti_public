/**
* user:  VR474723
* fname: MARCELLO
* lname: DE VINCENZI
* task:  k_up_1_down_seq
* score: 0.0
* date:  2022-06-29 12:37:31.874379
*/
#include <iostream>
using namespace std;

int calc_seq(int,int,int);

int g,n,k;

int main(){

cin >> g;
cin >> n;
cin >> k;

int result;

if(g==1)
    result=calc_seq(0,n,k)+1;
cout << result;
}

int calc_seq(int s,int n,int k){
    if(n==2)
        return 1;
    if(s==0){
        return calc_seq(0,n-1,k) + calc_seq(k,n-1,k);
    }
    else{
        if((n-1)*2>s)
            return calc_seq(s,n-1,k) + calc_seq(s-1,n-1,k);
        else
            if((n-1)*2==s)
                return 1;
            else
                return 0;
    }
}