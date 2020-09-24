/**
* user:  VR445435_id495pug
* fname: MATTEO
* lname: ZEGGIOTTI
* task:  chordal_lexBFS
* score: 0.0
* date:  2020-09-18 12:04:08.409223
*/
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <fstream>
#include <sstream>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;

map<int, vector<int>> graph; //node : edges

bool find_in_vector(vector<int> v, int el)
{
	return find(v.begin(), v.end(), el) != v.end();
}

void print_map(map<int, vector<int>> m)
{
	for (pair<int, vector<int>> el : m)
	{
		cout << get<0>(el) << " : ";

		for (int edge : get<1>(el))
		{
			cout << edge << " ";
		}
		cout << endl;
	}
}

void print_vector(vector<int> vec)
{
	for(int el : vec)
	{
		cout << el << " ";
	}
	cout << endl;
}

bool is_neightbour(int a, int b)
{
	if (a==b)
	{
		return true;
	}
	vector<int> near = graph.at(a);
	return find(near.begin(), near.end(), b) != near.end();
}


string find_triple(int n_nodes)
{
	string found = "99999999";
	for (int j = 1; j <= n_nodes; j++)
	{
		for (int i = 1; i < j; i++)
		{
			for(int j1 : graph.at(j))
			{
				if (find_in_vector(graph.at(i), j1) == false && i != j1)
				{
					bool ok = true;
					bool entered = false;
					for(int i1 : graph.at(i))
					{
						if (find_in_vector(graph.at(j), i1)== false)
						{
							entered = true;
							ok = ok && (i1 > j1);
						}
					}
					if (entered && ok){
						string ris = to_string(j) + " " + to_string(i) + " " + to_string(j1);
						if (ris < found)
						{
							found = ris;
						}
					}
					
				}
			}
		}
	}
	if (found == "99999999")
	{
		return "";
	}
	return found;
}

bool is_lexbfs(vector<int> sub_nodes, int pivot)
{
	if(sub_nodes.size() < 2)
	{
		return true;
	}

	vector<int> first_part;
	vector<int> second_part;
	bool ok = true;
	int change = 0;
	int index = 0;
	int index_of_change;
	bool old = true;
	for (int node : sub_nodes)
	{
		bool res = is_neightbour(pivot, node);
		if (res != old)
		{
			change++;
			index_of_change = index;
		}
		if (change > 1)
		{
			ok = false;
			break;
		}

		if(node != pivot)
		{
			if(res)
			{
				first_part.push_back(node);
			} else
			{
				second_part.push_back(node);
			}
		}
		
		old = res;
		index++;
	}

	if(ok == false)
	{
		return ok;
	}
	/*cout<< "pivot: " << pivot << endl;
	print_vector (first_part);
	print_vector(second_part);*/
	return is_lexbfs(first_part, pivot+1) && is_lexbfs(second_part, pivot+1);
}

int main()
{
	int g,n,m;
	cin >> g;
	cin >> n;
	cin >> m;

	
	
	
	int node1, node2;
	while(cin >> node1)
	{
		cin >> node2;
		if (graph.find(node1) == graph.end()) {
			vector<int> edges;
			edges.push_back(node2);
			graph.insert({node1, edges});
		} else
		{
			graph.at(node1).push_back(node2);
		}
		if (graph.find(node2) == graph.end()) {
			vector<int> edges;
			edges.push_back(node1);
			graph.insert({ node2, edges });
		}
		else
		{
			graph.at(node2).push_back(node1);
		}
	}

	//print_map(graph);
	vector<int> lexbfs;
	for(int i = 1; i<= n; i++)
	{
		lexbfs.push_back(i);
	}

	bool ok = is_lexbfs(lexbfs, 1);
	if(ok)
	{
		cout << is_lexbfs(lexbfs, 1) << endl;
	} else
	{
		cout << 0 <<endl;
		cout << find_triple(n) << endl;
	}
	
	
	
	
}
