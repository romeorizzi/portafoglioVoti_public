/**
* user:  VR445766_id158clr
* fname: MARCELLO
* lname: CILLUFFO
* task:  altopiano
* score: 27.0
* date:  2020-09-18 11:59:39.222907
*/
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>


using namespace std;

const int MIN = INT8_MIN;

int bit(int N) {
    int bit=-1;
    int n=N;
    while(n!=0) {
        n/=2; 
        bit++;
    }
    if(N^(1<<bit)!=0){
        bit++;
    }
    n=1<<bit;
    return n;
}

vector<int> range_tree(vector<int>& altezze,int N) {
    queue<int> coda;
    vector<int> albero;
    
    int n=bit(N);

    for(int i=n-1;i>=0;--i){
        int h =0;

        if(i<N){
            h=altezze[i];
        }
        else{
            h=MIN;
        }

        coda.push(h);
        albero.push_back(h);
    }
    while(coda.size()!=1) {
        int left,right,h;
        left=coda.front();
        coda.pop();
        right=coda.front();
        coda.pop();

        if(left>right){
            h=left;
        }
        else{
            h=right;
        }

        coda.push(h);
        albero.push_back(h);
    }
    return albero;
}

int massimo(vector<int>& albero,int id,int left,int right,int a,int b) {
    
    if (right<=a || left>=b)
        return MIN;

    if (left>=a && right<=b)
        return albero[id-1];

    int mid=(left+right)/2;

    return max(massimo(albero,2*id,left,mid,a,b), massimo(albero,2*id+1,mid,right,a,b));
}

void update(vector<int>& albero,int id,int left,int right,int x,int y) {
    
    if(right<=x||left>x){
        return;
    }

    if(right>left+1) {
        int mid=(left+right)/2;

        update(albero,2*id,left,mid,x,y);
        update(albero,2*id+1,mid,right,x,y);

        albero[id-1]=max(albero[2*id-1],albero[2*id]);
    }
    else {
        albero[id-1]=y;
    }
}

int main() {

    int N=0,M=0;

    cin>>N>>M;

    vector<int> altezze(N);

    for(int i=0;i<N;++i) {
        cin>>altezze[i];
    }

    vector<int> altipiani(N, MIN);

    for(int i=1; i<N-1;++i) {
        if(altezze[i-1]==altezze[i] && altezze[i]==altezze[i+1]) {
            altipiani[i]=altezze[i];
        }
    }

    vector<int> albero=range_tree(altipiani, N);

    reverse(albero.begin(),albero.end());

    int operazione,x,y;

    for(int i=0;i<M;++i) {

        cin>>operazione>>x>>y;

        if(operazione==1) {
            altezze[x]+=y;
            
            if(x-2>=0) {
                if(altezze[x-2]==altezze[x-1] && altezze[x-1]==altezze[x]) {
                    update(albero,1,0,bit(N),x-1,altezze[x-1]);
                }
                else {
                    update(albero,1,0,bit(N),x-1,MIN);
                }
            }
            if(x-1>=0 && x+1<N){
                if(altezze[x-1]==altezze[x] && altezze[x]==altezze[x+1]){
                    update(albero,1,0,bit(N),x,altezze[x]);
                }
                else{
                    update(albero,1,0,bit(N),x,MIN);
                }
            }
            if(x+2<N){
                if(altezze[x]==altezze[x+1] && altezze[x+1]==altezze[x+2]){
                    update(albero,1,0,bit(N),x+1,altezze[x+1]);
                }
                else{
                    update(albero,1,0,bit(N),x+1,MIN);
                }
            }
        }
        else{
            if(altezze[x]==altezze[x+1]){ 
                x++;
            }
            if(altezze[y]==altezze[y-1]){
                 y--;
            }
            int maximum=massimo(albero,1,0,bit(N),x,y+1);
            if(maximum==MIN)
                cout<<"NESSUN_ALTOPIANO"<<endl;
            else
                cout<<maximum<<endl;
        }
    }
    return 0;
}