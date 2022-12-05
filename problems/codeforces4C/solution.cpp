#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#include <map>
 
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  map<string, int> m;
  string s;
  int count;
  while(tt--){
    cin >> s;
    if(m.find(s) == m.end()){
      cout << "OK" << endl;
      m[s] = 1;
    } else {
      cout << s << m[s] << endl;
      m[s] += 1;
    }
  }
  return 0;
}