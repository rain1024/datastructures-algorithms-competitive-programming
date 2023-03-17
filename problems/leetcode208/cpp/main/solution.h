#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Trie {
 private:
  struct TrieNode {
    bool isEnd;
    unordered_map<char, TrieNode*> children;
    TrieNode() { isEnd = false; }

    ~TrieNode() {
      for (auto it : children) {
        delete it.second;
      }
    }
  };
  TrieNode* root;

 public:
  Trie() { root = new TrieNode(); }

  void insert(string word) {
    TrieNode* curr = root;
    for (char c : word) {
      if (curr->children.count(c) == 0) {
        curr->children[c] = new TrieNode();
      }
      curr = curr->children[c];
    }
    curr->isEnd = true;
  }

  bool search(string word) {
    TrieNode* curr = root;
    for (char c : word) {
      if (curr->children.count(c) == 0) {
        return false;
      }
      curr = curr->children[c];
    }
    return curr->isEnd;
  }

  bool startsWith(string prefix) {
    TrieNode* curr = root;
    for (char c : prefix) {
      if (curr->children.count(c) == 0) {
        return false;
      }
      curr = curr->children[c];
    }
    return true;
  }

  ~Trie() { delete root; }
};