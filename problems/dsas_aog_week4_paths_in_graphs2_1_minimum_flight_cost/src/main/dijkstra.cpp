#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

using namespace std;
int n, m;

long long distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code her
  long long MAX_DISTANCE = numeric_limits<long long>::max();
  vector<long long> dist(n, MAX_DISTANCE);
  vector<int> visited(n, 0);

  auto cmp = [](pair<int, long long> a, pair<int, long long> b){
    return a.second > b.second;
  };
  priority_queue<pair<int, long long>, vector<pair<int, long long>>, decltype(cmp)> pq(cmp);

  pq.emplace(s, 0);
  dist[s] = 0;
  visited[s] = 1;

  while(!pq.empty()){
    int u = pq.top().first;
    pq.pop();
    visited[u] = 1;

    // update the distance of adjacent vertices
    for(int i=0; i<adj[u].size(); i++){
      int v = adj[u][i];
      long long w = cost[u][i];

      if(dist[v] > dist[u] + w){
        dist[v] = dist[u] + w;
        if(!visited[v]){
          pq.emplace(v, dist[v]);
        }
      }
    }
  }
  return (dist[t] == MAX_DISTANCE) ? -1 : dist[t];
}

int main() {
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
