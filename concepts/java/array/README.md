# Array in Java

In computer science, an `array` is a data structure consisting of a collection of elements (values or variables), each identified by at least one array index or key. An array is stored such that the position of each element can be computed from its index tuple by a mathematical formula.

## Time Complexity Analysis of Array

| Operation       | Creation | Insertion        | Accessing | Update | Deletion         | Searching |
|-----------------|----------|------------------|-----------|--------|------------------|-----------|
| Time Complexity | $O(1)$   | $O(1)$ or $O(n)$ | $O(1)$    | $O(n)$ | $O(1)$ or $O(n)$ | $O(n)$    |

## Array implementation in Java

## Basic Operations

**Initialization**: Create an array with given values


```Java
int a[] = new int[5];

a[0] = 10;
a[1] = 20;
a[2] = 30;
a[3] = 40;
```




    40




```Java
int b[] = {1, 2, 3, 4, 5};
```

**Accessing Elements**: Access element by index (zero-based)


```Java
System.out.println("a[0] = " + a[0]);
System.out.println("a[4] = " + a[4]);
```

    a[0] = 10
    a[4] = 0


**Updating Elements**: Update an element by its index


```Java
a[0] = 100;
System.out.println("a[0] = " + a[0]);
```

    a[0] = 100


**Size**: Get the number of elements in the array

You can use the [`length`](https://docs.oracle.com/javase/specs/jls/se19/html/jls-10.html#jls-10.7) property of the array to get the number of elements in the array.


```Java
System.out.println("a.length = " + a.length);
```

    a.length = 5


**Traversal**: Visit all elements of the array


```Java
for(int i=0; i<a.length; i++) {
    System.out.println("a[" + i + "] = " + a[i]);
}
```

    a[0] = 100
    a[1] = 20
    a[2] = 30
    a[3] = 40
    a[4] = 0


**Input**: Read values into the array from a stream

```java
import java.util.Scanner;

public class Main {
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int a[] = new int[n];
        for(int i=0; i<n; i++){
            a[i] = s.nextInt();
        }
        
        for(int i=0; i<n; i++){
            System.out.print(a[i] + " ");
        }
    }
}
```

## 🔗 Further Reading

* [Array (data structure)](https://en.wikipedia.org/wiki/Array_(data_structure))
* ▶️ [Array In Data Structure](https://www.youtube.com/watch?v=eXFItikqw8c&ab_channel=Simplilearn), Simplilearn
* ▶️ [Dynamic and Static Arrays](https://www.youtube.com/watch?v=PEnFFiQe1pM&list=PLDV1Zeh2NRsB6SWUrDFW2RmDotAfPbeHu&index=4&ab_channel=WilliamFiset), WilliamFiset
* ▶️ [An Overview of Arrays and Memory (Data Structures & Algorithms #2)](https://www.youtube.com/watch?v=pmN9ExDf3yQ&ab_channel=CSDojo), CS Dojo

