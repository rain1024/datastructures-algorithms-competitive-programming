#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
// #include <fstream>

using namespace std;

void solve(unordered_map<char, int> m){
  char c;
  cin >> c;
  
  if(m.count(c) > 0){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // filesystem::path filepath =
  //     filesystem::current_path().parent_path().parent_path() / "data" /
  //     "1.in";
  // ifstream file(filepath);
  //   cin.rdbuf(file.rdbuf());  // redirect cin to file

  int tt;
  cin >> tt;
  string s = "codeforces";
  unordered_map<char, int> m;
  for(char c : s){
    m[c]++;
  }

  while (tt--) {
    solve(m);
  }
  return 0;
}