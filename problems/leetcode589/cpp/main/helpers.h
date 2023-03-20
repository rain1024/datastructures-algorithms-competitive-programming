#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

/* Temmplate class T should be a Nary Tree Node
 * See leetcode 589 (https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/)
 * class Node {
 *  public:
 *   int val;
 *   vector<Node*> children;
 * 
 *   Node() {}
 * 
 *   Node(int _val) { val = _val; }
 * 
 *   Node(int _val, vector<Node*> _children) {
 *     val = _val;
 *     children = _children;
 *   }
 * };
*/
template <typename T> T* parse_nary_tree(vector<string> s) {
  T* fake = new T();
  T* current = fake;
  queue<T*> q;
  for(string e: s){
    if(e == "null"){
      current = q.front();
      q.pop();
    } else {
      T* child = new T(stoi(e));
      q.push(child);
      current->children.push_back(child);
    }
  }
  return fake->children[0];
}

vector<string> parse_line(string line) {
  vector<string> v;
  string s;
  for (char c : line) {
    if (c == ' ') {
      v.push_back(s);
      s = "";
    } else {
      s += c;
    }
  }
  v.push_back(s);
  return v;
}

