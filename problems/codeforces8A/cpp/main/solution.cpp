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

bool is_contains(string s, string sub1, string sub2) {
  int p1 = s.find(sub1);
  if(p1 == -1){
    return false;
  }
  int p2 = s.find(sub2, p1 + sub1.size());
  if(p2 == -1){
    return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // filesystem::path filepath =
  //     filesystem::current_path().parent_path().parent_path() / "data" /
  //     "1.in";
  // ifstream file(filepath);
  //   cin.rdbuf(file.rdbuf());  // redirect cin to file

  string s;
  string s1;
  string s2;

  cin >> s >> s1 >> s2;
  bool forward = is_contains(s, s1, s2);
  reverse(begin(s), end(s));
  bool backward = is_contains(s, s1, s2);
  if (backward && forward) {
    cout << "both" << endl;
    return 0;
  }
  if (forward) {
    cout << "forward" << endl;
    return 0;
  }
  if (backward) {
    cout << "backward" << endl;
    return 0;
  }
  cout << "fantasy" << endl;
  return 0;
}