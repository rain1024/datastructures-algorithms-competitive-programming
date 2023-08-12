#include <algorithm>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "helpers.h"

using namespace std;

int main(int argc, char* argv[]) {
  string input = argv[1];
  string line;
  fstream f(input);
  long long sum_c = 0;
  vector<long long> v;
  while (getline(f, line)) {
    if (line.size() == 0) {
      v.push_back(sum_c);
      sum_c = 0;
    } else {
      sum_c += stoi(line);
    }
  }
  sort(v.begin(), v.end(), greater<long long>());
  long long total = v[0] + v[1] + v[2];
  cout << "max_c = " << total << endl;
}