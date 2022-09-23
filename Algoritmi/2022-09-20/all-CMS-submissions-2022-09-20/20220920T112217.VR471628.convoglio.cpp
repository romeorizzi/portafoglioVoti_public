/**
* user:  VR471628
* fname: ROBERT OCTAVIAN
* lname: TIMOFTE
* task:  esame_convoglio
* score: 60.0
* date:  2022-09-20 11:22:17.762290
*/
#include <cassert>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXM=15000, MAXN=12000;
int N,M;

vector<vector<int>> adjlist;
vector<int> match;
vector<bool> visited;
vector<bool> is_ancestor;

#define NO_CYCLE 0
#define CYCLE_FOUND 1
#define CYCLE_ENDED 2

int status = NO_CYCLE;
int cycle_root = 0;

void dfs(int current) {
	visited[current] = true;
	is_ancestor[current] = true;
	int matched = match[current];

	for (vector<int>::iterator it = adjlist[matched].begin();
		it != adjlist[matched].end(); it++)
	{
		if (*it != current) {
			if (visited[*it] && is_ancestor[*it]) {
				status = CYCLE_FOUND;
				cycle_root = *it;
				match[*it] = matched;
				return;
			}
			if (!visited[*it]) {
				dfs(*it);
				if (status == CYCLE_FOUND) {
					match[*it] = matched;
					if (cycle_root == current)
						status = CYCLE_ENDED;
					return;
				}

				if (status == CYCLE_ENDED)
					return;
			}
		}
	}

	is_ancestor[current] = false;
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
	visited.resize(N, false);
	is_ancestor.resize(N, false);

	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		assert(a >= 0);
		assert(a < N);
		assert(b >= 0);
		assert(b < N);
		//printf("message=%d, ship=%d\n",a,b);

		if (i<N)
			match[a] = b;
		else
			adjlist[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i])
			dfs(i);
		if (status == CYCLE_ENDED)
			break;
	}

	if (status != NO_CYCLE) {
		for (int i = 0; i < N; i++) {
			printf("%d %d\n", i, match[i]);
		}

		return 0;
	}

	printf("-1\n");
	return 0;
}
