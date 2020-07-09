/**
* user:  VR436720
* fname: BERTI
* lname: MARCO
* task:  gioco_cifre
* score: 100.0
* date:  2020-06-18 11:03:20.247623
*/
#include <stdio.h>
#include <iostream>
using namespace std;

int partenza;
int tolgo;
// int calc(int p){
//     if (p == 10)
//     {
//         return 0;
//     }
//     else
//     {
//         if(p%10 != 0)
//             p = p - (p % 10);
        
//     }
    
    
    
//     return;
// }
int main(){

    cin >> partenza;
    if((partenza % 10) == 0)
        cout << 0;
    else
    {
        tolgo  = partenza%10;
        cout << 1 << " " << tolgo;
    }
        

    return 0;
}