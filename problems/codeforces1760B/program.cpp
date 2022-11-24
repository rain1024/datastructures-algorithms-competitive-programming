#include <bits/stdc++.h>
 
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--){
    int n;
    string s;
    int m = 1;
    cin >> n >> s;
    for(auto c: s){
      m = max(m, c - 'a' + 1);
    }
    cout << m << '\n';
  }
  return 0;
}