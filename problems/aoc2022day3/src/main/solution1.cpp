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

int get_priority(char c) {
  int priority;
  // get priority
  if (c >= 'A' && c <= 'Z') {
    priority = c - 'A' + 27;
  }
  if (c >= 'a' && c <= 'z') {
    priority = c - 'a' + 1;
  }
  return priority;
}

int main(int argc, char* argv[]) {
  string input = argv[1];
  string line;
  fstream f(input);

  int sum = 0;
  int priority;
  int count = 0;
  while (getline(f, line)) {
    set<char> s1;
    if (line.size() != 0) {
      count += 1;
      int n = line.size();
      for (int i = 0; i < n; i++) {
        if (i < n / 2) {
          s1.insert(line[i]);
        } else {
          if (s1.find(line[i]) != s1.end()) {
            sum += get_priority(line[i]);
            break;
          }
        }
      }
    }
  }
  cout << "Sum = " << sum << endl;
}