/**
* user:  VR447848_id898cal
* fname: ALESSIA
* lname: FRASSON
* task:  turniPFG-2DAGs
* score: 10.0
* date:  2021-02-12 10:57:58.436265
*/
// turniPFG-2DAGs.cpp 
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool giorni[100000000];

int main()
{
    long N, K, T, contaliberi;
    string d1, d2, Astr, Bstr;
    long pos;
    long A, B;
    vector<string> disp;

    cin >> T >> K >> N;

    contaliberi = K;

    for (long i = 0; i < N; i++) {
      
        getline(cin, d1, ' ');
        getline(cin, d2);
       
        A = stoi(d1);
        B = stoi(d2);

        for (long j = A; j <= B; j++) {
            if (giorni[j] == false) {
                contaliberi -= 1;
                giorni[j] = true;
            }
        }
    }

    cout << contaliberi;
}
