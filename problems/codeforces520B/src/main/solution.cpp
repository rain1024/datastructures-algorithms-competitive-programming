#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>
#include <climits>

using namespace std;
const int MAX_N = 200;
int dp[MAX_N];

int solve(int n, int m){
  cout << "solve(" << n << "," << m << ")" << endl;
  if(n == m){
    return 0;
  }
  if(n > m){
    dp[n] += (n - m);
    return dp[n];
  }
  if(n > 1){
    dp[n] = 1 + min(solve(n -1, m), solve(n * 2, m));
  } else {
    dp[n] = 1 + solve(n * 2, m);
  }
  return dp[n];
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  dp[n] = 0;
  dp[m] = INT_MAX;
  dp[m] = solve(n, m);
  cout << dp[m] << endl;
  return 0;
}