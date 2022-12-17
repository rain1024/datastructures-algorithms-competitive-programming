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

# Bitwise NOT operation (signed interger)
print("~a =", ~a)  # -5 = int(0b1011) 

# Bitwise AND operation
print("a & b =", a & b)  # 4 = int(0b0100)

# Bitwise OR operation
print("a | b =", a | b)  # 14 = int(0b1110)

# Bitwise XOR operation
print("a ^ b =", a ^ b)  # 10 = int(0b1010)

# Left Shifting
print("a << 3 =", a << 3) # 32 = int(0b100000)

# Right Shifting
print("a >> 2 =", a >> 2) # 1 = int(0b1)
```

## 🔗 Further Reading

* [Bitwise operation](https://en.wikipedia.org/wiki/Bitwise_operation), wikipedia.org
* [Two complement](https://en.wikipedia.org/wiki/Two%27s_complement),
wikipedia.org
* ▶️ [Python Bitwise Operators](hhttps://realpython.com/python-bitwise-operators/),
realpython.com
* ▶️ [Bitwise Operations tutorial #1 | XOR, Shift, Subsets](https://www.youtube.com/watch?v=xXKL9YBWgCY&list=PLl0KD3g-oDOHpWRyyGBUJ9jmul0lUOD80&index=2&t=320s&ab_channel=Errichto), Errichto, 2020