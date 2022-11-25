# Bruteforce

**Problem**: Binary string

```cpp
#include <iostream>
#include <vector>
using namespace std;

#define endl "\n"
const int N = 10;
int a[100];

void show(){
	for(int i =1; i<=N; i++){
		cout << a[i];
	}
	cout << endl;
}

void backtrack(int i){
	if(i == N){
		show();
		return;
	}
	a[i+1] = 0;
	backtrack(i+1);
	a[i+1] = 1;
	backtrack(i+1);
}
	
int main(int argc, char *argv[])
{
	backtrack(0);
}
```

### Problems: Permutations

```cpp 
#include <iostream>
#include <vector>
using namespace std;

#define endl "\n"

const int N = 9;
int a[100];
bool check[100] = {false};

void show(){
	for(int i =1; i<=N; i++){
		cout << a[i];
	}
	cout << endl;
}

void backtrack(int i){
	if(i == N){
		show();
		return;
	}
	for(int k=1; k<=N; k++){
		a[i+1] = k;
		if(!check[k]){
			check[k] = true;
			backtrack(i +1);
			check[k] = false;
		}
	}
}
	
int main(int argc, char *argv[])
{
	backtrack(0);
}
```

### Problems: N Queens

```cpp
#include <iostream>
#include <vector>
using namespace std;

#define endl "\n"

const int N = 13;
int a[100];
bool check[100] = {false};
bool diag1[200] = {false};
bool diag2[200] = { false};

void show(){
	for(int i =1; i<=N; i++){
		for(int j = 1; j <=N; j++) {
			string s = a[i] == j ? "Q" : " ";
			cout << s;
		}
		cout << endl;
	}
	cout << "=========";
	cout << endl;
}

void backtrack(int i){
	if(i == N){
		show();
		return;
	}
	for(int k=1; k<=N; k++){
		a[i+1] = k;
		if(!(check[k] || diag1[i - k + N] || diag2[i+k])){
			check[k] = true;
			diag1[i-k+N] = true;
			diag2[i+k] = true;
			backtrack(i +1);
			check[k] = false;
			diag1[i-k+N] = false;
			diag2[i+k] = false;
		}
	}
}
	
int main(int argc, char *argv[])
{
	backtrack(0);
}
```