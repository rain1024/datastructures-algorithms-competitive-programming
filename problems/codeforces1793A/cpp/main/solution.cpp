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
  long long a, b;
  long long n, m;
  cin >> a >> b;
  cin >> n >> m;
  long long cost;
  long long q = n / (m+1);
  long long r = n - q * (m+1);
  cost = q * min(a * m, b * (m+1)) + r * min(a, b);
  cout << cost << endl;
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