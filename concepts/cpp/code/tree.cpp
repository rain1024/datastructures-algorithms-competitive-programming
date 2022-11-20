#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int key;
    Node* parent;
    vector<Node*> children;
    
    Node(int key){
        this->parent = NULL;
        this->key = key;
    }
    
    void setParent(Node* parent){
        this->parent = parent;
        parent->children.push_back(this);
    }
    
    string toString(){
        return to_string(this->key);
    }
};

int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    n2->setParent(n1);
    cout << n1->toString() << endl;
}