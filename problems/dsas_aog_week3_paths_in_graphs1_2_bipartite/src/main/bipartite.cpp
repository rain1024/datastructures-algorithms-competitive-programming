#include <iostream>
#include <queue>
#include <vector>

using std::queue;
using std::vector;

using namespace std;
int n, m;

int bipartite(vector<vector<int>> &adj) {
  vector<int> color(n, 0);
  queue<int> q;
  
  for (int i = 0; i < n; i++) {
    if(color[i] != 0){
      continue;
    }
    color[i] = 1;
    q.push(i);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : adj[u]) {
        if (color[v] == 0) {
          color[v] = -color[u];
          q.push(v);
        } else {
          if (color[v] == color[u]) {
            return 0;
          }
        }
      }
    }
  }

  return 1;
}

int main() {
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
