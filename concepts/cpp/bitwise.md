# Bitwise

From wikipedia

> In computer programming, a bitwise operation operates on a bit string, a bit array or a binary numeral (considered as a bit string) at the level of its individual bits. It is a fast and simple action, basic to the higher-level arithmetic operations and directly supported by the processor. Most bitwise operations are presented as two-operand instructions where the result replaces one of the input operands.

From official document 

> OFFICIAL DOCUMENT

![](../abstract/data-structures/image.png)


## 🎨 Design

**Bitwise Operators**

|                | Definition                              |
|----------------|-----------------------------------------|
| NOT            | NOT(1) = 0, NOT(0) = 1                  |
| AND            | 1 AND 1 = 1, 1 AND 0 = 0                |
| OR             | 1 OR 0 = 1, 0 OR 0 = 0                  |
| XOR            | 1 XOR 0 = 0, 1 XOR 1 = 1, O XOR  0 = 0  |

**Bitwise Shift**

|                 | Definition                 |
|-----------------|----------------------------|
| LEFT SHIFT      | LEFT_SHIFT(1101) = 110     |
| RIGHT SHIFT     | RIGHT_SHIFT(1101) = 11010  |


## 💻 Implementation in [Awesome Language]

⚠️ Typescript hasn't has built-in object `Awesome Type`.

Here are the implementation of [awesome type] in `Awesome Language` from scratch.

ℹ️ Typescript has standard built-in object [`Awesome Type`](awesome-link)

File [**`example.cpp`**](code/example.cpp)

```[id]
```

## 📈 Complexity Analysis of Tree


| Operation       | Complexity          |
|-----------------|---------------------|
| Operation 1     | $O(log(n))$         |

## 🔗 Further Reading

* ▶️ [Bitwise Operations tutorial #1 | XOR, Shift, Subsets](https://www.youtube.com/watch?v=xXKL9YBWgCY&list=PLl0KD3g-oDOHpWRyyGBUJ9jmul0lUOD80&index=2&t=320s&ab_channel=Errichto), Errichto, 2020
* [Bitwise operation](https://en.wikipedia.org/wiki/Bitwise_operation), wikipedia.org