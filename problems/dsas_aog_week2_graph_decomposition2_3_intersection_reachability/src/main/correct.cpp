#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

//function to fill the finishing times vector using DFS on the reverse graph
void dfs_reverse(int x, vector<vector<int>> &adj, vector<int> &used, vector<int> &f) {
  used[x] = 1;
  for (int i = 0; i < adj[x].size(); i++) {
    if (!used[adj[x][i]]) {
      dfs_reverse(adj[x][i], adj, used, f);
    }
  }
  f.push_back(x);
}

//function to count the number of SCCs using DFS on the original graph
void dfs(int x, vector<vector<int>> &adj, vector<int> &used, int &result) {
  used[x] = 1;
  for (int i = 0; i < adj[x].size(); i++) {
    if (!used[adj[x][i]]) {
      dfs(adj[x][i], adj, used, result);
    }
  }
}

int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  int n = adj.size();
  vector<int> used(n, 0);
  vector<int> f;
  //perform DFS on the reverse graph to get the finishing times
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs_reverse(i, adj, used, f);
    }
  }
  //reset the used vector
  std::fill(used.begin(), used.end(), 0);
  //build the reverse graph
  vector<vector<int>> adj_reverse(n, vector<int>());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      adj_reverse[adj[i][j]].push_back(i);
    }
  }
  //perform DFS on the original graph using the finishing times as the order in which the nodes should be visited
  for (int i = f.size() - 1; i >= 0; i--) {
    if (!used[f[i]]) {
      result++;
      dfs(f[i], adj_reverse, used, result);
    }
  }
  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << number_of_strongly_connected_components(adj);
}
