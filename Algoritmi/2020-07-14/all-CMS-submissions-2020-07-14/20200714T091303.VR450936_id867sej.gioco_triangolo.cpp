/**
* user:  VR450936_id867sej
* fname: FRANCESCO
* lname: MARTINI
* task:  gioco_triangolo
* score: 0.0
* date:  2020-07-14 09:13:03.878369
*/
#include<iostream>
#include<string>
#include<fstream>
#include<list>
#include<vector>
using namespace std;

int T, N,
int game[100000];
int val_ini;

char M, M_='N';
int l, v1, v2;
int l_=0, v1_=0, v2_=0;

void calc1() {

    if (v1 == 0 || v2 == 0){
        M_ = 'N';
        l_ = l;
        v1_ = v1;
        v2_ = v2;
        return;
        }

    val_ini ^= l;
    val_ini ^= v1;
    val_ini ^= v2;

    return;
}



void calc2() {


    return;
}




int main() {

    ifstream ifile;
    ofstream ofile;

    ifile.open("./input.txt");
    if (ifile.is_open()) {

        ifile >> T >> N;

        for (int i = 0; i < N; i++) {

            ifile >> game[i];
            val_ini ^=  game[i];

        }

        ifile >> M >> l >> v1 >> v2;

        ifile.close();


    }
    else {
        cout << "fail";
    }


    ofile.open("./output.txt");
    if (ofile.is_open()) {

        if (T == 1) {
            if (M == 'N') {
                ofile << 'T ' << l << ' ' << v1 << ' ' << v2;
            }
            else {
                calc1();
                ofile << M_ <<' ' << l_ << ' ' << v1_ << ' ' << v2_;

            }
        }
        else {
            if (val_ini == 0) {
                ofile << 0;
            }
            else {

                calc2();
                ofile << 1;
                ofile << M_ << ' ' << l_ << ' ' << v1_ << ' ' << v2_;
            }


        }

        ofile.close();


    }
    else {
        cout << "fail";
    }

    return 0;


}
