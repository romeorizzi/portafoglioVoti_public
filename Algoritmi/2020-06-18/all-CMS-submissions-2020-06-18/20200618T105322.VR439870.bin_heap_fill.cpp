/**
* user:  VR439870
* fname: SACCHETTO
* lname: LINDA
* task:  bin_heap_fill
* score: 25.0
* date:  2020-06-18 10:53:22.061241
*/
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 1000000;
const int MAX_VAL = 10;
int n;
int t;
int x[MAX_N];
int e[MAX_N];
int f[MAX_N];
int flag = 1;


int controllo_E_buono(int i){
    if(x[i]<x[(i-1)/2]){
        return 0;
    }
    return 1;
}

int main(){
    cin >> n >> t;
    for(int i = 0; i < n; i++)
       cin >> x[i];
    for(int i = 0; i < n; i++)
       cin >> e[i];
    for(int i = 0; i < n; i++)
       cin >> f[i];
    if(t==1){
            for(int i = 1; i < n; i++){
                if(flag==1){
                    if(e[i]==1){
                        flag = controllo_E_buono(i);
                    }
                }
                //flag=1;
            }
    }
    if(t==2){
        int count=0;
        int lung=0;
        int index[MAX_N];
        int array[MAX_N];
        for(int i=0; i<n; i++){
            if(f[i]!=0){
                index[count]=i;
                count++;
            }
            else{
                array[lung]=x[i];
                lung++;
            }
        }
        if(count==0){
            flag=1;
        }
        else{
        //ordina array
        std::sort(array,array + lung);
        //ricreo array con elementi stabili
        int j=0;
        int q=0;
        int finale[n];
        for(int i=0; i<n; i++){
                int k=index[j];
                if(i==k){
                    finale[i]=x[k];
                    j++;
                }
                else{
                    finale[i]=array[q];
                    q++;
                }
        }
        for(int i = 1; i < n; i++){
            if(flag==1){
                //flag = controllo_E_buono(i);
                if(e[i]==1){
                        flag = controllo_E_buono(i);
                }
            }
        }

                     
    }      
    }//chiuso else count
    
    cout << flag;
       

}
