/**
* user:  VR450936
* fname: MARTINI
* lname: FRANCESCO
* task:  poldo_sums
* score: 59.0
* date:  2020-06-18 11:58:50.709914
*/
#include<iostream>
#include<string>
#include<fstream>
#include<list>
#include<vector>
using namespace std;

int N, B;
int gym[100000];
int bun[100000];

int min;

struct nodo{
    int val;
    int ind;
    int old;
    char c = 'N';
};

vector <vector <nodo>> lista;

int main() {

    ifstream ifile;
    ofstream ofile;
    int len = 0;
    int tmp;
    int flag=false;
    int ind1=0, oldind;

    ifile.open("./input.txt");
    if (ifile.is_open()) {
        ifile >> N;
        for (int i = 0; i < N; i++) {

            ifile >> bun[i];
            ifile >> tmp;
            if (i > 0)
                gym[i] = gym[i - 1] + tmp;

            nodo temp;
            temp.val = bun[i];
            temp.ind = i;

            if (i == 0) {
                temp.c = 'F';
                gym[0] = tmp;
                vector<nodo> ln;
                ln.push_back(temp);
                lista.push_back(ln);
            }
            else {
                for (auto itr = lista.begin(); itr != lista.end();) {
                    
                    vector<nodo> ln = *itr;

                    
                    nodo litr = ln[ln.size() - 1];
                        //cout << litr->val;
               
                    if (temp.val >= (litr.val + gym[temp.ind - 1] - gym[litr.ind - 1])) {
                        temp.old = ln.size() - 1;
                        flag = true;
                    }

                        
                    if (!flag) {
                        itr->push_back(temp);
                        break;
                    }

                    itr++;

                    if (itr == lista.end() && flag) {
                        vector<nodo> ln1;
                        ln1.push_back(temp);
                        lista.push_back(ln1);
                        flag = !flag;
                        break;
                    }
                    else {

                        flag = false;
                    }
                    

                    
                                       
                }


            }
            
        }
        ifile.close();
    }
    else {
        cout << "fail";
    }

    

    string s = "";
    ofile.open("./output.txt");
    if (ofile.is_open()) {

        
        int alt;
        ofile << lista.size() << endl;
                
        if (lista.size() > 0) {
            auto it = lista[lista.size() - 1].begin();
            s= to_string(it->ind) + ' ';
            alt = it->old;
            for (int i = 0; i < lista.size() - 1; i++) {
                auto vec = lista[lista.size() - i - 2];
                
                s = ' ' + s;
                s= to_string(vec[alt].ind) + s;
                alt = vec[alt].old;
            }
        }
        ofile << s;
        ofile.close();


    }
    else {
        cout << "fail";
    }

    return 0;


}