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
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s;
  cin >> t;
  reverse(t.begin(), t.end());
  string merge = s + t;
  int count = 0;
  // cout << "merge: " << merge << endl;
  for(int i=1; i<merge.size(); i++){
    if(merge[i] == merge[i-1]){
      count++;
    }
  }
  if(count > 1){
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
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
  while (tt--) {
    solve();
  }
  return 0;
}