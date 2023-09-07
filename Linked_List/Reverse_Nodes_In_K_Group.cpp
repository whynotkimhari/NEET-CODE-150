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

    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;

        auto newHead = head;
        if(head->next) {
            newHead = reverseList(head->next);
            head->next->next = head;
        }
        head->next = nullptr;

        return newHead;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        int size = len(head);
        int max = (size - size % k);
        vector<ListNode*> lists;

        ListNode* listCurr = new ListNode(-1);
        ListNode* listHead = listCurr;

        ListNode* node;
        ListNode* base = new ListNode(-1);
        ListNode* returnHead = base;

        while(max--) {
            if(count < k) {
                // GET ONLY 1 NODE
                node = head;
                head = head->next;
                node->next = nullptr;

                // CONCAT
                listCurr->next = node;

                // UPDATE CURR
                listCurr = listCurr->next;
                count++;
            }

            if(count >= k) {
                lists.push_back(listHead->next);

                // RESET COUNTER AND TRACKER
                listCurr = new ListNode(-1);
                listHead = listCurr;
                count = 0;
            }
        }
        
        // REVERSE EACH LIST
        for(auto &list : lists) {
            auto x = reverseList(list);
            base->next = x;
            while(base->next) base = base->next;
        }

        // IF EXIST ONE GROUP SIZE < k
        // THIS GROUP WILL NOT BE REVERSE
        if(head) base->next = head;

        returnHead = returnHead->next;
        return returnHead;
    }
};
