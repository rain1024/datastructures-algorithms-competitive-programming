#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void dfs(int i, vector<vector<int>> adj, vector<int> &visited,
         vector<int> &orders) {
  visited[i] = true;
  for (auto j : adj[i]) {
    if (!visited[j]) {
      dfs(j, adj, visited, orders);
    }
  }
  orders.push_back(i);
}

vector<int> topological_sort(int n, vector<vector<int>> adj) {
  vector<int> visited(n, false);
  vector<int> orders;

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      dfs(i, adj, visited, orders);
    }
  }
  reverse(orders.begin(), orders.end());
  return orders;
}

int main() {
  int n = 8;
  vector<vector<int>> adj(n);

  adj[0] = {2, 3};
  adj[1] = {4, 6};
  adj[2] = {4};
  adj[3] = {2, 7};
  adj[4] = {5};
  adj[5] = {};
  adj[6] = {7};
  adj[7] = {};

  vector<int> orders = topological_sort(n, adj);
  for (auto i : orders) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}