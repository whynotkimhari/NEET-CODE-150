class Node {
    public:
        string domain;
        Node* next;
        Node* prev;

        Node() {
            this->domain = "";
            this->next = nullptr;
            this->prev = nullptr;
        }

        Node(string domain) {
            this->domain = domain;
            this->next = nullptr;
            this->prev = nullptr;
        }
};
class BrowserHistory {
private:
    Node* curr;
public:
    BrowserHistory(string homepage) {
        this->curr = new Node(homepage);
    }
    
    void visit(string url) {
        Node* node = new Node(url);
        node->prev = this->curr;
        this->curr->next = node;
        this->curr = node;
    }
    
    string back(int steps) {
        while(this->curr->prev) {
            if(!steps) break;
            this->curr = this->curr->prev;
            steps--;
        }
        return this->curr->domain;
    }
    
    string forward(int steps) {
        while(this->curr->next) {
            if(!steps) break;
            this->curr = this->curr->next;
            steps--;
        }
        return this->curr->domain;   
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
