#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ComputeCost(int n, int m, int a, int b) {
  int cost = 0;
  if (m >= n) {
    if(b <= n){
      return b;
    }
  }
  if (a * m >= b) {
    cost += n / m * b;
    n = n % m;
    cost += min(n * a, b);
  } else {
    cost += n * a;
  }
  
  return cost;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  cout << ComputeCost(n, m, a, b) << endl;
  return 0;
}