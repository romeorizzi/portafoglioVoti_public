/**
* user:  VR424402
* fname: D'ARIENZO
* lname: PAOLO
* task:  Prob3_pacman_best
* score: 0.0
* date:  2019-09-04 12:01:16.276651
*/
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <tuple>
#include <map>

const int MAXBLUE = 9;
const int MAXM = 1000;
const int MAXN = 1000;

char mappa[MAXM+1][MAXN+1];

int M, N;

struct pacman {
	int vivo;
	int nfantasmi;
	int npallini;
};
	
bool isMuro(int i, int j){
	return mappa[i][j] == '#';
}

bool isFantasma(int i, int j){
	return mappa[i][j] == '*';
}

bool isPallino(int i, int j){
	return mappa[i][j] >= '1' && mappa[i][j] <= '9';
}

bool canGoRight(int i, int j, int super){
	return (i+1 <= M && !isMuro(i+1, j) && (!isFantasma(i+1, j) || super > 0)) ? true : false;
}

bool canGoDown(int i, int j, int super){
	return (j+1 <= N && !isMuro(i, j+1) && (!isFantasma(i, j+1) || super > 0)) ? true : false;
}

std::map<std::tuple<int, int, int>, struct pacman > memoization;

pacman visita_internal(int i, int j, int super);

pacman visita(int i, int j, int super){
	std::tuple<int, int, int> key = std::tuple<int, int, int>(i, j, super);
	auto it = memoization.find(key);
	if(it != memoization.end()) {
		return memoization[key];
	} else{
		struct pacman val = visita_internal(i, j, super);
		memoization[key] = val;
		return val;
	}
}

pacman visita_internal(int i, int j, int super){
	assert(mappa[i][j] != '#');
	assert(mappa[i][j] != '*' || super > 0);
	
	if(i == M && j == N) {
		struct pacman endinfo;
		endinfo.vivo = 1;
		endinfo.nfantasmi = (isfantasma(i, j) ? 1 : 0);
		endinfo.npallini = (isPallino(i, j) ? 1 : 0);
		return endinfo;
	}
	
	super == std::max(0, superpoteri - 1);
	int pallini = 0;
	
	if(isPallino(i, j)) {
		pallini = mappa[i][j] - '0';
		if(super < pallini) {
			super = pallini;
		}
	}
	
	int fantasmi = isFantasma(i, j) ? 1 : 0;
	
	bool rightvalid = canGoRight(i,j, super);
	struct pacman rightinfo;
	if(rightvalid){
		rightinfo = visita(i+1, j, super);
	}
	
	bool downvalid = canGoDown(i,j,super);
	struct pacman downinfo;
	if(downvalid) {
		downinfo = visita(i, j+1, super);
	}
	
	struct pacman chosen;
	
	if(rightvalid && downvalid){
		if(rightinfo.vivo == 0 && downinfo.vivo == 1){
			chosen = downinfo;
		}
		else if(rightinfo.vivo == 1 && downinfo.vivo == 0){
			chosen = rightinfo;
		}else{
			if(rightinfo.nfantasmi > downinfo.nfantasmi){
				chosen = rightinfo;
			}
			else{
			if(rightinfo.nfantasmi < downinfo.nfantasmi){
				chosen = downinfo;
			} else {
				if(rightinfo.npallini < downinfo.npallini){
					chosen = rightinfo;
				}
				else {
					chosen = downinfo;
				}
			}
		}
	}
	
	else if(rightvalid){
		chosen =rightinfo;
		}
	else if (downvalid){
		chosen = downinfo;
		}
	else{
	chosen.vivo = 0;
	chosen.nfantasmi = 0;
	chosen.npallini = 0;
	}
	
	chosen.nfantasmi += (isFantasma(i, j) ? 1 : 0);
	chosen.npallini += (isPallino(i, j) ? 1 : 0);
	
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
	} while(mappa[i][j] != '#' && mappa[i][j] != '+' && mappa[i][j] != '*' && ( mappa[i][j] < '1' || mappa[i][j] > '9')  );

    int risp = 0;
    printf("%d\n",risp);
    return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
		
		
	
	
