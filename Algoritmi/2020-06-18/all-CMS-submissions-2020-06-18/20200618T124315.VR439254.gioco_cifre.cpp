/**
* user:  VR439254
* fname: TOAIARI
* lname: ANDREA
* task:  gioco_cifre
* score: 20.0
* date:  2020-06-18 12:43:15.619930
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int numero;
    cin >> numero;
    int t;
    while (numero != 0)
    {
        if (numero%10 != 0){
            t = numero%10;
            break;
        }
        numero /= 10;
    }
    
    
    
    cout << 1 << " " << t <<endl;
    return 0;
}