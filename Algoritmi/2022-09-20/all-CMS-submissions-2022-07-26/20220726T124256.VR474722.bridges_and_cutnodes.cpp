/**
* user:  VR474722
* fname: LUIGI
* lname: HU
* task:  esamebridges_and_cutnodes
* score: 15.0
* date:  2022-07-26 12:42:56.553497
*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    int t, n, m;
    cin >> t;
    cin >> n;
    cin >> m;

    int g[n][n];
    int i, k, a, b;

    for(i = 0; i < n; i++)
        for(k = i; k < n; k++)
            g[i][k] = 0;
    for(i = 0; i < m; i++){
        cin >> a;
        cin >> b;
        g[a][b] = 1;
        }
    if(t == 1){
        for(i = 0; i < n; i++)
            for(k = i + 1; k < n; k++)
                if(g[i][k] == 1){
                    for(a = 0, b = 0; a < n; a++){
                        if(a < i){
                            if(g[a][i] == 1){
                                if(a < k && g[a][k] == 1)
                                    b++;
                                else if(a > k && g[k][a] == 1)
                                    b++;
                            }
                        }
                        else if(a > i ){
                            if(g[i][a] == 1){
                                if(a < k && g[a][k] == 1)
                                    b++;
                                else if(a > k && g[k][a] == 1)
                                    b++;
                            }
                        }       
                    }
                    if(b == 0)
                        g[i][k] = 2;
                }
        
        for(i = 0; i < n; i++)
            for(k = i + 1; k < n; k++)
                if(g[i][k] > 0)
                    cout << g[i][k] - 1 << "\n"; 
    }  
    if (t == 2){
        for(i = 0; i < n; i++)
            for(k = i + 1; k < n; k++)
                if(g[i][k] == 1){
                    for(a = 0, b = 0; a < n; a++){
                        if(a < i){
                            if(g[a][i] == 1){
                                if(a < k && g[a][k] == 1)
                                    b++;
                                else if(a > k && g[k][a] == 1)
                                    b++;
                            }
                        }
                        else if(a > i ){
                            if(g[i][a] == 1){
                                if(a < k && g[a][k] == 1)
                                    b++;
                                else if(a > k && g[k][a] == 1)
                                    b++;
                            }
                        }       
                    }
                    if(b == 0)
                        g[i][k] = 2;
                }
        
        for(i = 0; i < n; i++)
            for(k = i + 1; k < n; k++)
                if(g[i][k] == 2){
                    int c;
                    for(a = 0, b = 0, c = 0; a < n; a++){
                        if(a < i){
                            if(g[a][i] > 0)
                                b++;         
                        }
                        else if(a > i){
                            if(g[i][a] > 0)
                                b++;
                        } 
                        if(a < k){
                            if(g[a][k] > 0)
                                c++;         
                        }
                        else if(a > k){
                            if(g[k][a] > 0)
                                c++;
                        }          
                    }
                    if(b > 1)
                        g[i][i] = 3;
                    if(c > 1)
                        g[k][k] = 3;
                }else if(g[i][k] == 1){
                    for(a = 0; a < n; a++){
                        if(a < i && g[i][i] != 4){
                            if(g[a][i] > 0 && g[a][k] > 0){
                                g[i][i] = 4;
                            }else 
                                g[i][i] = 5;
                        }
                        else if(a > i && a != k && g[i][i] != 4){
                            if(g[i][a] > 0 && g[k][a] > 0)
                                g[i][i] = 4;
                            else 
                                g[i][i] = 5;
                        }
                    } 
                    for(a = 0; a < n; a++){
                        if(a < k && a != i && g[k][k] != 4){
                            if(g[a][i] > 0 && g[a][k] > 0){
                                g[k][k] = 4;
                            }else 
                                g[k][k] = 5;
                        }
                        else if(a > k && g[k][k] != 4){
                            if(g[i][a] > 0 && g[k][a] > 0)
                                g[k][k] = 4;
                            else 
                                g[k][k] = 5;
                        }
                    } 
                }


        for(i = 0; i < n; i++)
            if(g[i][i] == 3 || g[i][i] == 5){
                cout << 1 << "\n"; 
            }else
                cout << 0 << "\n"; 
    } 
    return 0;
}