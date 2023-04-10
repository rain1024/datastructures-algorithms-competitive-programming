# Topological Sorting

*See implementation in*
[C++](/concepts/cpp/topological-sorting/README.md),
Java,
Python,
typescript

Topological sorting is a linear ordering of vertices in a directed acyclic graph (DAG) such that for every directed edge uv, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

## Applications

1. **Scheduling jobs from the given dependencies among jobs**. In computer science, applications of this type arise in instruction scheduling, ordering of formula cell evaluation when recomputing formula values in spreadsheets, logic synthesis, determining the order of compilation tasks to perform in makefiles, data serialization, and resolving symbol dependencies in linkers.

2. **Determining the order of compilation tasks to perform in makefiles**. Makefiles use topological sorting to determine which tasks can be executed in parallel.

3. **Instruction Scheduling**. In computer architecture, instruction scheduling is the process of assigning instructions to specific times in the instruction stream. The goal is to reduce the average time that an instruction must wait before it can begin execution. Instruction scheduling is a form of data flow analysis.

4. **Determining the order of formula cell evaluation when recomputing formula values in spreadsheets**. In spreadsheets, a topological sort of the dependency graph of cells can be used to determine the order in which to recompute the values of cells that have formulas, when the values of some of the input cells have changed.

5. **Logic synthesis**. In logic synthesis, a topological sort of the logic network can be used to determine the order in which to perform logic transformations, such as the removal of redundant logic gates.

6. **Data Serialization**. In systems programming, a topological sort of the dependency graph of data structures can be used to determine the order in which to serialize the data structures to a file, or to allocate memory for the data structures in a data structure interpreter.

7. **Resolving symbol dependencies in linkers**. In systems programming, a topological sort of the symbol dependency graph can be used to determine the order in which to emit the object code for a program, or to allocate memory for the program in a virtual machine.

## Algorithm

Topological Soring using DFS

1. Create a recursive function that takes the index of node and a visited array.
2. Mark the current node as visited.
3. Recur for all the vertices adjacent to this vertex.
4. Store the vertex to result array once all of its adjacent vertices (and their adjacent vertices and so on) are visited.
5. Print contents of result array.

## References

* [Topological Sort Algorithm | Graph Theory, WilliamFiset](https://www.youtube.com/watch?v=eL-KzMXSXXI&t=308s&ab_channel=WilliamFiset)
* [Topological Sort | GeeksforGeeks](https://www.geeksforgeeks.org/topological-sorting/)
* https://cp-algorithms.com/graph/topological-sort.html