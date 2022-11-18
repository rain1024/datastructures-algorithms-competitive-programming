class Graph {
  vertices: Vertex[];

  constructor() {
      this.vertices = [];
  };

  addVertex(data: string): Vertex {
      const vertex = new Vertex(data);
      this.vertices.push(vertex);
      return vertex;
  }

  addEdge(v1: Vertex, v2: Vertex): void {
      v1.addEdge(v2);
  }

  toString() {
      let s = '';
      this.vertices.forEach(v => {
          s += v.toString() + ' -> ';
          if (v.edges.length == 0){
              s += 'null\n';
          } else {
              v.edges.forEach((e) => {
                s += e.target.toString() + ' ';
              });
              s += '\n';
          }
      })
      return s;
  }
}

class Vertex {
  data: string;
  edges: Edge[];

  constructor(data: string){
      this.data = data;
      this.edges = [];
  }

  addEdge(target: Vertex) {
      this.edges.push(new Edge(this, target));
  }

  toString(): string {
      return this.data;
  }
}

class Edge {
  constructor(public source: Vertex, public target: Vertex) {
  }
}

const g = new Graph();
const v1: Vertex = g.addVertex("1");
const v2: Vertex = g.addVertex("2");
const v3: Vertex = g.addVertex("3");
g.addEdge(v1, v2);
g.addEdge(v1, v3);
g.addEdge(v2, v3);
console.log(g.toString());