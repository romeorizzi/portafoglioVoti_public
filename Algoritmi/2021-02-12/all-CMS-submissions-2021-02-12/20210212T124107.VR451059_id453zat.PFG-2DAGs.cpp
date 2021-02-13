/**
* user:  VR451059_id453zat
* fname: MASSIMILIANO
* lname: CITTADINI
* task:  PFG-2DAGs
* score: 18.0
* date:  2021-02-12 12:41:07.256303
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<tuple>

using namespace std;

int n1,m1,n2,m2,p;
vector<vector<int>>adj1;
vector<vector<int>>adj2;
vector<vector<int>>adj1_rev;
vector<vector<int>>adj2_rev;
vector<tuple<int,int>>pos;
vector<int>col1;
vector<int>col2;
/*    for (size_t i = 0; i < n; i++) {
    col1 = -1;
  }
  for (size_t i = 0; i < adj.size(); i++) {
    for (size_t j = 0; j < adj[i].size(); j++) {

    }
  }*/

void check() {
  int flag = 0;
  int res = 0;
  int p1 = 0;
  int p2 = 0;
  for (size_t i = 0; i < pos.size(); i++) {
    res = col1[get<0>(pos[i])] ^ col2[get<1>(pos[i])];
    if (!res) {
      cout << 0 <<endl;
    }else{
      cout << 1 <<endl;
    }
  }

/*
  // subtask 2 e 3
  for (size_t i = 0; i < pos.size(); i++) {
    if (col2[get<1>(pos[i])]==0) {
      cout << 0 <<endl;
    }else{
      for (size_t j = 0; j < adj2[get<1>(pos[i])].size(); j++) {
        if (col2[adj2[get<1>(pos[i])][j]]==0) {
          flag = 1;
          cout << 1 <<endl;
          break;
        }
      }
      if (!flag) {
        cout << 0 <<endl;
      }
    }
  }*/
}
void number(int flag) {
  vector<vector<int>>adj;
  vector<int>col;
  int w = 0;
  int s = 0;
  int n=0,m=0;
  vector<int>nbrs_color;
  int counter = 0;

  if (flag == 1) {
    adj = adj1_rev;
    //cout << adj[1][0];
    col.resize(n1);
    n = n1;
    m = m1;
  }else if (flag == 2) {
    adj = adj2_rev;
    col.resize(n2);
    n = n2;
    m = m2;
  }
  for (size_t i = 0; i < col.size(); i++) {
      col[i] = 0;
    }
  for (size_t i = adj.size()-1; i > 0; i--) {
    for (size_t j = 0; j < adj[i].size(); j++) {
      w = adj[i][j];
      if (col[w]==col[i]) {
        col[w]+=1;
      }
    }
  }


  /*for (size_t i = 0; i < col.size(); i++) {
    cout <<"V: "<<i<<" Color:"<< col[i]<<endl;
  }*/
  if (flag == 1) {
    col1=col;
  }else{
    col2=col;
  }

}


int main(int argc, char const *argv[]) {
  int v1 = 0, v2 = 0;
  cin >> n1 >> m1;
  //cout << n1 << m1;
  adj1.resize(n1);
  adj1_rev.resize(n1);

  for (size_t i = 0; i < m1; i++) {
    cin >> v1 >> v2;
    //cout << v1 << v2;
    adj1[v1].push_back(v2);
    adj1_rev[v2].push_back(v1);
  }
  for (size_t i = 0; i < adj1.size(); i++) {
    sort(adj1[i].begin(), adj1[i].end());
  }
  for (size_t i = 0; i < adj1.size(); i++) {
    sort(adj1_rev[i].begin(), adj1_rev[i].end());
  }
  v1 = 0;
  v2 = 0;
  cin >> n2 >> m2;
  adj2.resize(n2);
  adj2_rev.resize(n2);
  for (size_t k = 0; k < m2; k++) {
    cin >> v1 >> v2;
    //cout << v1 << v2;
    adj2[v1].push_back(v2);
    adj2_rev[v2].push_back(v1);
  }
  for (size_t i = 0; i < adj1.size(); i++) {
    sort(adj2[i].begin(), adj2[i].end());
  }
  for (size_t i = 0; i < adj1.size(); i++) {
    sort(adj2_rev[i].begin(), adj2_rev[i].end());
  }
  cin >> p;
  v1 = 0;
  v2 = 0;
  for (size_t i = 0; i < p; i++) {
    cin >> v1 >> v2;
    pos.push_back(make_tuple(v1,v2));
  }
  /*cout <<endl << "pos "<<endl;
  for (size_t i = 0; i < p; i++) {
    cout << get<0>(pos[i])<<" ";
    cout << get<1>(pos[i])<<endl;
  }*/
  /*for (size_t i = 0; i < adj2_rev.size(); i++) {
    cout << "vertice "<< "v "<<i<<endl;
    for (size_t j = 0; j < adj2_rev[i].size(); j++) {
      cout <<" adj1[v] " << adj2_rev[i][j]<<endl;
    }
  }*/
  number(1);
  number(2);
  /*for (size_t i = 0; i < col2.size(); i++) {
    cout <<"V: "<<i<<" Color:"<< col2[i]<<endl;
  }*/
  check();
  return 0;
}
