/**
* user:  VR445666
* fname: GAIARDELLI
* lname: SEBASTIANO
* task:  poldo_sums
* score: 59.0
* date:  2020-06-18 11:03:33.067761
*/
#include <bits/stdc++.h>

using namespace std;
int N;

int main(){

    ifstream input;
    ofstream output;
    input.open("input.txt");
    output.open("output.txt");

    //int N = 0;
    input >> N;

    int *menu, *lds, *gym;
    int prev[N];
    long int *sum;

    menu = new int[N];
    gym = new int[N];
    lds = new int[N];
    sum = new long int[N];

    input >> menu[0];
    input >> gym[0];
    sum[0] = gym[0];
    lds[0] = 1;
    prev[0]= -1;
    for(int i = 1; i < N ; i++){
        input >> menu[i];
        input >> gym[i];
        sum[i] = sum[i-1] + gym[i];
        lds[i]=1;
        prev[i]=-1;
    }

    /*std::cout << "menu\n";
    for(int i = 0; i < N ; i++){
        std::cout << menu[i] << " ";
    }
    std::cout << "\n";

    
    std::cout << "gym\n";
    for(int i = 0; i < N ; i++){
        std::cout << gym[i] << " ";
    }
    std::cout << "\n";

    std::cout << "sum\n";
    for(int i = 0; i < N ; i++){
        std::cout << sum[i] << " ";
    }
    std::cout << "\n";*/

    int max = 1;
    int max_index=0;
    for(int i = 1; i < N ; i++){
        int j = 0;
        //case j = 0
        if(lds[i]<lds[j]+1 && menu[j] + (sum[i-1])<= menu[i]){
            lds[i]=lds[j]+1;
            prev[i]=j;
        }

        for(j = 1; j < i ;j++){
            //cout << "i=" << i << " j="<<j << " menu[j]="menu[j] << " menu[i]+"
            if(lds[i]<lds[j]+1 && menu[j] + (sum[i-1]-sum[j-1]) <= menu[i]){
                
                lds[i]=lds[j]+1;
                prev[i]=j;
                //cout <<"\n"<< j << " " << prev[j] << "\n";
            }
        }

        if(lds[i]>max){
            max = lds[i];
            max_index=i;
        }
        /*for(int j = 0; j < i ;j++){
            if(menu[j] <= menu[i] && lds[i] < lds[j]+1){
                lds[i]=lds[j]+1;
            }
        }*/
    }

    //std::cout << "lds\n";
    /*for(int i = 0; i < N ; i++){
        std::cout << lds[i] << " ";
    }*/

    output << max << "\n";
    //std::cout << "\nmax=" << max << "\n";
    //std::cout << "\nmax_idx=" << max_index << "\n";

    //find sequence
    std::string seq = "";
    //std::string num = "";
    //for(int i = N-1 ; i >= 0 ; i--){
        //std::cout << lds[i] << " ";
    //    if(max==lds[i]){
    seq = std::to_string(max_index) + " " + seq;
    //num = std::to_string(menu[max_index]) + " " + num;
    
    while(prev[max_index]!=-1){
        max_index = prev[max_index];
        seq = std::to_string(max_index) + " " + seq;
        //num = std::to_string(menu[max_index]) + " " + num;
    }

//    break;
//}

    //}
    //std::cout << "\nprev\n";

    //for(int i = 0; i < N ; i++){
    //    std::cout << prev[i] << " ";
    //}
    //std::cout << "\n";

    output << seq << "\n";
    //std::cout << max << "\n";
    //std::cout << "seq= " <<seq << "\n";
    //std::cout << "num= " <<num << "\n";

    return 0;
}