#include <algorithm>
#include <climits>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "helpers.h"

using namespace std;

struct Node {
  string name;
  map<string, Node*> children;
  Node* parent;
  long long size;
  bool isFolder;

  Node(string name) {
    this->name = name;
    this->size = 0;
    this->isFolder = false;
  }
};

void calculateSize(Node* node, long long& sum, long long MIN_DELETE, long long& minSize) {
  if (!node->isFolder) return;
  long long size = 0;
  for (auto p : node->children) {
    Node* child = p.second;
    if (!child->isFolder) {
      size += child->size;
    } else {
      calculateSize(child, sum, MIN_DELETE, minSize);
      size += child->size;
    }
  }
  if (size < 100000) {
    sum += size;
  }
  if (size >= MIN_DELETE) {
    minSize = min(minSize, size);
  }
  node->size = size;
  return;
}

int main(int argc, char* argv[]) {
  string input = argv[1];
  string line;
  fstream f(input);
  Node* root = new Node("/");
  root->isFolder = true;
  Node* current;
  bool listing = false;
  while (getline(f, line)) {
    if (line == "$ ls") {
      listing = true;
    } else if (line.substr(0, 5) == "$ cd ") {
      string name = line.substr(5, line.size() - 1);
      if (name == "/") {
        current = root;
      } else if (name == "..") {
        current = current->parent;
      } else {
        current = current->children[name];
      }
      listing = false;
    } else {
      if (listing) {
        if (line.substr(0, 3) == "dir") {
          string name = line.substr(4, line.size() - 1);
          // create new folder
          if (current->children.find(name) == current->children.end()) {
            Node* newNode = new Node(name);
            newNode->isFolder = true;
            newNode->parent = current;
            current->children[name] = newNode;
          }
        } else {
          vector<string> parts = parse_line(line);
          string name = parts[1];
          long long size = stoll(parts[0]);
          // create new file
          if (current->children.find(name) == current->children.end()) {
            Node* newNode = new Node(name);
            newNode->parent = current;
            current->children[name] = newNode;
          }
          current->children[name]->size = size;
        }
      }
    }
  }
  long long sum = 0;
  long long minSize = LLONG_MAX;
  calculateSize(root, sum, 0, minSize);
  long long TOTAL_AVAILABLE = 70000000;
  long long UNUSED_SPACE = 30000000;
  long long MIN_DELETE = root->size - (TOTAL_AVAILABLE - UNUSED_SPACE);
  minSize = LLONG_MAX;
  calculateSize(root, sum, MIN_DELETE, minSize);
  cout << "root->size = " << root->size << endl;
  cout << "result = " << sum << endl;
  cout << "minSize = " << minSize << endl;
}