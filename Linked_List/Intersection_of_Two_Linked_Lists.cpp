/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> setA, setB;
        while(headA || headB) {
            setA.insert(headA);
            setB.insert(headB);
            if(headA == headB) return headA;
            if(headA)
            headA = headA->next;
            if(headB)
            headB = headB->next;

            if(setA.find(headB) != setA.end()) return headB;
            if(setB.find(headA) != setB.end()) return headA;
        }
        return nullptr;
    }
};
