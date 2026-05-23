class LRUCache {
public:
    class Node{
        public:
        int key_;
        int info;
        Node* prev;
        Node* next;
        Node(int _key,int _info){
            key_ = _key;
            info = _info;
        }
    };
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int cap;
    map<int,Node*>mpp;
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    void insertafterhead(Node* newnode){
        Node* temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
    }
    void deletegivennode(Node* delnode){
        Node* delprev = delnode -> prev;
        Node* delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }
    int get(int key) {
        if(mpp.find(key) != mpp.end()){
            Node* movnode = mpp[key];
            int mov = movnode-> info;
            mpp.erase(key);
            //Move movnode to front
            deletegivennode(movnode);
            insertafterhead(movnode);
            mpp[key] = head -> next;
            return mov;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node* existing = mpp[key];
            mpp.erase(key);
            deletegivennode(existing);
        }
        if(mpp.size() == cap){
            mpp.erase(tail -> prev -> key_);
            deletegivennode(tail -> prev);
        }
        insertafterhead(new Node(key,value));
        mpp[key] = head -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */