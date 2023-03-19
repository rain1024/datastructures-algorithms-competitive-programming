#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include <numeric>
// #include <fstream>

using namespace std;

void solve(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin >> a[i];
  }

  for(int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){
      // cout << "a[" << i << "]=" << a[i] << ", a[" << j << "]=" << a[j] << endl;
      // cout << "gcd(a[" << i << "], a[" << j << "])=" << gcd(a[i], a[j]) << endl;
      if(gcd(a[i], a[j]) <= 2){
        cout << "Yes" << endl;
        return;
      }
    }
  }
  cout << "No" << endl;
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