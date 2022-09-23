/**
* user:  VR471628
* fname: ROBERT OCTAVIAN
* lname: TIMOFTE
* task:  esame_convoglio
* score: 15.0
* date:  2022-09-20 11:06:17.519957
*/
#include <cassert>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXM=15000, MAXN=12000;
int N,M;

vector<vector<int>> adjlist;
vector<int> match;
vector<int> current_match;
vector<bool> picked;
bool different_match_found = false;

void bt(int current) {
	if (current == N) {
		for (int i = 0; i < N; i++) {
			if (match[i] != current_match[i]) {
				different_match_found = true;
				break;
			}
		}
	} else {
		for (vector<int>::iterator it = adjlist[current].begin();
			it != adjlist[current].end() && !different_match_found; it++)
		{
			if (!picked[*it]) {
				current_match[current] = *it;
				picked[*it] = true;
				bt(current+1);
				picked[*it] = false;
			}
		}
	}
}

int main(){
	scanf("%d%d",&N,&M);
	assert(M >= 2);
	assert(M <= MAXM);
	assert(N >= 2);
	assert(N < MAXN);
	//printf("N=%d, M=%d\n",N,M);

	adjlist.resize(N);
	match.resize(N);
	current_match.resize(N);
	picked.resize(N);

	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		assert(a >= 0);
		assert(a < N);
		assert(b >= 0);
		assert(b < N);
		//printf("message=%d, ship=%d\n",a,b);

		adjlist[a].push_back(b);
		if (i<N)
			match[a] = b;
	}

	bt(0);

	if (different_match_found) {
		for (int i = 0; i < N; i++) {
			printf("%d %d\n", i, current_match[i]);
		}

		return 0;
	}

	printf("-1\n");
	return 0;
}
