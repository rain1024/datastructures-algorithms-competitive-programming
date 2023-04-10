# Topological Sorting

Topological sorting is a linear ordering of vertices in a directed acyclic graph (DAG) such that for every directed edge uv, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

## Topological Sorting in C++

Example directed acyclic graph:

```
  5      0
  ^     / \
  |    v   v
  4 <- 2 <- 3
  ^         |
  |         v
  1 -> 6 -> 7
```

```cpp
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
```

Use DFS to find the topological sort:

```cpp
void dfs(int i, vector<vector<int>> adj, vector<int> &visited, vector<int> &orders){
  visited[i] = true;
  for(auto j: adj[i]){
    if(!visited[j]){
      dfs(j, adj, visited, orders);
    }
  }
  orders.push_back(i);
}

vector<int> topological_sort(int n, vector<vector<int>> adj) {
  vector<int> visited(n, false);
  vector<int> orders;

  for(int i=0; i<n; i++){
    if(!visited[i]){
      dfs(i, adj, visited, orders);
    }
  }
  reverse(orders.begin(), orders.end());
  return orders;
}
```

```cpp
vector<int> orders = topological_sort(n, adj);
for (auto i : orders) {
  cout << i << " ";
}
```

Output

```
1 6 0 3 7 2 4 5
```

## References

* [Topological Sort Algorithm | Graph Theory, WilliamFiset](https://www.youtube.com/watch?v=eL-KzMXSXXI&t=308s&ab_channel=WilliamFiset)
* [Topological Sort | GeeksforGeeks](https://www.geeksforgeeks.org/topological-sorting/)
* https://cp-algorithms.com/graph/topological-sort.html
