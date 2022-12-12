#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  cin >> m;
  int b[m];
  for (int j = 0; j < m; j++) {
    cin >> b[j];
  }
  sort(b, b + m);
  int pairs = 0;
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (abs(a[i] - b[j]) < 2) {
      pairs++;
      i++;
      j++;
    } else if (a[i] > b[j]) {
      j++;
    } else {
      i++;
    }
  }
  cout << pairs << endl;
  return 0;
}