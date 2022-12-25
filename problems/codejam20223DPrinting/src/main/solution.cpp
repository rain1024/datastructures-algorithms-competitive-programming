#include <algorithm>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct Printer {
  int c;
  int m;
  int y;
  int k;
};

void get_result(Printer p1, Printer p2, Printer p3){
  int c = min(min(p1.c, p2.c), p3.c);
  int m = min(min(p1.m, p2.m), p3.m);
  int y = min(min(p1.y, p2.y), p3.y);
  int k = min(min(p1.k, p2.k), p3.k);
  int sum = pow(10, 6);
  if(c + m + y + k < pow(10, 6)){
    cout << "IMPOSSIBLE";
  } else {
    m = min(m, max(sum - c, 0));
    y = min(y, max(sum - c - m, 0));
    k = sum - c - m - y;
    cout << c << " " << m << " " << y << " " << k;
  }
}

int main(int argc, char* argv[]) {
  int tt;
  cin >> tt;
  int c, m, y, k;
  for (int i = 0; i < tt; i++) {
    cin >> c >> m >> y >> k;
    Printer p1 = {c, m, y, k};
    cin >> c >> m >> y >> k;
    Printer p2 = {c, m, y, k};
    cin >> c >> m >> y >> k;
    Printer p3 = {c, m, y, k};
    cout << "Case #" << i + 1 << ": ";
    get_result(p1, p2, p3);
    cout << endl;
  }
}