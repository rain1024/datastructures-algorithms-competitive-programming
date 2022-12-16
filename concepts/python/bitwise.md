# Bitwise

From wikipedia

> In computer programming, a bitwise operation operates on a bit string, a bit array or a binary numeral (considered as
> a bit string) at the level of its individual bits. It is a fast and simple action, basic to the higher-level arithmetic
> operations and directly supported by the processor. Most bitwise operations are presented as two-operand instructions
> where the result replaces one of the input operands.

## 🎨 Design

**Bitwise Basic Operations**

|     | Definition                            |
|-----|---------------------------------------|
| NOT | NOT(1) = 0, NOT(0) = 1                |
| AND | 1 AND 1 = 1, 1 AND 0 = 0, 0 AND 0 = 0 |
| OR  | 1 OR 1 = 1, 1 OR 0 = 1, 0 OR 0 = 0    |
| XOR | 1 XOR 1 = 0, 1 XOR 0 = 1, O XOR 0 = 0 |

**Bitwise Shifts**

|             | Definition               | Calculation          |
|-------------|--------------------------|----------------------|
| LEFT SHIFT  | LEFT_SHIFT(1101) = 11010 | (x<<k) = $x(2^k)$    |
| RIGHT SHIFT | RIGHT_SHIFT(1101) = 110  | (x>>k) = $⌊x/(2^k)⌋$ | 

## 📈 Complexity Analysis

| Operation               | Complexity |
|-------------------------|------------|
| NOT, AND, OR, XOR       | $O(1)$     |
| LEFT SHIFT, RIGHT SHIFT | $O(1)$     |

## 💻 Implementation in Python

ℹ️ Python bitwise operators work only on integers.

```python
a = 4   # 0b0100
b = 14  # 0b1110

# Bitwise NOT operation
print("~a =", ~a)  # -5 = int(0b

# Bitwise AND operation
print("a & b =", a & b)

# Bitwise OR operation
print("a | b =", a | b)

# Bitwise XOR operation
print("a ^ b =", a ^ b)

    cout << "LS(x,1) = " << (x << 1) << endl;
    cout << "LS(x,2) = " << (x << 2) << endl;
    cout << "RS(x,1) = " << (x >> 1) << endl;
    cout << "RS(x,2) = " << (x >> 2) << endl;
    cout << " int(x) = " << int(x.to_ulong()) << endl;
}
```

**Results**

```
 NOT(x) = 1011
x AND y = 0100
x OR  y = 1110
x XOR y = 1010
LS(x,1) = 1000
LS(x,2) = 0000
RS(x,1) = 0010
RS(x,2) = 0001
 int(x) = 4
```



## 🔗 Further Reading

*
▶️ [Bitwise Operations tutorial #1 | XOR, Shift, Subsets](https://www.youtube.com/watch?v=xXKL9YBWgCY&list=PLl0KD3g-oDOHpWRyyGBUJ9jmul0lUOD80&index=2&t=320s&ab_channel=Errichto),
Errichto, 2020
*
▶️ [C++ Bitsets in Competitive Programming](https://www.youtube.com/watch?v=jqJ5s077OKo&list=PLl0KD3g-oDOHpWRyyGBUJ9jmul0lUOD80&index=2&ab_channel=Errichto),
Errichto, 2020
* [Bitwise operation](https://en.wikipedia.org/wiki/Bitwise_operation), wikipedia.org
