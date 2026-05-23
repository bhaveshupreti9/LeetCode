class Node {
public:
    string data;
    Node* next;
    Node* prev;

    Node() : data(""), next(nullptr), prev(nullptr) {}
    
    Node(string x) : data(x), next(nullptr), prev(nullptr) {}
    
    Node(string x, Node* nextNode, Node* prevNode)
        : data(x), next(nextNode), prev(prevNode) {}
};

class BrowserHistory {
    Node* current;

public:
    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newnode = new Node(url);
        current->next = newnode;
        newnode->prev = current;
        current = newnode;
    }
    
    string back(int steps) {
        while (steps) {
            if(current -> prev)current = current->prev;
            else break;
            steps--;
        }
        return current->data;
    }
    
    string forward(int steps) {
        while (steps) {
            if(current -> next)current = current -> next;
            else break;
            steps--;
        }
        return current->data;
    }
};