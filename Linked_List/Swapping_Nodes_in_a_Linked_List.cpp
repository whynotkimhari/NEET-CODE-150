/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Sol 1: Swap node itself
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int size = 0;
        ListNode* HEAD = head;

        while(head) {
            head = head->next;
            size++;
        }

        if(size == 1) return HEAD;

        int l = size - k;
        int cnter1 = 0, cnter2 = 0;
        ListNode* node1;
        ListNode* node2;
        ListNode* prenode1 = HEAD;
        ListNode* prenode2 = HEAD;

        if(k == 1 || k == size) {
            node2 = HEAD;
            while(node2->next) node2 = node2->next;
            while(prenode2->next->next) prenode2 = prenode2->next;

            cout << node2->val << " " << prenode2->val << " " << prenode1->val << endl;

            prenode2->next = prenode1;
            auto tmpNode = prenode1->next;
            prenode1->next = nullptr;
            node2->next = tmpNode;
            HEAD = node2;
            return HEAD;
        }

        while(prenode1) {
            if(cnter1 == k - 2) {
                node1 = prenode1->next;
                break;
            }
            prenode1 = prenode1->next;
            cnter1++;
        }

        while(prenode2) {
            if(cnter2 == l - 1) {
                node2 = prenode2->next;
                break;
            }
            prenode2 = prenode2->next;
            cnter2++;
        }

        prenode1->next = node2;
        prenode2->next = node1;
        auto tmpNode = node1->next;
        node1->next = node2->next;
        node2->next = tmpNode;

        return HEAD;
    }
};

// Sol 2: Swap nodes' value
class Solution {
public:
    int len(ListNode* head) {
        int size = 0;
        while(head) {
            head = head->next;
            size++;
        }
        return size;
    }

    ListNode* find(int id, ListNode* head) {
        int counter = 0;
        while(head) {
            if(counter == id) break;
            head = head->next;
            counter++;
        }
        return head;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        int size = len(head);

        if(size == 1) return head;

        ListNode* HEAD = head;
        int c1 = 0, c2 = 0;
        ListNode* n1 = find(k - 1, HEAD);
        ListNode* n2 = find(size - k, HEAD);
        swap(n1->val, n2->val);

        return HEAD;
    }
};
