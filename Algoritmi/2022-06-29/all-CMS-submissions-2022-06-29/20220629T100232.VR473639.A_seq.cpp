/**
* user:  VR473639
* fname: ANDREA
* lname: CINELLI
* task:  A_seq
* score: 23.0
* date:  2022-06-29 10:02:32.589529
*/
#include <iostream>
#include <cstdio>

using namespace std;

int G, N;
int* s;

int max_n = 0, max_count=0;

void find_next(int prev, int index, int partialCount, bool asc){
    if(index==N){
        if(partialCount > max_n){
            max_n = partialCount;
            max_count = 1;
        } else if (partialCount == max_n){
            max_count++;
        }
        return;
    }
    if(asc && s[index] > prev){
        find_next(s[index], index+1, partialCount+1, true);
        find_next(s[index], index+1, partialCount+1, false);
    }
    if(!asc && prev > s[index]){
        find_next(s[index], index+1, partialCount+1, false);
    }
    find_next(prev, index+1, partialCount, asc);
}


int main() {
    cin>>G;
    cin>>N;
    s = new int[N];
    for(int i=0; i<N; i++){
        cin>>s[i];
    }

    for(int i=0; i<N; i++){
        find_next(s[i], i, 1, true);
        find_next(s[i], i, 1, false);
    }

    if(G == 1)
        cout << max_n;
    else
        if(max_n==1)
            cout<<max_count/2;
        else
            cout<<max_count;
    
    return 0;
}