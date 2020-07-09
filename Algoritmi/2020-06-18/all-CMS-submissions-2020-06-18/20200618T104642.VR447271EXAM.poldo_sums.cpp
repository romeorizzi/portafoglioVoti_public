/**
* user:  VR447271EXAM
* fname: BALLINI
* lname: LEONARDO
* task:  poldo_sums
* score: 0.0
* date:  2020-06-18 10:46:42.828497
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


string solve ( int last, int index);
int sum_gym(int from, int to);
map <long int , string> memo;


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

    string solution = solve(0,1);
    ofstream output("output.txt");
    output << to_string(count(solution.begin(), solution.end(), ' ') )<< "\n";
    output << solution;
}


string solve ( int last, int index){

    if (index == size+1){
        return " ";
    }

    string tmp;
    try {
        tmp = memo.at(last*(size*10)+index);      // vector::at throws an out-of-range
    }
    catch (const std::out_of_range& oor) {
        tmp = "";
    }
    if (tmp != ""){
        return tmp;
    }



    if(panini[index] < panini[last] || panini[index] < ( sum_gym(last,index) + panini[last]) ){
        memo.insert( pair<int,string>(last*(size*10)+index , solve(last, index +1)) );
        return memo.at(last*(size*10)+index);
    }else{
        string s1 = solve(last, index + 1);
        string s2 = solve(index, index + 1);
        s2 = " " + to_string(index - 1 ) + s2;

        if(count(s1.begin(), s1.end(), ' ') > count(s2.begin(), s2.end(), ' ') ){
            memo.insert( pair<int,string>(last*(size*10)+index , s1 ));
        }else{
            memo.insert( pair<int,string>(last*(size*10)+index , s2 ));
        }
        return memo.at(last*(size*10)+index);
    }
}

int sum_gym(int from, int to){
    int sum = 0;
    for (int i = from ; i < to ; i++)
        sum+= gym[i];
    return sum;
}