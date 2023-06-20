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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return list1;
        if(!list1 && list2) return list2;
        if(list1 && !list2) return list1;

        ListNode* tmp1 = new ListNode();
        ListNode* tmp2 = new ListNode();
        ListNode* ans = nullptr;

        if(list1->val <= list2->val) {
            auto const curr = list1;
            tmp1->next = list1->next;
		        tmp2->next = list2;
            
            while(tmp1->next && tmp2->next) {
                if(tmp1->next->val <= tmp2->next->val) {
                    auto nxt = tmp1->next;
                    tmp1->next = tmp1->next->next;
                    list1->next = nxt;
                }
                else {
                    auto nxt = tmp2->next;
                    tmp2->next = tmp2->next->next;
                    list1->next = nxt;
                }
                list1 = list1->next;
            }

            while(tmp1->next) {
                auto nxt = tmp1->next;
                tmp1->next = tmp1->next->next;
                list1->next = nxt;
                list1 = list1->next;
            }

            while(tmp2->next) {
                auto nxt = tmp2->next;
                tmp2->next = tmp2->next->next;
                list1->next = nxt;
                list1 = list1->next;
            }
            ans = curr;
        }

        else {
            auto const curr = list2;
            tmp2->next = list2->next;
		        tmp1->next = list1;
            
            while(tmp1->next && tmp2->next) {
                if(tmp2->next->val <= tmp1->next->val) {
                    auto nxt = tmp2->next;
                    tmp2->next = tmp2->next->next;
                    list2->next = nxt;
                }
                else {
                    auto nxt = tmp1->next;
                    tmp1->next = tmp1->next->next;
                    list2->next = nxt;
                }
                list2 = list2->next;
            }

            while(tmp2->next) {
                auto nxt = tmp2->next;
                tmp2->next = tmp2->next->next;
                list2->next = nxt;
                list2 = list2->next;
            }

            while(tmp1->next) {
                auto nxt = tmp1->next;
                tmp1->next = tmp1->next->next;
                list2->next = nxt;
                list2 = list2->next;
            }
            ans = curr;
        }
      
        return ans;
    }
};
