/**
* user:  VR447271EXAM
* fname: BALLINI
* lname: LEONARDO
* task:  bin_heap_fill
* score: 25.0
* date:  2020-06-18 12:52:59.671077
*/
#include <set>
#include <iostream>
int size;
int type;
int * numbers;
int * maskE;
int * maskF;
int is_heap();
int is_fheap();

using namespace std;
int main(){

    cin >> size >> type;
    numbers = new int[size];
    maskE = new int[size];
    maskF = new int[size];

    for(int i = 0 ; i < size; i++){
        cin >> numbers[i];
    }
    for(int i = 0 ; i < size; i++){
        cin >> maskE[i];
    }
    for(int i = 0 ; i < size; i++){
        cin >> maskF[i];
    }

    if(type == 1){
        cout << is_heap();
    }else{
        cout << is_fheap();
    }

}

int is_heap(){
    for(int i = 1 ; i<size;i++){
        if( maskE[i] == 1 && numbers[i] < numbers[(i-1)/2])
            return 0;
    }
    return 1;
}

int is_fheap(){
    set <int> changable;
    int all_free = 1, all_lock = 1;
    for(int i = 0 ; i<size;i++){
        if (maskF[i] == 1){
            all_free = 0;
        }else{
            all_lock = 0;
        }
    }

    if (all_free){
        return 1;
    }else if ( all_lock){
        return is_heap();
    }


    for(int i = 0 ; i<size;i++){
        if (maskF[i] == 1)
            changable.insert(numbers[i]);
    }

    for(int i = 0 ; i<size;i++){
        if (maskF[i] == 1){
            numbers[i] = * changable.begin();
            changable.erase(numbers[i]);
        }
    }
    return is_heap();
}