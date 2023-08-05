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
    ListNode* middleNode(ListNode* head) {
        auto headCnt = head;
        int cntSizeIndex = 0;
        int id;
        while(true) {
            if(headCnt) { 
                cntSizeIndex++;
                headCnt = headCnt->next;
            }
            else break;
        }
        
        id = cntSizeIndex / 2;
        while(id--) {
            head = head->next;
        }
        return head;
    }
};
