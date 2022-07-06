/**
* user:  VR123456
* fname: TEST
* lname: MY
* task:  A_seq
* score: 0.0
* date:  2022-06-29 12:13:56.658220
*/
#define DEBUG
#define EVAL

#include <iostream>
#include <vector>
#include <cassert>
#include <cstdio>

const unsigned MAXN = 1000;
int g, n, num_left, num_right, max, sum, count;

int main () 
{
    #ifdef EVAL
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    std::cin >> g >> n;

    std::vector<int> s(n);
    // Salvo l'array di input in un vettore S
    int tmp, posizione_numero_massimo, numero_massimo = 0;
    for (int i=0; i<n; i++) {
        std::cin >> tmp;
        if (tmp >= numero_massimo) {
            // numero_massimo = tmp;
            // posizione_numero_massimo = i;
        }
        s.at(i) = tmp;
    }

    int res = 0;
    for (int i=0; i<n; i++) {
        num_left = num_right = 0;
        for (int j=i; j>0; j--) {
            if (s.at(j-1) >= s.at(j)) {
                break;
            } else if (s.at(j-1) < s.at(j)) {
                num_left += 1;
            }
        }

        for (int j=i; j<n-1; j++) {
            if (s.at(j+1) >= s.at(j)) {
                break;
            } else if (s.at(j+1) < s.at(j)) {
                num_right += 1;
            }
        }
        std::cout << "CENTRO: " << i << "\t";
        std::cout << "NUMERO: " << s.at(i) << "\t";
        std::cout << "LEFT: " << num_left << "\t";
        std::cout << "RIGHT: " << num_right << "\n";

        res = num_left + num_right + 1;
        if (sum < res) {
            count = 1;
            sum = num_left + num_right + 1;
        } else if (sum == res) {
            count++;
        }
    }

    if (g == 1) {
        std::cout << sum;
    } else if (g == 2) {
        std::cout << count;
    }

    return 0;
}