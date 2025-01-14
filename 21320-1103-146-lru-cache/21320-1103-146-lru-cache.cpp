class LRUCache {
public:
 class node {
      public:
        int key;
      int val;
      node * next;
      node * prev;
      
    };
   node * head = new node(-1, -1);
  node * tail = new node(-1, -1);

  int cap;
  unordered_map < int, node * > m;
  void addnode(node * newnode) {
    node * temp = head -> next;
    newnode -> next = temp;
    newnode -> prev = head;
    head -> next = newnode;
    temp -> prev = newnode;
  }

  void deletenode(node * delnode) {
    node * delprev = delnode -> prev;
    node * delnext = delnode -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
  }

  LRUCache(int capacity) {
    cap = capacity;
    head -> next = tail;
    tail -> prev = head;
  }
    int get(int key) {
        if (m.find(key) != m.end()) {
      node * resnode = m[key];
      int res = resnode -> val;
      deletenode(resnode);
      addnode(resnode);
      return res;
    }

    return -1;
    }
    
    void put(int key, int value) {
     if (m.find(key) != m.end()) {
      node * existingnode = m[key];
      existingnode->val = value;
      deletenode(existingnode);
      addnode(existingnode);
     }
     else{
     if (m.size() == cap) {
      m.erase(tail -> prev -> key);
      deletenode(tail -> prev);
    }
    node * newnod = new node(key,value);  
    addnode(newnod);
    m[key] = newnod;
     }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */