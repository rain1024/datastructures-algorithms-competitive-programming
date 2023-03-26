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
  int minScore(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> adj(n + 1);  // 1-based index
    vector<bool> visited(n + 1);

    for (auto road : roads) {
      adj[road[0]].push_back({road[1], road[2]});
      adj[road[1]].push_back({road[0], road[2]});
    }

    queue<int> q;
    q.push(1);
    int min_dist = INT_MAX;

    while (!q.empty()) {
      int node = q.front();
      q.pop();
      visited[node] = true;

      for (auto p : adj[node]) {
        int next = p.first;
        min_dist = min(min_dist, p.second);
        if (!visited[next]) {
          q.push(next);
        }
      }
    }
    return min_dist;
  }
};