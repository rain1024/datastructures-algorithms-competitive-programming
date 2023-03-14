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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // filesystem::path filepath =
  //     filesystem::current_path().parent_path().parent_path() / "data" /
  //     "1.in";
  // ifstream file(filepath);
  //   cin.rdbuf(file.rdbuf());  // redirect cin to file
  vector<int> a(4);
  cin >> a[0] >> a[1] >> a[2] >> a[3];
  sort(begin(a), end(a));
  if (a[0] + a[1] > a[2] || a[1] + a[2] > a[3]) {
    cout << "TRIANGLE";
    return 0;
  }
  if (a[0] + a[1] == a[2] || a[1] + a[2] == a[3]) {
    cout << "SEGMENT";
    return 0;
  }
  cout << "IMPOSSIBLE";

  return 0;
}