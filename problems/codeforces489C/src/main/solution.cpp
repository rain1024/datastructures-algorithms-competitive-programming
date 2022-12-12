#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void GenerateSmallest(int m, int s) {
  vector<int> a;
  int tm = m;
  while (m > 0) {
    if (s > 9) {
      a.insert(a.begin(), 9);
      s -= 9;
    } else if (s > 1) {
      if (m > 1){
        a.insert(a.begin(), s - 1);
        s = 1;
      } else {
        a.insert(a.begin(), s);
      }
    } else {
      if (m > 1) {
        a.insert(a.begin(), 0);
      } else {
        a.insert(a.begin(), 1);
      }
    }
    m--;
  }
  for (int i = 0; i < tm; i++) {
    cout << a[i];
  }
}

void GenerateBiggest(int m, int s) {
  vector<int> a;
  int tm = m;
  while (m > 0) {
    if (s > 9) {
      a.push_back(9);
      s -= 9;
    } else {
      a.push_back(s);
      s = 0;
    }
    m--;
  }
  for (int i = 0; i < tm; i++) {
    cout << a[i];
  }
}

void solve(int m, int s) {
  if (s > m * 9) {
    cout << -1 << " " << -1 << endl;
    return;
  }
  if (s == 0){
    if(m > 1){
      cout << -1 << " " << -1 << endl;
      return;
    } else {
      cout << 0 << " " << 0 << endl;
      return;
    }
  }
  GenerateSmallest(m, s);
  cout << " ";
  GenerateBiggest(m, s);
  cout << endl;
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, s;
  cin >> m >> s;
  solve(m, s);
  return 0;
}