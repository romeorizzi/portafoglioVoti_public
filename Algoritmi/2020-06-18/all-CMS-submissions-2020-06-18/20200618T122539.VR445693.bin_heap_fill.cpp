/**
* user:  VR445693
* fname: SPERANZA
* lname: GIOVANNI
* task:  bin_heap_fill
* score: 6.0
* date:  2020-06-18 12:25:39.828340
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


    for(int i = 1; i < n; i++){
        if(E[i] == 1){
                //cout << A[i] << " " << A[(i-1)/2] << endl;
                stabile = (A[i] >= A[(i-1)/2]);
            }
            if(!stabile)
                break;
        
        }


    return stabile;
}

bool F_stabile(){

    bool stabile = false;

    vector<long long int> ric;

    for(int i = 0; i < n; i++){
        if(F[i] == 1)
            ric.push_back(A[i]);
    }


    for(int i = 1; i < ric.size(); i++){
        if(E[i] = 1){
                stabile = (ric[i] >= ric[(i-1)/2]);
            }
        if(!stabile)
            break;
        
        }

    if(ric.size() == 0)
        stabile = true;

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

    //bool E_s = E_stabile();

    if(t == 1)
        cout << E_stabile() << endl;
    else if(t == 2)
        cout << F_stabile() << endl;


    cout << endl;



    return 0;
}