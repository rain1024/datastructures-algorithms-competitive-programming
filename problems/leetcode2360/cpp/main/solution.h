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
  int longestCycle(vector<int>& edges) {
    int n = edges.size();
    vector<bool> visit(n);
    vector<int> indegree(n);

    // Coount indegree of each node
    for (int edge : edges) {
      if (edge != -1) {
        indegree[edge]++;
      }
    }

    // Kahn's algorithms starts
    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      int node = q.front();
      q.pop();

      visit[node] = true;
      int neighbor = edges[node];
      if (neighbor != -1) {
        indegree[neighbor]--;
        if (indegree[neighbor] == 0) {
          q.push(neighbor);
        }
      }
    }
    // Kahn's algorithms end

    int answer = -1;
    for (int i = 0; i < n; i++) {
      if (!visit[i]) {
        int neighbor = edges[i];
        int count = 1;
        visit[i] = true;
        // Iterate in the cycle
        while (neighbor != i) {
          visit[neighbor] = true;
          count++;
          neighbor = edges[neighbor];
        }
        answer = max(answer, count);
      }
    }
    return answer;
  }
};