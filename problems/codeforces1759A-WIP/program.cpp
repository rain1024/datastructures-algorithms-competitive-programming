#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  string s;
  cin >> t;
  int count = 0;
  while(t--) {
    cin >> s;
    if(s.length() == 0){
      cout << "NO" << endl;
      continue;
    }
    if(s[0] == 'Y' || s[0] == 'e' || s[0] == 's'){
      if (s.substr(0, 1) == "Ye"){
        cout << "YES" << endl;
      } else {
        cout << "YES" << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}