/**
* user:  VR413877
* fname: NAPOLETANI
* lname: VALENTINA
* task:  bit_edit_to_zero
* score: 0.0
* date:  2019-02-26 12:12:31.844313
*/
#include<cassert>
#include<iostream>
#include <vector>


using namespace std;


vector<long long int> *num;
vector<long long int> *num2;

//##########################################
// BEGIN: modifica entro quest'area

void binario(int n){

num=new vector<long long int>();
int c=0;int i=0;
if(n==0) num->push_back(0);
else {
  while(n>0){
  num->push_back(n%2);
  n=n/2;
  c++;
  }
//for(i=0;i<c;i++){
 // cout<<A->at(i)<<endl;
//}
}

num2=new vector<long long int>(*num);
}

bool isZero(int par){
  //cout<<"iszero"<<endl;
  for(int i=par;i<num->size();i++){
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
      if(i+1<num->size()) {

        return i+1;
      }
      else return i;
    }

  }
}


int num_mosse(int n) {
  
  binario(n);
  long long int res=0;
  int res2=0;
  bool ultimo=false;
  
 /* if(num->at(0)!=1){
    //prima ultimo
    ultimo=true;
  }else{
    //prima destra
    ultimo=false;
  }*/
   if((*num)[0]==1 && isZero(1)){
     ultimo=true;
     //cout<<"qui"<<endl;
   }
  //cout<<"utlimo"<<ultimo<<endl;

  while(!isZero(0)){
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
  cin >> p >> n;
  assert(p >= 1);
  assert(p <= 2);
  assert(n >= 0);
  if(p  == 1)
    cout << num_mosse(n) << endl;
  if(p  == 2)
    cout << mossa(n) << endl;
  return 0;
}
