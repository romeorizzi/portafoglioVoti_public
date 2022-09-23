/**
* user:  VR474721
* fname: RICCARDO
* lname: BOLOGNA
* task:  esame_convoglio
* score: 15.0
* date:  2022-09-20 12:24:13.665623
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;




int N, M;
int mat[1600][2];
int K=0;
int finish=0;





void stampF(vector<int> tmp){
    
    for(int i=0;i<tmp.size();i=i+2){
        
        cout<<to_string(tmp[i]) + " " + to_string(tmp[i+1]);
        cout << "\n";
    }
}


void rec(int vin, vector<int> res){
    if(finish==1)
        return;
    else if(vin == N){
        if(K<3){
        int v[1600];
        for(int i = 0;i<N;i++)
            v[i] = 0;

        for(int i=1;i<res.size();i=i+2){
            int l = res[i];
            v[l] = 1;
        }
        int flag=1;
        for(int i=0;i<N;i++)
            if(v[i] != 1)
                flag=0;

        if (flag == 1){
            K++;
            if(K>1){
                stampF(res);
                finish = 1;
                }
                //cout << res +"\n";
        }
        }}

    else{
        
        for(int i=0;i<M;i++){
            if(mat[i][0] == vin){
                //vector<int> tmp;
                //tmp = to_string(mat[i][0]) + to_string(mat[i][1]);
                res.push_back(mat[i][0]);
                res.push_back(mat[i][1]);
                rec(vin+1, res);
                res.erase(res.end()-1);
                res.erase(res.end()-1);
                
            }
            
        }
        
        
    }
    
}




int main(){
    
    cin >> N;
    cin >> M;
    for(int i=0;i<M;i++)
        for(int j=0; j<2; j++)
            cin >> mat[i][j];

    vector<int> res;

    rec(0,res);
    
    if(K<2)
        cout << -1;
    
    
} 