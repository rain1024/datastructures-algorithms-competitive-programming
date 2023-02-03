# Skip list

From wikipedia

> A skip list (or skiplist) is a probabilistic data structure that allows  $$O(log n)$$ 
average complexity for search as well as $$O(log n)$$ average complexity for insertion 
within an ordered sequence of n elements.

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

<table>
<thead>
<th>Input</th>
<th>Output</th>
</thead>
<tbody>
<tr>
<td>
<pre>5 3
2 4 7 8 10
0 1
1 3
2 4</pre>
</td>
<td>
<pre>2
11
15</pre>
</td>
</tr>
</tbody>
</table>

## 📈 Complexity Analysis of Tree


| Operation       | Complexity          |
|-----------------|---------------------|
| Queries         | $O(N+Q)$            |

## Problems

* [Codeforces 1398C](https://codeforces.com/contest/1398/problem/C) `intermediate`

## 🔗 Further Reading

* ▶️ [Prefix Sum Array Explained](https://www.youtube.com/watch?v=7pJo_rM0z_s&ab_channel=MiketheCoder), MiketheCoder
* [Prefix sum](https://en.wikipedia.org/wiki/Prefix_sum), wikipedia
* [Introduction to Prefix Sums](https://usaco.guide/silver/prefix-sums?lang=cpp), Darren Yao, Dustin Miao, usaco.guide

