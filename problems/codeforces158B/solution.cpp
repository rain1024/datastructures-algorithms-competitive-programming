#include <bits/stdc++.h>

#include <cmath>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  int g1, g2, g3, g4;
  int m;
  int a;
  int count = 0;
  g1 = g2 = g3 = g4 = 0;
  while (tt--) {
    cin >> a;
    if (a == 1) g1++;
    if (a == 2) g2++;
    if (a == 3) g3++;
    if (a ==4) g4++;
  }
  count += g4;
  count += g3;
  g1 = g1 - min(g1, g3);
  count += g2 / 2;
  g2 = g2 % 2;
  if(g2 == 1){
    count += 1;
    g1 = max(0, g1 - 2);
  }
  count += ceil(g1 * 1.0 / 4);
  cout << count << endl;
  return 0;
}