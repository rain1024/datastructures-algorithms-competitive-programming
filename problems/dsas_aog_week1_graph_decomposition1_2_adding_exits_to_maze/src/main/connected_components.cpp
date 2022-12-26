#include <iostream>
#include <vector>

using std::pair;
using std::vector;

#define N 1000
bool visited[N];

using namespace std;

void dfs(vector<vector<int>> adj, int i) {
  for(auto j: adj[i]){
    if(!visited[j]){
      visited[j] = true;
      dfs(adj, j);
    };
  }
}
int number_of_components(vector<vector<int>> &adj, int n) {
  int res = 0;
  for (int i = 0; i < n; i++) {
    if(!visited[i]){
      dfs(adj, i);
      res++;
    }
  }
  return res;
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
  std::cout << number_of_components(adj, n);
}
