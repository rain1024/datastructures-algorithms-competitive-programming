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
  int w, d, h; 
  cin >> w >> d >> h;
  int a, b, f, g;
  cin >> a >> b >> f >> g;
  int length = h + min(
    min(b + abs(a - f) + g, a + abs(b -  g) + f),
    min(d - b + abs(a - f) + d - g, w - a + abs(b - g) + w - f));
  cout << length << endl;
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