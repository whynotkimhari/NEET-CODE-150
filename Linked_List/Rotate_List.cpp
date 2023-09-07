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

    ListNode* rotateRight(ListNode* head, int k) {
        int size = len(head);
        if(!size) return head;

        k %= size;
        int index = size - k;
        ListNode* ans;
        ListNode* tail = head;

        while(tail->next) tail = tail->next;
        tail->next = head;

        index--;
        while(index--) head = head->next;
        ans = head->next;
        head->next = nullptr;

        
        return ans;
    }
};
