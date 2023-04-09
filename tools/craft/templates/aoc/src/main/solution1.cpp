#include <algorithm>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "helpers.h"

using namespace std;

int main(int argc, char* argv[]) {
  string input = argv[1];
  string line;
  fstream f(input);
  int result = 0;
  while (getline(f, line)) {
    if (line.size() != 0) {
      cout << line << endl;
    }
  }
  cout << "result = " << result << endl;
}