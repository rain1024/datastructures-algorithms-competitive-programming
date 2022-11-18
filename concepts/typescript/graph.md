# Graph

From wikipedia

> In graph theory, a graph is a structure amounting to a set of objects in which some pairs of the objects are in some sense "related". The objects correspond to mathematical abstractions called vertices (also called nodes or points) and each of the related pairs of vertices is called an edge (also called link or line).

![](../abstract/data-structures/graph.png)


## 🎨 Graph Design

![](images/graph.png)

### Class Graph

**Properties**

|             | Definition                             |
|-------------|----------------------------------------|
| vertices    | all the vertices of graph              |

**Methods**

|                 | Definition                                      |
|-----------------|-------------------------------------------------|
| addVertex       | Add the new vertex to the graph                 |
| removeVertex    | Remove vertex from the graph                    |
| addEdge         | Add the new edge to the graph                   |

### Class Vertex

**Properties**

|             | Definition                             |
|-------------|----------------------------------------|
| data        | Construct a new Vertex from data       |

**Methods**

|                 | Definition                              |
|-----------------|-----------------------------------------|
| addEdge         | Add the new edge from the vertex        |

### Class Edge

**Methods**

|                 | Definition                                      |
|-----------------|-------------------------------------------------|
| constructor     | Construct an edge from two vertices             |

## 💻 Graph Implementation in Typescript

⚠️ Typescript hasn't has built-in object `Graph`.

Here are the implmentation of Graph in typescript from scratch.

```ts
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
Insert
const g = new Graph();
const v1: Vertex = g.addVertex("1");
const v2: Vertex = g.addVertex("2");
const v3: Vertex = g.addVertex("3");
g.addEdge(v1, v2);
g.addEdge(v1, v3);
g.addEdge(v2, v3);
console.log(g.toString());
```

Output

```
1 -> 2 3 
2 -> 3 
3 -> null
```

## 📈 Complexity Analysis of Set


| Operation       | Set                 |
|-----------------|---------------------|
| Add vertex      | $O(1)$              |
| Add edge        | $O(1)$              |

## 🔗 References

* [Graph](https://en.wikipedia.org/wiki/Graph_(discrete_mathematics)), wikipedia.com