#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

bool is_lucky(int i) { 
  int k;
  while(i > 0){
    // cout << "i = " << i << endl;
    k = i % 10;
    if(k != 4 && k != 7){
      return false;
    }
    i = (i - k) / 10;
  }
  return true;
}

bool is_almost_lucky(int n) {
  if(is_lucky(n)){
    return true;
  }

  for (int i = 4; i <= n/2; i++) {
    if (is_lucky(i)) {
      if (n % i == 0) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string result = is_almost_lucky(n) ? "YES": "NO";
  cout << result << endl;
  return 0;
}