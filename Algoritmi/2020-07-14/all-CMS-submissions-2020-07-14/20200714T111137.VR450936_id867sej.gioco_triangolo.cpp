/**
* user:  VR450936_id867sej
* fname: FRANCESCO
* lname: MARTINI
* task:  gioco_triangolo
* score: 0.0
* date:  2020-07-14 11:11:37.805311
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
int count = 0;

void calc1() {
    M_ = 'N';

    if (v1 == 0 || v2 == 0){
        l_ = l;
        v1_ = v1;
        v2_ = v2;
        return;
        }

    int tmp1 = val_ini;
    val_ini ^= l;
    val_ini ^= v1;
    val_ini ^= v2;

    int tmp = 0;
    tmp ^= tmp1;
    tmp ^= val_ini;

    for (int i = 0; i < N; i++) {
        
        l_ = game[i];

       if (l_ > tmp) {
                v1_ = l_ - tmp;
                v2 = 0;
          break;
       }

    }
    

    return;
}



void calc2() {

    for (int i = 0; i < N; i++) {

       
      

    }

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
                cout << "T " << l_ << ' ' << v1_ << ' ' << v2_;
            }


        }

        
    return 0;


}
