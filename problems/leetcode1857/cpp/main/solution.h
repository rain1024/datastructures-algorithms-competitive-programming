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
  int dfs(int node, string& colors, vector<vector<int>>& adj,
          vector<vector<int>>& count, vector<bool>& visit,
          vector<bool>& inStack) {
    if (inStack[node]) {
      return INT_MAX;
    }
    if (visit[node]) {
      return count[node][colors[node] - 'a'];
    }

    visit[node] = true;
    inStack[node] = true;

    for (auto& neighbor : adj[node]) {
      if (dfs(neighbor, colors, adj, count, visit, inStack) == INT_MAX) {
        return INT_MAX;
      }
      for (int i = 0; i < 26; i++) {
        count[node][i] = max(count[node][i], count[neighbor][i]);
      }
    }

    // after all the incoming edges to the node are processed
    // we count the color on the node it self
    count[node][colors[node] - 'a']++;
    inStack[node] = false;
    return count[node][colors[node] - 'a'];
  }

  int largestPathValue(string colors, vector<vector<int>>& edges) {
    int n = colors.length();
    vector<vector<int>> adj(n);
    for (auto& edge : edges) {
      adj[edge[0]].push_back(edge[1]);
    }

    vector<vector<int>> count(n, vector<int>(26));
    vector<bool> visit(n), inStack(n);
    int answer = 0;
    for (int i = 0; i < n; i++) {
      answer = max(answer, dfs(i, colors, adj, count, visit, inStack));
    }
    return answer == INT_MAX ? -1 : answer;
  }
};