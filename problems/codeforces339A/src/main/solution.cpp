#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  vector<char> v;
  for(auto c: s){
    if(c != '+'){
      v.push_back(c);
    }
  }
  sort(v.begin(), v.end());
  string result = "";
  result.push_back(v[0]);
  for(int i = 1; i < v.size(); i++){
    result.push_back('+');
    result.push_back(v[i]);
  }
  cout << result << endl;
  return 0;
}