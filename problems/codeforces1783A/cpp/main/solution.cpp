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

void solve() { 
  int n;
  cin >> n;
  vector<int> a(n);
  bool all_equals = true;
  for(int i=0; i<n; i++) {
    cin >> a[i];
    if(i > 0 && a[i] != a[0]) {
      all_equals = false;
    }
  }
  if(all_equals) {
    cout << "NO" << endl;
    return;
  }

  sort(begin(a), end(a), greater<int>());
  cout << "YES" << endl;
  cout << a[0] << " ";
  cout << a[n-1] << " ";
  for(int i=1; i<n-1; i++){
    cout << a[i] << " ";
  }
  cout << endl;
  return;
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