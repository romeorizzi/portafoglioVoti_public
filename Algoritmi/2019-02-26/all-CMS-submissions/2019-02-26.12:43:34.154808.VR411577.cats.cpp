/**
* user:  VR411577
* fname: TEREN
* lname: VIKTOR
* task:  cats
* score: 0.0
* date:  2019-02-26 12:43:34.154808
*/
#include <vector>
#include <map>
#include <cstdio>
#include <cassert>
#include <stdio.h>
#include <fstream>

using namespace std;


int main(){
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt","w",stdout));
    int nm, nf;
    scanf("%d", &nm);
    scanf("%d", &nf);
    vector<int> nm_vec(nm);// = new vector(nm);
    vector<int> nf_vec(nf);// = new vector(nf);
    vector<int> differences(nf);
    vector<int> p(nf);
    int temp;
    int max_length;
    int n = max_length;
    if(nm > nf)
        max_length = nf;
    else
        max_length = nm;
    for(int i=0; i< nm;i++){
        scanf("%d", &temp);
        nm_vec[i] = temp;
        //std::cout << nm_vec[nm_vec.size()-1];
        //printf("%d\n", nm_vec[nm_vec.size()-1]);
    }
    for(int i=0; i< nf;i++){
        scanf("%d", &temp);
        nf_vec[i] = temp;
        //std::cout << nf_vec[nm_vec.size()-1];
        //printf("%d\n", nf_vec[nf_vec.size()-1]);

    }
    int nm_val = nm_vec[0];
    for(auto elem: nf_vec){
        temp = nm_val - elem;
        if(temp <0)
            temp = -temp;
        differences.push_back(temp);
    }



    p[n-1]=differences[n-1];
    for(int i=n-2;i>=0;i--){
        p[i] = differences[i];
        if(p[i+1]>0)
            p[i]+=p[i+1];
    }
    int soluzione =p[0];
    for(int i=1;i<n;i++){
        if(p[i]>soluzione)
            soluzione = p[i];
    }

    printf("%d", soluzione);
    
}