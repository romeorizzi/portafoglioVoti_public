/**
* user:  VR476706
* fname: LUCA
* lname: GUGOLE
* task:  esame_two_three_steps
* score: 0.0
* date:  2023-02-20 12:20:13.329773
*/
#include<fstream>
#define MAX_N 1000001

using namespace std;

int MAXM = INT32_MIN;
//int L[MAX_N];
int N;

int maximize(int l[], int pos, int cost) {
    if (pos >= N) {
        if (cost > MAXM) {
            MAXM = cost;
        }
    } else {
        maximize(l, pos + 2, cost + l[pos]);
        maximize(l, pos + 3, cost + l[pos]);
    }
}

int main() {

    ifstream inp ("input.txt");
    if (inp.is_open()) {
        inp >> N;

        int l[N];
        for (int i = 0; i < N; i++) {
            inp >> l[i];
        }

        maximize(l, 0, 0);

        inp.close();
    }

    ofstream outp ("output.txt");
    outp << MAXM;
    outp.close();

    return 0;
}