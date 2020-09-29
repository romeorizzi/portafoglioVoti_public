/**
* user:  VR423652_id299avh
* fname: JASKIRAN
* lname: KAUR
* task:  altopiano
* score: 1.0
* date:  2020-09-18 10:08:07.923764
*/
#include <iostream>
#include <utility>
#include <algorithm>
#define MAX_N 100000
#define MAX_M 100000
#define OPERATION_MODIFY 1
#define OPERATION_FIND 2

int actual_n, actual_m;

int N[MAX_N]; 
std::pair<int, int> t[4*MAX_N];

struct {
    int op, a, b;
} operations [MAX_M];


/*void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = t[v]+new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}*/

std::pair<int, int> combine(std::pair<int, int> a, std::pair<int, int> b) {
    if (a.first > b.first) 
        return a;
    if (b.first > a.first)
        return b;
    return std::make_pair(a.first, a.second + b.second);
}

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = std::make_pair(a[tl], 1);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

std::pair<int, int> get_max(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return std::make_pair(0, 0);
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return combine(get_max(v*2, tl, tm, l, std::min(r, tm)), 
                   get_max(v*2+1, tm+1, tr, std::max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
    	int a=t[v].first+new_val;
        t[v] = std::make_pair(a, 1);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}


int main() {
	std::pair<int, int> aa;
    // read input from stdin
    std::cin >> actual_n >> actual_m;
    // read all height
    for(int i = 0; i < actual_n; i++) {
        std::cin >> N[i];
    }
    // read all operations
    for(int j = 0; j < actual_m; j++) {
        std::cin >> operations[j].op >> operations[j].a >> operations[j].b;
    }
    
    
    build(N, 1, 0, actual_n-1);
    //update(1, 0, actual_n-1, 0, 5);
    for(int i=0; i<4*actual_n; i++){
    	//std::cout<< t[i]<<" ";
    	
	}
	
	for(int j = 0; j < actual_m; j++) { 
        switch (operations[j].op)
        {
        case OPERATION_MODIFY:
            //modify_upland(operations[j].a, operations[j].b);
            update(1, 0, actual_n-1, operations[j].a, operations[j].b);
            break;

        case OPERATION_FIND:
        	aa=get_max(1, operations[j].a, operations[j].b, operations[j].a, operations[j].b);
        	if(aa.second==3) std::cout <<aa.first<<std::endl;
        	else std::cout<<"NESSUN_ALTOPIANO"<<std::endl;
            //find_upland(operations[j].a, operations[j].b);
            break;
        
        default:
            break;
        }
    }
	
	/*std::cout<<std::endl;
	//update(1, 0, actual_n-1, 0, 5);
    for(int i=0; i<4*actual_n; i++){
     std::cout << t[i].first << ", " << t[i].second << std::endl;
}
std::cout <<"uo"<<std::endl;
    	//std::cout<< t[i]<<" ";
    	update(1, 0, actual_n-1, 0, 5);
		update(1, 0, actual_n-1, 1, 4);	
    for(int i=0; i<4*actual_n; i++){
     std::cout << t[i].first << ", " << t[i].second << std::endl;
}
std::pair<int, int> aa=get_max(1, 1, actual_n-1, 1, actual_n-1);
std::cout <<"pino"<<aa.first << ", " << aa.second << std::endl;
   */ 
    return 0;
}
