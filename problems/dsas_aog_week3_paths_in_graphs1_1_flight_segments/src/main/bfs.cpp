#include <iostream>
#include <queue>
#include <vector>

using std::queue;
using std::vector;

using namespace std;

int n, m;

int distance(vector<vector<int>> &adj, int s, int t) {
  vector<int> distance(n, -1); // distance from s to each node
  queue<int> q;
  q.push(s);
  distance[s] = 0;
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(auto v: adj[u]){
      if(distance[v] == -1){
        distance[v] = distance[u] + 1;
        q.push(v);
      }
        
    }
  }
  return distance[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
