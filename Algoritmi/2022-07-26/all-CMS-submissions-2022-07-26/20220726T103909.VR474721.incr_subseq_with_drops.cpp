/**
* user:  VR474721
* fname: RICCARDO
* lname: BOLOGNA
* task:  esameincr_subseq_with_drops
* score: 0.0
* date:  2022-07-26 10:39:09.826946
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> massimi;
int mem [120];

void stamp(vector<int> v){
    for(int x:v)
        cout<<to_string(x) + " ";
}

vector<int> cut(vector<int> v,int ncut){
    for(int i=0;i<ncut;i++)
        v.erase(v.begin());
        
    return v;
    }

int count_mas(vector<int> v, int max){
    int cont = 0;
    for(int x:v)
        if(x == max)
            cont ++;
    return cont;
}

int seq1(vector<int> v, int min, int crol, int pos){
    int massimo = 0;
    if(v.size()==1 && v[0]>min)
        return 1;
    else if(v.size()==1 && v[0]<=min)
        return 0;
    else if(v.size()==0)
        return 0;
    else{
        for(int i=0;i<v.size();i++){
            if(v[i]>min || (v[i]<=min && crol>0)){
                if(v[i]<=min)
                    crol--;
                /*if(mem[i+pos]==-1){
                    mem[i+pos] = 1 + seq1(cut(v,i+1), v[i], crol,i+1);
                    massimo = max(mem[i+pos], massimo);
                }
                else
                    massimo = max(mem[i+pos], massimo);*/
                    massimo = max(1 + seq1(cut(v,i+1), v[i], crol,i+1), massimo);
            }

        }
        return massimo;
    }
    
}
/*
int seq2(vector<int> v, int min, int crol){
    int cont = 0,massimo = 0;
    vector<int> mass;
    if(v.size()==1 && v[0]>min)
        return 1;
    else if(v.size()==1 && v[0]<=min)
        return 0;
    else if(v.size()==0)
        return 0;
    else{
        for(int i=0;i<v.size();i++){
            if(v[i]>min || (v[i]<=min && crol>0)){
                if(v[i]<=min)
                    crol--;
                
                //massimo = max(1+seq(cut(v,i+1), v[i], crol), massimo);
                int n = seq1((cut(v,i+1)), v[i], crol);
                mass.push_back(n); 

            }

        }
        massimo = *max_element(mass.begin(),mass.end());
        cont = count_mas(mass,massimo);
        int tmp
        v.erase(v.begin());
        return cont + seq2(v);

    }


    

}

*/




int main(){
    vector<int> v;
    int g,n,k,tmp; 
    cin>>g;
    cin>>n;
    cin>>k;

    for(int i=0;i<n;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    
    for(int j = 0;j<n;j++)
        //for(int s = 0;s<n;s++)
          mem[j] = -1;
    //stamp(v);

    /*for(int p = 0;p<n;p++)
        
            cout<<mem[p];*/
    //cout<<"\n\n";
    int res = 0;
    //if(g==1)
    res = seq1(v,0,k,0);

    cout<<res;

}