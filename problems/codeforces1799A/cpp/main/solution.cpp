#include <algorithm>
#include <cmath>
// #include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void solve() {
  int n;
  int m;
  cin >> n;
  cin >> m;
  vector<int> p(m);
  for (int i = 0; i < m; i++) {
    cin >> p[i];
  }
  vector<int> output(n, -1);
  set<int> actions;
  int last_posts = n-1;
  for (int i = 0; i < m; i++) {
    if(actions.find(p[i]) == actions.end()) {
      actions.insert(p[i]);
      if(last_posts >= 0){
        output[last_posts] = i + 1;
        last_posts--;
      }
    }
  }

  for (auto item : output) {
    cout << item << " ";
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // filesystem::path filepath =
  //     filesystem::current_path().parent_path().parent_path() / "data" / "1.in";
  // ifstream file(filepath);
  // cin.rdbuf(file.rdbuf());  // redirect cin to file

  int tt;
  cin >> tt;
  int n, m;
  while (tt--) {
    solve();
  }
  return 0;
}