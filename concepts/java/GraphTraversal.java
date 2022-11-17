import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.HashSet;

class Edge {

  private Vertex source;
  private Vertex target;

  public Edge(Vertex source, Vertex target) {
    this.source = source;
    this.target = target;
  }

  public Vertex getSource() {
    return this.source;
  }

  public Vertex getTarget() {
    return this.target;
  }
}

class Vertex {

  private String data;
  private ArrayList<Edge> edges;

  public Vertex(String inputData) {
    this.data = inputData;
    this.edges = new ArrayList<Edge>();
  }

  public String getData() {
    return this.data;
  }

  public ArrayList<Edge> getEdges() {
    return this.edges;
  }

  public void addEdge(Vertex target) {
    this.edges.add(new Edge(this, target));
  }

  public void removeEdge(Vertex target) {
    this.edges.removeIf(edge -> edge.getTarget().equals(target));
  }

  public String toString() {
    String s = "";
    s += this.getData();
    if (this.edges.size() == 0) {
      s += " -> null";
    } else {
      s += " -> ";
      for (Edge e : this.edges) {
        s += e.getTarget().getData() + " ";
      }
    }
    return s;
  }
}

class Graph {

  private ArrayList<Vertex> vertices;
  private boolean isWeighted;
  private boolean isDirected;

  public Graph(boolean isWeighted, boolean isDirected) {
    this.vertices = new ArrayList<Vertex>();
    this.isWeighted = isWeighted;
    this.isDirected = isDirected;
  }

  public Vertex addVertex(String data) {
    Vertex v = new Vertex(data);
    this.vertices.add(v);
    return v;
  }

  public void addEdge(Vertex v1, Vertex v2) {
    v1.addEdge(v2);
    if (!this.isDirected) {
      v2.addEdge(v1);
    }
  }

  public void removeEdge(Vertex v1, Vertex v2) {
    v1.removeEdge(v2);
    if (!this.isDirected) {
      v2.removeEdge(v1);
    }
  }

  public void removeVertex(Vertex v) {
    this.vertices.remove(v);
    for (Vertex v0 : this.vertices) {
      v0.removeEdge(v);
    }
  }

  public void dfs(Vertex v) {
    HashSet<Vertex> visited = new HashSet<Vertex>();
    Stack<Vertex> s = new Stack();
    s.push(v);

    while (!s.isEmpty()) {
        Vertex vertex = s.pop();
        System.out.println(vertex.getData());
        if (!visited.contains(vertex)){
            for(Edge e: vertex.getEdges()){
                Vertex target = e.getTarget();
                if(!visited.contains(target)){
                    s.push(target);
                }
            }
        }
    }
  }

  public void bfs(Vertex v){
    HashSet<Vertex> visited = new HashSet<Vertex>();
    Queue<Vertex> q = new LinkedList();
    q.add(v);

    while (!q.isEmpty()) {
        Vertex vertex = q.remove();
        System.out.println(vertex.getData());
        if (!visited.contains(vertex)){
            for(Edge e: vertex.getEdges()){
                Vertex target = e.getTarget();
                if(!visited.contains(target)){
                    q.add(target);
                }
            }
        }
    }
  }

  public String toString() {
    String s = "";
    for (Vertex v : this.vertices) {
      s += v.toString() + "\n";
    }
    return s;
  }
}

class GraphTraversal {

  public static void main(String[] args) {
    Graph g = new Graph(false, true);
    Vertex v1 = g.addVertex("1");
    Vertex v2 = g.addVertex("2");
    Vertex v3 = g.addVertex("3");
    Vertex v4 = g.addVertex("4");
    Vertex v5 = g.addVertex("5");
    Vertex v6 = g.addVertex("6");
    g.addEdge(v1, v3);
    g.addEdge(v1, v4);
    g.addEdge(v3, v2);
    g.addEdge(v2, v5);
    g.addEdge(v4, v6);
    System.out.println("Graph Representation");
    System.out.println(g.toString());
    System.out.println("DFS");
    g.dfs(v1);

    System.out.println("\nBFS");
    g.bfs(v1);
  }
}
