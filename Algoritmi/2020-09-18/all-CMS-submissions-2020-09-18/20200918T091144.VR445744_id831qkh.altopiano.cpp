/**
* user:  VR445744_id831qkh
* fname: RICCARDO
* lname: BARTOLOMIOLI
* task:  altopiano
* score: 1.0
* date:  2020-09-18 09:11:44.137303
*/
#include <iostream>
using namespace std;
int N, M, alt[100000];

int main() {
   cin >> N >> M;
   for (int i = 0; i < N; i++) {
     cin >> alt[i];
   }

   for (int i = 0; i < M; i++) {
      int dec;
      cin >> dec;
      if (dec == 1) {
        int x, y;
        cin >> x >> y;
        alt[x] += y;
      }
      else {
         int start, end, max_alt = 0, length = 1;
         bool found = false;
         cin >> start >> end;
         for (int i = start; i < end; i++) {
            if (alt[i] == alt[i+1]) {
               length += 1;
               if (length == 3) {
                  found = true;
                  max_alt = max(max_alt, alt[i]);
               }
            }
            else {
               length = 1;
            }
         }
         if (found) {
            cout << max_alt;
         }
         else {
            cout << "NESSUN_ALTOPIANO";
         }
      }
   }
   return 0;
}
