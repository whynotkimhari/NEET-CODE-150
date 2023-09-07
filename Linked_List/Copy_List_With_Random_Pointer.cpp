/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class NodeData {
public:
    int val;
    int random_index;

    NodeData(int val, int random_index) {
        this->val = val;
        this->random_index = random_index;
    }
};

class Solution {
public:
    int len(Node* head) {
        int cnt = 0;
        while(head) {
            head = head->next;
            cnt++;
        }
        return cnt;
    }

    Node* find(Node* head, int index) {
        while(head) {
            if(!index) return head;
            head = head->next;
            index--;
        }
        return nullptr;
    }

    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        int size = len(head);
        int next_index, random_index;

        vector<NodeData*> nodes;

        while(head) {
            random_index = size - len(head->random);
            NodeData* newNodeData = new NodeData(head->val, random_index);
            nodes.push_back(newNodeData);
            head = head->next;
        }

        Node* newHead = new Node(0);
        Node* returnHead = newHead;
        
        for(auto &node: nodes) {
            Node* newNode = new Node(node->val);
            newHead->next = newNode;
            newHead = newHead->next;
        }

        returnHead = returnHead->next;
        newHead = returnHead;

        int id = 0;
        while(true) {
            int rd = nodes[id]->random_index;
            auto rdNode = find(returnHead, rd);
            newHead->random = rdNode;
            newHead = newHead->next;
            id++;

            if(id == size) break;
        }

        return returnHead;
    }
};
