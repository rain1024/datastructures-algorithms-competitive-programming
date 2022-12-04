#include <bits/stdc++.h>
#include <cmath>
 
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int n, m, a, k;
  cin >> n >> m >> a;
  k = ceil(n * 1.0 / a) * ceil(m * 1.0 / a);
  cout << k << endl;
  return 0;
}