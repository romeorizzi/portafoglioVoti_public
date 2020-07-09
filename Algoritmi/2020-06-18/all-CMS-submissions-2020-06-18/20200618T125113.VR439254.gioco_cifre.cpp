/**
* user:  VR439254
* fname: TOAIARI
* lname: ANDREA
* task:  gioco_cifre
* score: 100.0
* date:  2020-06-18 12:51:13.935342
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int numero;
    int numero_cp;
    cin >> numero;
    numero_cp = numero;
    int t;

    
    while (numero != 0)
    {
        if (numero%10 != 0){
            t = numero%10;
            break;
        }
        numero /= 10;
    }
    
    
    if (numero_cp % 10 == 0)
        cout << 0 << endl;
    else
        cout << 1 << " " << t <<endl;
    return 0;
}