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

struct DoubleLinkedList {
  string value;
  DoubleLinkedList* prev;
  DoubleLinkedList* next;
  DoubleLinkedList() : value(""), prev(nullptr), next(nullptr) {}
  DoubleLinkedList(string s) : value(s), prev(nullptr), next(nullptr) {}
};

DoubleLinkedList* add_next(DoubleLinkedList* l, string s) {
  DoubleLinkedList* next_node = new DoubleLinkedList(s);
  l->next = next_node;
  next_node->prev = l;
  return next_node;
}

class BrowserHistory {
 public:
  BrowserHistory(string homepage) {
    current_page = new DoubleLinkedList(homepage);
  }

  void visit(string url) { current_page = add_next(current_page, url); }

  string back(int steps) {
    for (int i = 0; i < steps; i++) {
      if (current_page->prev != nullptr) {
        current_page = current_page->prev;
      } else {
        continue;
      }
    }
    return current_page->value;
  }

  string forward(int steps) {
    for (int i = 0; i < steps; i++) {
      if (current_page->next != nullptr) {
        current_page = current_page->next;
      } else {
        continue;
      }
    }
    return current_page->value;
  }

 private:
  DoubleLinkedList* current_page;
};
