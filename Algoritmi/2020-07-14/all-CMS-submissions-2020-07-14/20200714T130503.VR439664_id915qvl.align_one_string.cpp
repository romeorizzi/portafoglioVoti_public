/**
* user:  VR439664_id915qvl
* fname: NEREO
* lname: SORIO
* task:  align_one_string
* score: 0.0
* date:  2020-07-14 13:05:03.684139
*/
#include <iostream>

bool is_comp(const char c1, const char c2){
    return c1==c2 || c1 == '*' || c2 == '*';
}

std::string rep(const char c, int delta){
    std::string result="";

    for(int i=0;i<delta;i++){
        result+="c";
    }
    return result;
}



int allinea_stringhe(int pos_a, int pos_b, std::string a, std::string b, int costi[], int asterischi){


}

int main(){

    //input
    int m, n, p;

    std::cin >> m >> n >> p;

    std::string a;
    std::cin >> a;
    std::string b;
    std::cin >> b;

    int costi[p+1];
    for(int i=0;i<p;i++){
       std::cin >> costi[i];
    }
    /*for(int i=0;i<p;i++){
        std::cout << costi[i] << " ";
    }*/

    bool flag = true; 
   
    return 0;
}