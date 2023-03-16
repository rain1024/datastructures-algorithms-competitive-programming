# Two Pointers in C++

The "Two Pointers" technique is a commonly used approach for solving algorithmic problems. This technique involves using two pointers that move through an array or string in a synchronized manner to solve the problem at hand.

## Problem 1: Remove duplicates from a sorted array

Given a sorted array `nums`, remove the duplicates in-place such that each element appears only once and returns the new length.


```c++
#include <vector>
#include <string>

using namespace std;

typedef vector<int> vi;
```


```c++
vector<int> nums = {1, 1, 2, 3, 7, 7, 9};
```


```c++
vi removeDuplicates(vector<int> nums){
  int slow = 0;
  for(int fast=1; fast<nums.size(); fast++){
    if(nums[fast] != nums[fast-1]){
      slow++;
      nums[slow] = nums[fast];
    }
  }
  return vector<int>(nums.begin(), nums.begin()+slow+1);
}
```


```c++
removeDuplicates(nums)
```




    { 1, 2, 3, 7, 9 }



## Problem 2: Reversing a string

Given a string `s`, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.


```c++
string s = "Let's take LeetCode contest";
```


```c++
string reverse(string s){
  int i = 0;
  int j = s.size()-1;
  while(i<j){
    swap(s[i], s[j]);
    i++;
    j--;
  }
  return s;
}
```


```c++
reverse(s)
```




    "tsetnoc edoCteeL ekat s'teL"



*Note*: In this code, we use [`swap`](https://cplusplus.com/reference/algorithm/swap/) function in `algorithm` header

## 🔗 Further Reading 

* [Two Pointers Technique](https://www.geeksforgeeks.org/two-pointers-technique/), geeksforgeeks
* [Two Pointers Technique](https://leetcode.com/articles/two-pointer-technique/), leetcode
* ▶️ [How to Use the Two Pointer Technique](https://www.youtube.com/watch?v=-gjxg6Pln50&ab_channel=TeamAlgoDaily), 
Team AlgoDaily
* ▶️ [LeetCode Day 8 - Middle of a Linked List (Two Pointers)](https://www.youtube.com/watch?v=wq4OZZ3YLj4&ab_channel=Errichto), Errichto
