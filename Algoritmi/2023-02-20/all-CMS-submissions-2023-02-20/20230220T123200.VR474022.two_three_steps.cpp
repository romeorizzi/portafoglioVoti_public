/**
* user:  VR474022
* fname: FILIPPO
* lname: ZICHE
* task:  esame_two_three_steps
* score: 100.0
* date:  2023-02-20 12:32:00.869705
*/
/**
 *  Soluzione farlocca di two_three_steps (illustra come curare input ed output)
 *
 *  Autore: Romeo Rizzi, 2018-06-14
 *
 */

#include <cassert>
#include <cstdio>
#include <unordered_map>

#define MAXN 1000000

int N;
int GGG[MAXN]; // GGG[i] = valore del ricordo i-esimo.

int max(int a, int b) {
  return (a > b) ? a : b;
}

std::unordered_map<int, int> create_cache() {

  std::unordered_map<int, int> result = {
    { N - 1, GGG[N - 1] },
    { N - 2, GGG[N - 2] },
    { N - 3, GGG[N - 3] + GGG[N - 1] }
  };

  for (int cur = N - 4; cur >= 0; cur--) {
    int best = max(result[cur + 2], result[cur + 3]);
    result.insert({ cur, GGG[cur] + best });
  }

  return result;
}

int main() {
  assert( freopen("input.txt", "r", stdin) );
  assert( freopen("output.txt", "w", stdout) );

  scanf("%d", &N);
  for(int i = 0; i < N; i++)
     scanf("%d", &GGG[i]);

  auto cache = create_cache();
  printf("%d\n", cache[0]); // giusto quando tutti i ricordi sono scialbi tranne al più il secondo. 
  return 0;
}

