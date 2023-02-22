/**
* user:  VR476706
* fname: LUCA
* lname: GUGOLE
* task:  esame_two_three_steps
* score: 0.0
* date:  2023-02-20 12:17:06.165285
*/
#include<fstream>
#define MAX_N 1000001

using namespace std;

int MAXM = INT32_MIN;
int L[MAX_N];
int N;

int maximize(int pos, int cost) {
    if (pos >= N) {
        if (cost > MAXM) {
            MAXM = cost;
        }
    } else {
        maximize(pos + 2, cost + L[pos]);
        maximize(pos + 3, cost + L[pos]);
    }
}

int main() {

    ifstream inp ("input.txt");
    if (inp.is_open()) {
        inp >> N;

        for (int i = 0; i < N; i++) {
            inp >> L[i];
        }

        maximize(0, 0);

        inp.close();
    }

    ofstream outp ("output.txt");
    outp << MAXM;
    outp.close();

    return 0;
}