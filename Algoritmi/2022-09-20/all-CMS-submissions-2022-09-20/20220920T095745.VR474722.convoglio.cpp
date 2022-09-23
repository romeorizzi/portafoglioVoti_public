/**
* user:  VR474722
* fname: LUIGI
* lname: HU
* task:  esame_convoglio
* score: 0.0
* date:  2022-09-20 09:57:45.289797
*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    int n ,m ,i ,k;

    cin >> n;
    cin >> m;

    int navi[n];
    for(i = 0; i < n; i++){
        navi[i] = -1;
    }
    int mess[m][2];

    for(i = 0; i < m; i++){
        cin >> mess[i][0];
        cin >> mess[i][1];
    }
    int c, z;
    for(i = m - 1; i > n - 1; i--){
        navi[mess[i][0]] = mess[i][1];
        c = 1;
        for(k = i - 1; k >= 0; k--){
            cout << c << "\n";
            if(navi[mess[k][0]] == -1){
                for(z = 0; z < n; z++){
                    if(navi[z] == mess[k][1]){
                        break;
                    }
                }
                if(z < n){
                    continue;
                }
                navi[mess[k][0]] = mess[k][1];
                c++;
            }
            if(c == n){
                break;
            }        
        }
        if(c == n){
            break;
        }else{
            for(z = 0; z < n; z++){
                navi[z] = -1;
            }
        }
    }
    //cout << navi[mess[0][0]] << "\n";
    int c1;
    c1 = 0;
    for(i = 0; i < n; i++){
        if(navi[i] == -1){
            c1++;
            break;
        }
    }
    if(c1 > 0){
        cout << -1;
    }
    else{
        for(i = 0; i < n; i++){
            cout << i << " " << navi[i] << "\n";
        }
    }

    return 0;
}