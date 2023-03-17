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
  vector<int> h(n);
  int c1 = 0;
  int c2 = 0;
  for(int i=0; i<n; i++){
    cin >> h[i];
    if(h[i] == 1){
      c1++;      
    } else {
      c2++;
    }
  }
  cout << c2 + c1 % 2 + c1 / 2 << endl; 
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