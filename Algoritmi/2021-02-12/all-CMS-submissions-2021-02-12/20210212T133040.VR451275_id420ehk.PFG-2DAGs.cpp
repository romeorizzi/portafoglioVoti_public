/**
* user:  VR451275_id420ehk
* fname: EDOARDO
* lname: GRASSI
* task:  PFG-2DAGs
* score: 100.0
* date:  2021-02-12 13:30:40.787083
*/
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

const auto MAX_P = 10000 + 1;
const auto MAX_N = 10000 + 1;

using Vert = int;

struct Graph
{
  std::vector<std::vector<Vert>> adj;
};

struct State
{
  //std::bitset<MAX_N> win;
  std::bitset<MAX_N> marks;
};

struct Grundy
{
  std::vector<uint32_t> nums;
};

void read(Graph& g)
{
  int V, A;
  cin >> V >> A;
  g.adj.resize(V);
  for (auto i = 0; i < A; ++i)
  {
    Vert u, v;
    cin >> u >> v;
    // avoid duplicate edges
    if (find(begin(g.adj[u]), end(g.adj[u]), v) == end(g.adj[u]))
      g.adj[u].push_back(v);
  }
}

void print(const Graph& g)
{
  cout << "--- Graph:\n";
  for (auto i = 0; i < g.adj.size(); ++i)
  {
    cout << "v" << i << ": ";
    for (auto v : g.adj[i])
      cout << v << ',';
    cout << '\n';
  }
  cout << "---\n";
}

void print(const State& s)
{
  cout << "--- State:\n";
  for (auto i = 0; i < s.marks.size(); ++i)
    cout << "v" << i << ": " << s.marks[i] << '\n';
  cout << "---\n";
}

void print(const Grundy& g)
{
  cout << "--- Grundy:\n";
  for (auto i = 0; i < g.nums.size(); ++i)
    cout << "v" << i << " : " << g.nums[i] << '\n';
  cout << "---\n";
}

void rec(const Graph& g, State& s, Grundy& gru, Vert v)
{
  /*
  if (empty(g.adj[v]))
  {
    s.win[v] = false;
    return;
  }
  */
  if (s.marks[v]) // already visited
    return;
  s.marks[v] = true;

  for (auto child : g.adj[v])
    rec(g, s, gru, child);

  // gather grundy numbers in children
  uint32_t buff[MAX_N];
  for (auto i = 0; i < g.adj[v].size(); ++i)
  {
    buff[i] = gru.nums[g.adj[v][i]];
  }
  // find mex()
  sort(begin(buff), begin(buff) + g.adj[v].size());
  /*cout << "Sorted: ";
  for (auto i = 0; i < g.adj[v].size(); ++i)
    cout << buff[i] << " ";
  cout << '\n';*/

  auto end = unique(begin(buff), begin(buff) + g.adj[v].size());

  auto gn = 0;
  for (; gn < distance(begin(buff), end); ++gn)
    if (gn != buff[gn])
      break;

  /*
  uint32_t gn = 0;
  for (auto i = 0; i < g.adj[v].size();)
  {
    while (i < g.adj[v].size() && buff[i] == gn)
      ++i;
    if (buff[i] != gn + 1)
      break;
    ++gn;
  }
  */
  gru.nums[v] = gn;
}

int main()
{
  Graph G1, G2;
  read(G1); read(G2);

  //print(G1); print(G2);

  struct Pos { Vert v1, v2; };
  std::vector<Pos> P;
  {
   int p;
   cin >> p;
   P.resize(p);
    for (auto i = 0; i < p; ++i)
      cin >> P[i].v1 >> P[i].v2;
  }

  State S1, S2;
  S1.marks.reset(); S2.marks.reset();

  //print(S1); print(S2);

  Grundy GN1, GN2;
  GN1.nums.resize(G1.adj.size());
  GN2.nums.resize(G2.adj.size());
  for (auto v = 0; v < G1.adj.size(); ++v)
    rec(G1, S1, GN1, v);
  for (auto v = 0; v < G2.adj.size(); ++v)
    rec(G2, S2, GN2, v);

  //print(GN1); print(GN2);

  for (const auto& p : P)
    if ((GN1.nums[p.v1] ^ GN2.nums[p.v2]) == 0)
      cout << "0\n"; // loss
    else
      cout << "1\n"; // win

  //print(S1); print(S2);
}
