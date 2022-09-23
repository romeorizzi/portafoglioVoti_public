/**
* user:  VR472108
* fname: DAVIDE
* lname: CAMPONOGARA
* task:  esame_convoglio
* score: 15.0
* date:  2022-09-20 11:22:01.830912
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

void resolve(map<int,vector<int>> myMapping, vector<int> assignment, int index){

    if(myMapping.size()==0 && !confronto(corrispondenza,assignment)){
        assignmentMain=assignment;
        return;
    }
    else if(myMapping.size()==0){
        return;
    }

    for(int i=index;i<N;i++){
        if(myMapping[i].size()==0){
            return;
        }
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
        vector<int> ass(assignment);
        int elem = mynewMap[index][j];
        ass.push_back(elem);
        std::map<int, vector<int>>::iterator it;
        it = mynewMap.find(index);
        mynewMap.erase(it);
        resolve(mynewMap ,ass, index+1);
    }


}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> N >> M;


	ship_message.resize(M);

	for(int i=0; i<M; i++){
        for(int j=0; j<2; j++){
            int x;
            cin >> x;
            ship_message[i].push_back(x);
        }
	}

	vector<int> a = {};
	for(int i=0; i<N; i++){
        mapping.insert(pair<int,vector<int>> (i,a));
	}

    int conto=0;
	for(int i=0; i<M; i++){
        mapping[ship_message[i][0]].push_back(ship_message[i][1]);
	}

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
