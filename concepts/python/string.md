# String

From wikipedia

> In computer programming, a string is traditionally a sequence of characters, either as a literal constant or as some kind of variable. The latter may allow its elements to be mutated and the length changed, or it may be fixed (after creation).

## 💻 String Implementation in Python

```python
# Creating a string
str_1 = "This is a sample string"
print(str_1)                   # This is a sample string
str_1 = "This is " + "a sample string"
print(str_1)                   # This is a sample string

# Lenght of string
print(len(str_1))              # 23

# Accessing charactors of string
print(str_1[0])                # T
print(str_1[-1])               # g

# Reversing a string
print(str_1[::-1])             # gnirts elpmas a si sihT

# Slicing a string
print(str_1[10:-6])            # sample

# String formatting

# Default order
str_1 = "{} {} {}".format('Zero', 'One', 'Two')
print(str_1)                   # Zero One Two
# Positional Formatting
str_2 = "{1} {0} {2}".format('Zero', 'One', 'Two')
print(str_2)                   # One Zero Two
# Keyword Formatting
str_3 = "{l} {f} {g}".format(g='Zero', f='One', l='Two')
print(str_3)                   # Two One Zero

# Formatting of Integers
str_4 = "{0:b}".format(16)     
print(str_4)                   # 10000
 # Formatting of Floats
str_5 = "{0:e}".format(165.6458)
print(str_5)                   # 1.656458e+02
# Rounding off Integers
str_6 = "{0:.2f}".format(1/6)
print(str_6)                   # 0.17

# Formatted string literals
value = 2.791514
print(f'{value:.2f}')          # 2.79
car = {'tires':4, 'doors':2}
print(f'car = {car}')          # car = {'tires': 4, 'doors': 2}

# String %
text = "%d little pigs come out, or I'll %s, and I'll %s, and I'll blow your %s down." % (3, 'huff', 'puff', 'house')
print(text)                    # 3 little pigs come out, or I'll huff, and I'll puff, and I'll blow your house down.

# String Methods

s = " Hanoi is the capital of Vietnam "
print(s.lower())               #  hanoi is the capital of vietnam
print(s.upper())               #  HANOI IS THE CAPITAL OF VIETNAM
print(s.strip())               # Hanoi is the capital of Vietnam
print(s.isalpha())             # False
print(s.isdigit())             # False
print(s.isspace())             # False
print(s.startswith(' Hanoi'))  # True
print(s.endswith('other'))     # False
print(s.find('Viet'))          # 25
print(s.replace('the capital', 'a city'))  #  Hanoi is a city of Vietnam
list_1 = s.split(' ')          
print(list_1)                  # ['', 'Hanoi', 'is', 'the', 'capital', 'of', 'Vietnam', ''] 
print(' '.join(list_1))        #  Hanoi is the capital of Vietnam
```


## 🔗 Further Reading

* [Python String](https://docs.python.org/3/library/string.html), docs.python.org
* [Python Strings](https://developers.google.com/edu/python/strings), developers.google.com
* [Python String](https://www.geeksforgeeks.org/python-string/), geeksforgeeks.org 2023
* ▶️ [How to Use Strings in Python](https://www.youtube.com/watch?v=Ctqi5Y4X-jA), 
Programming with Mosh
