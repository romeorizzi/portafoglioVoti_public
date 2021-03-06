/**
* user:  VR447271EXAM
* fname: BALLINI
* lname: LEONARDO
* task:  poldo_sums
* score: 18.0
* date:  2020-06-18 12:34:21.204727
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int * panini;
int * gym ;
int size;


string solve ( int last, int index, int gymm);
int sum_gym(int from, int to);



int main(){

    ifstream input ("input.txt");
    input >> size;
    panini = new int [size+1];
    gym = new int [size+1];




    panini[0]=0;
    gym[0] =0;
    for(int index = 1 ; index <= size ; index++){
        input >> panini[index] >> gym[index] ;
    }

    string solution = solve(0,1,0);
    ofstream output("output.txt");
    output << to_string(count(solution.begin(), solution.end(), ' ') -1)<< "\n";
    output << solution<< "\n";
}


string solve ( int last, int index, int gymm){

    if (index == size+1){
        return " ";
    }

    string tmp;

    pair<pair<int,int>,string> pair_tmp;

    if( panini[index] < gymm +  panini[last]){
        while(panini[index] < gymm +  panini[last] && index <= size){
            gymm+= gym[index];
            index ++;
        }

        return solve(last, index , gymm);
    }else{
        string s1 = solve(last, index + 1, gymm + gym[index] );
        string s2 = solve(index, index + 1, gym[index] );
        s2 = " " + to_string(index - 1 ) + s2;

        if(count(s1.begin(), s1.end(), ' ') > count(s2.begin(), s2.end(), ' ') ){
            return s1 ;
        }else{
            return s2 ;
        }
    }
}