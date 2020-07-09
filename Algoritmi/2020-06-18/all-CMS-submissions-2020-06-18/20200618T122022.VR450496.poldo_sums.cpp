/**
* user:  VR450496
* fname: ZANNI
* lname: GUGLIELMO
* task:  poldo_sums
* score: 0.0
* date:  2020-06-18 12:20:22.669886
*/
#include <iostream>
#include <fstream>
#include <vector>

#define MAX_ELEM 100000
//#define EVAL
//#define TEST 1

int panini[MAX_ELEM] = {0};
int palestra[MAX_ELEM] = {0};
int N = -1;
int temp = 0;
int sequenza[MAX_ELEM] = {0};
int result[1000][1000];

int compute_tot_gym(const int gym[MAX_ELEM], const int i, const int j){
    int res = -1001;
    if(i == -1 || j == -1){
        return res;
    }
    res = 0;
    for(int k = i; k < j; ++k){
        res+=gym[k];
    }
    return res;
}

void poldo_sum(const int pan[MAX_ELEM], const int pal[MAX_ELEM], int cont, int seq[MAX_ELEM], int index, int base_index){

    if(cont == 0 || base_index == 0){
        return;
    }
    if(index >= base_index){
        poldo_sum(pan, pal, cont, seq, 1, base_index-1);
    }
    temp = compute_tot_gym(pal, seq[index-1], seq[base_index]-1);
    if(pan[seq[base_index]] < pan[seq[index-1]] + temp){
        result[index][base_index] = -1;
        poldo_sum(pan, pal, cont, seq, index+1, base_index);
    } else {
        result[index][base_index] = 1;
        poldo_sum(pan, pal, cont, seq, index+1, base_index);
    }

}

/*void poldo_sum(const int pan[MAX_ELEM], const int pal[MAX_ELEM], int seq[MAX_ELEM], int max_seq){

    int tot_gym = -1001;

    for(int i = 0; i < max_seq; ++i){
        for(int j = 0; j < N; ++j){
            tot_gym = compute_tot_gym(pal, i, j);
            if(pan[j] >= pan[i] + tot_gym){
                for(int k = 0; k < N; ++k){
                    if(seq[k] == -1 && seq[k] < seq[j]){
                        if(seq[j] >= seq[k] + compute_tot_gym(pal, seq[k], seq[j]-1)){
                            seq[k+1] = seq[j];
                            break;
                        }
                    }
                }
            }
        }
    }
}*/

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    std::cin >> N;
    for(int i = 0, j = 0; i < N && j < N; ++i, ++j){
        std::cin >> panini[i];
        std::cin >> palestra[j];
        sequenza[i] = i;
    }

    poldo_sum(panini, palestra, N, sequenza, 1, N-1); //cont vale 0, no sequenze

    temp = 0;
    int max = -1;
    int row = -1;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(result[i][j] == 1){
                ++temp;
            }
        }
        if(temp > max){
            max = temp;
            row = i;
        }
    }
    std::cout << temp;
    for(int j = 0; j < N; ++j){
        if(result[row][j] == 1){
            std::cout << j;
            std::cout << " ";
        }
    }


    return 0;
}
