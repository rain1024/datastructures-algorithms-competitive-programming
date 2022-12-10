#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
 
using namespace std;

string IsHello(string s){
  string s1 = "hello";
  int i = 0;
  for(auto c: s){
    if(c == s1[i]){
      i++;
    }
    if(i == s1.length()){
      return "YES";
    }
  }
  return "NO";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  cout << IsHello(s);
  return 0;
}