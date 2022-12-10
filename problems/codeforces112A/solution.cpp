#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cctype>

using namespace std;

string compare_string(string s1, string s2){
  int n = s1.size();
  for(int i=0; i<n; i++){
    if(tolower(s1[i]) > tolower(s2[i])){
      return "1";
    }
    if(tolower(s1[i]) < tolower(s2[i])){
      return "-1";
    }
  }
  return "0";
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s1, s2;
  cin >> s1 >> s2;
  string c = compare_string(s1, s2);
  cout << c;
  return 0;
}