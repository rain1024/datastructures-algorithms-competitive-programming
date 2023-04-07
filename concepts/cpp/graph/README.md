# Graph

A `graph` is a data structure that consists of the following two components:

* A finite set of vertices also called as **nodes**.
* A finite set of ordered pair of the form `(u, v)` called as **edge**. The pair is ordered because `(u, v)` is not same as `(v, u)` in case of a **directed graph(di-graph)**. The pair of the form `(u, v)` indicates that there is an edge from vertex u to vertex v. The edges may contain weight/value/cost.

## Graph Representation in C++

Example graph: 

```
   1----->2----->3
   ^      |      |
   |      |      |
   |      v      v
   4<-----5<-----6
```

The most common way to represent a graph is using an `adjacency list`. An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph. The node is represented by the index of the list. The neighbors are the elements of the list. The following is an adjacency list representation of the graph above.


```c++
#include <iostream>
#include <vector>

using namespace std;
```


```c++
vector<vector<int>> adj(7); // 1-indexed

adj[1] = {2};
adj[2] = {3, 5};
adj[3] = {6};
adj[4] = {1};
adj[5] = {4};
adj[6] = {5};

for(int i=1; i<adj.size(); i++){
    cout << i << ": ";
    for(int j=0; j<adj[i].size(); j++){
        cout << adj[i][j] << " ";
    }
    cout << endl;
}

```

    1: 2 
    2: 3 5 
    3: 6 
    4: 1 
    5: 4 
    6: 5 


## References

* [Graph](https://en.wikipedia.org/wiki/Graph_(abstract_data_type)), wikipedia
* ▶️ [Graph Algorithms for Technical Interviews - Full Course](https://www.youtube.com/watch?v=tWVWeAqZ0WU&ab_channel=freeCodeCamp.org), freeCodeCamp.org
