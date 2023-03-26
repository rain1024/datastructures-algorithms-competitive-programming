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
  long long countPairs(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    long long P = (long long)n * (n - 1) / 2;  // total pairs
    for (auto e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }
    vector<bool> visited(n, false);
    queue<int> q;

    long long Pc = 0;  // total connected pairs;

    for (int i = 0; i < n; i++) {
      if (visited[i]) continue;
      long long ns = 0;  // num node in sub graph
      q.push(i);
      while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (visited[node]) continue;
        visited[node] = true;
        ns += 1;
        for (auto next : adj[node]) {
          if (!visited[next]) {
            q.push(next);
          }
        }
      }
      Pc += ns * (ns - 1) / 2;
    }
    return P - Pc;
  }
};