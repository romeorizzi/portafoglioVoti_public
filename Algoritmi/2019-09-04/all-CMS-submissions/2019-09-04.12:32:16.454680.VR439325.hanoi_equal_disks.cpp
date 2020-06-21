/**
* user:  VR439325
* fname: GILARDI
* lname: DANIELE
* task:  Prob2_hanoi_equal_disks
* score: 0.0
* date:  2019-09-04 12:32:16.454680
*/
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int t,n;
int conteggio=0;
vector <int> vettore_dischi_a1;
vector <int> vettore_dischi_a2;
vector <int> vettore_dischi_b1;
vector <int> vettore_dischi_b2;
vector <int> vettore_dischi_c1;
vector <int> vettore_dischi_c2;
vector <int> ::iterator it;
vector <char> vettore_mosse;
string temp_string;

void sposta(char da, char a){
    if (da=='A' && a=='B'){
        vettore_mosse.push_back(vettore_dischi_a2.front());
        vettore_mosse.push_back('A');
        vettore_mosse.push_back('B');
        vettore_dischi_b1.insert(vettore_dischi_b1.begin(),  vettore_dischi_a1.front());
        vettore_dischi_b2.insert(vettore_dischi_b2.begin(),   vettore_dischi_a2.front());
        vettore_dischi_a1.erase(vettore_dischi_a1.begin());
        vettore_dischi_a2.erase(vettore_dischi_a2.begin());
        conteggio++;
    }
    if (da=='B' && a=='C'){
        vettore_mosse.push_back(vettore_dischi_b2.front());
        vettore_mosse.push_back('B');
        vettore_mosse.push_back('C');
        vettore_dischi_c1.insert(vettore_dischi_c1.begin(),vettore_dischi_b1.front());
        vettore_dischi_c2.insert(vettore_dischi_c2.begin(),vettore_dischi_b2.front());
        vettore_dischi_b1.erase(vettore_dischi_b1.begin());
        vettore_dischi_b2.erase(vettore_dischi_b2.begin());
        conteggio++;
    }
    if (da=='A' && a=='C'){
        vettore_mosse.push_back(vettore_dischi_a2.front());
        vettore_mosse.push_back('A');
        vettore_mosse.push_back('C');
        vettore_dischi_c1.insert(vettore_dischi_c1.begin(),vettore_dischi_a1.front());
        vettore_dischi_c2.insert(vettore_dischi_c2.begin(),vettore_dischi_a2.front());
        vettore_dischi_a1.erase(vettore_dischi_a1.begin());
        vettore_dischi_a2.erase(vettore_dischi_a2.begin());
        conteggio++;
    }
    if (da=='C' && a=='B'){
        vettore_mosse.push_back(vettore_dischi_c2.front());
        vettore_mosse.push_back('C');
        vettore_mosse.push_back('B');
        vettore_dischi_b1.insert(vettore_dischi_b1.begin(),vettore_dischi_c1.front());
        vettore_dischi_b2.insert(vettore_dischi_b1.begin(),vettore_dischi_c2.front());
        vettore_dischi_c1.erase(vettore_dischi_c1.begin());
        vettore_dischi_c2.erase(vettore_dischi_c2.begin());
        conteggio++;
    }
    if (da=='C' && a=='A'){
        vettore_mosse.push_back(vettore_dischi_c2.front());
        vettore_mosse.push_back('C');
        vettore_mosse.push_back('A');
        vettore_dischi_a1.insert(vettore_dischi_a1.begin(),vettore_dischi_c1.front());
        vettore_dischi_a2.insert(vettore_dischi_a2.begin(),vettore_dischi_c2.front());
        vettore_dischi_c1.erase(vettore_dischi_c1.begin());
        vettore_dischi_c2.erase(vettore_dischi_c2.begin());
        conteggio++;
    }
}


int main(){

    scanf("%d%d", &t, &n);
    int temp;
    int prossimo_disco;
    
    
    for(int i=0; i<n; i++){
        scanf("%d", &temp);
        vettore_dischi_a1.push_back(temp);
        vettore_dischi_a2.push_back(i+1);
    }

    for(it=vettore_dischi_a1.begin(); it!=vettore_dischi_a1.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    for(it=vettore_dischi_a2.begin(); it!=vettore_dischi_a2.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    int size=vettore_dischi_a1.size();

    while(vettore_dischi_b1.size()<size){
        cout << vettore_dischi_b1.size()<<" "<<endl;
        int a=vettore_dischi_a1.front();
        int b=vettore_dischi_b1.front();
        int c=vettore_dischi_c1.front();
        if(vettore_dischi_a1.size()==1 && vettore_dischi_b1.size()==0){
            sposta('A','B');
        }
        else if(vettore_dischi_a1.size()>0 && vettore_dischi_b1.size()==0 && vettore_dischi_c1.size()==0){
            sposta('A', 'B');
        }
        else if(vettore_dischi_a1.size()>1 && vettore_dischi_b1.size()>0 &&   vettore_dischi_c1.size()==0){
            sposta('A','C');
        }
        else if(vettore_dischi_a1.size()==0 && vettore_dischi_b1.size()>0 && vettore_dischi_c1.size()>1){
            sposta('C','A');
        }
        else if(vettore_dischi_a1.size()==1 && vettore_dischi_c1.size()==0){
            sposta('A','B');
        }
        else if(vettore_dischi_a1.size()>0 && vettore_dischi_b1.size()>0 && vettore_dischi_c1.size()>0){
            if(vettore_dischi_c2.front()==vettore_dischi_b2.front()-1){
                if(vettore_dischi_c1.size()>0) sposta('C','B');
            }
            else if(vettore_dischi_a2.front()==vettore_dischi_b2.front()-1){
                if(vettore_dischi_a1.size()>0) sposta('A','B');
            }
            else if(vettore_dischi_b2.front()<vettore_dischi_c2.front()){
                if(vettore_dischi_b1.size()>0) sposta('B','C');
            }
            else if(vettore_dischi_c2.front()<vettore_dischi_b2.front()){
                if(vettore_dischi_c1.size()>0) sposta('C','B');
            }
            
            else if(vettore_dischi_a1.front()<= vettore_dischi_c1.front() && (vettore_dischi_a1.front()>vettore_dischi_b1.front())){
                if(vettore_dischi_a1.size()>0) sposta('A','C');
            }
            else{}
        }
        else{}
    }
    
    printf("%d",conteggio);
    
    
    for(int i=0; i<conteggio; i++){
        cout<<"sposta il disco "<<vettore_mosse[i]<<" dal piolo "<< vettore_mosse[i+1] <<" al piolo "<< vettore_mosse[i+2]   <<endl;
    }
    
    return 0;
}