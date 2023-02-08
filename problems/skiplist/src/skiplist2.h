// Skiplist::insert method
void Skiplist::insert(int key) {
  // create a new node
  Node* newNode = new Node(key);
  // create a new level
  int level = 0;
  // create a new node pointer
  Node* node = head;
  // create a new node pointer
  Node* update[MAX_LEVEL];
  // set all the update pointers to NULL
  memset(update, 0, sizeof(Node*)*MAX_LEVEL);
  // loop through the list
  for (int i = level; i >= 0; i--) {
    // while the next node is not NULL and the next node's key is less than the new node's key
    while (node->forward[i] != NULL && node->forward[i]->key < key) {
      // set the node to the next node
      node = node->forward[i];
    }
    // set the update pointer to the node
    update[i] = node;
  }
  // set the node to the next node
  node = node->forward[0];
  // if the node is not NULL and the node's key is equal to the new node's key
  if (node == NULL || node->key != key) {
    // create a new level
    int rlevel = randomLevel();
    // if the new level is greater than the current level
    if (rlevel > level) {
      // loop through the list
      for (int i = level + 1; i < rlevel + 1; i++) {
        // set the update pointer to the head
        update[i] = head;
      }
      // set the level to the new level
      level = rlevel;
    }
    // create a new node
    node = new Node(key);
    // loop through the list
    for (int i = 0; i <= level; i++) {
      // set the new node's forward pointer to the update pointer's forward pointer
      node->forward[i] = update[i]->forward[i];
      // set the update pointer's forward pointer to the new node
      update[i]->forward[i] = node;
    }
  }
}

SKiplist::Skiplist(){
  // create a new node
  Node* newNode = new Node(-1);
  // set the head to the new node
  head = newNode;
  // set the level to 0
  level = 0;
  // set the max level to 3
  MAX_LEVEL = 3;
}