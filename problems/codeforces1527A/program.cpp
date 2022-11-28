#include <bits/stdc++.h>
#include <cmath>
using namespace std;

void solve(int n){
  int base = log2(n);
  int k1 = n >> base << base;
  int k = k1 - 1;
  if(k1 == 0){
    k = 0;
  }
  cout << k << "\n";
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  int n;
  cin >> tt;
  while(tt--){
    cin >> n;
    solve(n);
  }
  return 0;
}