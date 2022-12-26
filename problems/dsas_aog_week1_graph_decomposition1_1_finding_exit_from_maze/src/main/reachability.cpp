#include <iostream>
#include <queue>
#include <vector>

using std::pair;
using std::vector;

#define MAX_N 1000

using namespace std;

// connected components
int cc[MAX_N];
bool visited[MAX_N];

void dfs(vector<vector<int>> adj, int i, int cci) {
  visited[i] = true;
  cc[i] = cci;
  for (auto j : adj[i]) {
    if (!visited[j]) {
      dfs(adj, j, cci);
    }
  }
}

int reach(vector<vector<int>> adj, int x, int y, int n) {
  int cci = 1;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      dfs(adj, i, cci++);
    }
  }
  return cc[x] == cc[y];
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1, n);
}
