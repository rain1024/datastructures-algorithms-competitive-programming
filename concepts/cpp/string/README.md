# String in C++

In competitive programming, programmers use strings or arrays to store and manipulate sequences of characters. This data structure is straightforward, fast, and easy to use. 

## String implementation in C++

## Basic Opeartions


```c++
#include <iostream>

using namespace std;
```

**Initialization**: Create a string with given value


```c++
string s = "hello world";
cout << s;
```

    hello world

**Accessing Characters**: Access a character by its index (zero-based)


```c++
string s = "programming is fun";
cout << "s[0] = " << s[0] << endl;
cout << "s[1] = " << s[5] << endl;
```

    s[0] = p
    s[1] = a


**Updating Characters**: Update a character by its index


```c++
string s = "The cat sat on the mat";
cout << "Before: " << s << endl;
s[4] = 'd';
s[5] = 'o';
s[6] = 'g';
s[19] = 'c';
s[21] = 'r';
cout << "After : " << s << endl;
```

    Before: The cat sat on the mat
    After : The dog sat on the car


**Traversal**: Visit all characters of the string


```c++
// count vowels in a string
string s = "the cat sat on the mat";
int vowels = 0;
for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
        vowels++;
    }
}
cout << "Vowels: " << vowels << endl;
```

    Vowels: 6


**Length**: Get the number of characters in the string


```c++
string s = "the cat sat on the mat";
cout << "Length: " << s.length() << endl;
```

    Length: 22


**Reversal**: Reverse the order of characters in the string


```c++
string s = "the cat sat on the mat";
cout << "Before: " << s << endl;
reverse(begin(s), end(s));
cout << "After : " << s << endl;
```

    Before: the cat sat on the mat
    After : tam eht no tas tac eht


**Uppercase**: Convert all characters in the string to uppercase


```c++
string s = "the cat sat on the mat";
cout << "Before: " << s << endl;
for (int i = 0; i < s.length(); i++) {
    s[i] = toupper(s[i]);
}
cout << "After : " << s << endl;
```

    Before: the cat sat on the mat
    After : THE CAT SAT ON THE MAT


**Lowercase**: Convert all characters in the string to lowercase


```c++
string s = "THE CAT SAT ON THE MAT";
cout << "Before: " << s << endl;
for (int i = 0; i < s.length(); i++) {
    s[i] = tolower(s[i]);
}
cout << "After : " << s << endl;
```

    Before: THE CAT SAT ON THE MAT
    After : the cat sat on the mat


## 🔗 Further Reading

* [String (computer science)](https://en.wikipedia.org/wiki/String_(computer_science)), wikipedia
* ▶️ [Strings](https://youtu.be/tI_tIZFyKBw?t=5369), CS50
* ▶️ [How Strings Work in C++ (and how to use them)](https://www.youtube.com/watch?v=ijIxcB9qjaU&ab_channel=TheCherno), The Cherno
