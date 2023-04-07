# Graph

*See implementation in*
[C++](/concepts/cpp/graph/README.md),
Java,
Python,
typescript

In computer science, a graph is a data structure that consists of the following two components:

* A finite set of vertices also called as **nodes**.
* A finite set of ordered pair of the form `(u, v)` called as **edge**. The pair is ordered because `(u, v)` is not same as `(v, u)` in case of a **directed graph(di-graph)**. The pair of the form `(u, v)` indicates that there is an edge from vertex u to vertex v. The edges may contain weight/value/cost.

## Graph Representation

Graph representation can be done in two ways:

* Adjacency Matrix: A two-dimensional array of size V x V where V is the number of vertices in a graph. Let the 2D array be `adj[][]`, a slot `adj[i][j] = 1` indicates that there is *an edge* from vertex `i` to vertex `j`. Adjacency matrix for undirected graph is always symmetric. Adjacency Matrix is also used to represent weighted graphs. If `adj[i][j] = w`, then there is an edge from vertex `i` to vertex `j` with weight `w`.

The following graph can be represented using an adjacency matrix.

```
   1----->2----->3
   ^      |      |
   |      |      |
   |      v      v
   4<-----5<-----6
```

```
Adjacency Matrix:

    1 2 3 4 5 6
 1  0 1 0 0 0 0
 2  0 0 1 0 1 0
 3  0 0 0 0 0 1
 4  1 0 0 0 0 0
 5  0 0 0 1 0 0
 6  0 0 0 0 1 0
```


* Adjacency List: An array of lists is used. The size of the array is equal to the number of vertices. Let the array be `array[]`. An entry `array[i]` represents the list of vertices adjacent to the `ith` vertex. This representation can also be used to represent a weighted graph. The weights of edges can be represented as lists of pairs. Following is the adjacency list representation of the above graph.

The following graph can be represented using an adjacency matrix.

```
   1----->2----->3
   ^      |      |
   |      |      |
   |      v      v
   4<-----5<-----6
```

```
Adjacency List:

  1: [2]
  2: [3, 5]
  3: [6]
  4: [1]
  5: [4]
  6: [5]
```

## References

* [Graph](https://en.wikipedia.org/wiki/Graph_(abstract_data_type)), wikipedia
* ▶️ [Graph Algorithms for Technical Interviews - Full Course](https://www.youtube.com/watch?v=tWVWeAqZ0WU&ab_channel=freeCodeCamp.org), freeCodeCamp.org
