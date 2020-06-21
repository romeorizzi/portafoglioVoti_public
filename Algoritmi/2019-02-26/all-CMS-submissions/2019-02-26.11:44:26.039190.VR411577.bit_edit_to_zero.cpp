/**
* user:  VR411577
* fname: TEREN
* lname: VIKTOR
* task:  bit_edit_to_zero
* score: 30.0
* date:  2019-02-26 11:44:26.039190
*/
#include <vector>
#include <map>
#include <cstdio>
#include <cassert>
#include <string>
#include <set>

using namespace std;

map<int, int> *mappa;
set<int> *visited;


vector<bool> convert(int n){
    //printf("convert %d\n", n);
   vector<bool> ris;
    std::string r;
    while(n!=0){
        r=(n%2==0 ?"0":"1")+r;
        n/=2;
    }
    //printf("%s", r);
    for(auto elem: r){
        if(elem == '1'){
            ris.push_back(true);
        }
        else{
            ris.push_back(false);
        }
        //printf("%c", elem);
    }
    //printf("\n");
    /*for(auto elem: ris){
        if(elem){
            printf("1");
        }
        else{
            printf("0");
        }
    }
    printf("\n");*/
    return ris;

}

int convert_back(vector<bool> v){
    //printf("convert back ");
    /*for(auto elem: v){
        if(elem){
            printf("1");
        }
        else{
            printf("0");
        }
    }
    printf("\n");*/
    int sum=0;
    for(int i=v.size()-1; i>=0; i--){
        if(v[i]){
            int invar=1;
            for(int k=0; k< v.size()-i-1;k++){
                invar = invar*2;
            }
            sum = sum+invar;
        }
    } 
    //printf("after conversion: %d\n", sum);
    return sum; 
}

int num_mosse(int n){
    //printf("num_ mosse %d \n", n);
    if(n == 0)
        return 0;
    if(mappa->find(n) != mappa->end()){
        //printf("CACHE FOUND\n");
        return mappa->find(n)->second;
    }
    if(visited->find(n) != visited->end())
        return 99999999;
    visited->insert(n);
    vector<bool> v = convert(n);
    int size = v.size();
    /*bool tutto_false=true;
    for(auto val: v){
        if(val){
            tutto_false=false;
            break;
        }
    }
    if(tutto_false)
        return 0;*/
    //mossa 2
    int ris_mossa_2;
    int ris_mossa_1;
    vector<bool> vec2;
    for(auto elem: v){
        vec2.push_back(elem);
    }
    int vec2_num;
    for(int i=v.size()-1;i>=0;i--){
        //v[i] è la prima occorrenza a 0 da destra
        if(v[i]){
            if(i > 0){
                vec2[i-1] = !vec2[i-1];
                vec2_num = convert_back(vec2);
                ris_mossa_2 = num_mosse(vec2_num);
                //printf("ris mossa 2: %d\n", ris_mossa_2);
                break;
            }
            else{
                break;
                /*vector<bool>::iterator it;
                it = vec2.begin();
                vec2.insert(it, true);*/
            }
            
        }
    }
    //mossa 1
    vector<bool> vec;
    for(auto elem: v){
        vec.push_back(elem);
    }
    vec[vec.size()-1] = !vec[vec.size()-1];
    int vec_num = convert_back(vec);
    //printf("vec num  mossa 1: %d\n", vec_num);
    ris_mossa_1 = num_mosse(vec_num);
    //printf("ris mossa 1: %d\n", ris_mossa_1);
    if(ris_mossa_1 < ris_mossa_2){
        mappa->insert({vec_num, ris_mossa_1+1});
        return ris_mossa_1+1;
    }
    else{
        mappa->insert({vec2_num, ris_mossa_2+1});
        return ris_mossa_2+1;
    }
}

int main(){
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt","w",stdout));
    int num;
    int azione;//1=num_mosse, 2=se vabene applicare la mossa 2
    int prima;
    int dopo;
    
    vector<bool> vec2;
    scanf("%d", &azione);
    scanf("%d", &num);
    mappa = new map<int, int>();
    visited = new set<int>();
    vector<bool> vec = convert(num);
    if(azione== 1)
        printf("%d", num_mosse(num));
    else{
        prima = num_mosse(num);
        /*for(auto elem: vec){
            vec2.push_back(elem);
        }*/
        for(int i=vec.size()-2;i>=0;i--){
            //vec[i] è la prima occorrenza a 0 da destra
            if(!vec[i] && vec[i+1]){
                vec[i] = !vec[i];
                break;
            }
        }
        dopo=num_mosse(convert_back(vec));
        if(dopo < prima){
            //cout << "ok";
            printf("ok %d < %d", dopo, prima);
        }
        else{
            //cout << "no";
            printf("no %d >= %d", dopo, prima);
        }

    }
}