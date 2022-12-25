#include <algorithm>
#include <cmath>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<int>> grid;

void show_grid(vector<vector<int>> g, int n, int m) {
  cout << "Show grid" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%02d ", g[i][j]);
    }
    cout << endl;
  }
}

vector<vector<int>> zeros(int n, int m) {
  vector<vector<int>> v;
  for (int i = 0; i < n; i++) {
    vector<int> row;
    for (int j = 0; j < m; j++) {
      row.push_back(0);
    }
    v.push_back(row);
  }
  return v;
}

vector<vector<int>> normalize(vector<vector<int>> g, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] > 32) {
        g[i][j] = g[i][j] - 32;
      }
    }
  }
  return g;
}

void reset(int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 32) {
        grid[i][j] = 0;
      }
    }
  }
}

// TBD: incorrect function
int trip(int n, int m, int start_i, int start_j, int end_i, int end_j) {
  vector<vector<int>> new_grid = zeros(n, m);
  reset(n, m);
  grid[start_i][start_j] = 0b100000;
  grid[end_i][end_j] = 0;

  show_grid(grid, n, m);
  
  int wi, wj, ni, nj, ei, ej, si, sj;
  int k = 0;

  while (grid[end_i][end_j] != 32) {
    k++;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        // wall
        new_grid[i][j] |= (grid[i][j] & (1 << 0));
        //    N
        // W     E
        //    S
        if (j != 0 && j != m - 1) {
          // west
          wi = i;
          wj = j > 1 ? j - 1 : m - 2;
          new_grid[wi][wj] |= (grid[i][j] & (1 << 3));
          // east
          ei = i;
          ej = j != m - 2 ? j + 1 : 1;
          new_grid[ei][ej] |= (grid[i][j] & (1 << 4));
          if (i != 0) {
            if (j != 1) {
              new_grid[wi][wj] |= (grid[i][j] & (1 << 5));
            }
            if (j != m - 2) {
              new_grid[ei][ej] |= (grid[i][j] & (1 << 5));
            }
          }
        }
        if (i != 0 && i != n - 1) {
          // north
          ni = i != 1 ? i - 1 : n - 2;
          nj = j;
          new_grid[ni][nj] |= (grid[i][j] & (1 << 2));
          // south
          si = i != n - 2 ? i + 1 : 1;
          sj = j;
          new_grid[si][sj] |= (grid[i][j] & (1 << 1));
          if (i != 1) {
            new_grid[ni][nj] |= (grid[i][j] & (1 << 5));
          }
          if (i != m - 2) {
            new_grid[si][sj] |= (grid[i][j] & (1 << 5));
          }
        }
        // position
        new_grid[i][j] |= (grid[i][j] & (1 << 5));
        if (i == 0 && j == 1) {
          new_grid[1][1] |= grid[0][1] & (1 << 5);
        }
        if (i == 1 && j == 1) {
          new_grid[0][1] |= grid[1][1] & (1 << 5);
        }
        if (i == n - 2 && j == m - 2) {
          new_grid[n - 1][m - 2] |= grid[n - 2][m - 2] & (1 << 5);
        }
        if (i == n - 1 && j == m - 2) {
          new_grid[n - 2][m - 2] |= grid[n - 1][m - 2] & (1 << 5);
        }
      }
    }
    grid = normalize(new_grid, n, m);
    new_grid = zeros(n, m);
  }
  return k;
}

int main(int argc, char* argv[]) {
  // string input = argv[1];
  string input =
      "/Users/anhv/projects/datastructures-algorithms-competitive-programming/"
      "problems/aoc2022day24/data/input.txt";
  string line;
  fstream f(input);
  vector<string> data;
  while (getline(f, line)) {
    data.push_back(line);
  }
  int n = data.size();
  int m = data[0].size();

  // E > < ^ v # .
  // 1 1 1 1 1 1
  // 5 4 3 2 1 0
  std::unordered_map<char, int> mm = {
      {'.', 0b000000}, {'#', 0b000001}, {'v', 0b000010}, {'^', 0b000100},
      {'<', 0b001000}, {'>', 0b010000}};
  for (int i = 0; i < n; i++) {
    vector<int> row;
    for (int j = 0; j < m; j++) {
      int value = mm[data[i][j]];
      row.push_back(value);
    }
    grid.push_back(row);
  }

  int c1 = trip(n, m, 0, 1, n - 1, m - 2);
  int c2 = trip(n, m, n - 1, m - 2, 0, 1);
  int c3 = trip(n, m, 0, 1, n - 1, m - 2);
  cout << "c1 = " << c1 << endl;
  cout << "c2 = " << c2 << endl;
  cout << "c3 = " << c3 << endl;
  int total = c1 + c2 + c3;
  cout << "total = " << total << endl;
  return 0;
}