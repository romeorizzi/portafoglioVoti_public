/**
* user:  VR449169
* fname: MONTRESOR
* lname: STEFANO
* task:  poldo_sums
* score: 68.0
* date:  2020-06-18 10:29:39.883036
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct kicked {
    int index;
    int kicker_column;
    int kicker_row;
};

struct sum_set{
    int sum;
    bool set;
};

vector<int> pan;
vector<int> pal;

vector<int> f;
int n;
//vector<vector<sum_set>> sum;

int sum_gym(int start, int end){
    //if(sum[start][end].set){
    //    return sum[start][end].sum;
    //}
    int tot = 0;
    for(int i = start; i <= end; i++){
        tot += pal[i];
    }
    //sum[start][end].set = true;
    //sum[start][end].sum = tot;
    return tot;
}

void poldo(int n){
    vector<vector<kicked>> m;
    m.resize(n);
    int index_r = 0;
    int riga_max = 0;
    vector<int> max_col;
    max_col.resize(n,-1);
    bool written = false;
    m[0].resize(1,{0,-1,-1});
    m[0][0].index = 0;
    max_col[0]++;

    for (int i = 1; i < n; i++){
        written = false;
        index_r = 0;
        while(!written){
            int curr_index = m[index_r][max_col[index_r]].index;
            if(pan[i] >= pan[curr_index] + sum_gym(curr_index, i - 1)){
                if (index_r == riga_max){
                    riga_max++;
                    m[riga_max].resize(1);
                    m[riga_max][0].index = i;
                    m[riga_max][0].kicker_row = index_r;
                    m[riga_max][0].kicker_column = max_col[index_r];
                    max_col[riga_max]++;
                    written = true;
                }
            }
            else{//scrivo dove sono(o cliclo tutta la colonna?)
                max_col[index_r]++;
                m[index_r].resize(max_col[index_r]+1);
                m[index_r][max_col[index_r]].index = i;
                m[index_r][max_col[index_r]].kicker_row = index_r - 1;
                if (index_r > 0){
                    m[index_r][max_col[index_r]].kicker_column = max_col[index_r - 1];
                }
                else
                {
                    m[index_r][max_col[index_r]].kicker_column = -1;
                }
                
                written = true;
            }
            index_r++;
        }
    }

    cout << riga_max + 1 << endl;
    vector<int> res;
    res.resize(riga_max+1);
    int riga = riga_max;
    int colonna = max_col[riga];
    for (int i = 0; i < riga_max + 1; i++){
        //cout << "i " << i << " rig " << riga <<" col " << colonna << endl;
        res[i] = m[riga][colonna].index;
        int tmp = riga;
        riga = m[riga][colonna].kicker_row;
        colonna = m[tmp][colonna].kicker_column;
    }

    for (int i = riga_max; i >= 0; i--)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    
    cin >> n;
    pan.resize(n);
    pal.resize(n);
    //sum.resize(n);
    
    for (int i=0; i<n; i++){
        //sum[i].resize(n, {0,false});
        cin >> pan[i];
        cin >> pal[i];
    }
    poldo(n);
}