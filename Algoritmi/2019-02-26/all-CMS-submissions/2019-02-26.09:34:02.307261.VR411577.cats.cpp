/**
* user:  VR411577
* fname: TEREN
* lname: VIKTOR
* task:  cats
* score: 0.0
* date:  2019-02-26 09:34:02.307261
*/
#include <vector>
#include <map>
#include <cstdio>
#include <cassert>
#include <stdio.h>
#include <fstream>

using namespace std;

//int array[max_value];
//int p[MAX_VALUE];

/*int value_ric(int n, int *array){
    //somma sottointervallo
    assert(n>= 1);
    if(n==1)
        return array[0];
    int valore = max_value_ric(n-1, array);
    int somma = 0;
    for(int left=n-1; left >=0; left--){
        somma+=array[left];
        if(somma > valore)
            valore = somma;
    }
}*/



int main(){
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt","w",stdout));
    int nm, nf;
    scanf("%d", &nm);
    scanf("%d", &nf);
    vector<int> nm_vec(nm);// = new vector(nm);
    vector<int> nf_vec(nf);// = new vector(nf);
    int temp;
    int max_length;
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
    //printf("%d", max_length);
    int max=0;
    if(nm>= nf){
        for(int i=0; i<= nm-max_length;i++){
            int temp;
            int subsum=0;
            for(int j=0;j<max_length;j++){
                temp = nm_vec[i+j]-nf_vec[j];
                //printf("%d %d %d\n", nm_vec[i+j], nf_vec[j], temp);
                if(temp < 0)
                    temp = -temp;
                subsum = subsum+ temp;
            }
            if(subsum > max)
                max = subsum;
        }
    }
    else{
        for(int i=0; i<= nf-max_length;i++){
            int temp;
            int subsum=0;
            for(int j=0;j<max_length;j++){
                temp = nm_vec[j]-nf_vec[i+j];
                if(temp < 0)
                    temp = -temp;
                subsum = subsum+ temp;
            }
            if(subsum > max)
                max = subsum;
        }
    }
    printf("%d", max);

    //p[N-1] = array[N-1]
    
}