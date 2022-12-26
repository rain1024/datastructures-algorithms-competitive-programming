#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::pair;

#define MAX_N 1000

using namespace std;

// connected components
int cc[MAX_N];
bool visited[MAX_N];

int reach(vector<vector<int> > &adj, int x, int y, int n) {
  int current_cc = 1;
  queue<int> q;
  q.push(1);
  while(!q.empty()){
    int node = q.front();
    q.pop();
    visited[node] = true;
    cc[node] = current_cc;
    for(auto neighbor : adj[node]){
      if(!visited[neighbor]){
        q.push(neighbor);
      };
    }
    
    if(q.empty()){
      for(int i=0; i<n; i++){
        if(!visited[i]){
          q.push(i);
          current_cc++;
        }
      }
    }
  }
  // for(int i=0; i<n; i++){
  //   cout << "cc[" << i << "] = " << cc[i] << endl;
  // }
  //write your code here
  return cc[x] == cc[y];
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
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
