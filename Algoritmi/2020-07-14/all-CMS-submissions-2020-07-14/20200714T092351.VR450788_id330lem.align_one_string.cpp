/**
* user:  VR450788_id330lem
* fname: LUCA
* lname: CRIVELLARO
* task:  align_one_string
* score: 0.0
* date:  2020-07-14 09:23:51.456571
*/
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int MAXN = 1000;
const int INF = 100000;
int m,n,p;
string a, b;
int cost[1000+1];
int mat[1000][1000];

int is_comp(char c1, char c2){
    if(c1 != c2)
        return 0;
    return 1;
}

int solve(int id1, int id2, int idr){


    if(id1 > m || id2 > n || idr > m)
        return INF;

    //cout << id1 << " " << id2 << " "<<idr << endl;
    if(is_comp(a[id1], b[id2]) == 0 )
        return INF;
    

    if(id1 == m-1){
        if(is_comp(a[id1], b[id2])==1 && idr == m-1)
            return 0;
        else
            return INF;
    }

    int min = INF;
    //se questi due caratteri sono compatibili posso lasciarli come sono e andare oltre
    int temp = solve(id1+1,id2+1,idr+1);
    if(is_comp(a[id1], b[id2])==1){
        if(temp < min)
            min = temp;
    }
    

    //altrimenti devo provare tutti i casi da 0 a m-idr

    for(int delta = 1; delta <= m-idr; delta++){

        temp = cost[delta] + solve(id1+delta, id2+1, idr+delta);
        if(temp < min)
            min = temp;

    }
    return min;

    /*

    

    int min = -1;
    for(int delta = 1; delta <= m-idr; delta++){
        if(min == -1){
            min = cost[delta] + solve(id1+delta, id2+1, idr+delta);
        }
        else{
            int temp = cost[delta] + solve(id1+delta, id2+1, idr+delta);
            if(temp < min)
                min = temp;
        }
    }
    */


}



int main(){

    
    cin >> m >> n >> p;
    cin >> a >> b;
    for(int i = 0; i <= p; i++){
        cin >> cost[i];
    }


    int temp = solve(0, 0, 0);
    if(temp == INF){
        cout << -1 << endl;
    }
    else
        cout << temp << endl;
    /*cout << a << endl << b << endl; 

    for(int i = 0; i <= p; i++){
        cout << cost[i] << endl;
    }
    */

    return 0;
}