# Skip list

From wikipedia

> A skip list (or skiplist) is a probabilistic data structure that allows $O(log\ n)$
average complexity for search as well as $O(log\ n)$ average complexity for insertion 
within an ordered sequence of n elements.

## Time complexity of Skip list

|            | Time complexity         |
|------------|-------------------------|
| Insertion  | $O(log\ n)$              |
| Deletion   | $O(log\ n)$              |
| Search     | $O(log\ n)$              |
| Access     | $O(n)$                  |

## 💻 Implementation

ℹ️ Here is the implementation of the Skip list in C++

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

## 🔗 Further Reading

* ▶️ [Skip Lists](https://www.youtube.com/watch?v=NDGpsfwAaqo&ab_channel=AlgorithmsLab), Algorithms Lab
* [Skip list](https://en.wikipedia.org/wiki/Skip_list), wikipedia
* ▶️ [8 Key Data Structures That Power Modern Databases](https://www.youtube.com/watch?v=W_v05d_2RTo&ab_channel=ByteByteGo)


