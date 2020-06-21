/**
* user:  VR439237
* fname: DEPALO
* lname: CHRISTIAN
* task:  Prob2_hanoi_equal_disks
* score: 0.0
* date:  2019-09-04 10:53:00.510205
*/
#include<iostream>
#include<fstream>
#include<cassert>
using namespace std;

const int N = 100000;
int total = 0;
int A[N];

void sposta_disco(int n, char piolo_from, char piolo_to) {
   printf("sposta il disco %d dal piolo %c al piolo %c\n", n, piolo_from, piolo_to);
   total += 1;
}

void sposta_torre(int N, char piolo_from, char piolo_to, char piolo_extra) {
   assert(N>=0);
   if(N==0) return;
   assert(N>=1);
   sposta_torre(N-1, piolo_from,piolo_extra,piolo_to);
   sposta_disco(N,piolo_from,piolo_to);
   sposta_torre(N-1, piolo_extra,piolo_to,piolo_from);
}

int main() {
    int type;
    int num_disks;

    cin >> type;
    cin >> num_disks;  
    
    for(int i = 0; i < num_disks; i++) {
       cin >> A[i];
    }
 
    if(type == 0) {
      sposta_torre(num_disks,'A','C','B');
      cout << total << endl;
    }

    else if(type == 1) {
      sposta_torre(num_disks,'A','C','B');
    }

    return 0;
}
