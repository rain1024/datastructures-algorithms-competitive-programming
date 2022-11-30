#include <iostream>
#include <string>
#include <vector>

using namespace std;

using ll = long long;
using vl = vector<ll>;

int lcs(string a, string b) {
  int n = a.size();
  int m = b.size();
  int dp[n + 1][m + 1];
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int j = 0; j <= m; j++) {
    dp[0][j] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i] == b[j]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[n][m];
}

int main() {
  string a, b;
  
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> a >> b;
    cout << lcs(a, b) << endl;
  }
}