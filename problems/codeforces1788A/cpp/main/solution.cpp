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
  vector<unsigned long long> a(n);
  int c = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    c += (a[i] == 2);
  }
  if(c % 2 == 1){
    cout << "-1" << endl;
    return;
  }
  int ci = 0;
  for(int i=0; i<n-1; i++){
    ci += (a[i] == 2);
    if(ci == c / 2){
      cout << i+1 << endl; // 1-based index
      return;
    }
  }
  cout << "-1" << endl;
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