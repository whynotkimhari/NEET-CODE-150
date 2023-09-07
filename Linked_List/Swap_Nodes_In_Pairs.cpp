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
    int len(ListNode* head) {
        int cnt = 0;
        while(head) {
            head = head->next;
            cnt++;
        }
        return cnt;
    }

    ListNode* swapPairs(ListNode* head) {
        int size = len(head);
        if(size <= 1) return head;

        ListNode* rtHead = nullptr;
        ListNode* last = nullptr;
        
        while(head && head->next) {
            auto tmp = head->next;
            head->next = tmp->next;
            tmp->next = head;
            if(last == nullptr) last = head;
            else {
                last->next = tmp;
                last = head;
            }
            if(rtHead == nullptr) rtHead = tmp;
            head = head->next;
        }

        return rtHead;
    }
};
