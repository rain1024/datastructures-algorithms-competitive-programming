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

int main(int argc, char* argv[]) {
  int tt;
  cin >> tt;
  int r, c;
  for (int i = 0; i < tt; i++) {
    cout << "Case #" << i + 1 << ":" << endl;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (i == 0 && j == 0) {
          cout << "..";
        } else {
          cout << "+-";
        }
      }
      cout << "+" << endl;
      for (int j = 0; j < c; j++) {
        if (i == 0 && j == 0) {
          cout << "..";
        } else {
          cout << "|.";
        }
      }
      cout << "|" << endl;
    }
    for (int j = 0; j < c; j++) {
      cout << "+-";
    }
    cout << "+" << endl;
  }
}