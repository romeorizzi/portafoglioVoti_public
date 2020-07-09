/**
* user:  VR450788
* fname: CRIVELLARO
* lname: LUCA
* task:  poldo_sums
* score: 8.0
* date:  2020-06-18 11:13:22.942803
*/
#include<iostream>
#include<vector>
#include<cassert>
#include<list>
using namespace std;

int panini[10000];
int gym[10000];
vector<list<int>> sol;
int N;
int index_sol = 0;
int seq[10000];

int solve(int index_seq, int last_element, int index_sol){

    
    int sum = 0;
    //calcolo somma se index > 0, altrimenti sto analizzando il primo elemento
    if(index_seq > 0){// && last_element != -1){
        for(int i = last_element; i <= index_seq-1 ; i++){
            sum += gym[i];
        }

    }


    //caso base
    if(index_seq == N-1){
        if (panini[index_seq] >= panini[last_element] + sum || last_element == -1)
            return 1;
        else 
            return 0;
        
    }
    

    //se devo ancora prendere il primo elemento
    if(last_element == -1){
        int a = 1 + solve(index_seq+1, index_seq, index_sol+1);
        int b = solve(index_seq+1, last_element ,index_sol);

        if(a > b){
            seq[index_sol] = index_seq;
        }
        
        return max(a,b);
    }
    

    //se la condizione vale e posso prenderlo
    if(panini[index_seq] >= panini[last_element] + sum){
        int a = 1 + solve(index_seq+1, index_seq, index_sol+1);
        int b = solve(index_seq+1, last_element ,index_sol);

        if(a > b){
            seq[index_sol] = index_seq;
        }
        return max(a,b);
    }

    //se non posso prenderlo
    return solve(index_seq+1, last_element, index_sol);

}


bool check(int index_seq, int last_element){

    int sum = 0;
    //calcolo somma se index > 0, altrimenti sto analizzando il primo elemento
    //cout << index_seq << " " << last_element <<"->"  ;
    for(int i = last_element; i <= index_seq-1 ; i++){
        sum += gym[i];
    }
    //cout <<( panini[index_seq] >= panini[last_element] + sum) << endl; 

    return panini[index_seq] >= panini[last_element] + sum;

}
int main(){

    
    #ifdef EVAL
        assert(freopen("input.txt","r",stdin)>0);
        assert(freopen("output.txt","w",stdout)>0);
    #endif
    
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> panini[i] >> gym[i];
    }
   
    
    int k = solve(0,-1,0);
    cout << k << endl;

    for(int i = 0; i < k; i++){
        cout << seq[i] << " ";
    }
    
    /*sol.resize(N);
    sol[0].push_back(0);
    vector<int> parents;
    parents.resize(N);

    for(int i = 1; i < N; i++){

        int j = 0;
        while(sol[j].size()!=0){
            if(!check(i, sol[j].front())){
                
                sol[j].push_back(i);
                parents[i] = sol[j].front();
                break;
            }
                        
            else{
                j++;
            }
        }
        sol[j].push_back(i);
        parents[i] = sol[j].front();

        
        
    }
    int l;
    for(l = 0; l < N; l++){
        if(sol[l].size() == 0)
            break;
    }

    cout << l << endl;

    
    for(int i = 1 ; i < N; i++)
        cout << parents[i] << " ";
    */
   
    return 0;
}