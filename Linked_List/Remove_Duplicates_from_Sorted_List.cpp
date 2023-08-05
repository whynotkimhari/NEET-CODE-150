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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        vector<int> temp;
        while(head) {
            if(!temp.size()) {
                temp.push_back(head->val);
                head = head->next;
            }
            else {
                if(temp.back() == head->val) head = head->next;
                else {
                    temp.push_back(head->val);
                    head = head->next;
                }
            }
        }

        ListNode* newHead = new ListNode(temp[0]);
        auto const rt = newHead;
        for(int i = 1; i < temp.size(); i++) {
            ListNode* k = new ListNode(temp[i]);
            newHead->next = k;
            newHead = k;
        }

        return rt;
    }
};
