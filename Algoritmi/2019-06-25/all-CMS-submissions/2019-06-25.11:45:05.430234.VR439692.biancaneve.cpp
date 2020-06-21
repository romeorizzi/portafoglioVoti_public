/**
* user:  VR439692
* fname: ASTOLFI
* lname: RICCARDO
* task:  biancaneve
* score: 0.0
* date:  2019-06-25 11:45:05.430234
*/
#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector <int> riga;

void scambia(int p1,int p2){
    int tmp;
    tmp = riga.at(p1);
    riga.at(p1) = riga.at(p2);
    riga.at(p2) = tmp;
}

bool op2(int cmd1,int cmd2){
    int index_min;
    int index_max;
    int index;
    vector<int>::iterator itr1=riga.begin();
    vector<int>::iterator itr3 = riga.begin();

    itr1 = find(riga.begin(),riga.end(),cmd1);
    itr3 = find(riga.begin(),riga.end(),cmd2);

    if(itr1 != riga.end()) index_min = distance(riga.begin(),itr1);
    if(itr3 != riga.end()) index_max = distance(riga.begin(),itr3);

    if(itr1>itr3){
        for(vector<int>::iterator i =itr3+1;i!=itr1;i++){
            if(*i>*itr3|| *i<*itr1) return false;
        }
    }else{
        for(vector<int>::iterator i = itr1+1; i!=itr3;i++){
            if(*i>*itr3||*i<*itr1) return false;
        }

    }
    return true;
}

int main(){
int n=0;
int m=0;
cin>>n;
cin>>m;

int arr[n];
    for(int i = 0;i<n;i++){
    int tmp;
    cin>>tmp;
    riga.push_back(tmp);
    arr[i] = tmp;
}

    for(int i = 0; i<m;i++){
    int op,cmd1,cmd2,
    cin>>op;
    cin>>cmd1;
    cin>>cmd2;
    
    if(op==1) scambia(cmd1-1,cmd2-1);
    if(op==2){
        if(op2(cmd1,cmd2)) cout<< "YES" <<endl;
    else cout<<"NO"<<endl;
    }
}

return 0;
}
