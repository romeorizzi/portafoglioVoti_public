/**
* user:  VR445435_id495pug
* fname: MATTEO
* lname: ZEGGIOTTI
* task:  altopiano
* score: 100.0
* date:  2020-09-18 09:31:25.361131
*/
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <fstream>
#include <sstream>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> actions;
int n;
int n_actions;
vector<int> heigths;

int max(int a, int b){
	if (a > b){
		return a;
	}
	return b;
}
void init()
{
	
	string row;
	int id;

	cin >> n;
	cin >> n_actions;

	int heigth;
	for (int i = 0; i < n; i++)	{
		cin >> heigth;
		heigths.push_back(heigth);
	}

	while (cin >> id)	{
		vector<int> action;

		action.push_back(id);
		cin >> id;
		action.push_back(id);
		cin >> id;
		action.push_back(id);

		actions.push_back(action);
	}

}

tuple<int, int, int, int, int, int> build_dad(int left_sx, int left_sx_n, int left_size, int left_alt, int left_dx, int left_dx_n, int right_sx, int right_sx_n, int right_size, int right_alt, int right_dx, int right_dx_n) {
	int sx, sx_n, size, alt, dx, dx_n;
	sx = left_sx;
	dx = right_dx;
	alt = max(left_alt, right_alt);
	sx_n = left_sx_n;
	dx_n = right_dx_n;
	size = left_size + right_size;
	if(left_dx == right_sx){
		int new_candidate_n = left_dx_n + right_sx_n;
		if (new_candidate_n > 2){
			alt = max(alt, left_dx);
		}
		if (left_size == left_sx_n){
			sx_n = new_candidate_n;
		}
		if (right_size == right_dx_n){
			dx_n = new_candidate_n;
		}
	}

	return {sx, sx_n, size, alt, dx, dx_n};
}

void build_tree(vector<int> &data_arr, vector<tuple<int, int, int, int, int, int>> &tree_arr)
{

	int middle = data_arr.size();
	for (int i = 0; i < middle; i++) {
		int heigth = data_arr[i];
		tree_arr[middle + i] = { heigth, 1, 1, INT_MIN, heigth, 1 };
	}

	for (int i = middle - 1; i > 0; i--)
	{
		
		int left_sx, left_sx_n, left_size, left_alt, left_dx, left_dx_n,
			right_sx, right_sx_n, right_size, right_alt, right_dx, right_dx_n;
		tuple<int, int, int, int, int, int> sx = tree_arr[i * 2];
		tuple<int, int, int, int, int, int> dx = tree_arr[i * 2 + 1];
		left_sx = get<0>(sx);
		left_sx_n = get<1>(sx);
		left_size = get<2>(sx);
		left_alt = get<3>(sx);
		left_dx = get<4>(sx);
		left_dx_n = get<5>(sx);
		right_sx = get<0>(dx);
		right_sx_n = get<1>(dx);
		right_size = get<2>(dx);
		right_alt = get<3>(dx);
		right_dx = get<4>(dx);
		right_dx_n = get<5>(dx);
		tree_arr[i] = build_dad(left_sx, left_sx_n, left_size, left_alt, left_dx, left_dx_n, right_sx, right_sx_n, right_size, right_alt, right_dx, right_dx_n);
	}
}

void update(int index, int increment, vector<tuple<int, int, int, int, int, int>> &tree_arr)
{
	index = tree_arr.size() / 2 + index;
	tuple<int, int, int, int, int, int> leaf = tree_arr[index];
	int new_val = get<0>(leaf) + increment;
	tree_arr[index] = { new_val, 1, 1, INT_MIN, new_val, 1 };
	

	int dad_index = index / 2;
	while (dad_index > 0)
	{
		int old_sx, old_sx_n, old_size, old_alt, old_dx, old_dx_n;
		tuple<int, int, int, int, int, int> old = tree_arr[dad_index];
		old_sx = get<0>(old);
		old_sx_n = get<1>(old);
		old_size = get<2>(old);
		old_alt = get<3>(old);
		old_dx = get<4>(old);
		old_dx_n = get<5>(old);

		tuple<int, int, int, int, int, int> sx = tree_arr[dad_index * 2];
		tuple<int, int, int, int, int, int> dx = tree_arr[dad_index * 2 + 1];
		tree_arr[dad_index] = build_dad(get<0>(sx), get<1>(sx), get<2>(sx), get<3>(sx), get<4>(sx), get<5>(sx), get<0>(dx), get<1>(dx), get<2>(dx), get<3>(dx), get<4>(dx), get<5>(dx));
		if (tree_arr[dad_index] == make_tuple(old_sx, old_sx_n, old_size, old_alt, old_dx, old_dx_n))
		{
			break;
		}
		dad_index = dad_index / 2;
	}
}

