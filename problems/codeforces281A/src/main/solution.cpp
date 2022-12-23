#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      char c = toupper(s[i]);
      cout << c;
    } else {
      cout << s[i];
    }
  }
  cout << endl;
  return 0;
}