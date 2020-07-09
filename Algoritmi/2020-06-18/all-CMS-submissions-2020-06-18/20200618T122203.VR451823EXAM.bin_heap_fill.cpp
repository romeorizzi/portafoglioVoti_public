/**
* user:  VR451823EXAM
* fname: CINQUETTI
* lname: ETTORE
* task:  bin_heap_fill
* score: 2.0
* date:  2020-06-18 12:22:03.796328
*/
#include<fstream>
#include<iostream>
#include<vector>
#include<assert.h>
#include<list>
#include<algorithm>
#include <cmath>

using namespace std;

int l_array;

vector<int> heap_array;
vector<int> e_array;
vector<int> f_array;

using namespace std;

int check_heap() {

    list<int> new_heap;

    for(int i = 0; i < l_array; i++) {
        if(e_array[i] == 1){
            new_heap.push_back(heap_array[i]); 
        }
    }

    vector<int> result(new_heap.size());
    copy(new_heap.begin(), new_heap.end(), result.begin());

    for(int i = 0; i < new_heap.size(); i++) {
        int padre = ceil((i-1)/2); 
        if(result[i] < result[padre]) return 0;
    }

    return 1;

}

int rearrange_heap() {


    vector<int> result(heap_array.size());
    copy(heap_array.begin(), heap_array.end(), result.begin());

    for(int i = 0; i < heap_array.size(); i++) {
        int padre = ceil((i-1)/2);
        if(result[i] < result[padre]) {
            if (f_array[i]==1 or f_array[padre]==1) return 0;
            int temp = result[i];
            result[i] = result[padre];
            result[padre] = temp;
            i = 0;
        }
    }

    return 1;
    

}





int main (void) {

	ifstream fileIn;
	fileIn.open("input.txt");
	ofstream fileOut;
	fileOut.open("output.txt");

	if(!fileIn.is_open() || !fileOut.is_open()) return -1;

    cin.rdbuf(fileIn.rdbuf());
    cout.rdbuf(fileOut.rdbuf());

    cin >> l_array;

    int task;
    cin >> task;

    heap_array.resize(l_array);
    e_array.resize(l_array);
    f_array.resize(l_array);

    for(int i = 0; i < l_array; i++){
    	cin >> heap_array[i];
    }

    for(int i = 0; i < l_array; i++){
        cin >> e_array[i];
    }

    for(int i = 0; i < l_array; i++){
        cin >> f_array[i];
    }

    /*printf("\n%d", l_array);
    printf("\n%d", task);

    for(int i = 0; i < l_array; i++){
        printf("\n%d", heap_array[i]);
    }

    for(int i = 0; i < l_array; i++){
        printf("\n%d", e_array[i]);
    }

    for(int i = 0; i < l_array; i++){
        printf("\n%d", f_array[i]);
    }   */ 

	if(task == 1) printf("%d", check_heap());
    if(task == 2) printf("%d", rearrange_heap());

}