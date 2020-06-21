/**
* user:  VR413877
* fname: NAPOLETANI
* lname: VALENTINA
* task:  bit_edit_to_zero
* score: 0.0
* date:  2019-02-26 11:39:39.800522
*/
#include<cassert>
#include<iostream>
#include <vector>


using namespace std;

vector<long long int> *A;
vector<long long int> *num;

//##########################################
// BEGIN: modifica entro quest'area

void binario(int n){

A=new vector<long long int>();
int c=0;int i=0;
if(n==0) A->push_back(0);
else {
  while(n>0){
  A->push_back(n%2);
  n=n/2;
  c++;
  }
//for(i=0;i<c;i++){
 // cout<<A->at(i)<<endl;
//}
}

num=new vector<long long int>(*A);

}

bool isZero(){
  //cout<<"iszero"<<endl;
  for(int i=0;i<num->size();i++){
    if(num->at(i)!=0) {
  //  cout<<"ret"<<false<<endl;
      return false;
    }
  }
       //   cout<<"ret"<<true<<endl;
  return true;
}

int find(){
  //  cout<<"find"<<endl;
  for(int i=0;i<num->size();i++){
    if(num->at(i)!=0) {
       // cout<<"ret"<<i+1<<endl;
      return i+1;
    }
  }
}


int num_mosse(int n) {
  
  binario(n);
  int res=0;
  bool ultimo=true;
  
  if(num->at(0)!=1){
    //prima ultimo
    ultimo=true;
  }else{
    //prima destra
    ultimo=false;
  }

  //cout<<"utlimo"<<ultimo<<endl;

  while(!isZero()){
      if(ultimo){
        //cout<<"utlimo"<<endl;
        if((*num)[0]==0){
          num->at(0)=1;
        }else {
          num->at(0)=0;
        }
        res++;
        ultimo=false;
      }
      else {
        //cout<<"destra"<<endl;
        int pos=find();
        if((*num)[pos]==0){
          num->at(pos)=1;
        }else {
          num->at(pos)=0;
        }
        res++;
        ultimo=true;
      }       
  }

  return res;   
}

int mossa(int n) {
  assert(n > 0);
  binario(n);
  if(num->at(0)!=1){
    return 1;
  }
  else return 2;
}

// END: modifica entro quest'area
// ################################################


int main() {
  int p, n;
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  //assert(2 == scanf("%d %d", &Nm, &Nf));
  cin >> p >> n;
  assert(p >= 1);
  assert(p <= 2);
  assert(n >= 0);
  if(p  == 1)
    cout << num_mosse(n) << endl;
  if(p  == 2)
    cout << mossa(n) << endl;
  delete A;
  delete num;
  return 0;
}
