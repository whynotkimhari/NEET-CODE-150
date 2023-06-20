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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sz1 = 0, sz2 = 0;
        auto ll1 = l1, ll2 = l2;
        while(ll1) {
            ll1 = ll1->next;
            sz1++;
        }
        while(ll2) {
            ll2 = ll2->next;
            sz2++;
        }
        int r = 0;
        if(sz2 <= sz1) {
            auto const lll1 = l1;
            while(l1 && l2) {
                if(l1->val + l2->val + r < 10) {
                    l1->val = l1->val + l2->val + r;
                    r = 0;
                }
                else {
                    l1->val = (l1->val + l2->val + r) % 10;
                    r = 1;
                }

                if(l1->next) {
                    l1 = l1->next;
                    l2 = l2->next;
                }
              
                else {
                    if(r) {
                        l1->next = new ListNode(r);
                        r = 0;
                    }
                    l1 = l1->next;
                    l2 = l2->next;
                }
            }

            while(l1) {
                if(l1->val + r < 10) {
                    l1->val += r;
                    r = 0;
                }
              
                else {
                    l1->val = (l1->val + r) % 10;
                    r = 1;
                }
              
                if(l1->next)
                    l1 = l1->next;
              
                else {
                    if(r) {
                        l1->next = new ListNode(r);
                        r = 0;
                    }
                    l1 = l1->next;
                }
            }
            return lll1;
        }
        
        else {
            auto const lll2 = l2;
            while(l1 && l2) {
                if(l1->val + l2->val + r < 10) {
                    l2->val += l1->val + r;
                    r = 0;
                }
              
                else {
                    l2->val = (l2->val + l1->val + r) % 10;
                    r = 1;
                }
              
                if(l2->next) {
                    l1 = l1->next;
                    l2 = l2->next;
                }
              
                else {
                    if(r) {
                        l2->next = new ListNode(r);
                        r = 0;
                    }
                    l2 = l2->next;
                    l1 = l1->next;
                }
            }
          
            while(l2) {
                if(l2->val + r < 10) {
                    l2->val += r;
                    r = 0;
                }
              
                else {
                    l2->val = (l2->val + r) % 10;
                    r = 1;
                }
              
                if(l2->next)
                    l2 = l2->next;
              
                else {
                    if(r) {
                        l2->next = new ListNode(r);
                        r = 0;
                    }
                    l2 = l2->next;
                }
            }
            return lll2;
        }
        return nullptr;
    }
};
