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
| size        | the number of (unique) elements in Set |

**Methods**

|                 | Definition                                                         |
|-----------------|--------------------------------------------------------------------|
| add             | Appends a new element with a specified value to the end of the Set.|
| has             | a boolean indicating whether an element with the specified value exists in the Set or not. |
| delete          |  Returns true if an element in the Set existed and has been removed, or false if the element does not exist. |

### Class Edge

### Class Vertex


## 💻 Set Implementation in Typescript

Typescript has standard built-in object [`Set`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Set)

```ts
let s = new Set();  
s.add('2');
s.add('3')
s.add('5')
console.log(s);            // Set (3) {"2", "3", "5"} 
console.log(s.has('1'));   // false
console.log(s.has('2'));   // true
s.delete('5')    
console.log(s);            // Set (2) {"2", "3"} 
s.add('4');
console.log(s)             // Set (3) {"2", "3", "4"} 
```

## 📈 Complexity Analysis of Set


| Operation       | Set                 |
|-----------------|---------------------|
| Insert          | $O(1)$              |
| Delete          | $O(1)$              |
| Check exist     | $O(1)$              |

## 🔗 References

* 2022, [Standard built-in objects > Set](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Set), developer.mozilla.org