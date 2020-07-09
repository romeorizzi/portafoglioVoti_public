/**
* user:  VR445693
* fname: SPERANZA
* lname: GIOVANNI
* task:  bin_heap_fill
* score: 0.0
* date:  2020-06-18 11:54:11.771484
*/
#include<iostream>
#include<vector>
#include<list>

using namespace std;

long long int n;
int t;
vector<long long int> A;
vector<int> E;
vector<int> F;

bool E_stabile(){
    bool stabile = false;
    //vector<int> padre;
    //vector<list<int>> figli;
    int temp = 0;


    for(int i = 0; i < n; i++){
        if(E[i] = 1){
                stabile = (A[i] >= A[(i-1)/2]);
            }
        
        }


    return stabile;
}

int main(){

    cin >> n >> t;

    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        A.push_back(num);
    }


    for(int i = 0; i < n; i++){
        cin >> num;
        E.push_back(num);
    }

    for(int i = 0; i < n; i++){
        cin >> num;
        F.push_back(num);
    }

    bool E_s = E_stabile();

    if(t == 1)
        cout << E_s << endl;


    cout << endl;



    return 0;
}