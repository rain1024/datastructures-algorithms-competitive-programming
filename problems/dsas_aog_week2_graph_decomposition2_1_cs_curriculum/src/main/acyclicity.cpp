#include <iostream>
#include <vector>

using std::pair;
using std::vector;

#define N 1000
bool visited[N];
bool recursion_stack[N];

bool dfs(vector<vector<int>> adj, int i){
  visited[i] = true;
  recursion_stack[i] = true;
  for(auto j: adj[i]){
    if(!visited[j]){
      bool output = dfs(adj, j);
      if(output){
        return true;
      }
    } else {
      if(recursion_stack[j]){
        return true;
      }
    }
  }
  recursion_stack[i] = false;
  return false;
};

// return true if the give graph has cycle.
int acyclic(vector<vector<int>> &adj, int n) {
  for(int i=0; i<n; i++){
    if(!visited[i]){
      bool output = dfs(adj, i);
      if(output){
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj, n);
}
