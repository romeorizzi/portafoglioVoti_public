/**
* user:  VR449169
* fname: MONTRESOR
* lname: STEFANO
* task:  bin_heap_fill
* score: 23.0
* date:  2020-06-18 12:51:56.570532
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<int> A;
vector<int> E;
vector<int> F;

int checkProp(int i){
    
    if (A[i] < A[(i - 1)/2]){
        return 0;
    } 
    return 1;
}



int checkRecursive(int index, int to_swap){
    int father = (index-1)/2;
    if (father == 0){
        if (F[father]){
            return -1;
        }
        else{
            if (E[father*2+1]){
                if (A[father*2+1] < to_swap){
                    return -1;
                }
            }
            if (E[father*2+2]){
                if (A[father*2+2] < to_swap){
                    return -1;
                }
            }
        }
        if (A[father] >= A[(to_swap - 1)/2]){
            return father;
        }
        return -1;
    }

    if (F[father]){
        return checkRecursive(father, to_swap);;
    }
    else{
        if (E[father*2+1]){
            if (A[father*2+1] < to_swap){
                return checkRecursive(father, to_swap);
            }
        }
        if (E[father*2+2]){
            if (A[father*2+2] < to_swap){
                return checkRecursive(father, to_swap);
            }
        }
        if (A[father] >= A[(to_swap - 1)/2]){
            return father;
        }
        return checkRecursive(father, to_swap);;
    }
    
}

void swap(int i1, int i2){
    int tmp = A[i1];
    A[i1] = A[i2];
    A[i2] = tmp;
}


int checkRic(int n){
    for (int i = 1; i < n; i++){
        int swap_to = checkRecursive(i, i);
        if (swap_to < 0){
            return 0;
        }
        swap(swap_to,i);
    }
    return 1;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, t;
    cin >> n >> t;
    
    int countF;
    int good = 1;
    A.resize(n);
    E.resize(n);
    F.resize(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    for(int i = 0; i < n; i++){
        cin >> E[i];
        if(E[i]){
            if (!checkProp(i)){
                good = 0;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cin >> F[i];
        if (F[i] == 1){
            countF++;
        }
    }
    if(t==1){
        cout << good << endl;
    }
    
    else if (t==2){
        if(countF == 0){
            cout << 1 << endl;
        }
        else if (n==1){
            cout << 1 << endl;
        }
        else{
            cout << checkRic(n) << endl;;
        }
    }
    
}