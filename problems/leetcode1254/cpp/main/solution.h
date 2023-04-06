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
  int connected_component(vector<set<int>> edges, int n, int w, int h,
                          vector<int> nodes) {
    int s = 0;
    vector<int> visit(n, false);
    stack<int> st;

    // dfs in each unvisited node
    for (int i = 0; i < n; i++) {
      if (nodes[i] == 1) {
        visit[i] = true;
        continue;
      }
      if (visit[i]) continue;
      st.push(i);
      bool is_border = false;
      while (!st.empty()) {
        int node = st.top();
        st.pop();
        visit[node] = true;
        if (node < w || node > w * (h - 1)) {
          is_border = true;
        }
        if (node % w == 0 || node % w == (w - 1)) {
          is_border = true;
        }
        for (int next : edges[node]) {
          if (nodes[next] == 1) continue;
          if (visit[next]) continue;
          st.push(next);
        }
      }
      if (!is_border) {
        s++;
      }
    }
    return s;
  }

  int closedIsland(vector<vector<int>>& grid) {
    int h = grid.size();
    int w = grid[0].size();
    int n = h * w;
    vector<set<int>> edges(n);
    vector<int> nodes(n);

    for (int x = 0; x < n; x++) {
      int xh = x / w;
      int xw = x % w;
      nodes[x] = grid[xh][xw];
      if (x % w > 0) {
        edges[x].insert(x - 1);
        edges[x - 1].insert(x);
      }
      if (x % w != (w - 1)) {
        edges[x].insert(x + 1);
        edges[x + 1].insert(x);
      }
      if (x > w) {
        edges[x].insert(x - w);
        edges[x - w].insert(x);
      }
      if (x < n - 1 - w) {
        edges[x].insert(x + w);
        edges[x + w].insert(x);
      }
    }
    return connected_component(edges, n, w, h, nodes);
  }
};