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
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(begin(a), end(a));
  // for(auto i : a){
  //   cout << i << " ";
  // }
  // cout << endl;
  long long count = 0;
  int h = 1; // health
  for(int i=0; i<n; i++){
    // cout << "a[" << i << "] = " << a[i] << ", h = " << h << endl;
    if(a[i] > h){
      count += (long long) (a[i] - h);
      h++;
    } else if(a[i] == h){
      h++;
    }
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
  while (tt--) {
    solve();
  }
  return 0;
}