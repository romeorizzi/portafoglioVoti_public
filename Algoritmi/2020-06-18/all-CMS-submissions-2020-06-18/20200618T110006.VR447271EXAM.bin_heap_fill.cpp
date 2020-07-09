/**
* user:  VR447271EXAM
* fname: BALLINI
* lname: LEONARDO
* task:  bin_heap_fill
* score: 23.0
* date:  2020-06-18 11:00:06.226585
*/

#include <iostream>
int size;
int type;
int * numbers;
int * maskE;
int * maskF;
int is_heap();

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
    }

}

int is_heap(){
    for(int i = 1 ; i<size;i++){
        if( maskE[i] == 1 && numbers[i] < numbers[(i-1)/2])
            return 0;
    }
    return 1;
}