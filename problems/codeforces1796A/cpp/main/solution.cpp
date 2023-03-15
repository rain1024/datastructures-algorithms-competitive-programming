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

void solve(string fb){
  int n;
  string s;
  cin >> n;
  cin >> s;
  cout << (fb.find(s) == string::npos ? "NO" : "YES") << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string fb = "";
  int i = 1;
  while(fb.size() < 100){
    if(i % 3 == 0){
      fb += "F";
    }
    if(i % 5 == 0){
      fb += "B";
    }
    i++;
  }

  // filesystem::path filepath =
  //     filesystem::current_path().parent_path().parent_path() / "data" /
  //     "1.in";
  // ifstream file(filepath);
  //   cin.rdbuf(file.rdbuf());  // redirect cin to file

  int tt;
  cin >> tt;
  while (tt--) {
    // cout << tt << '\n';
    solve(fb);
  }
  return 0;
}