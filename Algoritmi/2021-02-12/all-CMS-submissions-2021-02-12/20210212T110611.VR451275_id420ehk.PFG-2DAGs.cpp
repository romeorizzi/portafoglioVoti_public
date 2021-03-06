/**
* user:  VR451275_id420ehk
* fname: EDOARDO
* lname: GRASSI
* task:  PFG-2DAGs
* score: 0.0
* date:  2021-02-12 11:06:11.063112
*/
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const auto MAX_P = 10000 + 1;
const auto MAX_N = 10000 + 1;

using Vert = int;
enum class Mark : uint8_t { unk = 0, loss, win };

struct Graph
{
  std::vector<Vert> adj[MAX_N];
};

struct State
{
  //std::bitset<MAX_N> win;
  Mark mark[MAX_N];
};

void rec(const Graph& g, State& s, Vert v)
{
  /*
  if (empty(g.adj[v]))
  {
    s.win[v] = false;
    return;
  }
  */
  if (s.mark[v] != Mark::unk) // already visited
    return;

  for (auto child : g.adj[v])
    rec(g, s, child);

  s.mark[v] = Mark::loss;
  for (auto child : g.adj[v])
    if (s.mark[child] == Mark::loss)
    {
      s.mark[v] = Mark::win;
      break;
    }
}

int main()
{
  int V[2];

  Graph G[2];

  for (auto i = 0; i < 2; ++i)
  {
    int A;
    cin >> V[i] >> A;
    for (auto m = 0; m < A; ++m)
    {
      Vert u, v;
      cin >> u >> v;
      G[i].adj[u].push_back(v);
    }
  }

  struct Pos { Vert v1, v2; };
  std::vector<Pos> P;
  {
   int p;
   cin >> p;
   P.resize(p);
    for (auto i = 0; i < p; ++i)
      cin >> P[i].v1 >> P[i].v2;
  }

  State S[2];
  for (auto i = 0; i < V[0]; ++i)
    rec(G[0], S[0], 0);
  for (auto i = 0; i < V[1]; ++i)
    rec(G[1], S[1], 0);

  for (const auto& p : P)
    if (S[0].mark[p.v1] != S[1].mark[p.v2])
      cout << "1\n"; // win
    else
      cout << "0\n"; // loss
}
