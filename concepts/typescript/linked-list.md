# Linked List

## Time Complexity Analysis of Linked List

INSERTION

| Operation       | Singly Linked List  | Double Linked List  |
|-----------------|---------------------|---------------------|
| Insert head     | $O(1)$              | $O(1)$              |
| Insert middle   | $O(n)$              | $O(n)$              |
| Insert tail     | $O(1)$              | $O(1)$              |

DELETION

| Operation       | Singly Linked List  | Double Linked List  |
|-----------------|---------------------|---------------------|
| Delete head     | $O(1)$              | $O(1)$              |
| Delete middle   | $O(n)$              | $O(n)$              |
| Delete tail     | $O(n)$              | $O(1)$              |

## Linked List Implementation in Typescript

⚠️ Typescript hasn't has built-in object `Linked List`.

Here are the implmentation of liked list in typescript from Scratch
```ts
class LinkedListNode<T> {
    val: T;
    next: LinkedListNode<T> | null;
    prev: LinkedListNode<T> | null;

    constructor(val: T){
        this.val = val;
        this.next = null;
        this.prev = null;
    }
}

class LinkedList<T> implements Iterable<LinkedListNode<T>> {
    public head: LinkedListNode<T> | undefined;
    public tail: LinkedListNode<T> | undefined;

    constructor(){}

    /***************************************
                    INSERTION
    ****************************************/
    addBack(node: LinkedListNode<T>) {
        if(this.head == undefined){
            this.head = node;
            this.tail = node;
            return;
        }
        if(this.tail == undefined){
            return;    
        } else {
            this.tail.next = node;
            this.tail = node;
        }
    }

    /***************************************
                    ITERATOR
    ****************************************/
    *[Symbol.iterator](): Iterator<LinkedListNode<T>> {
        if(this.head == null) return;

        let iter: LinkedListNode<T> | null;

        for (iter = this.head; iter != null; iter = iter.next) {
           yield iter;
        }
    }

    /***************************************
                    toString
    ****************************************/
    public toString = () : string => {
        let result: string = "";
        for(const item of this){
            result += `${item.val}`;
            if(item.next != null){
                result += ` -> `;
            }
        }
        return result;
    }
}

let linked_list = new LinkedList();
linked_list.addBack(new LinkedListNode(1));
linked_list.addBack(new LinkedListNode(2));
linked_list.addBack(new LinkedListNode(3));
console.log(linked_list.toString());
// outputs: 1 -> 2 -> 3

let linked_list_2 = new LinkedList();
linked_list_2.addBack(new LinkedListNode("a"));
linked_list_2.addBack(new LinkedListNode("b"));
linked_list_2.addBack(new LinkedListNode("c"));
console.log(linked_list_2.toString());
// outputs: a -> b -> c
```
## References


* 2022, [Data Structures in Typescript #5 - Linked List Intro](https://www.youtube.com/watch?v=oXXLFvtG6-Q&list=PLn4fTSbSpY5cL4_0MP83wq5khbmG3IKKd&index=5&ab_channel=JeffZhang), Jeff Zhang
* 2017, [LinkedList implementation in Typescript](https://stackoverflow.com/questions/42588925/linkedlist-implementation-in-typescript), stackoverflow.com

