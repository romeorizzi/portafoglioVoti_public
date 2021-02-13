/**
* user:  VR451275_id420ehk
* fname: EDOARDO
* lname: GRASSI
* task:  PFG-2DAGs
* score: 0.0
* date:  2021-02-12 11:37:59.326901
*/
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const auto MAX_P = 10000 + 1;
const auto MAX_N = 10000 + 1;

using Vert = int;
enum Mark : uint8_t { unk = 0, loss = 1, win = 2 };

struct Graph
{
  std::vector<std::vector<Vert>> adj;
};

struct State
{
  //std::bitset<MAX_N> win;
  std::vector<Mark> marks;
};

void read_graph(Graph& g)
{
  int V, A;
  cin >> V >> A;
  g.adj.resize(V);
  for (auto i = 0; i < A; ++i)
  {
    Vert u, v;
    cin >> u >> v;
    g.adj[u].push_back(v);
  }
}

void print_state(const State& s)
{
  cout << "State:\n";
  for (const auto m : s.marks)
    cout << m << '\n';
}

void rec(const Graph& g, State& s, Vert v)
{
  /*
  if (empty(g.adj[v]))
  {
    s.win[v] = false;
    return;
  }
  */
  if (s.marks[v] != Mark::unk) // already visited
    return;

  for (auto child : g.adj[v])
    rec(g, s, child);

  s.marks[v] = Mark::loss;
  for (auto child : g.adj[v])
    if (s.marks[child] == Mark::loss)
    {
      s.marks[v] = Mark::win;
      break;
    }
}

int main()
{
  Graph G1, G2;
  read_graph(G1);
  read_graph(G2);

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
  S1.marks.resize(G1.adj.size());
  fill(begin(S1.marks), end(S1.marks), Mark::unk);
  S2.marks.resize(G2.adj.size());
  fill(begin(S2.marks), end(S2.marks), Mark::unk);

  //cout << "\n\n\n";
  //print_state(S1);
  //print_state(S2);

  for (auto v = 0; v < G1.adj.size(); ++v)
    rec(G1, S1, v);
  for (auto v = 0; v < G2.adj.size(); ++v)
    rec(G2, S2, 0);

  for (const auto& p : P)
    if (S1.marks[p.v1] != S2.marks[p.v2])
      cout << "1\n"; // win
    else
      cout << "0\n"; // loss

  //cout << "\n\n\n";
  //print_state(S1);
  //print_state(S2);
}
