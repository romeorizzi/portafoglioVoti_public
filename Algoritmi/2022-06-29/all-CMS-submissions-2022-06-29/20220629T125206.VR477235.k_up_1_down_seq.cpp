/**
* user:  VR477235
* fname: MATTEO
* lname: CAVALIERE
* task:  k_up_1_down_seq
* score: 84.0
* date:  2022-06-29 12:52:06.258743
*/
#include <iostream>
#include <string>

int G, N, K;
int memo[1001][1001];
int V[1000];
int V2[1000];
int R = -1;
long long int NUM = 1000000007;

int n_seq(int prec, int index) {
    if (index == N) {
        if (G == 2) {
            R--;
            if (R == -1) {
                for (int i = 0; i < N - 1; i++) {
                    std::cout << V[i] << " ";
                }
                std::cout << V[N - 1] << "\n";
                exit(0);
            }
        }

        if (G == 4) {
            for (int i = 0; i < N - 1; i++) {
                std::cout << V[i] << " ";
            }
            std::cout << V[N - 1] << "\n";
        }

        if (G == 3) {
            R++;
            for (int i = 0; i < N; i++) {
                if (V[i] != V2[i]) {
                    return 1;
                }
            }
            std::cout << R << std::endl;
            exit(0);
        }
        
        return 1;
    }

    int count = 0;
    if (prec - 1 - (N - index) <= 0 && prec - 1 >= 0) {
        V[index - 1] = prec - 1;
        count += n_seq(prec - 1, index + 1);
    }

    if (prec - (N - index) <= 0) {
        V[index - 1] = prec;
        count += n_seq(prec, index + 1);
    }

    if (prec + K - (N - index) <= 0) {
        V[index -1] = prec + K;
        count += n_seq(prec + K, index + 1);
    }

    return count;
}

int main () {
    std::cin >> G;
    std::cin >> N;
    std::cin >> K;

    for (int i = 0; i < K + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            memo[i][j] = -1;
        }
    }

    if (G == 2) {
        std::cin >> R;
    }

    if (G == 3) {
        for (int i = 0; i < N; i++) {
            std::cin >> V2[i];
        }
    }

    int res = n_seq(0, 2);

    if (G != 4 && G != 3) {
        std::cout << (res % NUM) << std::endl;
    }
}