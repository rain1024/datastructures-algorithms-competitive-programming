# Queue

From wikipedia

> In computer science, a queue is a collection of entities that are maintained in a sequence and can be modified by the addition of entities at one end of the sequence and the removal of entities from the other end of the sequence.

## 💻 Implementation in Typescript

```ts
interface IQueue<T> {
  enqueue(item: T): void;
  dequeue(): T | undefined;
  size(): number;
}

class Queue<T> implements IQueue<T> {
  private storage: T[] = [];

  constructor(private capacity: number = Infinity) {}

  enqueue(item: T): void {
    if (this.size() === this.capacity) {
      throw Error("Queue has reached max capacity, you cannot add more items");
    }
    this.storage.push(item);
  }
  dequeue(): T | undefined {
    return this.storage.shift();
  }
  size(): number {
    return this.storage.length;
  }
}

const queue = new Queue<string>();

queue.enqueue("A");
queue.enqueue("B");

queue.size();    // Output: 2
queue.dequeue(); // Output: "A"
queue.size();    // Output: 1
```

## 🔗 Further Reading

* ▶️ [Queue Introduction](https://www.youtube.com/watch?v=KxzhEQ-zpDc&list=PLDV1Zeh2NRsB6SWUrDFW2RmDotAfPbeHu&index=11&ab_channel=WilliamFiset), Data structures playlist, WilliamFiset, 2017
* ▶️ [Queue Implementation](https://www.youtube.com/watch?v=EoisnPvUkOA&list=PLDV1Zeh2NRsB6SWUrDFW2RmDotAfPbeHu&index=12&ab_channel=WilliamFiset), Data structures playlist, WilliamFiset, 2017
* ▶️ [Queue Code](https://www.youtube.com/watch?v=HV-hpvuGaC4&list=PLDV1Zeh2NRsB6SWUrDFW2RmDotAfPbeHu&index=13&ab_channel=WilliamFiset), Data structures playlist, WilliamFiset, 2017
* [Typescript Data Structures: Stack and Queue](https://dev.to/glebirovich/typescript-data-structures-stack-and-queue-hld), dev.to, 2021