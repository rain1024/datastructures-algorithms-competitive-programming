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

void solve(string pi){
  string s;
  cin >> s;
  int count = 0;
  for(int i=0; i<s.size(); i++){
    if(s[i] != pi[count]){
      cout << count << endl;
      return;
    }
    count++;
  }
  cout << count << endl;

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
  string pi = "314159265358979323846264338327";
  while (tt--) {
    solve(pi);
  }
  return 0;
}