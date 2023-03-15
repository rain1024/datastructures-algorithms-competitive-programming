#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    int x, y;
    // int j = 0;
    // for(auto item: board){
    //     if(j==3 || j==6 || j==9){
    //         cout << "------ ------ -------" << endl;
    //     }
    //     j++;
    //     int i = 0;
    //     for(auto cell: item){
    //         i++;
    //         if(i == 0 || i == 3 || i == 6){
    //             cout << cell << " | ";
    //         } else {
    //             cout << cell << " ";
    //         }
    //     }
    //     cout << endl;
    // }

    // init groups
    vector<vector<vector<int>>> groups;
    vector<vector<int>> group, row, col;

    // add row and column
    for (int i = 0; i < 9; i++) {
      row.clear();
      col.clear();
      for (int j = 0; j < 9; j++) {
        row.push_back({i, j});
        col.push_back({j, i});
      }
      groups.push_back(row);
      groups.push_back(col);
    }

    //
    vector<vector<int>> nodes = {{0, 0}, {0, 3}, {0, 6}, {3, 0}, {3, 3},
                                 {3, 6}, {6, 0}, {6, 3}, {6, 6}};
    for (auto node : nodes) {
      x = node[0];
      y = node[1];
      group.clear();
      for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
          group.push_back({x + i, y + j});
        }
      }
      groups.push_back(group);
    }

    // check groups

    string value;
    for (auto group : groups) {
      set<string> s;
      s.clear();
      for (auto pair : group) {
        x = pair[0];
        y = pair[1];
        value = board[x][y];
        if (s.find(value) != s.end()) {
          return false;
        }
        if (value != ".") {
          s.insert(value);
        }
      }
    }
    return true;
  }
};