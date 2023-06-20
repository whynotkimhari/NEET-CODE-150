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

// Solution 1: Create new Linked List
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;

        stack<int> st;

        while(head) {
            st.push(head->val);
            head = head->next;
        }

        ListNode* tmp = new ListNode();
        ListNode* newHead = new ListNode(st.top());
        st.pop();
        tmp->next = newHead;
        while(!st.empty()) {
            ListNode* newNode = new ListNode(st.top());
            st.pop();
            tmp->next->next = newNode;
            tmp = tmp->next;
        }

        return newHead;
    }
};

// Solution 2: Using 2 pointers: current and previous
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr) {
            auto nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
};

// Solution 3: Using Recursion
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;

        auto newHead = head;
        if(head->next) {
            newHead = reverseList(head->next);
            head->next->next = head;
        }
        head->next = nullptr;

        return newHead;
    }
};
