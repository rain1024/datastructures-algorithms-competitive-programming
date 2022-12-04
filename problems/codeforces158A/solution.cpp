#include <bits/stdc++.h>
#include <vector>
 
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k, a;
  int count = 0;
  cin >> n >> k;
  vector<int> v;
  for(int i=0; i<n; i++){
    cin >> a;
    v.push_back(a);
  }
  for(int i=0; i<n; i++){
    if(v[i] >= v[k-1] && v[i] > 0){
      count++;
    }
  }
  cout << count << "\n";
  return 0;
}