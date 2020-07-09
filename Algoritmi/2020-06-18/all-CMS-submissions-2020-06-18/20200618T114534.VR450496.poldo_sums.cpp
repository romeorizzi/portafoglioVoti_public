/**
* user:  VR450496
* fname: ZANNI
* lname: GUGLIELMO
* task:  poldo_sums
* score: 0.0
* date:  2020-06-18 11:45:34.179915
*/
#include <iostream>
#include <fstream>

int n;
int play_move[2];

void win(int N){
    if(N < 10){
        play_move[0] = 1;
        play_move[1] = N%10;
        return;
    }
    if(N % 10 == 0){
        play_move[0] = 0;
        play_move[1] = -1;
        return;
    }
    else {
        play_move[0] = 1;
        play_move[1] = N%10;
        return;
    }
}

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    std::cin >> n;

    win(n);
    if(play_move[1] == -1) {
        std::cout << play_move[0];
        return 0;
    } else {
        std::cout << play_move[0];
        std::cout << " ";
        std::cout << play_move[1];
        return 0;
    }

    //return 0;
}
