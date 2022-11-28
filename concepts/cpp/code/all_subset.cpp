#include <iostream>
#include <vector>

using namespace std;
int N = 3;
vector<int> a = {1, 2, 3};
vector<int> b;

void show(){
  for(int i=0; i<N; i++){
    if(b[i+1] == 1){
      cout << a[i] << " ";
    }
  }
  cout << endl;
}

void backtrack(int i){
  if(i == N){
    show();
    return;
  }
  b[i+1] = 0;
  backtrack(i+1);
  b[i+1] = 1;
  backtrack(i+1);
}

int main(){
  for(int i=0; i<=N; i++){
    b.push_back(0);
  }
  backtrack(0);
  return 0;
}