int calcola_intervalli(int _from, int _to, vector<tuple<int, int, int, int, int, int>> &tree_arr)
{
	_to++;
	int left = tree_arr.size() / 2 + _from;
	int right = tree_arr.size() / 2 + _to;
	tuple<int, int, int, int, int, int> cumulative_l = {INT_MIN, 1, 1, INT_MIN, INT_MIN, 1};
	tuple<int, int, int, int, int, int> cumulative_r = { INT_MIN, 1, 1, INT_MIN, INT_MIN, 1 };
	bool first_l = true;
	bool first_r = true;
	while (left < right)
	{
		if (left % 2 == 1)
		{
			if (first_l)
			{
				cumulative_l = tree_arr[left];
				first_l = !first_l;
			}
			else
			{
				cumulative_l = build_dad(get<0>(cumulative_l), get<1>(cumulative_l), get<2>(cumulative_l), get<3>(cumulative_l), get<4>(cumulative_l), get<5>(cumulative_l), get<0>(tree_arr[left]), get<1>(tree_arr[left]), get<2>(tree_arr[left]), get<3>(tree_arr[left]), get<4>(tree_arr[left]), get<5>(tree_arr[left]));
			}
			left++;
		}
		if (right % 2 == 1)
		{
			right--;
			if (first_r)
			{
				cumulative_r = tree_arr[right];
				first_r = !first_r;
			}
			else
			{
				cumulative_r = build_dad(get<0>(tree_arr[right]), get<1>(tree_arr[right]), get<2>(tree_arr[right]), get<3>(tree_arr[right]), get<4>(tree_arr[right]), get<5>(tree_arr[right]), get<0>(cumulative_r), get<1>(cumulative_r), get<2>(cumulative_r), get<3>(cumulative_r), get<4>(cumulative_r), get<5>(cumulative_r));
			}
		}
		left = left / 2;
		right = right / 2;
	}
	return get<3>(build_dad(get<0>(cumulative_l), get<1>(cumulative_l), get<2>(cumulative_l), get<3>(cumulative_l), get<4>(cumulative_l), get<5>(cumulative_l), get<0>(cumulative_r), get<1>(cumulative_r), get<2>(cumulative_r), get<3>(cumulative_r), get<4>(cumulative_r), get<5>(cumulative_r)));
}

int main()
{

	init();
	/*for (int el : heigths ){
		cout << el;
	}
	cout << endl;
	for (vector<int> action : actions){
		for (int com : action){
			cout << com;
		}
		cout << endl;
	}*/
	
	int resume = pow(2, (int)(log2(n)) + 1) - n;

	for (int i=0; i< resume; i++){
		heigths.push_back(INT_MIN);
	}

	//sx, sx_n, size, alt, dx, dx_n
	vector<tuple<int, int, int, int, int, int>> tree(2 * heigths.size());

	build_tree(heigths, tree);
/*
	for (int el : heigths) {
		cout << el;
	}
	cout << endl;
	
	for(tuple<int, int, int, int, int, int> node : tree){
		cout << "<";
		cout << get<0>(node) << " ";
		cout << get<1>(node) << " ";
		cout << get<2>(node) << " ";
		cout << get<3>(node) << " ";
		cout << get<4>(node) << " ";
		cout << get<5>(node) << " ";
		cout << "> ";
	}
	cout << endl;
	*/

	for (vector<int> action : actions)
	{
		if (action[0] == 2) {
			int altopiano = calcola_intervalli(action[1], action[2], tree);
			if (altopiano == INT_MIN)
			{
				cout << "NESSUN_ALTOPIANO" << endl;
			} else
			{
				cout << altopiano << endl;
			}
			
		}
		if(action[0] == 1)
		{
			update(action[1], action[2], tree);
		}
		
	}

	return 0;
}