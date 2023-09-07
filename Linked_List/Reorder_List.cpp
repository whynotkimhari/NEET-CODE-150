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

    void reorderList(ListNode* head) {
        // ATTENTION: NODES' VALUE CAN NOT BE MODIFY
        // WE CAN ASSIGN ->NEXT TO HEAD
        // BUT WE CAN NOT ASSIGN SOMETHING TO HEAD NODE (L0)
        int size = len(head);
        if(size <= 1) return;

        vector<ListNode*> nodes;
        ListNode* tmpNode;
        auto tmp = head;

        while(tmp) {
            tmpNode = tmp;
            tmp = tmp->next;
            tmpNode->next = nullptr;
            nodes.push_back(tmpNode);
        }

        for(int i = 0; i < size / 2; i++) {
            if(i) {
                head->next = nodes[i];
                head = head->next;
            }
            head->next = nodes[size - 1 - i];
            head = head->next;
        }

        if(size % 2) {
            head->next = nodes[size / 2];     
        }
    }
};
