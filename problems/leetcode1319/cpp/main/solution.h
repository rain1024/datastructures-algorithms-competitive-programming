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
  int makeConnected(int n, vector<vector<int>>& connections) {
    int e = connections.size();
    if (e < n - 1) {
      return -1;
    }
    vector<bool> visited(n, false);
    vector<vector<int>> edges(n, vector<int>{});
    int scc = 0;
    for (auto connection : connections) {
      int x = connection[0];
      int y = connection[1];
      edges[x].push_back(y);
      edges[y].push_back(x);
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
      // bfs
      if (!visited[i]) {
        scc++;
        q.push(i);
        while (!q.empty()) {
          int node = q.front();
          q.pop();
          if (visited[node]) continue;
          visited[node] = true;
          for (auto next : edges[node]) {
            if (!visited[next]) {
              q.push(next);
            }
          }
        }
      }
    }
    return scc - 1;
  }
};