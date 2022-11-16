# Graph

A graph consists `nodes` and `edges`.
```java
import java.util.ArrayList; 

class Edge {
    private String source;
    private String target;
    
    public Edge(String source, String target){
        this.source = source;
        this.target = target;
    }
}

class Vertex {
    private String data;
    private ArrayList<Edge> edges;
    
    public Vertex(String inputData){
        this.data = inputData;
        this.edges = new ArrayList<Edge>();
    }
}

class HelloWorld {
    public static void main(String[] args) {
        System.out.println("Hello, World!");
    }
}
```