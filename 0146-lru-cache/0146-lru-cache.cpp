class LRUCache {
public:
    class Node {
        public:
            int ky;
            int val;
            Node* next;
            Node* prev;
            Node(int key, int value) {
                ky = key;
                val = value;
            }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> mpp;

    LRUCache(int capacity) {
        cap = capacity;
        mpp.clear();
        head->next = tail;
        tail->prev = head;
    }

    void addnode(Node* node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }

    void deletenode(Node* node) {
        Node* delprev = node->prev;
        Node* delnext = node->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key) {
        if(mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            mpp.erase(key);
            deletenode(node);
            addnode(node);
            mpp[key] = head->next;
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            mpp.erase(key);
            deletenode(node);
        }
        if(mpp.size() == cap) {
            mpp.erase(tail->prev->ky);
            deletenode(tail->prev);
        }
        addnode(new Node(key, value));
        mpp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */