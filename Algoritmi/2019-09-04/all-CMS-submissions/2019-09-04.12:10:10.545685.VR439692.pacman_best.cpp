/**
* user:  VR439692
* fname: ASTOLFI
* lname: RICCARDO
* task:  Prob3_pacman_best
* score: 0.0
* date:  2019-09-04 12:10:10.545685
*/

#include <cassert>
#include <cstdio>
#include <algorithm>
#include <tuple>
#include <map>

const int BASE = 1000000;
const int MAXBLUE = 5;
const int MAXM = 1000;
const int MAXN = 1000;

char mappa[MAXM+1][MAXN+1];

int M, N;

struct info{
    int vivo;
    int nfant;
    int npal;
    };

bool ismuro(int i,int j){
       return mappa[i][j] == '#';
}

bool isfant(int i,int j){
       return mappa[i][j] == '*';
}

bool ispal(int i,int j){
       return mappa[i][j] >= '1' && mappa[i][j] <= '9';
}

bool goR(int i,int j,int sup){
       return(i+1<= M && !ismuro(i+1,j)&&(!isfant(i+1,j) || sup >0)) ? true : false;
}

bool goD(int i,int j,int sup){
       return(j+1<= M && !ismuro(i,j+1)&&(!isfant(i,j+1) || sup >0)) ? true : false;
} 

std::map< std::tuple<int,int,int>,struct info > memoization;

info visitaint(int i, int j, int sup);

info visita(int i,int j,int sup){
    std::tuple<int,int,int> key = std::tuple<int,int,int>(i,j,sup);
    auto it = memoization.find(key);
    if( it != memoization.end()){
        return memoization[key];
    } else {
        struct info val = visitaint(i,j,sup);
        memoization[key] = val;
        return val;
    }
}

info visitaint(int i,int j, int sup){
    assert(mappa[i][j] != '#');
    assert(mappa[i][j] != '*' || sup>0);

    if(i== M && j==N){
        struct info endinfo;
        endinfo.vivo = 1;
        endinfo.nfant = (isfant(i,j) ? 1:0); 
        endinfo.npal = (ispal(i,j) ? 1:0);
        return endinfo;
    }

    sup = std::max(0,sup-1);
    int pal = 0;
    if(ispal(i,j)){
        pal = mappa[i][j]-'0';
        if(sup<pal){
            sup = pal; 
        }
       }
    int fantasmi = isfant(i,j) ? 1:0;

    bool rightvalid = goR(i,j,sup);
    
    struct info rightinfo;
    if(rightvalid){
        rightinfo = visita(i+1,j,sup);
    }
    
    bool downvalid = goD(i,j,sup);
   
    struct info downinfo;
    if(downvalid){
        downinfo = visita(i,j+1,sup);
    }

    struct info chosen;
    if(rightvalid && downvalid){
        if(rightinfo.vivo ==0 && downinfo.vivo ==1){
            chosen = downinfo;
        }else if(rightinfo.vivo == 1 && downinfo.vivo ==0){
            chosen = rightinfo;
        }else{
            if(rightinfo.nfant > downinfo.nfant){
               chosen = rightinfo;
            }else if(rightinfo.nfant < downinfo.nfant){
              chosen = downinfo;
            }else{
                if(rigthinfo.npal<downinfo.npal){
                    chosen=rightinfo;
                } else {
                    chosen = downinfo;
                }
    }
    }
}else if(rightvalid){
       chosen = rightinfo;
    }else if (downvalid){
       chosen = downinfo;
    }else {
        chosen.vivo = 0;
        chosen.nfant = 0;
        chosen.npal = 0;
}

chosen.nfant +=(isfant(i,j) ? 1:0);
chosen.npal +=(ispal(i,j) ? 1:0);

return chosen;
}
int main() {
#ifdef EVAL
    assert( freopen("input.txt", "r", stdin) );
    assert( freopen("output.txt", "w", stdout) );
#endif
    scanf("%d%d", &M, &N);
	
    for (int i = 1; i <= M; i++) {
      for (int j = 1; j <= N; j++) {
	do { 
	  scanf("%c", &mappa[i][j]);
	} while(mappa[i][j] != '#' && mappa[i][j] != '+' && mappa[i][j] != '*' && ( mappa[i][j] < '1' || mappa[i][j] > '5')  );

    int risp = 0;
    printf("%d\n",risp);
    return 0;
}
}
}
