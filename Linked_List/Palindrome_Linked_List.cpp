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
    bool isPalindrome(ListNode* head) {
        double sumChecking = 0;
        int len = 0, i = 0, lastM;

        ListNode* HEAD = head;

        while(head) {
            len++;
            head = head->next;
        }

        if(len % 2) {
            while(HEAD) {
                if(i == len / 2) sumChecking += 0;
                else if(i < len / 2) {
                    if(i) sumChecking += HEAD->val * i;
                    else sumChecking += HEAD->val;
                }
                else {
                    if(i != len - 1) sumChecking -= HEAD->val * (len - i - 1);
                    else sumChecking -= HEAD->val;
                }
                HEAD = HEAD->next;
                i++;
            }

        }

        else {
            while(HEAD) {
                if(i < len / 2) {
                    if(i > 1) sumChecking += HEAD->val * log(i);
                    else sumChecking += HEAD->val;
                    lastM = HEAD->val;
                }
                else {
                    if(i != len - 1 && len - i - 1 != 1) {
                        sumChecking -= HEAD->val * log(len - i - 1);
                        if(i == len / 2 && lastM != HEAD->val) return false;
                    }
                    else sumChecking -= HEAD->val;
                }
                
                HEAD = HEAD->next;
                i++;
            }
        }
        return !(round(sumChecking));
    }
};
