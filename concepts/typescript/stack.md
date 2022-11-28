# Stack

From wikipedia

> In computer science, a stack is an abstract data type that serves as a collection of elements, with two main operations: `Push`, which adds an element to the collection, and `Pop`, which removes the most recently added element that was not yet removed.

## 💻 Implementation in Typescript

```ts
interface IStack<T> {
  push(item: T): void;
  pop(): T | undefined;
  peek(): T | undefined;
  size(): number;
}

class Stack<T> implements IStack<T> {
  private storage: T[] = [];

  constructor(private capacity: number = Infinity) {}

  push(item: T): void {
    if (this.size() === this.capacity) {
      throw Error("Stack has reached max capacity, you cannot add more items");
    }
    this.storage.push(item);
  }

  pop(): T | undefined {
    return this.storage.pop();
  }

  peek(): T | undefined {
    return this.storage[this.size() - 1];
  }

  size(): number {
    return this.storage.length;
  }
}

const stack = new Stack<string>();
stack.push("A");
stack.push("B");

stack.size(); // Output: 2
stack.peek(); // Output: "B"
stack.size(); // Output: 2
stack.pop();  // Output: "B"
stack.size(); // Output: 1
```

## 🔗 Further Reading

* ▶️ [Stack Introduction](https://youtu.be/L3ud3rXpIxA?list=PLDV1Zeh2NRsB6SWUrDFW2RmDotAfPbeHu), Data structures playlist, WilliamFiset, 2017
* ▶️ [Stack Implementation](https://www.youtube.com/watch?v=RAMqDLI6_1c&list=PLDV1Zeh2NRsB6SWUrDFW2RmDotAfPbeHu&index=9&ab_channel=WilliamFiset), Data structures playlist, WilliamFiset, 2017
* ▶️ [Stack Code](https://www.youtube.com/watch?v=oiZssCfk4_U&list=PLDV1Zeh2NRsB6SWUrDFW2RmDotAfPbeHu&index=10&ab_channel=WilliamFiset), Data structures playlist, WilliamFiset, 2017
* [Typescript Data Structures: Stack and Queue](https://dev.to/glebirovich/typescript-data-structures-stack-and-queue-hld), dev.to, 2021