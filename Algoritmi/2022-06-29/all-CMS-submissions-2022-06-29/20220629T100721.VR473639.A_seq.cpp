/**
* user:  VR473639
* fname: ANDREA
* lname: CINELLI
* task:  A_seq
* score: 0.0
* date:  2022-06-29 10:07:21.410938
*/
#include <iostream>
#include <cstdio>

using namespace std;

int G, N;
int* s;
int** memoAsc;
int** memoDesc;

int find_next_value(int prevIndex, int index, bool asc){
    if(index==N){
        return 0;
    }
    if(asc && memoAsc[prevIndex][index]!=-1){
        return memoAsc[prevIndex][index];
    }
    if(!asc && memoDesc[prevIndex][index]!=-1){
        return memoDesc[prevIndex][index];
    }
    if(asc && s[index] > s[prevIndex]){
        int ascOrder = find_next_value(index, index+1, true);
        int descOrder = find_next_value(index, index+1, false);
        memoAsc[prevIndex][index] = ascOrder;
        memoDesc[prevIndex][index] = descOrder;
        if (ascOrder > descOrder)
            return 1 + ascOrder;
        return 1 + descOrder;
    }
    if(!asc && s[prevIndex] > s[index]){
        int descOrder = find_next_value(index, index+1, false);
        memoDesc[prevIndex][index] = descOrder;
        return 1 + descOrder;
    }
    
    int res = find_next_value(prevIndex, index+1, asc);
    if(asc)
       memoAsc[prevIndex][index] = res;
    else
       memoDesc[prevIndex][index] = res;
    return res;
}


int main() {
    cin>>G;
    cin>>N;
    s = new int[N];
    memoAsc = new int*[N];
    memoDesc = new int*[N];

    for(int i=0; i<N; i++){
        cin>>s[i];
        memoAsc[i] = new int[N];
        memoDesc[i] = new int[N];
        for(int j=0; j<N; j++){
            memoAsc[i][j] = -1;
            memoDesc[i][j] = -1;
        }
    }

    int max_n = 0, max_count = 0;

    for(int i=N-1; i>=0; i--){
        int ascOrder = 1+find_next_value(i, i, true);
        int descOrder = 1+find_next_value(i, i, false);

        if(ascOrder>max_n){
            max_n=ascOrder;
            max_count = 0;
        }
        if(descOrder>max_n){
            max_n=descOrder;
            max_count = 0;
        }
        if(descOrder == max_n || ascOrder == max_n)
            max_count++;
    }

    if(G == 1)
        cout << max_n;
    else
        cout << max_count;
    
    return 0;
}