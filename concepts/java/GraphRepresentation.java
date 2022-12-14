import java.util.ArrayList; 

class Edge {
    private Vertex source;
    private Vertex target;
    
    public Edge(Vertex source, Vertex target){
        this.source = source;
        this.target = target;
    }
    
    public Vertex getSource(){
        return this.source;
    }
    
    public Vertex getTarget(){
        return this.target;
    }
}

class Vertex {
    private String data;
    private ArrayList<Edge> edges;
    
    public Vertex(String inputData){
        this.data = inputData;
        this.edges = new ArrayList<Edge>();
    }
    
    public String getData(){
        return this.data;
    }
    
    public ArrayList<Edge> getEdges(){
        return this.edges;
    }
    
    public void addEdge(Vertex target){
        this.edges.add(new Edge(this, target));
    }
    
    public void removeEdge(Vertex target){
        this.edges.removeIf(edge -> edge.getTarget().equals(target));
    }
    
    public String toString(){
        String s = "";
        s += this.getData();
        if (this.edges.size() == 0){
            s += " -> null";
        } else {
            s += " -> ";
            for(Edge e: this.edges){
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
    
    public Graph(boolean isWeighted, boolean isDirected){
        this.vertices = new ArrayList<Vertex>();
        this.isWeighted = isWeighted;
        this.isDirected = isDirected;
    }
    
    public Vertex addVertex(String data){
        Vertex v = new Vertex(data);
        this.vertices.add(v);
        return v;
    }
    
    public void addEdge(Vertex v1, Vertex v2){
        v1.addEdge(v2);
        if (!this.isDirected){
            v2.addEdge(v1);
        }
    }
    
    public void removeEdge(Vertex v1, Vertex v2){
        v1.removeEdge(v2);
        if (!this.isDirected){
            v2.removeEdge(v1);
        }
    }
    
    public void removeVertex(Vertex v){
        this.vertices.remove(v);
        for(Vertex v0: this.vertices){
            v0.removeEdge(v);
        }
    }
    
    public String toString(){
        String s = "";
        for(Vertex v: this.vertices){
            s +=  v.toString() + "\n";
        }
        return s;
    }

}

class Main {
    public static void main(String[] args) {
        System.out.println("Graph Representation");
        
        Graph g = new Graph(false, true);
        Vertex v1 = g.addVertex("1");
        Vertex v2 = g.addVertex("2");
        Vertex v3 = g.addVertex("3");
        g.addEdge(v1, v2);
        g.addEdge(v1, v3);
        g.addEdge(v2, v3);
        System.out.println(g);
        
        // Remove Edge
        g.removeEdge(v2, v3);
        System.out.println("Remove edge");
        System.out.println(g);
        
        // Remove Vertex
        g.removeVertex(v3);
        System.out.println("Remove vertex");
        System.out.println(g);
    }
}