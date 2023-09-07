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

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;

        ListNode* L = new ListNode(-501);
        ListNode* M = new ListNode(-501);
        ListNode* headL = L;
        ListNode* headM = M;
        ListNode* node;

        int id = 1;

        while(id < left) {
            node = head;
            head = head->next;
            node->next = nullptr;
            L->next = node;
            L = L->next;
            id++;
        }

        while(id >= left && id <= right) {
            node = head;
            head = head->next;
            node->next = nullptr;
            M->next = node;
            M = M->next;
            id++;
        }

        headM = headM->next;
        L->next = reverseList(headM);
        while(L->next) L = L->next;
        if(head) L->next = head;
        
        headL = headL->next;
        return headL;
    }
};
