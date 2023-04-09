#include <algorithm>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include "helpers.h"

using namespace std;

int main(int argc, char* argv[]) {
  string input = argv[1];
  string line;
  fstream f(input);
  string result = "";
  bool is_parse_command = false;

  // string CrateMover = "9000";
  string CrateMover = "9001";

  vector<vector<char>> data(10, vector<char>());
  vector<stack<int>> crates(10, stack<int>());

  while (getline(f, line)) {
    if (line.size() != 0) {
      if (!is_parse_command) {
        if (line.substr(0, 3) == " 1 ") {
          continue;
        }

        int order = 1;
        for (int i = 1; i < line.size(); i += 4) {
          if (line[i] != ' ') {
            data[order].push_back(line[i]);
          }
          order++;
        }

      } else {
        cout << "command = " << line << endl;
        vector<string> parts = parse_line(line);
        int move = stoi(parts[1]);
        int from = stoi(parts[3]);
        int to = stoi(parts[5]);
        vector<char> temp;
        for (int i = 0; i < move; i++) {
          temp.push_back(crates[from].top());
          crates[from].pop();
        }
        for (int i = 0; i < move; i++) {
          if (CrateMover == "9000") {
            crates[to].push(temp[i]);
          } else {
            crates[to].push(temp[temp.size() - 1 - i]);
          }
        }
      }
    } else {
      is_parse_command = true;
      for (int i = 1; i < data.size(); i++) {
        cout << "crate " << i << " = ";
        for (int j = data[i].size() - 1; j >= 0; j--) {
          cout << data[i][j] << " ";
          crates[i].push(data[i][j]);
        }
        cout << endl;
      }
    }
  }
  for (int i = 1; i < crates.size(); i++) {
    result += crates[i].top();
  }
  cout << "result = " << result << endl;
}