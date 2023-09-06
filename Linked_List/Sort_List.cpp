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

    void print(ListNode* head) {
        while(head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    ListNode* split(ListNode* head, int start, int end) {
        ListNode* newHead = new ListNode(0);
        ListNode* tmpHead = newHead;

        int cnter = 0;

        while(head) {
            if(cnter >= start && cnter <= end) {
                newHead->next = new ListNode(head->val);
                newHead = newHead->next;
            }
            head = head->next;
            cnter++;
        }

        tmpHead = tmpHead->next;
        return tmpHead;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* newHead = new ListNode(0);
        ListNode* head = newHead;

        while(head1 && head2) {
            if(head1->val < head2->val) {
                newHead->next = new ListNode(head1->val);
                newHead = newHead->next;
                head1 = head1->next;
            }

            else {
                newHead->next = new ListNode(head2->val);
                newHead = newHead->next;
                head2 = head2->next;
            }
        }

        while(head1) {
            newHead->next = new ListNode(head1->val);
            newHead = newHead->next;
            head1 = head1->next;
        }

        while(head2) {
            newHead->next = new ListNode(head2->val);
            newHead = newHead->next;
            head2 = head2->next;
        }

        head = head->next;
        return head;
    }

    ListNode* sortList(ListNode* head) {
        if(!head) return head;
        int size = len(head);
        if(size == 1) return head;
        else if(size == 2) {
            ListNode* a = new ListNode(head->val);
            ListNode* b = new ListNode(head->next->val);
            return merge(a, b);
        }
        else {
            int mid = size / 2;
            return merge(sortList(split(head, 0, mid - 1)), sortList(split(head, mid, size - 1)));
        }
        
        return nullptr;
    }
};
