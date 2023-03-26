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
  int count = 0;
  void dfs(int node, int parent, vector<vector<pair<int, int>>>& adj) {
    for (auto& [child, sign] : adj[node]) {
      if (child != parent) {
        count += sign;
        dfs(child, node, adj);
      }
    }
  }
  int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<pair<int, int>>> adj(n);
    for (auto c : connections) {
      adj[c[0]].push_back({c[1], 1});
      adj[c[1]].push_back({c[0], 0});
    }
    dfs(0, -1, adj);
    return count;
  }
};