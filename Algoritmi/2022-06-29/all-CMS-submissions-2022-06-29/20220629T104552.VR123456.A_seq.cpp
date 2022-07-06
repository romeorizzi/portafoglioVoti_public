/**
* user:  VR123456
* fname: TEST
* lname: MY
* task:  A_seq
* score: 0.0
* date:  2022-06-29 10:45:52.622234
*/
#define DEBUG
#define EVAL

#include <iostream>
#include <vector>
#include <cassert>
#include <cstdio>

const unsigned MAXN = 1000;
int g, n, num_left, num_right, max;

int main () 
{
    #ifdef EVAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    std::cin >> g >> n;

    std::vector<int> s(n);
    // Salvo l'array di input in un vettore S
    int tmp, posizione_numero_massimo, numero_massimo = 0;
    for (int i=0; i<n; i++) {
        std::cin >> tmp;
        if (tmp >= max) {
            max = tmp;
            posizione_numero_massimo = i;
        }
        s.at(i) = tmp;
    }

    for (int i=posizione_numero_massimo; i>0; i--) {
        if (s.at(i-1) >= s.at(i)) {
            break;
        }
        if (s.at(i-1) < s.at(i)) {
            num_left += 1;
        }
    }

    for (int i=posizione_numero_massimo; i<n-1; i++) {
        if (s.at(i+1) >= s.at(i)) {
            break;
        }
        if (s.at(i+1) < s.at(i)) {
            num_right += 1;
        }
    }

    // std::cout << "Sottoseguenza left";
    // std::cout << num_left;
    // std::cout << "\n";

    // std::cout << "Sottoseguenza right";
    // std::cout << num_right;
    // std::cout << "\n";


    // std::cout << g;
    // std::cout << " ";
    // std::cout << n;
    // std::cout << "\n";
    
    // for(int i=0; i<n; i++) {
    //     std::cout << s[i];
    // }

    // std::cout << "\n MAX: ";
    int res = num_left + num_right + 1;
    std::cout << res;

    return 0;
}