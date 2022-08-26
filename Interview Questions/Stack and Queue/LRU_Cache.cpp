//Using Doubly Linked List and Hash Map
    class node {
        public:
        int key;
        int value;
        node* next;
        node* prev;
        //Constructor
        node(int _key, int _value) {
            key = _key;
            value = _value;
        }
    };
    
    //Function to add node in doubly linked list
    void addnode(node* newnode) {
        //temp will point to tail
        node* temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
    }
    
    //Function to delete node in doubly linked list
    void deletenode(node* delnode) {
        node* delprev = delnode -> prev;
        node* delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }
    
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    
    int cap;
    unordered_map <int, node * > m;
    
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(m.count(key)) {
            node* ansNode = m[key];
            int ans = ansNode -> value;
            deletenode(ansNode);
            addnode(ansNode);
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        //If key is already present
        if(m.count(key)) {
            node* existingnode = m[key];
            m.erase(key);
            deletenode(existingnode);
        }
        if(m.size() == cap) {
            m.erase(tail -> prev -> key);
            deletenode(tail -> prev);
        }
        
        addnode(new node(key, value));
        m[key] = head -> next;
    }