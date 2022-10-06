/**
* user:  VR472108
* fname: DAVIDE
* lname: CAMPONOGARA
* task:  esame_convoglio
* score: 15.0
* date:  2022-09-20 11:55:47.807176
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <forward_list>

using namespace std;

vector<vector<int>> ship_message;
map<int,vector<int>> mapping;

vector<int> assignmentMain;
vector<int> corrispondenza;

bool found=false;

int N, M;

bool confronto(vector<int> primo, vector<int> secondo){
    bool a= true;
    for(int i=0;i<N;i++){
        if(primo[i]!=secondo[i]){
            a=false;
        }
    }
    return a;
}

int resolve(map<int,vector<int>> myMapping, vector<int> assignment, int index){

    if(found){
        return 0;
    }
    if(myMapping.size()==0 && !confronto(corrispondenza,assignment)){
        assignmentMain=assignment;
        found=true;
        return 0;
    }
    else if(myMapping.size()==0){
        return -1;
    }

    for(int j=0;j<myMapping[index].size();j++){

        map<int,vector<int>> mynewMap(myMapping);
    	for(int i=index+1;i<N;i++){
            for(int k=0;k<mynewMap[i].size();k++){
                if(mynewMap[i][k]==mynewMap[index][j]){
                    mynewMap[i].erase(mynewMap[i].begin()+k);
                }
            }
        }
        bool stop= false;
        for(int i=index+1;i<N;i++){
            if(mynewMap[i].size()==0){
                stop=true;
            }
        }
        if(!stop){
            vector<int> ass(assignment);
            int elem = mynewMap[index][j];
            ass.push_back(elem);
            std::map<int, vector<int>>::iterator it;
            it = mynewMap.find(index);
            mynewMap.erase(it);
            if(resolve(mynewMap ,ass, index+1)==0){
                return 0;
            }
        }

    }
    return -1;


}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	cin >> N >> M;


	ship_message.resize(M);


	vector<int> a = {};
	for(int i=0; i<N; i++){
        mapping.insert(pair<int,vector<int>> (i,a));
	}


	for(int i=0; i<M; i++){
            int x;
            cin >> x;
            int y;
            cin >> y;
            mapping[x].push_back(y);
	}

	int conto=0;
	for(int i=0; i<M; i++){
        if(conto<N){
            corrispondenza.push_back(mapping[i][0]);
        }
        conto++;
	}

	map<int,vector<int>> mynewMap(mapping);
	vector<int> assignment;
	resolve(mynewMap,assignment,0);


	if(assignmentMain.size()==N){
        for(int i=0;i<N;i++){
            cout<<i<< " "<<assignmentMain[i]<< endl;
        }
    }
    else{
        cout<<-1<<endl;
    }
	return 0;
}
