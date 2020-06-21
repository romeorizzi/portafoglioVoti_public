/**
* user:  VR439692
* fname: ASTOLFI
* lname: RICCARDO
* task:  Prob1_tree_split_out
* score: 0.0
* date:  2019-09-04 11:21:01.063902
*/
#include <iostream>
#include <vector>

using namespace std;

const int MAX_VAL = 1000000;
int kids[MAX_VAL];
int num_decr[MAX_VAL];
int depth[MAX_VAL*2];

int posR,posW;
int node_index = 0;

void print_array(int n){
    for(int i=0;i<n;i++)
        cout<<" "<<kids[i];
}

int removecod1(int root,int d){
root = node_index;
if(d%2==0){
    if(kids[root]!=0){
    int tmp  = kids[root];
    for(int i=0;i<tmp;i++){
        kids[root]+= removecod1(node_index++,d+1);
    }
    kids[root] -= tmp;
   }
}
else{
    for(int i=0;i<kids[root];i++){
           removecod1(node_index++,d+1);
    }
    int tmp = kids[root];
    kids[root] = -1;
    return tmp;
   }
    return 0;
}

int removecod2(int root,int d){
    int somma = 0;
    if(d%2 ==0){
        if(num_decr[root]==1)return 1;
        while(num_decr[root]>1){
            num_decr[root] -=num_decr[++node_index];
            somma += removecod2(node_index,d+1);
        }
    }
    else{
        if(num_decr[root]==1){ num_decr[root]=-1;
        while(num_decr[root]>1){
            num_decr[root]-= num_decr[++node_index];
            somma += removecod2(node_index,d+1);
        }
    num_decr[root] = -1;
    return somma;
}
return 1;
}

void removecod3(int root,int d) {
    cout<<"root >> "<< root << " d >>" << d <<endl;
    while(depth[root] !=0){
        if(d%2 == 0){
            if(root>0){
                depth[root]-=1;
            }
            removecod3(root+1,d+1);
        } else{
            depth[root] = -1;
            removecod3(root+1,d+1);
        }
    }
    }

int main(){
    int cod,n=1;
    cin >> cod;
    if(cod==1){
        cin>>kids[0];
        n+= kids[0];
    for(int i =1;i<n;i++){
        cin >> kids[i];
        if(kids[i]>0) n+=kids[i];
    }

    cout<< 1 << " ";
    if(removecod1(0,0)==0){
        for(int i =0;i<n;i++){
            if(kids[i]!= -1)
                cout << kids[i] << " ";
        }
     }
      }else{
        if(cod==2){
            cin >> num_decr[0];
            n=num_decr[0];
            for(int i=1;i<n;i++){
                cin >> num_decr[i];
            }
            if(removecod2(0,0)==1){
                if(num_decr[0]>1) num_decr[0]++;
                cout << 2 << " ";
                for(int i =0;i<n;i++){
                    if(num_decr[i]!=-1
                        cout << num_decr[i] << " ";
            }
        }
   } else{
        n=0;
        cin >> depth[n++];
        cin >> depth[n++];

        while(depth[n-1] > 0){
            cin >> depth[n++];
        }
        removecod3(1,0);
        cout << 3 << " ";
        }
        
        return 0;
       }
}

    
