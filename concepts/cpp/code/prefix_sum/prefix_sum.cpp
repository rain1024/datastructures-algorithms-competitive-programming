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