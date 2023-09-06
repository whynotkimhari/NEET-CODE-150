class Node {
    public:
        int val;
        Node* next;

        Node() {
            this->val = 0;
            this->next = nullptr;
        }

        Node(int val) {
            this->val = val;
            this->next = nullptr;
        }

        Node(int val, Node* next) {
            this->val = val;
            this->next = next;
        }
};

class MyLinkedList {
private:
    int size;
    Node* head;

public:
    MyLinkedList() {
        this->size = 0;
        this->head = nullptr;
    }
    
    int get(int index) {
        if(index > this->size - 1 || index < 0) return -1;
        Node* tmp = this->head;
        while(tmp) {
            if(!index) return tmp->val;
            tmp = tmp->next;
            index--;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node* newHead = new Node(val);

        if(this->head != nullptr) {
            newHead->next = this->head;
            this->head = newHead;
        }
        else this->head = newHead;
        
        this->size++;
    }
    
    void addAtTail(int val) {
        if(!this->size) addAtHead(val);
        else {
            Node* tail = this->head;
            Node* newTail = new Node(val);

            while(tail->next) tail = tail->next;
            
            tail->next = newTail;
            this->size++;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(!index) addAtHead(val);
        else if(index == this->size) addAtTail(val);
        else if(index > this->size || index < 0) return;
        else {
            Node* newNode = new Node(val);
            Node* tmpHead = this->head;
            while(tmpHead) {
                if(!(index - 1)) {
                    Node* tmp = tmpHead->next;
                    tmpHead->next = newNode;
                    newNode->next = tmp;
                    this->size++;
                    return;
                }
                index--;
                tmpHead = tmpHead->next;
            }
        }
        return;
        
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index > this->size - 1) return;
        else if(index == 0) {
            this->head = this->head->next;
            this->size--;
        }
        else if(index == this->size - 1) {
            Node* tmpHead = this->head;
            while(tmpHead->next->next) tmpHead = tmpHead->next;
            tmpHead->next = nullptr;
            this->size--;
        }
        else {
            Node* tmpHead = this->head;
            while(tmpHead) {
                if(!(index - 1)) {
                    Node* tmp = tmpHead->next->next;
                    tmpHead->next = tmp;
                    this->size--;
                    return;
                }
                index--;
                tmpHead = tmpHead->next;
            }
        }
        return;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
