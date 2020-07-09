/**
* user:  VR439254
* fname: TOAIARI
* lname: ANDREA
* task:  bin_heap_fill
* score: 25.0
* date:  2020-06-18 11:06:12.287470
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
vector<int> heap;
vector<int> e;
vector<int> f;


int check_t1(){
    for(int i=0; i<n; i++){
        if(e[i] == 1 && heap[i] < heap[(i-1)/2])
            return 0;
    }
    return 1;
}

// int check_t2(){
//     for(int i=n-1; i>0; i--){
//         if(e[i] == 1 && (heap[i] < heap[(i-1)/2]) && (f[i] == 1 || f[(i-1)/2] == 1))
//             return 0;
//     }
//     return 1;
// }

int check_t2(){
    for(int i=n-1; i>0; i--){
        if(e[i] == 1 && (heap[i] < heap[(i-1)/2])){
            if (f[i] == 1 || f[(i-1)/2] == 1){
                return 0;
            }
            else
            {
                int tmp = f[i];
                f[i] = f[(i-1)/2];
                f[(i-1)/2] = tmp;
            }
        }
    }
    return 1;
}

int main(){
    int task;
    int tmp;
    cin >> n;
    cin >> task;

    for(int i=0; i<n; i++){
        cin >> tmp;
        heap.push_back(tmp);
    }

    for(int i=0; i<n; i++){
        cin >> tmp;
        e.push_back(tmp);
    }

    for(int i=0; i<n; i++){
        cin >> tmp;
        f.push_back(tmp);
    }

    // cout << "Heap\n";
    // for (int i = 0; i < n; i++){
    //     cout << heap[i] << " ";
    // }
    // cout << endl;
    
    if(task == 1){
        cout << check_t1();
    }
    else
    {
        cout << check_t2();
    }
    
    return 0;
}