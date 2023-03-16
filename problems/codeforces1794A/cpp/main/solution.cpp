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

void solve(){
  int n;
  cin >> n;
  vector<string> sub;
  string s;
  for(int i=0; i<2 * n - 2; i++){
    cin >> s;
    if(s.size() == n - 1){
      sub.push_back(s);
    }
  }
  string s1 = sub[0];
  string s2 = sub[1];
  for(int i=0; i<n-1; i++){
    if(s1[i] != s2[n-2-i]){
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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
  while (tt--) {
    solve();
  }
  return 0;
}