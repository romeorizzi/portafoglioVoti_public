/**
* user:  VR450936_id867sej
* fname: FRANCESCO
* lname: MARTINI
* task:  gioco_triangolo
* score: 0.0
* date:  2020-07-14 09:21:56.832489
*/
#include<iostream>
#include<string>
#include<fstream>
#include<list>
#include<vector>
using namespace std;

int T, N;
int game[100000];
int val_ini;

char M, M_='T';
int l, v1, v2;
int l_=1, v1_=0, v2_=0;

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

    

        cin >> T >> N;

        for (int i = 0; i < N; i++) {

            cin >> game[i];
            val_ini ^=  game[i];

        }

        cin >> M >> l >> v1 >> v2;

  




        if (T == 1) {
            if (M == 'N') {
                cout << "T " << l << ' ' << v1 << ' ' << v2;
            }
            else {
                calc1();
                cout << M_ <<' ' << l_ << ' ' << v1_ << ' ' << v2_;

            }
        }
        else {
            if (val_ini == 0) {
                cout << 0;
            }
            else {

                calc2();
                cout << 1 << endl;
                cout << M_ << ' ' << l_ << ' ' << v1_ << ' ' << v2_;
            }


        }

        
    return 0;


}
