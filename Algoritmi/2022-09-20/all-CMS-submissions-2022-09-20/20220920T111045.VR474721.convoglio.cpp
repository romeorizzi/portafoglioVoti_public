/**
* user:  VR474721
* fname: RICCARDO
* lname: BOLOGNA
* task:  esame_convoglio
* score: 0.0
* date:  2022-09-20 11:10:45.315444
*/
#include<iostream>
#include<string>

using namespace std;

//int mat[6][2] = {0,2,1,0,2,1,0,0,1,2,2,2};
//int mat[6][2] = {0,2,1,0,1,2,2,1,0,0,2,2};
//int prov[4][2] = {0,2,1,0,1,1,2,1};
//int mat[4][2] = {0,1,2,1,0,0,1,0};
//int mat[7][2] = {0,2,1,0,2,1,1,1,0,0,1,2,2,2};
//int mat[12][2] = {5,2,2,8,3,6,8,4,7,9,0,5,1,1,9,7,4,3,6,0,1,7,9,1};
//int mat[15][2] = {0,1,8,9,6,3,5,7,9,6,2,8,4,0,7,2,1,4,3,5,9,0,0,6,4,4,7,1,1,2};
//int mat[15][2] = {7,9,2,1,0,3,4,5,9,2,1,7,3,4,6,8,8,6,5,0,9,5,6,1,3,6,8,7,2,7};
//int mat[14][2] = {8,7,6,9,7,1,0,4,2,6,1,5,9,3,4,2,5,0,3,8,1,4,2,7,0,5,8,6};

int N, M;
int mat[5200][5200];
int K=0;
int finish=0;
int cont=0;
void stamp(){
    for(int i = 0; i < M; i++){
        for(int j=0;j<2;j++)
            cout << mat[i][j];
        cout<<"\n";
    }
}


void stampF(string tmp){
    for(int i=0;i<N*2;i=i+2){
        
        cout<<to_string(tmp[i]-'0') + " " + to_string(tmp[i+1]-'0');
        cout << "\n";
    }
}


void rec(int vin, int c, string res){
    if(finish==1)
        return;
    else if(vin == N){
        if(K<2){
        int v[5000];
        for(int i =0;i<N;i++)
            v[i] = 0;
        for(int i=1;i<res.size();i=i+2){
            int l = res[i] - '0';
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
        //string res;
        cont++;
        for(int i=0;i<M;i++){
            if(mat[i][0] == vin){
                string tmp;
                tmp = to_string(mat[i][0]) + to_string(mat[i][1]);
                res = res + tmp;
                rec(vin+1, 0, res);
                for(int d = 0;d<tmp.size();d++)
                    res.erase(res.end()-1);
                
            }
            //if (c==1)
              //  cout <<res + "\n";
        }
        
        
    }
    
}




int main(){
    //stamp();
    //stamp();
    cin >> N;
    cin >> M;
    for(int i=0;i<M;i++)
        for(int j=0; j<2; j++)
            cin >> mat[i][j];


    rec(0,1,"");

    if(K<2)
        cout << -1;

    //cout <<"\n" +to_string(cont);
} 