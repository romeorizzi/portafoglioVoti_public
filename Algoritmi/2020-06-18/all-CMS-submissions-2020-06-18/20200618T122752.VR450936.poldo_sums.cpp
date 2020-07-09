/**
* user:  VR450936
* fname: MARTINI
* lname: FRANCESCO
* task:  poldo_sums
* score: 5.0
* date:  2020-06-18 12:27:52.205083
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
string s = "";
string stemp = "";
int min;

struct nodo{
    int val;
    int ind;
    int old;
    char c = 'N';
};

vector <vector<nodo>> lista;

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
                s = to_string(temp.ind) + ' ';
            }
            else {
                for (auto itr = lista.begin(); itr != lista.end();) {
                    
                    vector<nodo> ln = *itr;

                    
                    nodo litr = ln[ln.size() - 1];
                        //cout << litr->val;
                    stemp = stemp + to_string(litr.ind) + ' ';
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
                        stemp= stemp + to_string(temp.ind) + ' ';
                        break;
                    }
                    else {

                        flag = false;
                    }
                    

                    
                                       
                }


            }
          
            if (s.size() < stemp.size())
                s = stemp;
            stemp = "";
        }
        ifile.close();
    }
    else {
        cout << "fail";
    }

    

    
    ofile.open("./output.txt");
    if (ofile.is_open()) {

        
        int alt;
        ofile << lista.size() << endl;
        ofile << s;
        ofile.close();


    }
    else {
        cout << "fail";
    }

    return 0;


}