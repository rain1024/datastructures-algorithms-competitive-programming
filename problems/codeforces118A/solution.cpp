#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  string s;
  cin >> s;
  set<char> vowels = {'A', 'O', 'Y', 'E', 'U', 'I', 'a', 'o', 'y', 'e', 'u', 'i', 'o'};
  for(auto c: s){
    if(vowels.find(c) == vowels.end()){
      if(c > 'A' && c <= 'Z'){
        c = c - 'A' + 'a';
      }
      cout << '.' << c;
    }
  }
  cout << endl;
  return 0;
}