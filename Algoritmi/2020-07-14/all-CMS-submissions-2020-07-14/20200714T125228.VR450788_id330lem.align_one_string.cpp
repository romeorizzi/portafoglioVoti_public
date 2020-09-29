/**
* user:  VR450788_id330lem
* fname: LUCA
* lname: CRIVELLARO
* task:  align_one_string
* score: 2.0
* date:  2020-07-14 12:52:28.822783
*/
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int MAXN = 1000;
const int INF = 10000000;
int m,n,p;
string a, b;
int cost[1000+1];
long long int mat[1000][1000];

int is_comp(char c1, char c2){
    if(c1 != c2)
        return 0;
    return 1;
}

long long int solve(int id1, int id2){


    //caso base se ho finito array b
    if(id2 == n-1)
        return cost[m-id1-1];
        
    //caso base se ho ginito array a
    if(id1 == m-1)
        return 0;
        

    int min = INF;

    if(mat[id1][id2] != 0)
        return mat[id1][id2];
    
    
    //altrimenti devo provare tutti i casi da 0 a m-idr
    for(int delta = 1; delta <= m-id1; delta++){
 
        if(id1+delta < m && id2+1 < n)
            if(a[id1+delta] == b[id2+1]){
                int temp = cost[delta-1] + solve(id1+delta, id2+1);
                if(temp < min){
                    min = temp;
                }        
            }    
    }
    return mat[id1][id2] = min;
}



int main(){

    
    cin >> m >> n >> p;
    cin >> a >> b;
    for(int i = 0; i <= p; i++){
        cin >> cost[i];
    }


    int temp = solve(0, 0);
    if(temp == INF){
        cout << -1 << endl;
    }
    else
        cout << temp << endl;
    
    


    /*cout << a << endl << b << endl; 
    cout <<a[8] << endl;
    /*
    for(int i = 0; i <= p; i++){
        cout << cost[i] << endl;
    }
    */
    

    return 0;
}