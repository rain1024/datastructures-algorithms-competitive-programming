# Range Queries

From wikipedia

> In computer science, the prefix sum, cumulative sum, inclusive scan, or simply scan of a sequence of numbers $x_0, x_1, x_2, ...$ is a second sequence of numbers $y_0, y_1, y_2, ...$, the sums of prefixes (running totals) of the input sequence: $y_0 = x_0, y_1 = x_0 + x_1, y_2 = x_0 + x_1+ x_2, ...$

## 🎨 Design

**Methods**

|                     | Definition                         |
|---------------------|------------------------------------|
| Query(left, right)  | Sum of range from left to right    |


## 💻 Implementation

ℹ️ Here is the implementation of the prefix sum in C++

```cpp
#include <iostream>
#include <vector>

using namespace std; 

using ll = long long;
using vl = vector<ll>;

vl prefix_sum(const vl a){
    int n = (int)(size(a));
    vl output(n + 1);
    for(int i=0; i<n; i++){
        output[i+1] = output[i] + a[i];
    }
    return output;
}

int main(){
    int N, Q;
    cin >> N >> Q;
    
    vector<long long> a(N);
    for(long long & x: a){
        cin >> x;
    }
    vl p = prefix_sum(a);
    while(Q--){
        int l, r;
        cin >> l >> r;
        cout << p[r] - p[l] << "\n";
    }
}
```

Input 

<table>
<thead>
<th>Input</th>
<th>Output</th>
</thead>
<tbody>
<tr>
<td>
<code>
5 3
2 4 7 8 10
0 1
1 3
2 4
</code>
</td>
</tr>
</tbody>
</table>

Output

```
2
11
15
```

## 📈 Complexity Analysis of Tree


| Operation       | Complexity          |
|-----------------|---------------------|
| Queries         | $O(N+Q)$            |

## 🔗 Further Reading

* ▶️ [Prefix Sum Array Explained](https://www.youtube.com/watch?v=7pJo_rM0z_s&ab_channel=MiketheCoder), MiketheCoder
* [Prefix sum](https://en.wikipedia.org/wiki/Prefix_sum), wikipedia
* [Introduction to Prefix Sums](https://usaco.guide/silver/prefix-sums?lang=cpp), Darren Yao, Dustin Miao, usaco.guide

