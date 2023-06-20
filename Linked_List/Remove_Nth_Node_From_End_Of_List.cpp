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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0;
        auto const HEAD = head;
        auto head2 = head;

        while(head) {
            sz++;
            head = head->next;
        }

        if(sz == n) return HEAD->next;

        int index = sz - n;
        while(head2) {
            if(index == 1) {
                head2->next = head2->next->next;
                break;
            }
            else {
                head2 = head2->next;
            }
            index--;
        }

        return HEAD;
    }
};
