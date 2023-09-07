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
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* head = new ListNode(0);
        ListNode* tmp;
        ListNode* rtHead = head;
        while(a && b) {
            if(a->val < b->val) {
                tmp = a;
                a = a->next;
            }
            else {
                tmp = b;
                b = b->next;
            }
            tmp->next = nullptr;
            head->next = tmp;
            head = head->next;
        }
        if(a) head->next = a;
        if(b) head->next = b;
        rtHead = rtHead->next;
        return rtHead;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* base = nullptr;
        for(auto list: lists) base = merge(base, list);
        return base;
    }
};
