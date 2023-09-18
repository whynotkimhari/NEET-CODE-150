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
    ListNode* insertionSortList(ListNode* head) {
        vector<int> vals;
        while(head) {
          vals.push_back(head->val);
          head = head->next;
        }
        sort(vals.begin(), vals.end());

        ListNode* newHead = new ListNode(vals[0]);
        ListNode* flag = newHead;
        for(int i = 1; i < vals.size(); i++) {
          newHead->next = new ListNode(vals[i]);
          newHead = newHead->next;
        }

        return flag;
    }
};
