#include <algorithm>
#include <climits>
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
  int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> visit(m, vector<int>(n, false));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        // continue if cell[i][j] is not border
        if (!(i == 0 || i == m - 1 || j == 0 || j == n - 1)) continue;
        // continue if grid[i][j] == 0
        if (grid[i][j] == 0) continue;
        // continue if visit[i][j]
        if (visit[i][j]) continue;
        // dfs from cell[i][j]
        stack<pair<int, int>> st;
        // cout << "i, j = " << i << ", " << j << endl;
        st.push({i, j});
        while (!st.empty()) {
          pair<int, int> cell = st.top();
          st.pop();
          int ci = cell.first;
          int cj = cell.second;
          if (visit[ci][cj]) continue;
          // cout << "ci, cj = " << ci << ", " << cj << endl;
          visit[ci][cj] = true;
          vector<int> dm = {0, 0, 1, -1};
          vector<int> dn = {1, -1, 0, 0};
          for (int t = 0; t < 4; t++) {
            int ni = ci + dm[t];
            int nj = cj + dn[t];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 1) {
              if (!visit[ni][nj]) {
                st.push({ni, nj});
              }
            }
          }
        }
      }
    }

    int count = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1 && visit[i][j] == false) {
          count++;
        }
      }
    }
    return count;
  }
};