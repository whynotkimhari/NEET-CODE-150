/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Solution 1: Using HashSet: Space complexity O(n) 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> seen;
        while(head) {
            auto it = seen.find(head);
            if(it != seen.end()) {
                return true;
            }
            else {
                seen.insert(head);
            }
            head = head->next;
        }
        return false;
    }
};

// Solution 2: Using Floyd's Tortoise and Hare
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fastP = head; ListNode* slowP = head;

        while(fastP && fastP->next) {
            fastP = fastP->next->next;
            slowP = slowP->next;
            if(fastP == slowP) return true;
        }
        return false;
    }
};
