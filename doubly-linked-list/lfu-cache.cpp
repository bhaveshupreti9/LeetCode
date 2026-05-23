class LFUCache {
public:
    class Node{
    public:
        int key_;
        int info;
        int count;
        Node* prev;
        Node* next;
        Node(int _key,int _info){
            key_ = _key;
            info = _info;
            count = 1;
        }
    };
    class List{
    public:
        int size;
        Node* head;
        Node* tail;
        List(){
            head = new Node(-1,-1);
            tail = new Node(-1,-1);
            size = 0;
            head -> next = tail;
            tail -> prev = head;
        }
        void insertafterhead(Node* newnode){
            Node* temp = head -> next;
            newnode -> prev = head;
            newnode -> next = temp;
            temp -> prev = newnode;
            head -> next = newnode;
            size++;
        }
        void deletegivennode(Node* delnode){
            Node* delprev = delnode -> prev;
            Node* delnext = delnode -> next;
            delprev -> next = delnext;
            delnext -> prev = delprev;
            size--;
        }
    };
    int cap;
    map<int,Node*>keymap;
    map<int,List*>freqmap;
    int minf;
    int cursize;
    LFUCache(int capacity) {
        cap = capacity;
        minf = 0;
        cursize = 0;
    }
    
    void updatefreq(Node* node){
        keymap.erase(node -> key_);
        freqmap[node -> count] -> deletegivennode(node);
        if(node -> count == minf && freqmap[node -> count] -> size == 0)minf++;
        List* nexthigh = new List();
        if(freqmap.find(node -> count +1) != freqmap.end()){
            nexthigh = freqmap[node -> count +1];
        }
        else nexthigh = new List();
        node -> count += 1;
        nexthigh -> insertafterhead(node);
        freqmap[node -> count] = nexthigh;
        keymap[node -> key_] = node;
    }
    int get(int key) {
        if(keymap.find(key) != keymap.end()){
            Node* node = keymap[key];
            int val = node -> info;
            updatefreq(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
       /* If the size of Cache is 0, 
       no data-items can be inserted */
       if (cap == 0) {
           return;
       }
       
       // If key already exists
       if(keymap.find(key) != keymap.end()) {
           
           // Get the node
           Node* node = keymap[key]; 
           
           // Update the value
           node->info = value; 
           
           // Update the frequency
           updatefreq(node); 
       }
       
       // Else if the key does not exist
       else {
           
           // If cache limit is reached
           if(cursize == cap) {
               
               // Remove the least frequently used data-item
               List* list = freqmap[minf]; 
               keymap.erase(list->tail->prev->key_); 
               
               // Update the frequency map 
               freqmap[minf]->deletegivennode(
                   list->tail->prev
               );
               
               // Decrement the current size of cache
               cursize--; 
           }
           
           // Increment the current cache size
           cursize++; 
           
           // Adding new value to the cache
           minf = 1; // Set its frequency to 1
           
           // Create a dummy list
           List* listFreq = new List(); 
           
           // If the list already exist
           if(freqmap.find(minf) != 
              freqmap.end()) {
               
               // Update the pointer to already present list
               listFreq = freqmap[minf]; 
           }
           
           // Create the node to store data-item
           Node* node = new Node(key, value); 
           
           // Add the node to dummy list
           listFreq->insertafterhead(node);
           
           // Add the node to Hashmap
           keymap[key] = node; 
           
           // Update the frequency list map 
           freqmap[minf] = listFreq; 
       }
   }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */