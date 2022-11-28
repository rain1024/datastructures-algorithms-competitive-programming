# Bitwise

From wikipedia

> In computer programming, a bitwise operation operates on a bit string, a bit array or a binary numeral (considered as a bit string) at the level of its individual bits. It is a fast and simple action, basic to the higher-level arithmetic operations and directly supported by the processor. Most bitwise operations are presented as two-operand instructions where the result replaces one of the input operands.

## 🎨 Design

**Bitwise Operators**

|                | Definition                              |
|----------------|-----------------------------------------|
| NOT            | NOT(1) = 0, NOT(0) = 1                  |
| AND            | 1 AND 1 = 1, 1 AND 0 = 0                |
| OR             | 1 OR 0 = 1, 0 OR 0 = 0                  |
| XOR            | 1 XOR 0 = 0, 1 XOR 1 = 1, O XOR  0 = 0  |

**Bit Shifts**

|                 | Definition                 |
|-----------------|----------------------------|
| LEFT SHIFT      | LEFT_SHIFT(1101) = 110     |
| RIGHT SHIFT     | RIGHT_SHIFT(1101) = 11010  |


## 💻 Implementation in C++

ℹ️ C++ has standard built-in operators for bitwise operators and bit shifts

```cpp
#include <iostream>
#include <bitset>

using namespace std; 

int main(){
    bitset<4> x = 0b0100;
    bitset<4> y = 0b1110;
    cout << " NOT(x) = " << ~x << endl;
    cout << "x AND y = " << (x & y) << endl;              
    cout << "x OR  y = " << (x | y) << endl;
    cout << "x XOR y = " << (x ^ y) << endl;
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

## 📈 Complexity Analysis


| Operation                | Complexity          |
|--------------------------|---------------------|
| NOT, AND, OR, XOR        | $O(1)$              |
| LEFT_SHIFT, RIGHT_SHIFT  | $O(1)$              |

## 🔗 Further Reading

* ▶️ [Bitwise Operations tutorial #1 | XOR, Shift, Subsets](https://www.youtube.com/watch?v=xXKL9YBWgCY&list=PLl0KD3g-oDOHpWRyyGBUJ9jmul0lUOD80&index=2&t=320s&ab_channel=Errichto), Errichto, 2020
* ▶️ [C++ Bitsets in Competitive Programming](https://www.youtube.com/watch?v=jqJ5s077OKo&list=PLl0KD3g-oDOHpWRyyGBUJ9jmul0lUOD80&index=2&ab_channel=Errichto), Errichto, 2020
* [Bitwise operation](https://en.wikipedia.org/wiki/Bitwise_operation), wikipedia.org