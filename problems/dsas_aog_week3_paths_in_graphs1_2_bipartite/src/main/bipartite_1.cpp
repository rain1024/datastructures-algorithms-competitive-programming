#include <iostream>
#include <queue>
#include <vector>

using std::queue;
using std::vector;

int n, m;

int bipartite(vector<vector<int> > &adj) {
  // Set up a color array to store the colors of the vertices
  // Initially, all vertices are unmarked (color = -1)
  vector<int> colors(n, -1);

  // Set up a queue for the BFS
  queue<int> q;

  // Start at vertex 0 and mark it with color 0 (red)
  colors[0] = 0;
  q.push(0);

  // While the queue is not empty
  while (!q.empty()) {
    // Get the next vertex from the queue
    int v = q.front();
    q.pop();

    // Visit all neighbors of v
    for (int u : adj[v]) {
      // If the neighbor has not been visited yet
      if (colors[u] == -1) {
        // Mark the neighbor with the opposite color of v
        colors[u] = 1 - colors[v];
        // Add the neighbor to the queue
        q.push(u);
      }
      // If the neighbor has already been visited and has the same color as v
      else if (colors[u] == colors[v]) {
        // The graph is not bipartite
        return 0;
      }
    }
  }

  // If we reach this point, the graph is bipartite
  return 1;
}

int main() {
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
