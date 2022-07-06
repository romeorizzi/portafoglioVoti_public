/**
* user:  VR473639
* fname: ANDREA
* lname: CINELLI
* task:  A_seq
* score: 0.0
* date:  2022-06-29 10:01:28.672717
*/
#include <iostream>
#include <cstdio>

using namespace std;

int G, N;
int* s;

int find_next_value(int prev, int index, bool asc){
    if(index==N){
        return 0;
    }
    if(asc && s[index] > prev){
        int ascOrder = find_next_value(s[index], index+1, true);
        int descOrder = find_next_value(s[index], index+1, false);
        if (ascOrder > descOrder)
            return 1 + ascOrder;
        return 1 + descOrder;
    }
    if(!asc && prev > s[index]){
        return 1 + find_next_value(s[index], index+1, false);
    }
    
    return find_next_value(prev, index+1, asc);
}


int main() {
    cin>>G;
    cin>>N;
    s = new int[N];
    for(int i=0; i<N; i++){
        cin>>s[i];
    }

    int max_n = 0, max_count = 0;

    for(int i=N-1; i>=0; i--){
        int ascOrder = 1+find_next_value(s[i], i, true);
        int descOrder = 1+find_next_value(s[i], i, false);

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