class Graph:
    def __init__(self, directed=False):
        self.nodes = set()
        self.edges = {}
        self.directed = directed

    def add_edge(self, u, v):
        self.nodes.add(u)
        self.nodes.add(v)
        if u in self.edges:
            self.edges[u].append(v)
        else:
            self.edges[u] = [v]
        if not self.directed:
            if v in self.edges:
                self.edges[v].append(u)
            else:
                self.edges[v] = [u]
                self.edges[v] = [u]


def main():
    # Create a list of edges for a tree with 7 nodes
    edges = {1: [2, 3], 2: [3, 4, 5], 3: [6, 7]}

    # Create a list of edges for a tree with 7 nodes
    edges = {1: [2, 3], 2: [3, 4, 5], 3: [6, 7]}

    graph = Graph(7, edges)


if __name__ == "__main__":
    main()
